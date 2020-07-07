#include "usbbootmakergenerator.h"

#include <QDir>

#include <com/ngos/devtools/shared/console/console.h>



QList<UsbBootMakerGenerator *> UsbBootMakerGenerator::sGenerators;



UsbBootMakerGenerator::UsbBootMakerGenerator()
    : Generator()
{
    sGenerators.append(this);
}

bool UsbBootMakerGenerator::generateAll(const QString &path)
{
    QString usbBootMakerPath = path + "/tools/qt/usb_boot_maker";

    if (!QDir(usbBootMakerPath).exists())
    {
        Console::err(QString("%1 not found").arg(usbBootMakerPath));

        return false;
    }



    for (qint64 i = 0; i < sGenerators.length(); ++i)
    {
        if (!sGenerators.at(i)->generate(usbBootMakerPath))
        {
            return false;
        }
    }



    return true;
}

bool UsbBootMakerGenerator::generate(const QString &/*path*/)
{
    return false;
}
