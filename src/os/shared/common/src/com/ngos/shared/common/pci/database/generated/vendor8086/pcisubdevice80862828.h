// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862828_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862828_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862828: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_17AA20A8 = 0x17AA20A8,
    SUBDEVICE_E4BFCC47 = 0xE4BFCC47
};



inline const char8* enumToString(PciSubDevice80862828 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862828::NONE:               return "NONE";
        case PciSubDevice80862828::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice80862828::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice80862828::SUBDEVICE_17AA20A8: return "SUBDEVICE_17AA20A8";
        case PciSubDevice80862828::SUBDEVICE_E4BFCC47: return "SUBDEVICE_E4BFCC47";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862828 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862828 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862828::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice80862828::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice80862828::SUBDEVICE_17AA20A8: return "ThinkPad R61";
        case PciSubDevice80862828::SUBDEVICE_E4BFCC47: return "CCG-RUMBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862828_H
