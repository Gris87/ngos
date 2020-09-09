// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086200E = 0x8086200E,
    SUBDEVICE_80862013 = 0x80862013,
    SUBDEVICE_80862017 = 0x80862017
};



inline const char8* enumToString(PciSubDevice80861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861002::NONE:               return "NONE";
        case PciSubDevice80861002::SUBDEVICE_8086200E: return "SUBDEVICE_8086200E";
        case PciSubDevice80861002::SUBDEVICE_80862013: return "SUBDEVICE_80862013";
        case PciSubDevice80861002::SUBDEVICE_80862017: return "SUBDEVICE_80862017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861002::SUBDEVICE_8086200E: return "Pro 100 LAN+Modem 56 Cardbus II";
        case PciSubDevice80861002::SUBDEVICE_80862013: return "Pro 100 SR Mobile Combo Adapter";
        case PciSubDevice80861002::SUBDEVICE_80862017: return "Pro 100 S Combo Mobile Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861002_H
