#include <QApplication>
#include <QDebug>
#include <QFile>

#include "src/com/ngos/devtools/build_config_gui/main/mainwindow.h"
#include "src/com/ngos/devtools/build_config_gui/other/global.h"



qint32 main(qint32 argc, char *argv[])
{
    QApplication app(argc, argv);



    Global::sProjectDir = app.applicationDirPath();

    do
    {
        if (QFile::exists(Global::sProjectDir + "/ngos.files"))
        {
            break;
        }



        qint64 index = Global::sProjectDir.lastIndexOf('/');

        if (index < 0)
        {
            qDebug() << "Project directory not found";

            return 1;
        }

        Global::sProjectDir = Global::sProjectDir.left(index);
    } while(true);



    MainWindow mainWindow;
    mainWindow.loadBuildConfigFile();
    mainWindow.show();

    return app.exec();
}
