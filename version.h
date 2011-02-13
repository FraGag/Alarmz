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

#ifndef VERSION_H
#define VERSION_H

#define ALARMZ__STR(str) #str
#define ALARMZ_STR(str) ALARMZ__STR(str)

#define ALARMZ_VERSION_MAJOR       2
#define ALARMZ_VERSION_MINOR       0
#define ALARMZ_VERSION_REVISION    1
#define ALARMZ_VERSION_BUILD       0

#define ALARMZ_VERSION_STR_SHORT ALARMZ_STR(ALARMZ_VERSION_MAJOR) "." ALARMZ_STR(ALARMZ_VERSION_MINOR) "." ALARMZ_STR(ALARMZ_VERSION_REVISION)
#define ALARMZ_VERSION_STR ALARMZ_VERSION_STR_SHORT "." ALARMZ_STR(ALARMZ_VERSION_BUILD)

#endif // VERSION_H
