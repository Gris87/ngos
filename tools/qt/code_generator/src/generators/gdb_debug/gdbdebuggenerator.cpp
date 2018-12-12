#include "gdbdebuggenerator.h"

#include <QDir>
#include <console/console.h>



QList<GdbDebugGenerator *> GdbDebugGenerator::sGenerators;



GdbDebugGenerator::GdbDebugGenerator()
    : Generator()
{
    sGenerators.append(this);
}

bool GdbDebugGenerator::generateAll(const QString &path)
{
    QString gdbDebugPath = path + "/tools/qt/gdb_debug";

    if (!QDir(gdbDebugPath).exists())
    {
        Console::err(QString("%1 not found").arg(gdbDebugPath));

        return false;
    }



    for (qint64 i = 0; i < sGenerators.length(); ++i)
    {
        if (!sGenerators.at(i)->generate(gdbDebugPath))
        {
            return false;
        }
    }



    return true;
}

bool GdbDebugGenerator::generate(const QString &/*path*/)
{
    return false;
}
