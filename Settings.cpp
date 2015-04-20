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

#include "Settings.h"
#include <QApplication>
#ifdef ALARMZ_BUILD_ENVIRONMENT
# include <QDebug>
#endif
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QVariant>
#include <QWidget>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

namespace Alarmz {

QString Settings::applicationFilePath;
QString Settings::applicationDirPath;

#if defined(Q_OS_WIN)

static QString sessionStartupCommand()
{
    // Initialize a byte array to store the path to the executable
    QByteArray path(MAX_PATH * sizeof(TCHAR), '\0');

    // Get the path to the executable
    DWORD size = GetModuleFileName(0, reinterpret_cast<LPTSTR>(path.data()), MAX_PATH);

    // Resize to the length of the string
    path.resize(size * sizeof(TCHAR));

# ifndef UNICODE
    // Create a QString from the QByteArray, reading it as ANSI
    QString command(path.data());
# else
    // Create a QString from the QByteArray, reading it as UTF-16
    QString command(QString::fromUtf16(reinterpret_cast<const ushort *>(path.data()), size));
# endif

    // If the path starts with \\?\, it can be as long as 32768, so read the path again with a larger buffer
    if (command.startsWith("\\\\?\\")) {
        // Resize to 0 first so there's no copying to do if the underlying buffer moves
        path.resize(0);

        // http://msdn.microsoft.com/en-us/library/aa365247.aspx
        // This page says the maximum length is 32767, but it's not clear whether this includes a terminating null character
        path.resize(32768);

        // Same as before, but with the new length
        size = GetModuleFileName(0, reinterpret_cast<LPTSTR>(path.data()), 32768);
        path.resize(size * sizeof(TCHAR));
# ifndef UNICODE
        command = path.data();
# else
        command = QString::fromUtf16(reinterpret_cast<const ushort *>(path.data()), size);
# endif
    }

    // Append the -b command line argument to tell Alarmz to start hidden and load the file specified in fileToOpenOnStartup()
    command.append(" -b");
    return command;
}

#elif defined(ALARMZ_XDG_AUTOSTART)

static QString sessionStartupCommand()
{
    QString command(Settings::applicationFilePath);

    // http://standards.freedesktop.org/desktop-entry-spec/latest/ar01s06.html

    // If the executable path contains any reserved character,
    // the path must be quoted.
    if (command.contains(QRegExp("[ \t\n\"'\\\\><~|&;$*?#()`]"))) {
        // Escape the characters that require escaping.
        command.replace(QRegExp("([\"`$\\\\])"), "\\\\1");
        
        // Quote the path.
        command = '"' + command + '"';
    }

    // Append the -b command line argument to tell Alarmz to start hidden and load the file specified in fileToOpenOnStartup()
    command.append(" -b");

    // Backslashes must be escaped again.
    command.replace('\\', "\\\\");

    // Percent signs must be escaped.
    command.replace('%', "%%");

    return command;
}

#endif

Settings Settings::_instance;

Settings::Settings() : settings("FraGag", "Alarmz")
{
}

int Settings::readIntSetting(const QString &name, int defaultValue) const
{
    QVariant var(this->settings.value(name));
    if (var.type() == QVariant::Invalid) {
        return defaultValue;
    }

    if (var.type() == QVariant::Bool) {
        return (int)var.toBool();
    }

    if (var.type() == QVariant::Int) {
        return var.toInt();
    }

    if (var.type() == QVariant::UInt) {
        return var.toUInt();
    }

    if (var.type() == QVariant::LongLong) {
        return (int)var.toLongLong();
    }

    if (var.type() == QVariant::ULongLong) {
        return (int)var.toULongLong();
    }

    if (var.type() == QVariant::String) {
        QString str(var.toString());
        bool ok = false;
        int value = str.toInt(&ok);
        if (ok) {
            return value;
        }
    }

    return defaultValue;
}

QColor Settings::readColorSetting(const QString &name, const QColor &defaultValue) const
{
    QVariant var(this->settings.value(name));
    if (var.type() == QVariant::Invalid) {
        return defaultValue;
    }

    if (var.type() == QVariant::Int) {
        return static_cast<QRgb>(var.toInt());
    }

    if (var.type() == QVariant::UInt) {
        return var.toUInt();
    }

    if (var.type() == QVariant::LongLong) {
        return static_cast<QRgb>(var.toLongLong());
    }

    if (var.type() == QVariant::ULongLong) {
        return static_cast<QRgb>(var.toULongLong());
    }

    if (var.type() == QVariant::Color) {
        return qvariant_cast<QColor>(var);
    }

    if (var.type() == QVariant::String) {
        QString str(var.toString());
        bool ok = false;
        uint value = str.toUInt(&ok);
        if (ok) {
            return value;
        }
    }

    return defaultValue;
}

void Settings::writeColorSetting(const QString &name, const QColor &value)
{
#ifdef Q_OS_WIN
    // For some reason, only int values get saved as REG_DWORD,
    // uint values get saved as REG_SZ
    this->settings.setValue(name, (int)value.rgb());
#else
    this->settings.setValue(name, value.rgb());
#endif
}

void Settings::reloadTranslation(const QString &prefix, QTranslator &translator)
{
    QString translationsFile(prefix + "_" + this->language());
    if (translator.load(translationsFile, Settings::applicationDirPath)) {
        QCoreApplication::removeTranslator(&translator);
        QCoreApplication::installTranslator(&translator);
#ifdef ALARMZ_BUILD_ENVIRONMENT
    } else {
        qDebug() << "Failed to load translations from file" << translationsFile;
#endif
    }
}

void Settings::reloadTranslation()
{
    this->reloadTranslation("Alarmz", this->alarmzTranslator);
    this->reloadTranslation("qt", this->qtTranslator);
}

QString Settings::language() const
{
    return this->settings.value("Language", QString()).toString();
}

bool Settings::autoSave() const
{
    return this->readIntSetting("AutoSave", 0) != 0;
}

#ifdef Q_OS_WIN

static bool runOnSessionStartup(HKEY hkey)
{
    static TCHAR valueName[] = TEXT("Alarmz");
    DWORD type, dataSize;

    // Query once to get the size of the data
    if (RegQueryValueEx(hkey, valueName, 0, &type, 0, &dataSize) == ERROR_SUCCESS && type == REG_SZ) {
        // Create a buffer large enough to hold all the data
        QByteArray valueData((int)dataSize, '\0');

        // Query again to get the data, now that we have a buffer of the appropriate size
        if (RegQueryValueEx(hkey, valueName, 0, &type, reinterpret_cast<BYTE *>(valueData.data()), &dataSize) == ERROR_SUCCESS && type == REG_SZ && (int)dataSize == valueData.size()) {
# ifndef UNICODE
            QString valueDataString(QString::fromLocal8Bit(valueData.constData()));
# else
            // A null character in UTF-16 requires 2 null bytes. QByteArray will provide one and this byte will provide the other.
            valueData.append('\0');
            QString valueDataString(QString::fromUtf16(reinterpret_cast<const ushort *>(valueData.constData())));
# endif
            return valueDataString == sessionStartupCommand();
        }
    }

    return false;
}

#endif

bool Settings::runOnSessionStartup() const
{
#if defined(Q_OS_WIN)
    HKEY hkey;
    if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), 0, 0, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &hkey, NULL) == ERROR_SUCCESS) {
        bool result = Alarmz::runOnSessionStartup(hkey);
        (void)RegCloseKey(hkey);
        return result;
    }
