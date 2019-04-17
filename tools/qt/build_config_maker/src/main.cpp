#include <QCoreApplication>
#include <QDateTime>
#include <QString>
#include <console/console.h>

#include "src/main/buildconfigmaker.h"



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: build_config_maker PATH_TO_BUILDCONFIG_H [--reset] {BUILD_PARAMETER=VALUE}\n"
                "    * PATH_TO_BUILDCONFIG_H - path to buildconfig.h file\n"
                "    * BUILD_PARAMETER       - One of the parameters from buildconfig.h file\n"
                "    * VALUE                 - What value should be assigned to the BUILD_PARAMETER\n"
                "\n" // Ignore CppSingleCharVerifier
                "    --reset - Reset all parameters to their defaults"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    QStringList arguments = app.arguments();

    if (arguments.length() < 3)
    {
        usage();

        return 1;
    }



    QString buildConfigPath = arguments.at(1);



    bool reset = false;

    if (arguments.length() > 2 && arguments.at(2) == "--reset")
    {
        reset = true;
    }



    QMap<QString, QString> parameters;

    for (qint64 i = (reset ? 3 : 2); i < arguments.length(); ++i)
    {
        QString arg = arguments.at(i);



        qint64 index = arg.indexOf('=');

        if (index < 0)
        {
            usage();

            return 1;
        }



        QString name  = arg.left(index).trimmed();
        QString value = arg.mid(index + 1).trimmed();

        parameters.insert(name, value);
    }



    Console::out("Build config maker started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH_TO_BUILDCONFIG_H = %1").arg(buildConfigPath));



    if (reset)
    {
        Console::out("--reset");
    }



    QMapIterator<QString, QString> it(parameters);

    while (it.hasNext())
    {
        it.next();

        Console::out(QString("%1 = %2").arg(it.key()).arg(it.value()));
    }

    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    BuildConfigMaker maker(buildConfigPath, reset, parameters);
    qint64 res = maker.process();

    Console::out("");
    Console::out(QString("Build config modified in %1 ms").arg(QDateTime::currentMSecsSinceEpoch() - startTime));
    Console::out("");

    return res;
}
