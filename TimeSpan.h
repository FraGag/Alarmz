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

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <QDateTime>

namespace Alarmz {

class TimeSpan
{

private:
    qint64 msecs;

public:
    TimeSpan(qint64 msecs) : msecs(msecs) { }
    int days() const { return this->msecs / 86400000; }
    int hours() const { return (this->msecs / 3600000) % 24; }
    int minutes() const { return (this->msecs / 60000) % 60; }
    int seconds() const { return (this->msecs / 1000) % 60; }
    int milliSeconds() const { return this->msecs % 1000; }
    double totalDays() const { return this->msecs / 86400000.0; }
    double totalHours() const { return this->msecs / 3600000.0; }
    double totalMinutes() const { return this->msecs / 60000.0; }
    double totalSeconds() const { return this->msecs / 1000.0; }
    int totalMilliSeconds() const { return this->msecs; }

};

TimeSpan operator-(const QDateTime &dt1, const QDateTime &dt2);

} // namespace Alarmz

#endif // TIMESPAN_H
