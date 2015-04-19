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

#ifndef ADDEDITALARMDIALOG_H
#define ADDEDITALARMDIALOG_H

#include <QDialog>

namespace Alarmz {

class Alarm;

namespace Ui {
    class AddEditAlarmDialog;
}

class AddEditAlarmDialog : public QDialog
{
    Q_OBJECT

public:
    AddEditAlarmDialog(QWidget *parent = 0);
    ~AddEditAlarmDialog();

    Alarm *showForAdd();
    void showForEdit(Alarm *alarm);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddEditAlarmDialog *ui;
    void updateAlarm(Alarm *alarm);

};

} // namespace Alarmz

#endif // ADDEDITALARMDIALOG_H
