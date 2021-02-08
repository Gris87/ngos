// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862560_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862560_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862560: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280126 = 0x10280126,
    SUBDEVICE_14582560 = 0x14582560,
    SUBDEVICE_14625800 = 0x14625800
};



inline const char8* enumToString(PciSubDevice80862560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862560::NONE:               return "NONE";
        case PciSubDevice80862560::SUBDEVICE_10280126: return "SUBDEVICE_10280126";
        case PciSubDevice80862560::SUBDEVICE_14582560: return "SUBDEVICE_14582560";
        case PciSubDevice80862560::SUBDEVICE_14625800: return "SUBDEVICE_14625800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862560 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862560::SUBDEVICE_10280126: return "Optiplex GX260";
        case PciSubDevice80862560::SUBDEVICE_14582560: return "GA-8PE667 Ultra";
        case PciSubDevice80862560::SUBDEVICE_14625800: return "845PE Max (MS-6580)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862560_H
