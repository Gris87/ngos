#include <QCoreApplication>
#include <QDateTime>
#include <QString>

#include <com/ngos/devtools/image_builder/main/imagebuilder.h>
#include <com/ngos/devtools/shared/console/console.h>



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: image_builder -b PATH_TO_BOOT_ELF (-c PATH_TO_CONFIGURE_ELF -k PATH_TO_KERNEL_ELF | -t PATH_TO_TEXT_ELF) -o PATH_TO_RESULT_IMAGE\n"
                "    * -b PATH_TO_BOOT_ELF      - specify path to boot.elf file\n"
                "    * -c PATH_TO_CONFIGURE_ELF - specify path to configure.elf file\n"
                "    * -k PATH_TO_KERNEL_ELF    - specify path to kernel.elf file\n"
                "    * -t PATH_TO_TEXT_ELF      - specify path to text.elf file\n"
                "    * -o PATH_TO_RESULT_IMAGE  - specify path to result image\n"
                "\n" // Ignore CppSingleCharVerifier
                "If you specify argument \"-t PATH_TO_TEXT_ELF\" it will replace existing .configure section and .kernel section in boot.elf file with a single .text section"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    const QStringList &arguments = app.arguments();



    QString bootElfPath;
    QString configureElfPath;
    QString kernelElfPath;
    QString textElfPath;
    QString resultImagePath;

    for (qint64 i = 1; i < arguments.size(); ++i)
    {
        QString arg = arguments.at(i);

        if (arg == "-b")
        {
            if (i >= arguments.size() - 1)
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
            if (i >= arguments.size() - 1)
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
            if (i >= arguments.size() - 1)
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
        if (arg == "-t")
        {
            if (i >= arguments.size() - 1)
            {
                usage();

                Console::err(QString("Additional argument missing for %1").arg(arg));

                return 1;
            }

            if (textElfPath != "")
            {
                Console::err("PATH_TO_TEXT_ELF is already specified");

                return 1;
            }

            ++i;
            textElfPath = arguments.at(i);
        }
        else
        if (arg == "-o")
        {
            if (i >= arguments.size() - 1)
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
    Console::out(QString("PATH_TO_TEXT_ELF      = %1").arg(textElfPath));
    Console::out(QString("PATH_TO_RESULT_IMAGE  = %1").arg(resultImagePath));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    if (bootElfPath == "")
    {
        usage();

        Console::err("PATH_TO_BOOT_ELF is not specified");

        return 1;
    }



    if (textElfPath == "")
    {
        if (configureElfPath == "")
        {
            usage();

            Console::err("PATH_TO_CONFIGURE_ELF is not specified");

            return 1;
        }



        if (kernelElfPath == "")
        {
            usage();

            Console::err("PATH_TO_KERNEL_ELF is not specified");

            return 1;
        }
    }
    else
    {
        if (configureElfPath != "")
        {
            Console::err("PATH_TO_CONFIGURE_ELF ignored");
        }



        if (kernelElfPath != "")
        {
            Console::err("PATH_TO_KERNEL_ELF ignored");
        }
    }



    if (resultImagePath == "")
    {
        usage();

        Console::err("PATH_TO_RESULT_IMAGE is not specified");

        return 1;
    }



    ImageBuilder imageBuilder(bootElfPath, configureElfPath, kernelElfPath, textElfPath, resultImagePath);
    qint64 res = imageBuilder.process();

    Console::out(QString("Image built in %1 ms").arg(QDateTime::currentMSecsSinceEpoch() - startTime));
    Console::out("");

    return res;
}