#elif defined(ALARMZ_XDG_AUTOSTART)
    return !QStandardPaths::locate(QStandardPaths::GenericConfigLocation, "autostart/Alarmz.desktop").isEmpty();
#endif

    return false;
}

bool Settings::canSetRunOnSessionStartup() const
{
#if defined(Q_OS_WIN) || defined(ALARMZ_XDG_AUTOSTART)
    return true;
#else
    return false;
#endif
}

QString Settings::fileToOpenOnStartup() const
{
    return this->settings.value("OpenAtBoot", QString()).toString();
}

bool Settings::applyToastBackgroundColor() const
{
    return this->readIntSetting("Toasts_ApplyBgColor", 1) != 0;
}

bool Settings::gradientOnToastBackground() const
{
    return this->readIntSetting("Toasts_GradientOnBg", 1) != 0;
}

bool Settings::applyToastTextColor() const
{
    return this->readIntSetting("Toasts_ApplyTextColor", 1) != 0;
}

QColor Settings::toastBackgroundColor1() const
{
    return this->readColorSetting("Toasts_BgColor1", qRgb(255, 96, 0));
}

QColor Settings::toastBackgroundColor2() const
{
    return this->readColorSetting("Toasts_BgColor2", qRgb(255, 255, 0));
}

QColor Settings::toastTextColor() const
{
    return this->readColorSetting("Toasts_TextColor", qRgb(0, 0, 0));
}

