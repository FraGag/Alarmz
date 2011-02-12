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

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QToolButton;
QT_END_NAMESPACE

namespace Alarmz {

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog {
    Q_OBJECT
public:
    OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

protected:
    virtual void accept();
    virtual void changeEvent(QEvent *e);

private:
    Ui::OptionsDialog *ui;
    void apply();
    void showColorDialog(QToolButton *button);

private slots:
    void on_browseForFileToOpenOnStartupButton_clicked();
    void on_browseForSoundToPlayButton_clicked();
    void on_toastBackgroundColor1Button_clicked();
    void on_toastBackgroundColor2Button_clicked();
    void on_toastTextColorButton_clicked();
    void on_snoozeButtonBackgroundColor1Button_clicked();
    void on_snoozeButtonBackgroundColor2Button_clicked();
    void on_snoozeButtonTextColorButton_clicked();
    void on_closeButtonBackgroundColor1Button_clicked();
    void on_closeButtonBackgroundColor2Button_clicked();
    void on_closeButtonTextColorButton_clicked();
    void on_buttonBox_clicked(QAbstractButton* button);
};

} // namespace Alarmz

#endif // OPTIONSDIALOG_H
