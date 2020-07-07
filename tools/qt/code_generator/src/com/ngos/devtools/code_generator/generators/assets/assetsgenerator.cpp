#include "assetsgenerator.h"

#include <QDir>

#include <com/ngos/devtools/shared/console/console.h>



QList<AssetsGenerator *> AssetsGenerator::sGenerators;



AssetsGenerator::AssetsGenerator()
    : Generator()
{
    sGenerators.append(this);
}

bool AssetsGenerator::generateAll(const QString &path)
{
    QString osPath = path + "/src/os";

    if (!QDir(osPath).exists())
    {
        Console::err(QString("%1 not found").arg(osPath));

        return false;
    }



    for (qint64 i = 0; i < sGenerators.length(); ++i)
    {
        if (!sGenerators.at(i)->generate(osPath))
        {
            return false;
        }
    }



    return true;
}

bool AssetsGenerator::generate(const QString &/*path*/)
{
    return false;
}
