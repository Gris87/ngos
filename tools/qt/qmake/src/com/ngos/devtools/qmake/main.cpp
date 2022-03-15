#include <QCoreApplication>                                                                                                                                                                              // Colorize: green
#include <QDateTime>                                                                                                                                                                                     // Colorize: green
#include <QString>                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/qmake/main/qmake.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/devtools/shared/console/console.h>                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void usage()                                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Ignore CppAlignmentVerifier [BEGIN]                                                                                                                                                               // Colorize: green
    Console::err(                                                                                                                                                                                        // Colorize: green
                "Usage: qmake PATH_TO_PRO_FILE\n"                                                                                                                                                        // Colorize: green
                "    * PATH_TO_PRO_FILE - path to pro file\n"                                                                                                                                            // Colorize: green
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
    const QStringList &arguments = app.arguments();                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check arguments                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (arguments.size() != 2)                                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            usage();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return 1;                                                                                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString pathToProFile = arguments.at(1);                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Output application info                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Console::out("QMake started");                                                                                                                                                                   // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
        Console::out("Parameters:");                                                                                                                                                                     // Colorize: green
        Console::out(QString("PATH_TO_PRO_FILE = %1").arg(pathToProFile));                                                                                                                               // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QMake make(pathToProFile);                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 res = make.process();                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Output final messages                                                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
        Console::out(QString("QMake finished in %1 ms")                                                                                                                                                  // Colorize: green
                                .arg(QDateTime::currentMSecsSinceEpoch() - startTime)                                                                                                                    // Colorize: green
        );                                                                                                                                                                                  // Colorize: green
        Console::out("");                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
