#include <QApplication>

#include "com/ngos/devtools/usb_boot_maker/main/mainwindow.h"



qint32 main(qint32 argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
