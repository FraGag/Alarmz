/* Alarmz - A program to show user-defined alarms
   Copyright (C) 2010, 2015 Francis Gagné <fragag1@gmail.com>

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

#include "AlarmListModel.h"
#include <QRegExp>

namespace Alarmz {

AlarmListModel::AlarmListModel(QObject *parent) :
    QAbstractListModel(parent),
    _dirty(false)
{
}

AlarmListModel::~AlarmListModel()
{
    foreach (Alarm *alarm, this->alarms) {
        delete alarm;
    }
}

int AlarmListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return this->alarms.count();
}

int AlarmListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 4;
}

QVariant AlarmListModel::data(const QModelIndex &index, int role) const
{
    QVariant var(this->alarms[index.row()]->field(index.column()));
    switch (role) {
    case Qt::DisplayRole:
    {
        if (var.type() == QVariant::DateTime) {
            return var.toDateTime().toString(Qt::DefaultLocaleShortDate);
        }

        QString str(var.toString());
        int index = str.indexOf(QRegExp("\r?\n|\r"));
        if (index == -1) {
            return str;
        }

        return str.left(index) + "...";
    }

    case Qt::ToolTipRole:
        if (var.type() == QVariant::DateTime) {
            return var.toDateTime().toString(Qt::DefaultLocaleLongDate);
        }

        return this->alarms[index.row()]->field(index.column());
    }

    return QVariant();
}

QVariant AlarmListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (role) {
        case Qt::DisplayRole:
            switch (section) {
            case 0: return tr("Message");
            case 1: return tr("Scheduled date and time");
            case 2: return tr("Frequency");
            case 3: return tr("Display method");
            }

            break;
        }
    }

    return QVariant();
}

void AlarmListModel::append(Alarm *alarm)
{
    this->_dirty = true;
    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());
    this->alarms.append(alarm);
    this->dataChanged(this->index(this->rowCount() - 1, 0), this->index(this->rowCount() - 1, this->columnCount() - 1));
    this->endInsertRows();
}

Alarm *AlarmListModel::alarmAt(int index) const
{
    return this->alarms.at(index);
}

void AlarmListModel::removeAt(int index)
{
    this->_dirty = true;
    this->beginRemoveRows(QModelIndex(), index, index);
    this->alarms.remove(index);
    this->endRemoveRows();
}

void AlarmListModel::clear()
{
    this->_dirty = true;
    this->beginRemoveRows(QModelIndex(), 0, this->alarms.count());
    foreach (Alarm *alarm, this->alarms) {
        delete alarm;
    }

    this->alarms.clear();
    this->endRemoveRows();
}

int AlarmListModel::count() const
{
    return this->alarms.count();
}

void AlarmListModel::setList(QVector<Alarm *> alarms)
{
    this->clear(); // delete current alarms
    this->beginInsertRows(QModelIndex(), 0, alarms.count());
    this->alarms = alarms;
    this->endInsertRows();
}

bool AlarmListModel::dirty() const
{
    if (this->_dirty) {
        return true;
    }

    foreach (Alarm *alarm, this->alarms) {
        if (alarm->dirty()) {
            return true;
        }
    }

    return false;
}

void AlarmListModel::setDirty(bool dirty)
{
    this->_dirty = dirty;

    if (dirty == false) {
        foreach (Alarm *alarm, this->alarms) {
            alarm->setDirty(false);
        }
    }
}

}
