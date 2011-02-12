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

#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QDateTime>
#include <QList>
#include <QWidget>

namespace Alarmz {

class Alarm;

namespace Ui {
    class ToastWidget;
}

class ToastWidget : public QWidget
{
    Q_OBJECT

public:
    ToastWidget(QWidget *parent = 0);
    ~ToastWidget();

    void pop(Alarm *alarm);

protected:
    virtual void changeEvent(QEvent *e);
    virtual void closeEvent(QCloseEvent *);
    virtual void paintEvent(QPaintEvent *e);
    virtual void timerEvent(QTimerEvent *e);

#ifdef Q_WS_WIN
    virtual bool winEvent(MSG *message, long *result);
#endif

private:
    static const int MaxWidth = 200;
    static const int MaxHeight = 150;
    static QList<ToastWidget *> visibleInstances;

    static void repositionToasts();

    Ui::ToastWidget *ui;
    int snoozeTimerId;
    int rollTimerId;
    int fadeTimerId;
    QDateTime snoozeStartTime;
    QDateTime emergeStartTime;

    void reposition();
    void pop();

private slots:
    void on_messageLabel_linkActivated(QString link);
    void snooze();
    void onWorkAreaResized(int screen);
    void loadSettings();

};

} // namespace Alarmz

#endif // ALARMWIDGET_H
