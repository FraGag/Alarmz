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

#include "TimeSpan.h"

namespace Alarmz {

TimeSpan operator-(const QDateTime &dt1, const QDateTime &dt2)
{
    QDateTime dt1UTC(dt1.toUTC());
    QDateTime dt2UTC(dt2.toUTC());
    int days = dt2UTC.daysTo(dt1UTC);
    int msecs = dt2UTC.time().msecsTo(dt1UTC.time());
    return TimeSpan(static_cast<qint64>(days) * 86400000 + msecs);
}

} // namespace Alarmz
