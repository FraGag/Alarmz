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

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Alarm.h"
#include "AlarmListModel.h"
#include "AddEditAlarmDialog.h"
#include "OptionsDialog.h"
#include "Settings.h"
#include "ToastWidget.h"
#include "version.h"
#include <QCloseEvent>
#include <QDesktopServices>
#include <QDomDocument>
#include <QFileDialog>
#include <QMenu>
#include <QMessageBox>
#include <QTextStream>
#include <QTimerEvent>
#include <QUrl>
#include <QVector>

namespace Alarmz {

const char MainWindow::DateTimeFormat[] = "yyyy-MM-dd HH:mm:ss";
const TranslationSourceWithComment MainWindow::OpenSaveFileDialogFilter = QT_TRANSLATE_NOOP3("Alarmz::MainWindow", "Alarmz files (*.alarmz);;All files (*.*)", "Filter for open/save dialog");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    trayIcon(QIcon(":/icons/Alarmz.ico"), this)
{
    this->ui->setupUi(this);

    this->connect(qApp, SIGNAL(aboutToQuit()), SLOT(shutdown()));
    this->connect(this->ui->actionNew, SIGNAL(triggered()), SLOT(newFile()));
    this->connect(this->ui->actionOpen, SIGNAL(triggered()), SLOT(openFile()));
    this->connect(this->ui->actionSave, SIGNAL(triggered()), SLOT(saveFile()));
    this->connect(this->ui->actionSaveAs, SIGNAL(triggered()), SLOT(saveFileAs()));
    this->connect(this->ui->actionCloseWindow, SIGNAL(triggered()), SLOT(close()));
    this->connect(this->ui->actionExit, SIGNAL(triggered()), SLOT(quit()));

    this->ui->alarmsTreeView->setModel(this->model = new AlarmListModel(this));

    this->trayIcon.setToolTip("Alarmz");
    QMenu *menu = new QMenu(this);
    menu->addAction(tr("&Open File..."), this, SLOT(openFile()));
    menu->addAction(tr("&Save File"), this, SLOT(saveFile()));
    menu->setDefaultAction(menu->addAction(tr("S&how Window"), this, SLOT(showAndActivate())));
    menu->addAction(tr("E&xit"), this, SLOT(quit()));
    this->trayIcon.setContextMenu(menu);
    this->connect(&this->trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
    this->trayIcon.show();

    this->timer = this->startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

static int parseAlarm(QDomElement elem, Alarm *&alarm)
{
    if (elem.nodeName() != "alarm") {
        return 1;
    }

    QDateTime dateTime(QDateTime::fromString(elem.attribute("datetime"), MainWindow::DateTimeFormat));
    if (!dateTime.isValid()) {
        return 2;
    }

    bool ok;
    int frequency = elem.attribute("frequency").toInt(&ok);
    if (!ok) {
        return 3;
    }

    int display = elem.attribute("display").toInt(&ok);
    if (!ok) {
        return 4;
    }

    alarm = new Alarm();
    alarm->setMessage(elem.text());
    alarm->setDateTime(dateTime);
    alarm->setFrequency(static_cast<AlarmFrequency>(frequency));
    alarm->setDisplayMethod(static_cast<AlarmDisplayMethod>(display));
    return 0;
}

static void parseError(QWidget *parent, QString fileName, QString message)
{
    static QString genericErrorString(MainWindow::tr("An error occurred while trying to load file <b>%1</b>."));

    QMessageBox::critical(
            parent,
            MainWindow::tr("Error loading file", "Title of message box displayed when an error occurred while trying to load a file"),
            QString("%1<br><br>%2").arg(genericErrorString.arg(fileName), message)
    );
}

void MainWindow::openFile(const QString &fileName)
{
    QDomDocument doc;

    // Create a scope for file and errorMsg
    {
        QFile file(fileName);
        QString errorMsg;
        int errorLine = 0;
        int errorColumn = 0;

        // Documents don't use namespaces, so we don't need namespace processing
        if (!doc.setContent(&file, &errorMsg, &errorLine, &errorColumn)) {
            parseError(this, fileName, tr("%1<br>Line: %2<br>Column: %3").arg(errorMsg).arg(errorLine).arg(errorColumn));
            return;
        }
    }

    if (doc.documentElement().nodeName() != "alarmz") {
        parseError(this, fileName, tr("The XML document doesn't have the correct root element."));
        return;
    }

    QVector<Alarm *> alarms;
    const QDomNodeList nodes(doc.documentElement().childNodes());
    for (uint i = 0; i < nodes.length(); i++) {
        QDomNode node(nodes.item(i));
        switch (node.nodeType()) {
        case QDomNode::ElementNode: {
            QDomElement elem(node.toElement());
            Alarm *alarm = 0;
            switch (parseAlarm(elem, alarm)) {
            case 0:
                alarms.append(alarm);
                break;

            case 1:
                parseError(this, fileName, tr("An unexpected XML element was encountered."));
                goto deleteAlarms;

            case 2:
                parseError(this, fileName, tr("The format of the date and time of an alarm is invalid."));
                goto deleteAlarms;

            case 3:
                parseError(this, fileName, tr("The frequency of an alarm is invalid."));
                goto deleteAlarms;

            case 4:
                parseError(this, fileName, tr("The display method of an alarm is invalid."));
                goto deleteAlarms;
            }

            break;
        }

        case QDomNode::TextNode:
            if (!node.nodeValue().trimmed().isEmpty()) {
                parseError(this, fileName, tr("A text node in the <alarmz> element containing characters other than whitespace was encountered."));
                goto deleteAlarms;
            }

            break;

        default:
            parseError(this, fileName, tr("An unexpected XML node was found in the document."));
            goto deleteAlarms;
        }
    }

    this->model->setList(alarms);
    this->model->setDirty(false);
    this->fileName = fileName;
    return;

deleteAlarms:
    foreach (Alarm *alarm, alarms) {
        delete alarm;
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    this->QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange: {
        this->ui->retranslateUi(this);
        QList<QAction *> actions = this->trayIcon.contextMenu()->actions();
        actions.at(0)->setText(tr("&Open File..."));
        actions.at(1)->setText(tr("&Save File"));
        actions.at(2)->setText(tr("S&how Window"));
        actions.at(3)->setText(tr("E&xit"));
        break;
    }

    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    e->ignore();
    this->hide();
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    e->accept();

    QList<int> alarmsToDelete;
    QDateTime now(QDateTime::currentDateTime());
    for (int idx = 0; idx < this->model->count(); idx++) {
        Alarm *alarm = this->model->alarmAt(idx);
        if (alarm->dateTime() < now) {
            if (alarm->displayMethod() == Toast) {
                ToastWidget *toast = new ToastWidget();
                toast->pop(alarm);
            } else {
                QMessageBox::Icon icon;
                switch (alarm->displayMethod()) {
                case MsgBox_NoIcon:
                    icon = QMessageBox::NoIcon;
                    break;

                case MsgBox_Critical:
                    icon = QMessageBox::Critical;
                    break;

                case MsgBox_Question:
                    icon = QMessageBox::Question;
                    break;

                case MsgBox_Exclamation:
                    icon = QMessageBox::Warning;
                    break;

                case MsgBox_Information:
                    icon = QMessageBox::Information;
                    break;

                default:
                    icon = QMessageBox::NoIcon;
                    break;
                }

                QMessageBox *mbox = new QMessageBox(icon, "Alarmz", alarm->message(), QMessageBox::Ok);
                mbox->show();
            }

            switch (alarm->frequency()) {
            case NoRepeat:
                alarmsToDelete.append(idx);
                break;

            case Daily:
                alarm->setDateTime(alarm->dateTime().addDays(1));
                alarm->setDirty(true);
                break;

            case Weekly:
                alarm->setDateTime(alarm->dateTime().addDays(7));
                alarm->setDirty(true);
                break;

            case Monthly:
                alarm->setDateTime(alarm->dateTime().addMonths(1));
                alarm->setDirty(true);
                break;

            case Yearly:
                alarm->setDateTime(alarm->dateTime().addYears(1));
                alarm->setDirty(true);
                break;

            default:
                alarmsToDelete.append(idx);
                break;
            }
        }
    }

    for (int idx = alarmsToDelete.count() - 1; idx >= 0; idx--) {
        this->model->removeAt(alarmsToDelete.at(idx));
    }
}

int MainWindow::saveCheck()
{
    if (this->model->dirty()) {
        if (!this->fileName.isEmpty() && Settings::instance().autoSave()) {
            return this->saveFile() ? 0 : 2;
        }

        switch (QMessageBox::warning(this, "Alarmz", tr("The alarms file was modified. Do you want to save the changes?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save)) {
        case QMessageBox::Save:
            return this->saveFile() ? 0 : 2;

        case QMessageBox::Discard:
            return 1;

        default:
            return 2;
        }
    }

    return 0;
}

void MainWindow::newFile()
{
    if (this->saveCheck() != 2) {
        this->model->clear();
        this->model->setDirty(false);
        this->fileName.clear();
    }
}

void MainWindow::openFile()
{
    if (this->saveCheck() != 2) {
        QString fileName(QFileDialog::getOpenFileName(this, tr("Open...", "Title for open file dialog"), QString(), tr(OpenSaveFileDialogFilter)));
        if (!fileName.isEmpty()) {
            this->openFile(fileName);
        }
    }
}

bool MainWindow::saveFile()
{
    if (this->fileName.isEmpty()) {
        return this->saveFileAs();
    }

    QDomDocument doc;
    QDomProcessingInstruction xmldecl(doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\""));

    QDomElement root(doc.createElement("alarmz"));
    for (int i = 0; i < this->model->count(); i++) {
        Alarm *alarm = this->model->alarmAt(i);
        if (alarm) {
            QDomElement element(doc.createElement("alarm"));
            element.setAttribute("datetime", alarm->dateTime().toString(DateTimeFormat));
            element.setAttribute("frequency", static_cast<int>(alarm->frequency()));
            element.setAttribute("display", static_cast<int>(alarm->displayMethod()));
            element.setAttribute("xml:space", "preserve");
            QDomText text(doc.createTextNode(alarm->message()));
            element.appendChild(text);
            root.appendChild(element);
        }
    }

    doc.appendChild(xmldecl);
    doc.appendChild(root);

    QFile file(this->fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    doc.save(stream, 1);
    this->model->setDirty(false);
    return true;
}

bool MainWindow::saveFileAs()
{
    QString fileName(QFileDialog::getSaveFileName(this, tr("Save...", "Title for save file dialog"), QString(), tr(OpenSaveFileDialogFilter)));
    if (!fileName.isEmpty()) {
        this->fileName = fileName;
        return this->saveFile();
    }

    return false;
}

void MainWindow::on_actionOptions_triggered()
{
    OptionsDialog od(this);
    od.exec();
}

void MainWindow::quit()
{
    // Ensure the window is visible (this can be called from the system tray icon context menu)
    // On Windows, if the main window is not visible and saveCheck() causes a message box to display,
    // it won't have a taskbar button associated with it.
    this->show();

    if (this->saveCheck() != 2) {
        disconnect(qApp, SIGNAL(aboutToQuit()), this, SLOT(shutdown()));
        QCoreApplication::quit();
    }
}

void MainWindow::shutdown()
{
    // The application is being forced to close. No user interaction is possible.
    if (!this->fileName.isEmpty() && Settings::instance().autoSave()) {
        this->saveFile();
    }
}

void MainWindow::on_actionAdd_triggered()
{
    AddEditAlarmDialog d(this);
    Alarm *alarm = d.showForAdd();
    if (alarm) {
        this->model->append(alarm);
    }
}

void MainWindow::on_actionDuplicate_triggered()
{
    QModelIndex index(this->ui->alarmsTreeView->currentIndex());
    if (index.row() >= 0 && index.row() < this->model->count()) {
        Alarm *alarm = this->model->alarmAt(index.row());
        if (alarm) {
            Alarm *newAlarm = new Alarm();
            newAlarm->setMessage(alarm->message());
            newAlarm->setDateTime(alarm->dateTime());
            newAlarm->setFrequency(alarm->frequency());
            newAlarm->setDisplayMethod(alarm->displayMethod());
            this->model->append(newAlarm);
        }
    }
}

void MainWindow::on_actionEdit_triggered()
{
    on_alarmsTreeView_activated(this->ui->alarmsTreeView->currentIndex());
}

void MainWindow::on_actionDelete_triggered()
{
    this->model->removeAt(this->ui->alarmsTreeView->currentIndex().row());
}

void MainWindow::on_actionEnable_toggled(bool checked)
{
    if (checked) {
        this->timer = this->startTimer(1000);
    } else {
        this->killTimer(this->timer);
        this->timer = 0;
    }
}

void MainWindow::on_actionHelpContents_triggered()
{
    QDesktopServices::openUrl("file:///" + Settings::applicationDirPath + "/doc/" + Settings::instance().language() + "/index.html");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(
            this,
            "Alarmz",
            "<p><strong>Alarmz v. " ALARMZ_VERSION_STR_SHORT "</strong></p>"
            "<p>Copyright (C) 2010 Francis Gagné</p>"
            "<p>" + tr("English translation: Francis Gagné", "Translators, leave your name here!") + "</p>"
            "<p>" + tr("The program's icon comes from the BeOS operating system.") + "</p>"
            "<p>" + tr("Icons in the menus and tool bars come from the Silk icon set.") + " <a href=\"http://www.famfamfam.com/lab/icons/silk/\">http://www.famfamfam.com/lab/icons/silk/</a></p>"
            "<p>" + tr("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.") + "</p>"
            "<p>" + tr("This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.") + "</p>"
            "<p>" + tr("You should have received a copy of the GNU General Public License along with this program. If not, see &lt;<a href=\"http://www.gnu.org/licenses/\">http://www.gnu.org/licenses/</a>>.") + "</p>");
}

void MainWindow::on_alarmsTreeView_activated(const QModelIndex &index)
{
    if (index.row() >= 0 && index.row() < this->model->count()) {
        Alarm *alarm = this->model->alarmAt(index.row());
        if (alarm) {
            AddEditAlarmDialog d(this);
            d.showForEdit(alarm);
        }
    }
}

void MainWindow::on_alarmsTreeView_currentIndexChanged(const QModelIndex &index)
{
    this->ui->actionDuplicate->setEnabled(index.row() != -1);
    this->ui->actionEdit->setEnabled(index.row() != -1);
    this->ui->actionDelete->setEnabled(index.row() != -1);
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        this->showAndActivate();
    }
}

void MainWindow::showAndActivate()
{
    this->show();
    this->activateWindow();
    this->raise();
}

} // namespace Alarmz
