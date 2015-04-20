# Alarmz - A program to show user-defined alarms
# Copyright (C) 2010, 2015 Francis Gagné <fragag1@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# -------------------------------------------------
# Project created by QtCreator 2010-05-04T13:32:19
# -------------------------------------------------
QT += multimedia widgets xml
TARGET = Alarmz
TEMPLATE = app
SOURCES += main.cpp \
    MainWindow.cpp \
    Alarm.cpp \
    AlarmListModel.cpp \
    AddEditAlarmDialog.cpp \
    AlarmsTreeView.cpp \
    ToastWidget.cpp \
    OptionsDialog.cpp \
    Settings.cpp \
    TimeSpan.cpp
HEADERS += MainWindow.h \
    Alarm.h \
    AlarmListModel.h \
    AddEditAlarmDialog.h \
    AlarmsTreeView.h \
    ToastWidget.h \
    version.h \
    OptionsDialog.h \
    Settings.h \
    TranslationSourceWithComment.h \
    TimeSpan.h
FORMS += MainWindow.ui \
    AddEditAlarmDialog.ui \
    ToastWidget.ui \
    OptionsDialog.ui
RESOURCES += Alarmz.qrc
win32:RC_FILE += Alarmz.rc
OTHER_FILES += Alarmz.ico \
    Alarmz.rc
Debug:DEFINES += ALARMZ_BUILD_ENVIRONMENT
win32-msvc*:LIBS += advapi32.lib

# Translations
TRANSLATIONS = Alarmz_fr.ts
