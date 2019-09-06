#include <QCoreApplication>
#include <QDateTime>
#include <QFile>
#include <console/console.h>

#include "src/generators/assets/assetsgenerator.h"
#include "src/generators/common/commongenerator.h"
#include "src/generators/configure/configuregenerator.h"
#include "src/generators/usb_boot_maker/usbbootmakergenerator.h"



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: code_generator PATH\n"
                "    * PATH - path to NGOS project folder"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    QStringList arguments = app.arguments();

    if (arguments.length() != 2)
    {
        usage();

        return 1;
    }



    QString targetPath = arguments.at(1);



    Console::out("Code generator started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH = %1").arg(targetPath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    if (!QFile::exists(targetPath + "/ngos.files"))
    {
        Console::err("PATH is invalid");

        return 2;
    }



    if (!AssetsGenerator::generateAll(targetPath))
    {
        return 3;
    }



    if (!CommonGenerator::generateAll(targetPath))
    {
        return 3;
    }



    if (!ConfigureGenerator::generateAll(targetPath))
    {
        return 3;
    }



    if (!UsbBootMakerGenerator::generateAll(targetPath))
    {
        return 3;
    }



    Console::out("");
    Console::out(QString("Code generation completed in %1 ms").arg(QDateTime::currentMSecsSinceEpoch() - startTime));
    Console::out("");



    return 0;
}
