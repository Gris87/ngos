#include "commongenerator.h"

#include <QDir>
#include <com/ngos/devtools/shared/console/console.h>



QList<CommonGenerator *> CommonGenerator::sGenerators;



CommonGenerator::CommonGenerator()
    : Generator()
{
    sGenerators.append(this);
}

bool CommonGenerator::generateAll(const QString &path)
{
    if (!QDir(path).exists())
    {
        Console::err(QString("%1 not found").arg(path));

        return false;
    }



    for (qint64 i = 0; i < sGenerators.length(); ++i)
    {
        if (!sGenerators.at(i)->generate(path))
        {
            return false;
        }
    }



    return true;
}

bool CommonGenerator::generate(const QString &/*path*/)
{
    return false;
}
