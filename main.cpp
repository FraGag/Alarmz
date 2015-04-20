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

#include "MainWindow.h"
#include "Settings.h"
#include <QApplication>
#include <string.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_UNUSED(app)

    // On some platforms, the path to the application might not be directly
    // available. If a relative path is used to start the application, then
    // it is assumed to be relative to the current working directory. We
    // retrieve the application path now to make sure that it is correct even
    // if we later change the working directory. We need this path to find the
    // help files and .qm files.
    QString appFilePath = QApplication::applicationFilePath();
    QString appDirPath = QApplication::applicationDirPath();
#ifdef ALARMZ_BUILD_ENVIRONMENT
    appDirPath = appDirPath.left(appDirPath.lastIndexOf('/'));
#endif
    Alarmz::Settings::applicationFilePath = appFilePath;
    Alarmz::Settings::applicationDirPath = appDirPath;

    Alarmz::Settings::instance().reloadTranslation();
    Alarmz::MainWindow w;

    if (argc > 1) {
        if (strcmp(argv[1], "-b") == 0) {
            w.openFile(Alarmz::Settings::instance().fileToOpenOnStartup());

            // Don't show the window!
            return QApplication::exec();
        }

        w.openFile(argv[1]);
    }

    w.show();
    return QApplication::exec();
}
