/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed 28. Jul 20:31:46 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "AlarmsTreeView.h"

namespace Alarmz {

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionOptions;
    QAction *actionCloseWindow;
    QAction *actionExit;
    QAction *actionAdd;
    QAction *actionDuplicate;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionEnable;
    QAction *actionHelpContents;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    AlarmsTreeView *alarmsTreeView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAlarms;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Alarmz__MainWindow)
    {
        if (Alarmz__MainWindow->objectName().isEmpty())
            Alarmz__MainWindow->setObjectName(QString::fromUtf8("Alarmz__MainWindow"));
        Alarmz__MainWindow->resize(600, 400);
        Alarmz__MainWindow->setWindowTitle(QString::fromUtf8("Alarmz"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Alarmz.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Alarmz__MainWindow->setWindowIcon(icon);
        Alarmz__MainWindow->setIconSize(QSize(16, 16));
        actionNew = new QAction(Alarmz__MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/silk/silk/page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(Alarmz__MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/silk/silk/folder_page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(Alarmz__MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/silk/silk/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSaveAs = new QAction(Alarmz__MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionOptions = new QAction(Alarmz__MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionCloseWindow = new QAction(Alarmz__MainWindow);
        actionCloseWindow->setObjectName(QString::fromUtf8("actionCloseWindow"));
        actionExit = new QAction(Alarmz__MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd = new QAction(Alarmz__MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/silk/silk/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon4);
        actionDuplicate = new QAction(Alarmz__MainWindow);
        actionDuplicate->setObjectName(QString::fromUtf8("actionDuplicate"));
        actionDuplicate->setEnabled(false);
        actionEdit = new QAction(Alarmz__MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionEdit->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/silk/silk/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon5);
        actionDelete = new QAction(Alarmz__MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/silk/silk/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon6);
        actionEnable = new QAction(Alarmz__MainWindow);
        actionEnable->setObjectName(QString::fromUtf8("actionEnable"));
        actionEnable->setCheckable(true);
        actionEnable->setChecked(true);
        actionHelpContents = new QAction(Alarmz__MainWindow);
        actionHelpContents->setObjectName(QString::fromUtf8("actionHelpContents"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/silk/silk/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelpContents->setIcon(icon7);
        actionAbout = new QAction(Alarmz__MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Alarmz__MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        alarmsTreeView = new AlarmsTreeView(centralWidget);
        alarmsTreeView->setObjectName(QString::fromUtf8("alarmsTreeView"));
        alarmsTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        alarmsTreeView->setIndentation(0);

        verticalLayout->addWidget(alarmsTreeView);

        Alarmz__MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Alarmz__MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAlarms = new QMenu(menuBar);
        menuAlarms->setObjectName(QString::fromUtf8("menuAlarms"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Alarmz__MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Alarmz__MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Alarmz__MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Alarmz__MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Alarmz__MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAlarms->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionOptions);
        menuFile->addSeparator();
        menuFile->addAction(actionCloseWindow);
        menuFile->addAction(actionExit);
        menuAlarms->addAction(actionAdd);
        menuAlarms->addAction(actionDuplicate);
        menuAlarms->addAction(actionEdit);
        menuAlarms->addAction(actionDelete);
        menuAlarms->addSeparator();
        menuAlarms->addAction(actionEnable);
        menuHelp->addAction(actionHelpContents);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionEdit);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHelpContents);

        retranslateUi(Alarmz__MainWindow);

        QMetaObject::connectSlotsByName(Alarmz__MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Alarmz__MainWindow)
    {
        actionNew->setText(QApplication::translate("Alarmz::MainWindow", "&New...", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("Alarmz::MainWindow", "&Open...", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("Alarmz::MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("Alarmz::MainWindow", "Save &As...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setShortcut(QApplication::translate("Alarmz::MainWindow", "F12", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("Alarmz::MainWindow", "O&ptions...", 0, QApplication::UnicodeUTF8));
        actionCloseWindow->setText(QApplication::translate("Alarmz::MainWindow", "&Close Window", 0, QApplication::UnicodeUTF8));
        actionCloseWindow->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("Alarmz::MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAdd->setText(QApplication::translate("Alarmz::MainWindow", "&Add...", 0, QApplication::UnicodeUTF8));
        actionAdd->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionDuplicate->setText(QApplication::translate("Alarmz::MainWindow", "&Duplicate", 0, QApplication::UnicodeUTF8));
        actionDuplicate->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("Alarmz::MainWindow", "&Edit...", 0, QApplication::UnicodeUTF8));
        actionEdit->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("Alarmz::MainWindow", "De&lete", 0, QApplication::UnicodeUTF8));
        actionDelete->setShortcut(QApplication::translate("Alarmz::MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionEnable->setText(QApplication::translate("Alarmz::MainWindow", "E&nable", 0, QApplication::UnicodeUTF8));
        actionHelpContents->setText(QApplication::translate("Alarmz::MainWindow", "&Contents", 0, QApplication::UnicodeUTF8));
        actionHelpContents->setShortcut(QApplication::translate("Alarmz::MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Alarmz::MainWindow", "&About...", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("Alarmz::MainWindow", "Ctrl+F1", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Alarmz::MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuAlarms->setTitle(QApplication::translate("Alarmz::MainWindow", "&Alarms", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("Alarmz::MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("Alarmz::MainWindow", "Main Toolbar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Alarmz__MainWindow);
    } // retranslateUi

};

} // namespace Alarmz

namespace Alarmz {
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
} // namespace Alarmz

#endif // UI_MAINWINDOW_H
