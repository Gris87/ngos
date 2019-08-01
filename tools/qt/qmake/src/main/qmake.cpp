#include "qmake.h"

#include <QFile>
#include <QIODevice>
#include <console/console.h>



QMake::QMake(const QString &pathToProFile)
    : mPathToProFile(pathToProFile)
{
    // Nothing
}

qint64 QMake::process()
{
    QFile file(mPathToProFile);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to read file \"%1\"").arg(mPathToProFile));

        return 1;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    return 0;
}
