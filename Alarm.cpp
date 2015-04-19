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

#include "Alarm.h"

namespace Alarmz {

const TranslationSourceWithComment Alarm::LocalizedFrequencyNoRepeat = QT_TRANSLATE_NOOP3("Alarmz::Alarm", "None", "Alarm frequency: none");
const TranslationSourceWithComment Alarm::LocalizedFrequencyDaily    = QT_TRANSLATE_NOOP3("Alarmz::Alarm", "Daily", "Alarm frequency: daily");
const TranslationSourceWithComment Alarm::LocalizedFrequencyWeekly   = QT_TRANSLATE_NOOP3("Alarmz::Alarm", "Weekly", "Alarm frequency: weekly");
const TranslationSourceWithComment Alarm::LocalizedFrequencyMonthly  = QT_TRANSLATE_NOOP3("Alarmz::Alarm", "Monthly", "Alarm frequency: monthly");
const TranslationSourceWithComment Alarm::LocalizedFrequencyYearly   = QT_TRANSLATE_NOOP3("Alarmz::Alarm", "Yearly", "Alarm frequency: yearly");
const char *Alarm::LocalizedDisplayMethodMsgBox_NoIcon      = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Message box - no icon");
const char *Alarm::LocalizedDisplayMethodMsgBox_Critical    = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Message box - error");
const char *Alarm::LocalizedDisplayMethodMsgBox_Question    = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Message box - question");
const char *Alarm::LocalizedDisplayMethodMsgBox_Exclamation = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Message box - warning");
const char *Alarm::LocalizedDisplayMethodMsgBox_Information = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Message box - information");
const char *Alarm::LocalizedDisplayMethodToast              = QT_TRANSLATE_NOOP("Alarmz::Alarm", "Toast");

void Alarm::setMessage(const QString &message)
{
    if (this->_message != message) {
        this->_message = message;
        this->_dirty = true;
    }
}

void Alarm::setDateTime(const QDateTime &dateTime)
{
    if (this->_dateTime != dateTime) {
        this->_dateTime = dateTime;
        this->_dirty = true;
    }
}

void Alarm::setFrequency(AlarmFrequency frequency)
{
    if (this->_frequency != frequency) {
        this->_frequency = frequency;
        this->_dirty = true;
    }
}

void Alarm::setDisplayMethod(AlarmDisplayMethod displayMethod)
{
    if (this->_displayMethod != displayMethod) {
        this->_displayMethod = displayMethod;
        this->_dirty = true;
    }
}

QVariant Alarm::field(int field) const
{
    switch (field) {
    case 0:
        return this->_message;

    case 1:
        return this->_dateTime;

    case 2:
        switch (this->_frequency) {
        case NoRepeat: return tr(LocalizedFrequencyNoRepeat);
        case Daily: return tr(LocalizedFrequencyDaily);
        case Weekly: return tr(LocalizedFrequencyWeekly);
        case Monthly: return tr(LocalizedFrequencyMonthly);
        case Yearly: return tr(LocalizedFrequencyYearly);
        default: return QString();
        }

    case 3:
        switch (this->_displayMethod) {
        case MsgBox_NoIcon: return tr(LocalizedDisplayMethodMsgBox_NoIcon);
        case MsgBox_Critical: return tr(LocalizedDisplayMethodMsgBox_Critical);
        case MsgBox_Question: return tr(LocalizedDisplayMethodMsgBox_Question);
        case MsgBox_Exclamation: return tr(LocalizedDisplayMethodMsgBox_Exclamation);
        case MsgBox_Information: return tr(LocalizedDisplayMethodMsgBox_Information);
        case Toast: return tr(LocalizedDisplayMethodToast);
        default: return QString();
        }

    default:
        return QVariant();
    }
}

} // namespace Alarmz
