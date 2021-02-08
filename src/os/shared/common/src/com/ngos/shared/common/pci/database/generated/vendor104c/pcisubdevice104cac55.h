// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC55_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC55_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC55: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140512 = 0x10140512,
    SUBDEVICE_103C0025 = 0x103C0025
};



inline const char8* enumToString(PciSubDevice104CAC55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC55::NONE:               return "NONE";
        case PciSubDevice104CAC55::SUBDEVICE_10140512: return "SUBDEVICE_10140512";
        case PciSubDevice104CAC55::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC55 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC55::SUBDEVICE_10140512: return "ThinkPad T30/T40";
        case PciSubDevice104CAC55::SUBDEVICE_103C0025: return "XE4500 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC55_H
