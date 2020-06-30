#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H



#include "src/com/ngos/devtools/code_generator/generators/generator.h"

#include <QList>



class UsbBootMakerGenerator: public Generator
{
public:
    UsbBootMakerGenerator(); // TEST: NO

    static bool generateAll(const QString &path); // TEST: NO

protected:
    virtual bool generate(const QString &path); // TEST: NO

private:
    static QList<UsbBootMakerGenerator *> sGenerators;
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_USBBOOTMAKERGENERATOR_H
