#include <QCoreApplication>
#include <QDateTime>
#include <QString>
#include <console/console.h>

#include "src/main/imagebuilder.h"



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: image_builder -b PATH_TO_BOOT_ELF -c PATH_TO_CONFIGURE_ELF (-k PATH_TO_KERNEL_ELF | -i PATH_TO_INSTALLER_ELF) -o PATH_TO_RESULT_IMAGE\n"
                "    * -b PATH_TO_BOOT_ELF      - specify path to boot.elf file\n"
                "    * -c PATH_TO_CONFIGURE_ELF - specify path to configure.elf file\n"
                "    * -k PATH_TO_KERNEL_ELF    - specify path to kernel.elf file\n"
                "    * -i PATH_TO_INSTALLER_ELF - specify path to installer.elf file\n"
                "    * -o PATH_TO_RESULT_IMAGE  - specify path to result kernel image"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    QStringList arguments = app.arguments();



    QString bootElfPath;
    QString configureElfPath;
    QString kernelElfPath;
    QString installerElfPath;
    QString resultImagePath;

    for (qint64 i = 1; i < arguments.length(); ++i)
    {
        QString arg = arguments.at(i);

        if (arg == "-b")
        {
            if (i >= arguments.length() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (bootElfPath != "")
            {
                Console::err("PATH_TO_BOOT_ELF is already specified");

                return 1;
            }

            ++i;
            bootElfPath = arguments.at(i);
        }
        else
        if (arg == "-c")
        {
            if (i >= arguments.length() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (configureElfPath != "")
            {
                Console::err("PATH_TO_CONFIGURE_ELF is already specified");

                return 1;
            }

            ++i;
            configureElfPath = arguments.at(i);
        }
        else
        if (arg == "-k")
        {
            if (i >= arguments.length() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (kernelElfPath != "")
            {
                Console::err("PATH_TO_KERNEL_ELF is already specified");

                return 1;
            }

            ++i;
            kernelElfPath = arguments.at(i);
        }
        else
        if (arg == "-i")
        {
            if (i >= arguments.length() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (installerElfPath != "")
            {
                Console::err("PATH_TO_INSTALLER_ELF is already specified");

                return 1;
            }

            ++i;
            installerElfPath = arguments.at(i);
        }
        else
        if (arg == "-o")
        {
            if (i >= arguments.length() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (resultImagePath != "")
            {
                Console::err("PATH_TO_RESULT_IMAGE is already specified");

                return 1;
            }

            ++i;
            resultImagePath = arguments.at(i);
        }
        else
        {
            usage();

            Console::err(QString("Unknown argument: %1").arg(arg));

            return 1;
        }
    }



    Console::out("Image builder started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH_TO_BOOT_ELF      = %1").arg(bootElfPath));
    Console::out(QString("PATH_TO_CONFIGURE_ELF = %1").arg(configureElfPath));
    Console::out(QString("PATH_TO_KERNEL_ELF    = %1").arg(kernelElfPath));
    Console::out(QString("PATH_TO_INSTALLER_ELF = %1").arg(installerElfPath));
    Console::out(QString("PATH_TO_RESULT_IMAGE  = %1").arg(resultImagePath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    if (bootElfPath == "")
    {
        usage();

        Console::err("PATH_TO_BOOT_ELF is not specified");

        return 1;
    }



    if (configureElfPath == "")
    {
        usage();

        Console::err("PATH_TO_CONFIGURE_ELF is not specified");

        return 1;
    }



    if (kernelElfPath == "" && installerElfPath == "")
    {
        usage();

        Console::err("PATH_TO_KERNEL_ELF is not specified");

        return 1;
    }



    if (kernelElfPath != "" && installerElfPath != "")
    {
        usage();

        Console::err("You should specify PATH_TO_KERNEL_ELF or PATH_TO_INSTALLER_ELF");

        return 1;
    }



    if (resultImagePath == "")
    {
        usage();

        Console::err("PATH_TO_RESULT_IMAGE is not specified");

        return 1;
    }



    ImageBuilder imageBuilder(bootElfPath, configureElfPath, kernelElfPath, installerElfPath, resultImagePath);
    qint64 res = imageBuilder.process();

    Console::out(QString("Image built in %1 ms").arg(QDateTime::currentMSecsSinceEpoch() - startTime));
    Console::out("");

    return res;
}
