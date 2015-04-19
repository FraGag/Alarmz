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

#ifndef ALARM_H
#define ALARM_H

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QVariant>
#include "TranslationSourceWithComment.h"

namespace Alarmz {

enum AlarmFrequency
{
    NoRepeat,
    Daily,
    Weekly,
    Monthly,
    Yearly
};

enum AlarmDisplayMethod
{
    MsgBox_NoIcon,
    MsgBox_Critical,
    MsgBox_Question,
    MsgBox_Exclamation,
    MsgBox_Information,
    Toast
};

class Alarm : public QObject
{
    Q_OBJECT

private:
    QString _message;
    QDateTime _dateTime;
    AlarmFrequency _frequency;
    AlarmDisplayMethod _displayMethod;
    uint _dirty : 1;

public:
    static const TranslationSourceWithComment LocalizedFrequencyNoRepeat,
                                              LocalizedFrequencyDaily,
                                              LocalizedFrequencyWeekly,
                                              LocalizedFrequencyMonthly,
                                              LocalizedFrequencyYearly;
    static const char *LocalizedDisplayMethodMsgBox_NoIcon,
                      *LocalizedDisplayMethodMsgBox_Critical,
                      *LocalizedDisplayMethodMsgBox_Question,
                      *LocalizedDisplayMethodMsgBox_Exclamation,
                      *LocalizedDisplayMethodMsgBox_Information,
                      *LocalizedDisplayMethodToast;

    static inline QString tr(const TranslationSourceWithComment sc) { return tr(sc.source, sc.comment); }

    explicit Alarm(QObject *parent = 0) :
            QObject(parent),
            _frequency(Daily),
            _displayMethod(MsgBox_NoIcon),
            _dirty(1)
    {
    }

    const QString &message() const { return this->_message; }
    const QDateTime &dateTime() const { return this->_dateTime; }
    AlarmFrequency frequency() const { return this->_frequency; }
    AlarmDisplayMethod displayMethod() const { return this->_displayMethod; }

    void setMessage(const QString &message);
    void setDateTime(const QDateTime &dateTime);
    void setFrequency(AlarmFrequency frequency);
    void setDisplayMethod(AlarmDisplayMethod displayMethod);

    QVariant field(int field) const;

    bool dirty() const { return this->_dirty; }
    void setDirty(bool dirty) { this->_dirty = dirty; }

signals:

public slots:

};

} // namespace Alarmz

#endif // ALARM_H
