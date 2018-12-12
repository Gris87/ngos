#include <QApplication>
#include <QDebug>
#include <QFile>

#include "src/main/mainwindow.h"
#include "src/other/global.h"



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
    mainWindow.show();



    QStringList arguments = app.arguments();

    if (arguments.length() > 1 && arguments.at(1) == "--auto")
    {
        mainWindow.on_actionRestart_triggered();
    }



    return app.exec();
}
