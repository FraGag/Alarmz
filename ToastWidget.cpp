/* Alarmz - A program to show user-defined alarms
   Copyright (C) 2010 Francis Gagné <fragag1@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ToastWidget.h"
#include "ui_ToastWidget.h"
#include "Alarm.h"
#include "Settings.h"
#include "TimeSpan.h"
#include <QtGlobal>
#include <QApplication>
#include <QColor>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QPainter>
#include <QRect>
#include <QSound>
#include <QUrl>
#ifdef Q_WS_WIN
#include <windows.h>
#endif

namespace Alarmz {

QList<ToastWidget *> ToastWidget::visibleInstances;

ToastWidget::ToastWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToastWidget),
    snoozeTimerId(0),
    rollTimerId(0),
    fadeTimerId(0)
{
    this->ui->setupUi(this);

    // Don't exit Alarmz when a toast is closed while the main window is hidden
    this->setAttribute(Qt::WA_QuitOnClose, false);

    this->connect(this->ui->snoozeButton, SIGNAL(clicked()), SLOT(snooze()));
    QDesktopWidget *dw = QApplication::desktop();
    this->connect(dw, SIGNAL(workAreaResized(int)), SLOT(onWorkAreaResized(int)));
    this->loadSettings();
    this->connect(&Settings::instance(), SIGNAL(changed()), SLOT(loadSettings()));
}

ToastWidget::~ToastWidget()
{
    delete this->ui;
}

void ToastWidget::pop(Alarm *alarm)
{
    this->ui->messageLabel->setText(alarm->message());

    visibleInstances.append(this);
    this->pop();
}

void ToastWidget::snooze()
{
    this->snoozeTimerId = this->startTimer(1000);
    this->snoozeStartTime = QDateTime::currentDateTime();
    visibleInstances.removeOne(this);
    this->hide();
    repositionToasts();
}

void ToastWidget::repositionToasts()
{
    for (int i = 0; i < visibleInstances.length(); i++) {
        visibleInstances.at(i)->reposition();
    }
}

void ToastWidget::reposition()
{
    Settings &settings(Settings::instance());
    QDesktopWidget *dw = QApplication::desktop();
    QRect rect(dw->availableGeometry(dw->primaryScreen()));
    if (settings.useNativeBorder() && !this->isVisible()) {
        // Show and hide to get the proper frame size
        this->move(-32768, -32768);
        this->show();
        this->hide();
    }

    int end = visibleInstances.indexOf(this);
    int corner = settings.corner();
    if (settings.direction() == 0) {
        // horizontal stacking
        int multiplier = corner & 1 ? -1 : 1;
        int x = corner & 1 ? rect.left() + rect.width() - this->frameSize().width() : 0;

        for (int i = 0; i < end; i++) {
            x += visibleInstances.at(i)->frameSize().width() * multiplier;
        }

        this->move(x, corner & 2 ? rect.top() + rect.height() - this->frameSize().height() : 0);
    } else {
        // vertical stacking
        int multiplier = corner & 2 ? -1 : 1;
        int y = corner & 2 ? rect.top() + rect.height() - this->frameSize().height() : 0;

        for (int i = 0; i < end; i++) {
            y += visibleInstances.at(i)->frameSize().height() * multiplier;
        }

        this->move(corner & 1 ? rect.left() + rect.width() - this->frameSize().width() : 0, y);
    }
}

void ToastWidget::pop()
{
    this->ui->widget->adjustSize();
    switch (Settings::instance().toastEmergence()) {
    case 1:
        this->setMinimumSize(this->ui->widget->size());
        this->setMaximumSize(this->ui->widget->size());
        break;

    case 3:
        this->setWindowOpacity(0.0);
        this->setMinimumSize(this->ui->widget->size());
        this->setMaximumSize(this->ui->widget->size());
        this->fadeTimerId = this->startTimer(16);
        this->emergeStartTime = QDateTime::currentDateTime();
        break;

    default:
        this->setMinimumSize(0, 0);
        this->resize(0, 0);
        this->rollTimerId = this->startTimer(16);
        this->emergeStartTime = QDateTime::currentDateTime();
        break;
    }

    this->reposition();
    this->show();
    QString soundToPlay(Settings::instance().soundToPlay());
    if (!soundToPlay.isEmpty()) {
        QSound::play(soundToPlay);
    }
}

void ToastWidget::onWorkAreaResized(int screen)
{
    if (this->isVisible()) {
        QDesktopWidget *dw = QApplication::desktop();
        if (screen == dw->primaryScreen()) {
            this->reposition();
        }
    }
}

void ToastWidget::changeEvent(QEvent *e)
{
    this->QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        this->ui->retranslateUi(this);
        break;

    default:
        break;
    }
}

void ToastWidget::closeEvent(QCloseEvent *e)
{
    this->QWidget::closeEvent(e);
    visibleInstances.removeOne(this);
    repositionToasts();
}

void ToastWidget::paintEvent(QPaintEvent *e)
{
    const Settings &settings = Settings::instance();
    int w = this->width(), h = this->height();
    QPainter painter(this);

    if (settings.useNativeBorder()) {
        if (settings.applyToastBackgroundColor()) {
            QRect rect(0, 0, w, h);
            if (settings.gradientOnToastBackground()) {
                bool vertical = settings.direction() != 0;
                QLinearGradient lg(0, 0, vertical ? w : 0, vertical ? 0 : h);
                lg.setColorAt(0, settings.toastBackgroundColor1());
                lg.setColorAt(1, settings.toastBackgroundColor2());
                painter.fillRect(rect, lg);
            } else {
                painter.fillRect(rect, settings.toastBackgroundColor1());
            }
        }
    } else {
        if (settings.applyToastBackgroundColor()) {
            QRect rect(2, 2, w - 2, h - 2);
            if (settings.gradientOnToastBackground()) {
                bool vertical = settings.direction() != 0;
                QLinearGradient lg(0, 0, vertical ? w - 4 : 0, vertical ? 0 : h - 4);
                lg.setColorAt(0, settings.toastBackgroundColor1());
                lg.setColorAt(1, settings.toastBackgroundColor2());
                painter.fillRect(rect, lg);
            } else {
                painter.fillRect(rect, settings.toastBackgroundColor1());
            }
        }

        painter.setPen(QPen(this->palette().light(), 1));
        painter.drawLine(0, 0, 0, h - 1);
        painter.drawLine(0, 0, w - 1, 0);
        painter.setPen(QPen(this->palette().midlight(), 1));
        painter.drawLine(1, 1, 1, h - 2);
        painter.drawLine(1, 1, w - 2, 1);
        painter.setPen(QPen(this->palette().shadow(), 1));
        painter.drawLine(w - 1, 0, w - 1, h - 1);
        painter.drawLine(0, h - 1, w - 1, h - 1);
        painter.setPen(QPen(this->palette().dark(), 1));
        painter.drawLine(w - 2, 1, w - 2, h - 2);
        painter.drawLine(1, h - 2, w - 2, h - 2);
    }
}

void ToastWidget::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == this->snoozeTimerId) {
        if (QDateTime::currentDateTime() >= this->snoozeStartTime.addSecs(Settings::instance().snoozeDuration() * 60)) {
            this->killTimer(this->snoozeTimerId);
            this->snoozeTimerId = 0;
            this->pop();
        }
    } else if (e->timerId() == this->rollTimerId) {
        double seconds = (QDateTime::currentDateTime() - this->emergeStartTime).totalSeconds();
        if (seconds > 0.5) {
            seconds = 0.5;
            this->killTimer(this->rollTimerId);
            this->rollTimerId = 0;
        }

        QSize size(this->ui->widget->size());
        if (Settings::instance().direction() == 0) {
            size.setWidth(static_cast<int>(size.width() * seconds * 2));
        } else {
            size.setHeight(static_cast<int>(size.height() * seconds * 2));
        }

        this->setMinimumSize(size);
        this->setMaximumSize(size);
        this->reposition();
    }
    else if (e->timerId() == this->fadeTimerId) {
        double seconds = (QDateTime::currentDateTime() - this->emergeStartTime).totalSeconds();
        if (seconds > 0.5) {
            seconds = 0.5;
            this->killTimer(this->fadeTimerId);
            this->fadeTimerId = 0;
        }

        this->setWindowOpacity(seconds * 2.0);
    }
}

#ifdef Q_WS_WIN
bool ToastWidget::winEvent(MSG *message, long *result)
{
    switch (message->message) {
    case WM_NCLBUTTONDOWN:
        if (message->wParam == HTCAPTION) {
            // prevent the user from moving the window
            *result = 0;
            return true;
        }

        break;

    case WM_SETTINGCHANGE:
        if (Settings::instance().useNativeBorder()) {
            this->reposition();
        }

        // don't return true, because Qt does some processing on its own for this message
        break;
    }

    return false;
}
#endif

void ToastWidget::on_messageLabel_linkActivated(QString link)
{
    QDesktopServices::openUrl(QUrl(link));
}

void ToastWidget::loadSettings()
{
    const Settings &settings = Settings::instance();
    bool visible = this->isVisible();
    this->setWindowFlags((settings.useNativeBorder() ? Qt::CustomizeWindowHint : Qt::FramelessWindowHint) | Qt::WindowStaysOnTopHint);
    if (visible) {
        this->show();
        this->reposition();
    }

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    if (settings.autoSize()) {
        sizePolicy.setVerticalPolicy(QSizePolicy::Minimum);
        this->ui->widget->setMinimumSize(MaxWidth, 0);
    } else {
        this->ui->widget->setMinimumSize(MaxWidth, MaxHeight);
    }

    this->ui->widget->setSizePolicy(sizePolicy);
    this->ui->widget->adjustSize();

    if (settings.applyToastTextColor()) {
        this->ui->messageLabel->setStyleSheet("color:" + settings.toastTextColor().name());
    } else {
        this->ui->messageLabel->setStyleSheet(QString());
    }

    {
        QString styleSheet;
        if (settings.applySnoozeButtonBackgroundColor()) {
            if (settings.gradientOnSnoozeButton()) {
                styleSheet +=
                        "background-color:qlineargradient(x1:0,y1:0,x2:1,y2:0,stop:0 " +
                        settings.snoozeButtonBackgroundColor1().name() +
                        ",stop:1 " +
                        settings.snoozeButtonBackgroundColor2().name() +
                        ");";
            } else {
                styleSheet +=
                        "background-color:" +
                        settings.snoozeButtonBackgroundColor1().name() +
                        ";";
            }
        }

        if (settings.applySnoozeButtonTextColor()) {
            styleSheet += "color:" + settings.snoozeButtonTextColor().name();
        }

        this->ui->snoozeButton->setStyleSheet(styleSheet);
    }

    {
        QString styleSheet;
        if (settings.applyCloseButtonBackgroundColor()) {
            if (settings.gradientOnCloseButton()) {
                styleSheet +=
                        "background-color:qlineargradient(x1:0,y1:0,x2:1,y2:0,stop:0 " +
                        settings.closeButtonBackgroundColor1().name() +
                        ",stop:1 " +
                        settings.closeButtonBackgroundColor2().name() +
                        ");";
            } else {
                styleSheet +=
                        "background-color:" +
                        settings.closeButtonBackgroundColor1().name() +
                        ";";
            }
        }

        if (settings.applyCloseButtonTextColor()) {
            styleSheet += "color:" + settings.closeButtonTextColor().name();
        }

        this->ui->closeButton->setStyleSheet(styleSheet);
    }
}

} // namespace Alarmz
