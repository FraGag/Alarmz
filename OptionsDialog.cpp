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

#include "OptionsDialog.h"
#include "ui_OptionsDialog.h"
#include "Settings.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QPushButton>

namespace Alarmz {

static void setBackgroundColor(QToolButton *button, const QColor &color)
{
    button->setStyleSheet("background-color: " + color.name());
}

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    this->ui->setupUi(this);
    this->ui->buttonBox->button(QDialogButtonBox::Ok)->setWhatsThis(tr("Saves the new options and closes the window."));
    this->ui->buttonBox->button(QDialogButtonBox::Cancel)->setWhatsThis(tr("Closes the window without saving the new options."));
    this->ui->buttonBox->button(QDialogButtonBox::Apply)->setWhatsThis(tr("Saves and applies the new options without closing the window."));

    Settings &settings = Settings::instance();

    // Set up language combo box
    {
        QString language(settings.language());
        QLocale enUSLocale(QLocale::English, QLocale::UnitedStates);
        this->ui->languageComboBox->addItem(QString("%1 (%2)").arg(QLocale::languageToString(QLocale::English), QLocale::countryToString(QLocale::UnitedStates)), "en_US");
        QDir appDir(Settings::applicationDirPath);
        QRegExp regExp("Alarmz_([a-z]{2}(?:_[A-Z]{2})?).qm", Settings::isFileSystemCaseSensitive());
        foreach (const QString &file, appDir.entryList(QDir::Files)) {
            if (regExp.exactMatch(file) && regExp.captureCount() >= 1) {
                QLocale locale(regExp.cap(1));
                if (locale.language() != QLocale::C && locale != enUSLocale) {
                    this->ui->languageComboBox->addItem(QString("%1 (%2)").arg(QLocale::languageToString(locale.language()), QLocale::countryToString(locale.country())), regExp.cap(1));
                }
            }
        }

        int index = this->ui->languageComboBox->findData(language);
        if (index < 0) {
            index = Settings::instance().language().indexOf('_');
            if (index >= 0) {
                index = this->ui->languageComboBox->findData(language.left(index));
                if (index < 0) {
                    index = 0;
                }
            } else {
                index = 0;
            }
        }

        this->ui->languageComboBox->setCurrentIndex(index);
    }

    this->ui->autoSaveCheckBox->setChecked(settings.autoSave());

    this->ui->runOnSessionStartupCheckBox->setEnabled(settings.canSetRunOnSessionStartup());
    this->ui->runOnSessionStartupCheckBox->setChecked(settings.runOnSessionStartup());
    this->ui->openThisFileOnStartupLineEdit->setText(settings.fileToOpenOnStartup());
    this->ui->openThisFileOnStartupCheckBox->setChecked(!this->ui->openThisFileOnStartupLineEdit->text().isEmpty());

    this->ui->toastBackgroundCheckBox->setChecked(settings.applyToastBackgroundColor());
    this->ui->gradientOnToastBackgroundCheckBox->setChecked(settings.gradientOnToastBackground());
    this->ui->toastTextCheckBox->setChecked(settings.applyToastTextColor());
    setBackgroundColor(this->ui->toastBackgroundColor1Button, settings.toastBackgroundColor1());
    setBackgroundColor(this->ui->toastBackgroundColor2Button, settings.toastBackgroundColor2());
    setBackgroundColor(this->ui->toastTextColorButton, settings.toastTextColor());
    this->ui->snoozeButtonBackgroundCheckBox->setChecked(settings.applySnoozeButtonBackgroundColor());
    this->ui->gradientOnSnoozeButtonCheckBox->setChecked(settings.gradientOnSnoozeButton());
    this->ui->snoozeButtonTextCheckBox->setChecked(settings.applySnoozeButtonTextColor());
    setBackgroundColor(this->ui->snoozeButtonBackgroundColor1Button, settings.snoozeButtonBackgroundColor1());
    setBackgroundColor(this->ui->snoozeButtonBackgroundColor2Button, settings.snoozeButtonBackgroundColor2());
    setBackgroundColor(this->ui->snoozeButtonTextColorButton, settings.snoozeButtonTextColor());
    this->ui->closeButtonBackgroundCheckBox->setChecked(settings.applyCloseButtonBackgroundColor());
    this->ui->gradientOnCloseButtonCheckBox->setChecked(settings.gradientOnCloseButton());
    this->ui->closeButtonTextCheckBox->setChecked(settings.applyCloseButtonTextColor());
    setBackgroundColor(this->ui->closeButtonBackgroundColor1Button, settings.closeButtonBackgroundColor1());
    setBackgroundColor(this->ui->closeButtonBackgroundColor2Button, settings.closeButtonBackgroundColor2());
    setBackgroundColor(this->ui->closeButtonTextColorButton, settings.closeButtonTextColor());
    this->ui->autoSizeCheckBox->setChecked(settings.autoSize());
    this->ui->useNativeBorderCheckBox->setChecked(settings.useNativeBorder());
    switch (settings.corner()) {
    case 0:
        this->ui->topLeftCornerRadioButton->setChecked(true);
        break;

    case 1:
        this->ui->topRightCornerRadioButton->setChecked(true);
        break;

    case 2:
        this->ui->bottomLeftCornerRadioButton->setChecked(true);
        break;

    default:
        this->ui->bottomRightCornerRadioButton->setChecked(true);
        break;
    }

