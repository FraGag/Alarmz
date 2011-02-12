/* Alarmz - A program to show user-defined alarms
   Copyright (C) 2010 Francis Gagn� <fragag1@gmail.com>

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

#include "AlarmsTreeView.h"
#include <QDebug>

namespace Alarmz {

AlarmsTreeView::AlarmsTreeView(QWidget *parent) :
    QTreeView(parent)
{
}

void AlarmsTreeView::currentChanged(const QModelIndex &current, const QModelIndex &)
{
    this->currentIndexChanged(current);
}

} // namespace Alarmz
