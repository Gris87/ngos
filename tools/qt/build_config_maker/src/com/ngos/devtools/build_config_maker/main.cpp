#include <QCoreApplication>                                                                                                                                                                              // Colorize: green
#include <QDateTime>                                                                                                                                                                                     // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/build_config_maker/main/buildconfigmaker.h>                                                                                                                                  // Colorize: green
#include <com/ngos/devtools/shared/console/console.h>                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void usage()                                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                               // Colorize: green
    Console::err(                                                                                                                                                                                        // Colorize: green
                "Usage: build_config_maker PATH_TO_BUILDCONFIG_H [--reset] {BUILD_PARAMETER=VALUE}\n"                                                                                                    // Colorize: green
                "    * PATH_TO_BUILDCONFIG_H - path to buildconfig.h file\n"                                                                                                                             // Colorize: green
                "    * BUILD_PARAMETER       - One of the parameters from buildconfig.h file\n"                                                                                                          // Colorize: green
                "    * VALUE                 - What value should be assigned to the BUILD_PARAMETER\n"                                                                                                   // Colorize: green
                "\n" // Ignore CppSingleCharVerifier                                                                                                                                                     // Colorize: green
                "    --reset - Reset all parameters to their defaults"                                                                                                                                   // Colorize: green
                );                                                                                                                                                                                       // Colorize: green
    // Ignore CppAlignmentVerifier [END]                                                                                                                                                                 // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
qint32 main(qint32 argc, char *argv[])                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QCoreApplication app(argc, argv);                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    const QStringList &arguments = app.arguments();                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check arguments                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (arguments.size() < 3)                                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            usage();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return 1;                                                                                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString                buildConfigPath;                                                                                                                                                              // Colorize: green
    bool                   reset;                                                                                                                                                                        // Colorize: green
    QMap<QString, QString> parameters;  // Parameter => Value                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get arguments                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        buildConfigPath = arguments.at(1);                                                                                                                                                               // Colorize: green
        reset           = arguments.size() > 2 && arguments.at(2) == "--reset";                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = (reset ? 3 : 2); i < arguments.size(); ++i)                                                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString arg = arguments.at(i);                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            qint64 index = arg.indexOf('=');                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (index < 0)                                                                                                                                                                               // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                usage();                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return 1;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            QString name  = arg.left(index).trimmed();                                                                                                                                                   // Colorize: green
            QString value = arg.mid(index + 1).trimmed();                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            parameters.insert(name, value);                                                                                                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Output application info                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Console::out("Build config maker started");                                                                                                                                                      // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
        Console::out("Parameters:");                                                                                                                                                                     // Colorize: green
        Console::out(QString("PATH_TO_BUILDCONFIG_H = %1").arg(buildConfigPath));                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (reset)                                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            Console::out("--reset");                                                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QMapIterator<QString, QString> it(parameters);                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        while (it.hasNext())                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            it.next();                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            Console::out(QString("%1 = %2")                                                                                                                                                              // Colorize: green
                                    .arg(it.key())                                                                                                                                                       // Colorize: green
                                    .arg(it.value())                                                                                                                                                     // Colorize: green
            );                                                                                                                                                                                           // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    BuildConfigMaker maker(buildConfigPath, reset, parameters);                                                                                                                                          // Colorize: green
    qint64 res = maker.process();                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Output final messages                                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
        Console::out(QString("Build config modified in %1 ms")                                                                                                                                           // Colorize: green
                                .arg(QDateTime::currentMSecsSinceEpoch() - startTime)                                                                                                                    // Colorize: green
        );                                                                                                                                                                                               // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
