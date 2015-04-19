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

#ifndef ALARMLISTMODEL_H
#define ALARMLISTMODEL_H

#include "Alarm.h"
#include <QAbstractListModel>
#include <QVector>

namespace Alarmz {

class AlarmListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QVector<Alarm *> alarms;
    bool _dirty;

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public:
    explicit AlarmListModel(QObject *parent = 0);
    virtual ~AlarmListModel();

    void append(Alarm *alarm);
    Alarm *alarmAt(int index) const;
    void removeAt(int index);
    void clear();
    int count() const;
    void setList(QVector<Alarm *> alarms);

    bool dirty() const;
    void setDirty(bool dirty);

};

} // namespace Alarmz

#endif // ALARMLISTMODEL_H
