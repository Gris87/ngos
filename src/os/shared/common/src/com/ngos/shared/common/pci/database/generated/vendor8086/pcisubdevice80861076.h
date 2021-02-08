// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861076_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861076_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861076: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280165 = 0x10280165,
    SUBDEVICE_1028016D = 0x1028016D,
    SUBDEVICE_1028019A = 0x1028019A,
    SUBDEVICE_1028106D = 0x1028106D,
    SUBDEVICE_80860076 = 0x80860076,
    SUBDEVICE_80861076 = 0x80861076,
    SUBDEVICE_80861176 = 0x80861176,
    SUBDEVICE_80861276 = 0x80861276
};



inline const char8* enumToString(PciSubDevice80861076 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861076::NONE:               return "NONE";
        case PciSubDevice80861076::SUBDEVICE_10280165: return "SUBDEVICE_10280165";
        case PciSubDevice80861076::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice80861076::SUBDEVICE_1028019A: return "SUBDEVICE_1028019A";
        case PciSubDevice80861076::SUBDEVICE_1028106D: return "SUBDEVICE_1028106D";
        case PciSubDevice80861076::SUBDEVICE_80860076: return "SUBDEVICE_80860076";
        case PciSubDevice80861076::SUBDEVICE_80861076: return "SUBDEVICE_80861076";
        case PciSubDevice80861076::SUBDEVICE_80861176: return "SUBDEVICE_80861176";
        case PciSubDevice80861076::SUBDEVICE_80861276: return "SUBDEVICE_80861276";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861076 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861076 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861076::SUBDEVICE_10280165: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_1028016D: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_1028019A: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_1028106D: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_80860076: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_80861076: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861076::SUBDEVICE_80861176: return "PRO/1000 MT Desktop Adapter";
        case PciSubDevice80861076::SUBDEVICE_80861276: return "PRO/1000 MT Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861076_H
