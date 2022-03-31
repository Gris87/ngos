#include "usbbootmakergenerator.h"                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDir>                                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/shared/console/console.h>                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QList<UsbBootMakerGenerator *> UsbBootMakerGenerator::sGenerators;                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
UsbBootMakerGenerator::UsbBootMakerGenerator()                                                                                                                                                           // Colorize: green
    : Generator()                                                                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    sGenerators.append(this);                                                                                                                                                                            // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool UsbBootMakerGenerator::generateAll(const QString &path)                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString usbBootMakerPath = path + "/tools/qt/usb_boot_maker";                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!QDir(usbBootMakerPath).exists())                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        Console::err(QString("%1 not found")                                                                                                                                                             // Colorize: green
                                .arg(usbBootMakerPath)                                                                                                                                                   // Colorize: green
        );                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return false;                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    for (qint64 i = 0; i < sGenerators.size(); ++i)                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!sGenerators.at(i)->generate(usbBootMakerPath))                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return true;                                                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
