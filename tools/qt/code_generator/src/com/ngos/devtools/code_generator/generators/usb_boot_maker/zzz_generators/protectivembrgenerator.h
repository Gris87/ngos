#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/usb_boot_maker/usbbootmakergenerator.h>



class ProtectiveMbrGenerator: public UsbBootMakerGenerator
{
public:
    ProtectiveMbrGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_USB_BOOT_MAKER_ZZZ_GENERATORS_PROTECTIVEMBRGENERATOR_H