bool Settings::applySnoozeButtonBackgroundColor() const
{
    return this->readIntSetting("Toasts_ApplySnoozeBgColor", 1) != 0;
}

bool Settings::gradientOnSnoozeButton() const
{
    return this->readIntSetting("Toasts_GradientOnSnooze", 1) != 0;
}

bool Settings::applySnoozeButtonTextColor() const
{
    return this->readIntSetting("Toasts_ApplySnoozeTextColor", 1) != 0;
}

QColor Settings::snoozeButtonBackgroundColor1() const
{
    return this->readColorSetting("Toasts_SnoozeBgColor1", qRgb(0, 192, 255));
}

QColor Settings::snoozeButtonBackgroundColor2() const
{
    return this->readColorSetting("Toasts_SnoozeBgColor2", qRgb(255, 255, 255));
}

QColor Settings::snoozeButtonTextColor() const
{
    return this->readColorSetting("Toasts_SnoozeTextColor", qRgb(0, 0, 0));
}

bool Settings::applyCloseButtonBackgroundColor() const
{
    return this->readIntSetting("Toasts_ApplyCloseBgColor", 1) != 0;
}

bool Settings::gradientOnCloseButton() const
{
    return this->readIntSetting("Toasts_GradientOnClose", 1) != 0;
}

bool Settings::applyCloseButtonTextColor() const
{
    return this->readIntSetting("Toasts_ApplyCloseTextColor", 1) != 0;
}

QColor Settings::closeButtonBackgroundColor1() const
{
    return this->readColorSetting("Toasts_CloseBgColor1", qRgb(85, 255, 0));
}

QColor Settings::closeButtonBackgroundColor2() const
{
    return this->readColorSetting("Toasts_CloseBgColor2", qRgb(255, 255, 255));
}

QColor Settings::closeButtonTextColor() const
{
    return this->readColorSetting("Toasts_CloseTextColor", qRgb(0, 0, 0));
}

bool Settings::autoSize() const
{
    return this->readIntSetting("Toasts_AutoSize", 1) != 0;
}

bool Settings::useNativeBorder() const
{
    return this->readIntSetting("Toasts_UseNativeBorder", 1) != 0;
}

int Settings::corner() const
{
    return this->readIntSetting("Toasts_Corner", 3);
}

int Settings::direction() const
{
    return this->readIntSetting("Toasts_Direction", 1);
}

int Settings::toastEmergence() const
{
    return this->readIntSetting("Toasts_Emergence", 2);
}

QString Settings::soundToPlay() const
{
    return this->settings.value("Toasts_SoundToPlay", QString()).toString();
}

int Settings::snoozeDuration() const
{
    return this->readIntSetting("Toasts_Snooze", 9);
}

void Settings::setLanguage(const QString &value)
{
    this->settings.setValue("Language", value);
    this->reloadTranslation();
}

void Settings::setAutoSave(bool value)
{
    this->settings.setValue("AutoSave", value ? 1 : 0);
}

void Settings::setRunOnSessionStartup(bool value)
{
    Q_UNUSED(value)
#if defined(Q_OS_WIN)
    HKEY hkey;
    if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), 0, 0, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &hkey, NULL) == ERROR_SUCCESS) {
        static TCHAR valueName[] = TEXT("Alarmz");
        if (value) {
            // Register the application to run on session startup
            QString command(sessionStartupCommand());
# ifndef UNICODE
            QByteArray cmd8bit(command.toLocal8Bit());

            // The array ends with a null character, see documentation for QByteArray::data()
            (void)RegSetValueEx(hkey, valueName, 0, REG_SZ, cmd8bit.data(), cmd8bit.size() + 1);
# else
            // QString::utf16() returns a null-terminated string
            (void)RegSetValueEx(hkey, valueName, 0, REG_SZ, reinterpret_cast<const BYTE *>(command.utf16()), (command.length() + 1) * sizeof(TCHAR));
# endif
        } else if (Alarmz::runOnSessionStartup(hkey)) {
            // Just delete the value :)
            (void)RegDeleteValue(hkey, valueName);
        }

        (void)RegCloseKey(hkey);
    }
