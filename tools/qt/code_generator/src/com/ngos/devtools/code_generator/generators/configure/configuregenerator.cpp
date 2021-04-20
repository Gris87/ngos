#include "configuregenerator.h"

#include <QDir>

#include <com/ngos/devtools/shared/console/console.h>



QList<ConfigureGenerator *> ConfigureGenerator::sGenerators;



ConfigureGenerator::ConfigureGenerator()
    : Generator()
{
    sGenerators.append(this);
}

bool ConfigureGenerator::generateAll(const QString &path)
{
    QString configurePath = path + "/src/os/configure";

    if (!QDir(configurePath).exists())
    {
        Console::err(QString("%1 not found").arg(configurePath));

        return false;
    }



    for (qint64 i = 0; i < sGenerators.size(); ++i)
    {
        if (!sGenerators.at(i)->generate(configurePath))
        {
            return false;
        }
    }



    return true;
}

bool ConfigureGenerator::generate(const QString &/*path*/)
{
    return false;
}
