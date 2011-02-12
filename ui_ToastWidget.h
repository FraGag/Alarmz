/********************************************************************************
** Form generated from reading UI file 'ToastWidget.ui'
**
** Created: Wed 28. Jul 20:31:46 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOASTWIDGET_H
#define UI_TOASTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

namespace Alarmz {

class Ui_ToastWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *messageLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *snoozeButton;
    QPushButton *closeButton;

    void setupUi(QWidget *Alarmz__ToastWidget)
    {
        if (Alarmz__ToastWidget->objectName().isEmpty())
            Alarmz__ToastWidget->setObjectName(QString::fromUtf8("Alarmz__ToastWidget"));
        Alarmz__ToastWidget->resize(200, 150);
        Alarmz__ToastWidget->setWindowTitle(QString::fromUtf8("Alarmz"));
        widget = new QWidget(Alarmz__ToastWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 200, 150));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageLabel = new QLabel(widget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setText(QString::fromUtf8(""));
        messageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        messageLabel->setWordWrap(true);
        messageLabel->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        gridLayout->addWidget(messageLabel, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        snoozeButton = new QPushButton(widget);
        snoozeButton->setObjectName(QString::fromUtf8("snoozeButton"));

        gridLayout->addWidget(snoozeButton, 1, 1, 1, 1);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout->addWidget(closeButton, 1, 2, 1, 1);


        retranslateUi(Alarmz__ToastWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), Alarmz__ToastWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(Alarmz__ToastWidget);
    } // setupUi

    void retranslateUi(QWidget *Alarmz__ToastWidget)
    {
        snoozeButton->setText(QApplication::translate("Alarmz::ToastWidget", "Snooze", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("Alarmz::ToastWidget", "Close", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Alarmz__ToastWidget);
    } // retranslateUi

};

} // namespace Alarmz

namespace Alarmz {
namespace Ui {
    class ToastWidget: public Ui_ToastWidget {};
} // namespace Ui
} // namespace Alarmz

#endif // UI_TOASTWIDGET_H
