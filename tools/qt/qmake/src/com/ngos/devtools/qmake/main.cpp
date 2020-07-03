#include <QCoreApplication>
#include <QDateTime>
#include <QString>
#include <com/ngos/devtools/shared/console/console.h>

#include "com/ngos/devtools/qmake/main/qmake.h"



void usage()
{
    // Ignore CppAlignmentVerifier [BEGIN]
    Console::err(
                "Usage: qmake PATH_TO_PRO_FILE\n"
                "    * PATH_TO_PRO_FILE - path to pro file\n"
                );
    // Ignore CppAlignmentVerifier [END]
}

qint32 main(qint32 argc, char *argv[])
{
    QCoreApplication app(argc, argv);



    QStringList arguments = app.arguments();

    if (arguments.length() < 2)
    {
        usage();

        return 1;
    }



    QString pathToProFile = arguments.at(1);



    Console::out("QMake started");
    Console::out("");
    Console::out("Parameters:");
    Console::out(QString("PATH_TO_PRO_FILE = %1").arg(pathToProFile));
    Console::out("");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();



    QMake make(pathToProFile);

    qint64 res = make.process();

    Console::out("");
    Console::out(QString("QMake finished in %1 ms").arg(QDateTime::currentMSecsSinceEpoch() - startTime));
    Console::out("");



    return res;
}