    switch (settings.direction()) {
    case 0:
        this->ui->horizontalDirectionRadioButton->setChecked(true);
        break;

    default:
        this->ui->verticalDirectionRadioButton->setChecked(true);
        break;
    }

    switch (settings.toastEmergence()) {
    case 1:
        this->ui->suddenToastEmergenceRadioButton->setChecked(true);
        break;

    default:
        this->ui->rollToastEmergenceRadioButton->setChecked(true);
        break;

    case 3:
        this->ui->fadeToastEmergenceRadioButton->setChecked(true);
        break;
    }

    this->ui->playSoundLineEdit->setText(settings.soundToPlay());
    this->ui->playSoundCheckBox->setChecked(!this->ui->playSoundLineEdit->text().isEmpty());
    this->ui->snoozeDurationSpinBox->setValue(settings.snoozeDuration());
}

OptionsDialog::~OptionsDialog()
{
    delete this->ui;
}

void OptionsDialog::accept()
{
    this->QDialog::accept();
    this->apply();
}

void OptionsDialog::changeEvent(QEvent *e)
{
    this->QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        this->ui->retranslateUi(this);
        break;

    default:
        break;
    }
}

void OptionsDialog::apply()
{
    Settings &settings = Settings::instance();

    settings.setLanguage(this->ui->languageComboBox->itemData(this->ui->languageComboBox->currentIndex()).toString());
    settings.setAutoSave(this->ui->autoSaveCheckBox->isChecked());

    settings.setRunOnSessionStartup(this->ui->runOnSessionStartupCheckBox->isChecked());
    settings.setFileToOpenOnStartup(this->ui->openThisFileOnStartupCheckBox->isChecked() ? this->ui->openThisFileOnStartupLineEdit->text() : QString());

    settings.setApplyToastBackgroundColor(this->ui->toastBackgroundCheckBox->isChecked());
    settings.setGradientOnToastBackground(this->ui->gradientOnToastBackgroundCheckBox->isChecked());
    settings.setApplyToastTextColor(this->ui->toastTextCheckBox->isChecked());
    settings.setToastBackgroundColor1(this->ui->toastBackgroundColor1Button->palette().background().color());
    settings.setToastBackgroundColor2(this->ui->toastBackgroundColor2Button->palette().background().color());
    settings.setToastTextColor(this->ui->toastTextColorButton->palette().background().color());

    settings.setApplySnoozeButtonBackgroundColor(this->ui->snoozeButtonBackgroundCheckBox->isChecked());
    settings.setGradientOnSnoozeButton(this->ui->gradientOnSnoozeButtonCheckBox->isChecked());
    settings.setApplySnoozeButtonTextColor(this->ui->snoozeButtonTextCheckBox->isChecked());
    settings.setSnoozeButtonBackgroundColor1(this->ui->snoozeButtonBackgroundColor1Button->palette().background().color());
    settings.setSnoozeButtonBackgroundColor2(this->ui->snoozeButtonBackgroundColor2Button->palette().background().color());
    settings.setSnoozeButtonTextColor(this->ui->snoozeButtonTextColorButton->palette().background().color());

    settings.setApplyCloseButtonBackgroundColor(this->ui->closeButtonBackgroundCheckBox->isChecked());
    settings.setGradientOnCloseButton(this->ui->gradientOnCloseButtonCheckBox->isChecked());
    settings.setApplyCloseButtonTextColor(this->ui->closeButtonTextCheckBox->isChecked());
    settings.setCloseButtonBackgroundColor1(this->ui->closeButtonBackgroundColor1Button->palette().background().color());
    settings.setCloseButtonBackgroundColor2(this->ui->closeButtonBackgroundColor2Button->palette().background().color());
    settings.setCloseButtonTextColor(this->ui->closeButtonTextColorButton->palette().background().color());

    settings.setAutoSize(this->ui->autoSizeCheckBox->isChecked());
    settings.setUseNativeBorder(this->ui->useNativeBorderCheckBox->isChecked());
    settings.setCorner(
            this->ui->topLeftCornerRadioButton->isChecked() ? 0 :
            this->ui->topRightCornerRadioButton->isChecked() ? 1 :
            this->ui->bottomLeftCornerRadioButton->isChecked() ? 2 : 3);
    settings.setDirection(this->ui->horizontalDirectionRadioButton->isChecked() ? 0 : 1);
    settings.setToastEmergence(
            this->ui->suddenToastEmergenceRadioButton->isChecked() ? 1 :
            this->ui->fadeToastEmergenceRadioButton->isChecked() ? 3 : 2);

    settings.setSoundToPlay(this->ui->playSoundCheckBox->isChecked() ? this->ui->playSoundLineEdit->text() : QString());
    settings.setSnoozeDuration(this->ui->snoozeDurationSpinBox->value());

    settings.changed();
}

