/********************************************************************************
** Form generated from reading UI file 'AddEditAlarmDialog.ui'
**
** Created: Wed 28. Jul 20:31:46 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITALARMDIALOG_H
#define UI_ADDEDITALARMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>

namespace Alarmz {

class Ui_AddEditAlarmDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *messageLabel;
    QPlainTextEdit *messagePlainTextEdit;
    QLabel *dateTimeLabel;
    QDateTimeEdit *dateTimeEdit;
    QLabel *frequencyLabel;
    QComboBox *frequencyComboBox;
    QLabel *displayMethodLabel;
    QComboBox *displayMethodComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Alarmz__AddEditAlarmDialog)
    {
        if (Alarmz__AddEditAlarmDialog->objectName().isEmpty())
            Alarmz__AddEditAlarmDialog->setObjectName(QString::fromUtf8("Alarmz__AddEditAlarmDialog"));
        Alarmz__AddEditAlarmDialog->resize(400, 300);
        Alarmz__AddEditAlarmDialog->setModal(true);
        gridLayout = new QGridLayout(Alarmz__AddEditAlarmDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageLabel = new QLabel(Alarmz__AddEditAlarmDialog);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(messageLabel, 0, 0, 1, 1);

        messagePlainTextEdit = new QPlainTextEdit(Alarmz__AddEditAlarmDialog);
        messagePlainTextEdit->setObjectName(QString::fromUtf8("messagePlainTextEdit"));

        gridLayout->addWidget(messagePlainTextEdit, 0, 1, 1, 1);

        dateTimeLabel = new QLabel(Alarmz__AddEditAlarmDialog);
        dateTimeLabel->setObjectName(QString::fromUtf8("dateTimeLabel"));

        gridLayout->addWidget(dateTimeLabel, 1, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(Alarmz__AddEditAlarmDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFrame(true);
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 1, 1, 1, 1);

        frequencyLabel = new QLabel(Alarmz__AddEditAlarmDialog);
        frequencyLabel->setObjectName(QString::fromUtf8("frequencyLabel"));

        gridLayout->addWidget(frequencyLabel, 2, 0, 1, 1);

        frequencyComboBox = new QComboBox(Alarmz__AddEditAlarmDialog);
        frequencyComboBox->setObjectName(QString::fromUtf8("frequencyComboBox"));

        gridLayout->addWidget(frequencyComboBox, 2, 1, 1, 1);

        displayMethodLabel = new QLabel(Alarmz__AddEditAlarmDialog);
        displayMethodLabel->setObjectName(QString::fromUtf8("displayMethodLabel"));

        gridLayout->addWidget(displayMethodLabel, 3, 0, 1, 1);

        displayMethodComboBox = new QComboBox(Alarmz__AddEditAlarmDialog);
        displayMethodComboBox->setObjectName(QString::fromUtf8("displayMethodComboBox"));

        gridLayout->addWidget(displayMethodComboBox, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Alarmz__AddEditAlarmDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        messageLabel->setBuddy(messagePlainTextEdit);
        dateTimeLabel->setBuddy(dateTimeEdit);
        frequencyLabel->setBuddy(frequencyComboBox);
        displayMethodLabel->setBuddy(displayMethodComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(messagePlainTextEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, frequencyComboBox);
        QWidget::setTabOrder(frequencyComboBox, displayMethodComboBox);
        QWidget::setTabOrder(displayMethodComboBox, buttonBox);

        retranslateUi(Alarmz__AddEditAlarmDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Alarmz__AddEditAlarmDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Alarmz__AddEditAlarmDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Alarmz__AddEditAlarmDialog);
    } // setupUi

    void retranslateUi(QDialog *Alarmz__AddEditAlarmDialog)
    {
        Alarmz__AddEditAlarmDialog->setWindowTitle(QApplication::translate("Alarmz::AddEditAlarmDialog", "Add/Edit Alarm...", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QApplication::translate("Alarmz::AddEditAlarmDialog", "&Message:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        messagePlainTextEdit->setWhatsThis(QApplication::translate("Alarmz::AddEditAlarmDialog", "Message displayed in the alarm.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        dateTimeLabel->setText(QApplication::translate("Alarmz::AddEditAlarmDialog", "&Date and time:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        dateTimeEdit->setWhatsThis(QApplication::translate("Alarmz::AddEditAlarmDialog", "Date and time at which the alarm will be displayed. When a frequency is set, the date will be changed automatically.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        frequencyLabel->setText(QApplication::translate("Alarmz::AddEditAlarmDialog", "&Frequency:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        frequencyComboBox->setWhatsThis(QApplication::translate("Alarmz::AddEditAlarmDialog", "Frequency at which the alarm will be repeated.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        displayMethodLabel->setText(QApplication::translate("Alarmz::AddEditAlarmDialog", "D&isplay method:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        displayMethodComboBox->setWhatsThis(QApplication::translate("Alarmz::AddEditAlarmDialog", "Method by which the alarm will be displayed.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

} // namespace Alarmz

namespace Alarmz {
namespace Ui {
    class AddEditAlarmDialog: public Ui_AddEditAlarmDialog {};
} // namespace Ui
} // namespace Alarmz

#endif // UI_ADDEDITALARMDIALOG_H
