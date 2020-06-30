#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H



#include "src/com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.h"



class ProtectiveMbrGenerator: public UsbBootMakerGenerator
{
public:
    ProtectiveMbrGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H