#elif defined(ALARMZ_XDG_AUTOSTART)
    // Find the XDG configuration path.
    QString path(QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation));
    QDir dir(path);
    QString desktopFilePath(dir.filePath("autostart/Alarmz.desktop"));
    
    if (value) {
        // Make sure the autostart subdirectory exists.
        if (dir.mkpath("autostart")) {
            QString fileContents = "[Desktop Entry]\nExec=" + sessionStartupCommand() + "\nName=Alarmz\nType=Application\n";
            QFile desktopFile(desktopFilePath);
            if (desktopFile.open(QIODevice::WriteOnly)) {
                desktopFile.write(fileContents.toUtf8());
            }
        }
    } else {
        QFile::remove(desktopFilePath);
    }
#endif
}

void Settings::setFileToOpenOnStartup(const QString &value)
{
    this->settings.setValue("OpenAtBoot", value);
}

void Settings::setApplyToastBackgroundColor(bool value)
{
    this->settings.setValue("Toasts_ApplyBgColor", value ? 1 : 0);
}

void Settings::setGradientOnToastBackground(bool value)
{
    this->settings.setValue("Toasts_GradientOnBg", value ? 1 : 0);
}

void Settings::setApplyToastTextColor(bool value)
{
    this->settings.setValue("Toasts_ApplyTextColor", value ? 1 : 0);
}

void Settings::setToastBackgroundColor1(const QColor &value)
{
    this->writeColorSetting("Toasts_BgColor1", value);
}

void Settings::setToastBackgroundColor2(const QColor &value)
{
    this->writeColorSetting("Toasts_BgColor2", value);
}

void Settings::setToastTextColor(const QColor &value)
{
    this->writeColorSetting("Toasts_TextColor", value);
}

void Settings::setApplySnoozeButtonBackgroundColor(bool value)
{
    this->settings.setValue("Toasts_ApplySnoozeBgColor", value ? 1 : 0);
}

void Settings::setGradientOnSnoozeButton(bool value)
{
    this->settings.setValue("Toasts_GradientOnSnooze", value ? 1 : 0);
}

void Settings::setApplySnoozeButtonTextColor(bool value)
{
    this->settings.setValue("Toasts_ApplySnoozeTextColor", value ? 1 : 0);
}

void Settings::setSnoozeButtonBackgroundColor1(const QColor &value)
{
    this->writeColorSetting("Toasts_SnoozeBgColor1", value);
}

void Settings::setSnoozeButtonBackgroundColor2(const QColor &value)
{
    this->writeColorSetting("Toasts_SnoozeBgColor2", value);
}

void Settings::setSnoozeButtonTextColor(const QColor &value)
{
    this->writeColorSetting("Toasts_SnoozeTextColor", value);
}

void Settings::setApplyCloseButtonBackgroundColor(bool value)
{
    this->settings.setValue("Toasts_ApplyCloseBgColor", value ? 1 : 0);
}

void Settings::setGradientOnCloseButton(bool value)
{
    this->settings.setValue("Toasts_GradientOnClose", value ? 1 : 0);
}

void Settings::setApplyCloseButtonTextColor(bool value)
{
    this->settings.setValue("Toasts_ApplyCloseTextColor", value ? 1 : 0);
}

void Settings::setCloseButtonBackgroundColor1(const QColor &value)
{
    this->writeColorSetting("Toasts_CloseBgColor1", value);
}

void Settings::setCloseButtonBackgroundColor2(const QColor &value)
{
    this->writeColorSetting("Toasts_CloseBgColor2", value);
}

void Settings::setCloseButtonTextColor(const QColor &value)
{
    this->writeColorSetting("Toasts_CloseTextColor", value);
}

void Settings::setAutoSize(bool value)
{
    this->settings.setValue("Toasts_AutoSize", value ? 1 : 0);
}

void Settings::setUseNativeBorder(bool value)
{
    this->settings.setValue("Toasts_UseNativeBorder", value ? 1 : 0);
}

void Settings::setCorner(int value)
{
    this->settings.setValue("Toasts_Corner", value);
}

void Settings::setDirection(int value)
{
    this->settings.setValue("Toasts_Direction", value);
}

void Settings::setToastEmergence(int value)
{
    this->settings.setValue("Toasts_Emergence", value);
}

void Settings::setSoundToPlay(const QString &value)
{
    this->settings.setValue("Toasts_SoundToPlay", value);
}

void Settings::setSnoozeDuration(int value)
{
    this->settings.setValue("Toasts_Snooze", value);
}

} // namespace Alarmz
