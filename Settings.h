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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QTranslator>

namespace Alarmz {

class OptionsDialog;

class Settings : public QObject
{
    Q_OBJECT

private:
    friend class Alarmz::OptionsDialog;

    static Settings _instance;

    Settings();
    QSettings settings;
    QTranslator alarmzTranslator;
    QTranslator qtTranslator;

    int readIntSetting(const QString &name, int defaultValue) const;
    QColor readColorSetting(const QString &name, const QColor &defaultValue) const;
    void writeColorSetting(const QString &name, const QColor &value);
    void reloadTranslation(const QString &prefix, QTranslator &translator);

public:
    static QString applicationDirPath;

    static Settings &instance() { return _instance; }
    static Qt::CaseSensitivity isFileSystemCaseSensitive();

    void reloadTranslation();

    QString language() const;
    bool autoSave() const;
    bool runOnSessionStartup() const;
    bool canSetRunOnSessionStartup() const;
    QString fileToOpenOnStartup() const;
    bool applyToastBackgroundColor() const;
    bool gradientOnToastBackground() const;
    bool applyToastTextColor() const;
    QColor toastBackgroundColor1() const;
    QColor toastBackgroundColor2() const;
    QColor toastTextColor() const;
    bool applySnoozeButtonBackgroundColor() const;
    bool gradientOnSnoozeButton() const;
    bool applySnoozeButtonTextColor() const;
    QColor snoozeButtonBackgroundColor1() const;
    QColor snoozeButtonBackgroundColor2() const;
    QColor snoozeButtonTextColor() const;
    bool applyCloseButtonBackgroundColor() const;
    bool gradientOnCloseButton() const;
    bool applyCloseButtonTextColor() const;
    QColor closeButtonBackgroundColor1() const;
    QColor closeButtonBackgroundColor2() const;
    QColor closeButtonTextColor() const;
    bool autoSize() const;
    bool useNativeBorder() const;
    int corner() const;
    int direction() const;
    int toastEmergence() const;
    QString soundToPlay() const;
    int snoozeDuration() const;

    void setLanguage(const QString &value);
    void setAutoSave(bool value);
    void setRunOnSessionStartup(bool value);
    void setFileToOpenOnStartup(const QString &value);
    void setApplyToastBackgroundColor(bool value);
    void setGradientOnToastBackground(bool value);
    void setApplyToastTextColor(bool value);
    void setToastBackgroundColor1(const QColor &value);
    void setToastBackgroundColor2(const QColor &value);
    void setToastTextColor(const QColor &value);
    void setApplySnoozeButtonBackgroundColor(bool value);
    void setGradientOnSnoozeButton(bool value);
    void setApplySnoozeButtonTextColor(bool value);
    void setSnoozeButtonBackgroundColor1(const QColor &value);
    void setSnoozeButtonBackgroundColor2(const QColor &value);
    void setSnoozeButtonTextColor(const QColor &value);
    void setApplyCloseButtonBackgroundColor(bool value);
    void setGradientOnCloseButton(bool value);
    void setApplyCloseButtonTextColor(bool value);
    void setCloseButtonBackgroundColor1(const QColor &value);
    void setCloseButtonBackgroundColor2(const QColor &value);
    void setCloseButtonTextColor(const QColor &value);
    void setAutoSize(bool value);
    void setUseNativeBorder(bool value);
    void setCorner(int value);
    void setDirection(int value);
    void setToastEmergence(int value);
    void setSoundToPlay(const QString &value);
    void setSnoozeDuration(int value);

signals:
    void changed();

};

} // namespace Alarmz

#endif // SETTINGS_H
