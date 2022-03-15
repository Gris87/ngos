#include <QCoreApplication>
#include <QDateTime>
#include <QFile>

#include <com/ngos/devtools/code_generator/generators/assets/assetsgenerator.h>
#include <com/ngos/devtools/code_generator/generators/common/commongenerator.h>
#include <com/ngos/devtools/code_generator/generators/configure/configuregenerator.h>
#include <com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.h>
#include <com/ngos/devtools/shared/console/console.h>



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



    const QStringList &arguments = app.arguments();

    if (arguments.size() != 2)
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

        return 1;
    }



    if (
        !AssetsGenerator::generateAll(targetPath)
        ||
        !CommonGenerator::generateAll(targetPath)
        ||
        !ConfigureGenerator::generateAll(targetPath)
        ||
        !UsbBootMakerGenerator::generateAll(targetPath)
       )
    {
        return 1;
    }



    Console::out("");
    Console::out(QString("%1 files generated")
                            .arg(Generator::getNumberOfGeneratedFiles())
    );
    Console::out("");
    Console::out(QString("Code generation completed in %1 ms")
                            .arg(QDateTime::currentMSecsSinceEpoch() - startTime)
    );
    Console::out("");



    return 0;
}
