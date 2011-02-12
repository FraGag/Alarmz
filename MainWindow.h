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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "TranslationSourceWithComment.h"

class QModelIndex;

namespace Alarmz {

class AlarmListModel;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    AlarmListModel *model;

public:
    static const char DateTimeFormat[];

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void openFile(const QString &fileName);

protected:
    virtual void changeEvent(QEvent *e);
    virtual void closeEvent(QCloseEvent *e);
    virtual void timerEvent(QTimerEvent *e);

private:
    static const TranslationSourceWithComment OpenSaveFileDialogFilter;

    static inline QString tr(const TranslationSourceWithComment sc) { return tr(sc.source, sc.comment); }

    Ui::MainWindow *ui;
    QSystemTrayIcon trayIcon;
    QString fileName;
    int timer;

    int saveCheck();

private slots:
    void newFile();
    void openFile();
    bool saveFile();
    bool saveFileAs();
    void quit();
    void shutdown();
    void on_actionOptions_triggered();
    void on_actionAdd_triggered();
    void on_actionDuplicate_triggered();
    void on_actionEdit_triggered();
    void on_actionDelete_triggered();
    void on_actionEnable_toggled(bool checked);
    void on_actionHelpContents_triggered();
    void on_actionAbout_triggered();
    void on_alarmsTreeView_activated(const QModelIndex &index);
    void on_alarmsTreeView_currentIndexChanged(const QModelIndex &index);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void showAndActivate();

};

} // namespace Alarmz

#endif // MAINWINDOW_H
