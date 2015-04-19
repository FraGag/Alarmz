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

#include "AddEditAlarmDialog.h"
#include "ui_AddEditAlarmDialog.h"
#include "Alarm.h"
#include <QPushButton>

namespace Alarmz {

AddEditAlarmDialog::AddEditAlarmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditAlarmDialog)
{
    this->ui->setupUi(this);

    this->ui->frequencyComboBox->addItem(Alarm::tr(Alarm::LocalizedFrequencyNoRepeat));
    this->ui->frequencyComboBox->addItem(Alarm::tr(Alarm::LocalizedFrequencyDaily));
    this->ui->frequencyComboBox->addItem(Alarm::tr(Alarm::LocalizedFrequencyWeekly));
    this->ui->frequencyComboBox->addItem(Alarm::tr(Alarm::LocalizedFrequencyMonthly));
    this->ui->frequencyComboBox->addItem(Alarm::tr(Alarm::LocalizedFrequencyYearly));
    this->ui->frequencyComboBox->setCurrentIndex(1);

    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodMsgBox_NoIcon));
    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodMsgBox_Critical));
    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodMsgBox_Question));
    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodMsgBox_Exclamation));
    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodMsgBox_Information));
    this->ui->displayMethodComboBox->addItem(Alarm::tr(Alarm::LocalizedDisplayMethodToast));
}

AddEditAlarmDialog::~AddEditAlarmDialog()
{
    delete this->ui;
}

void AddEditAlarmDialog::updateAlarm(Alarm *alarm)
{
    alarm->setMessage(this->ui->messagePlainTextEdit->toPlainText());
    alarm->setDateTime(this->ui->dateTimeEdit->dateTime());
    alarm->setFrequency(static_cast<AlarmFrequency>(this->ui->frequencyComboBox->currentIndex()));
    alarm->setDisplayMethod(static_cast<AlarmDisplayMethod>(this->ui->displayMethodComboBox->currentIndex()));
}

Alarm *AddEditAlarmDialog::showForAdd()
{
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setWhatsThis(tr("Adds the new alarm to the current file."));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setWhatsThis(tr("Closes the window without adding the alarm to the current file."));

    this->ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    if (this->exec() == Accepted) {
        Alarm *alarm = new Alarm();
        updateAlarm(alarm);
        return alarm;
    }

    return 0;
}

void AddEditAlarmDialog::showForEdit(Alarm *alarm)
{
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setWhatsThis(tr("Changes the properties of the alarm."));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setWhatsThis(tr("Closes the window without modifying the alarm."));

    this->ui->messagePlainTextEdit->setPlainText(alarm->message());
    this->ui->dateTimeEdit->setDateTime(alarm->dateTime());
    this->ui->frequencyComboBox->setCurrentIndex(alarm->frequency());
    this->ui->displayMethodComboBox->setCurrentIndex(alarm->displayMethod());
    if (this->exec() == Accepted) {
        updateAlarm(alarm);
    }
}

void AddEditAlarmDialog::changeEvent(QEvent *e)
{
    this->QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        this->ui->retranslateUi(this);
        break;

    default:
        break;
    }
}

} // namespace Alarmz
