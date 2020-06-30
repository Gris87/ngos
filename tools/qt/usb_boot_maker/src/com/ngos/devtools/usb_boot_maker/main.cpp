#include <QApplication>

#include "src/main/mainwindow.h"



qint32 main(qint32 argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