void OptionsDialog::on_browseForFileToOpenOnStartupButton_clicked()
{
    QString fileName(QFileDialog::getOpenFileName(this, "Browse for file to open on session startup...", QString(), "Alarms files (*.alarmz);;All files (*.*)"));
    if (!fileName.isEmpty()) {
        this->ui->openThisFileOnStartupLineEdit->setText(fileName);
    }
}

void OptionsDialog::on_browseForSoundToPlayButton_clicked()
{
    QString fileName(QFileDialog::getOpenFileName(this, "Browse for sound to play for toasts...", QString(), "WAV files (*.wav);;All files (*.*)"));
    if (!fileName.isEmpty()) {
        this->ui->playSoundLineEdit->setText(fileName);
    }
}

void OptionsDialog::showColorDialog(QToolButton *button)
{
    QColor color(QColorDialog::getColor(button->palette().background().color(), this));
    if (color.isValid()) {
        setBackgroundColor(button, color);
    }
}

void OptionsDialog::on_toastBackgroundColor1Button_clicked()
{
    this->showColorDialog(this->ui->toastBackgroundColor1Button);
}

void OptionsDialog::on_toastBackgroundColor2Button_clicked()
{
    this->showColorDialog(this->ui->toastBackgroundColor2Button);
}

void OptionsDialog::on_toastTextColorButton_clicked()
{
    this->showColorDialog(this->ui->toastTextColorButton);
}

void OptionsDialog::on_snoozeButtonBackgroundColor1Button_clicked()
{
    this->showColorDialog(this->ui->snoozeButtonBackgroundColor1Button);
}

void OptionsDialog::on_snoozeButtonBackgroundColor2Button_clicked()
{
    this->showColorDialog(this->ui->snoozeButtonBackgroundColor2Button);
}

void OptionsDialog::on_snoozeButtonTextColorButton_clicked()
{
    this->showColorDialog(this->ui->snoozeButtonTextColorButton);
}

void OptionsDialog::on_closeButtonBackgroundColor1Button_clicked()
{
    this->showColorDialog(this->ui->closeButtonBackgroundColor1Button);
}

void OptionsDialog::on_closeButtonBackgroundColor2Button_clicked()
{
    this->showColorDialog(this->ui->closeButtonBackgroundColor2Button);
}

void OptionsDialog::on_closeButtonTextColorButton_clicked()
{
    this->showColorDialog(this->ui->closeButtonTextColorButton);
}

void OptionsDialog::on_buttonBox_clicked(QAbstractButton* button)
{
    if (button == this->ui->buttonBox->button(QDialogButtonBox::Apply)) {
        this->apply();
    }
}

} // namespace Alarmz
