// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864222_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864222_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864222: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C135C = 0x103C135C,
    SUBDEVICE_80861000 = 0x80861000,
    SUBDEVICE_80861001 = 0x80861001,
    SUBDEVICE_80861005 = 0x80861005,
    SUBDEVICE_80861034 = 0x80861034,
    SUBDEVICE_80861044 = 0x80861044,
    SUBDEVICE_80861C00 = 0x80861C00
};



inline const char8* enumToString(PciSubDevice80864222 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864222::NONE:               return "NONE";
        case PciSubDevice80864222::SUBDEVICE_103C135C: return "SUBDEVICE_103C135C";
        case PciSubDevice80864222::SUBDEVICE_80861000: return "SUBDEVICE_80861000";
        case PciSubDevice80864222::SUBDEVICE_80861001: return "SUBDEVICE_80861001";
        case PciSubDevice80864222::SUBDEVICE_80861005: return "SUBDEVICE_80861005";
        case PciSubDevice80864222::SUBDEVICE_80861034: return "SUBDEVICE_80861034";
        case PciSubDevice80864222::SUBDEVICE_80861044: return "SUBDEVICE_80861044";
        case PciSubDevice80864222::SUBDEVICE_80861C00: return "SUBDEVICE_80861C00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864222 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864222 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864222::SUBDEVICE_103C135C: return "PRO/Wireless 3945ABG [Golan] Network Connection";
        case PciSubDevice80864222::SUBDEVICE_80861000: return "PRO/Wireless 3945ABG Network Connection";
        case PciSubDevice80864222::SUBDEVICE_80861001: return "WM3945ABG MOW2";
        case PciSubDevice80864222::SUBDEVICE_80861005: return "PRO/Wireless 3945BG Network Connection";
        case PciSubDevice80864222::SUBDEVICE_80861034: return "PRO/Wireless 3945BG Network Connection";
        case PciSubDevice80864222::SUBDEVICE_80861044: return "PRO/Wireless 3945BG Network Connection";
        case PciSubDevice80864222::SUBDEVICE_80861C00: return "PRO/Wireless 3945ABG Network Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864222_H
