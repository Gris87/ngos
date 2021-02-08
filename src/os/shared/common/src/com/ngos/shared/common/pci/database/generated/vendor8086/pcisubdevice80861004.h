// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861004: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110049 = 0x0E110049,
    SUBDEVICE_0E11B1A4 = 0x0E11B1A4,
    SUBDEVICE_101410F2 = 0x101410F2,
    SUBDEVICE_80861004 = 0x80861004,
    SUBDEVICE_80862004 = 0x80862004
};



inline const char8* enumToString(PciSubDevice80861004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861004::NONE:               return "NONE";
        case PciSubDevice80861004::SUBDEVICE_0E110049: return "SUBDEVICE_0E110049";
        case PciSubDevice80861004::SUBDEVICE_0E11B1A4: return "SUBDEVICE_0E11B1A4";
        case PciSubDevice80861004::SUBDEVICE_101410F2: return "SUBDEVICE_101410F2";
        case PciSubDevice80861004::SUBDEVICE_80861004: return "SUBDEVICE_80861004";
        case PciSubDevice80861004::SUBDEVICE_80862004: return "SUBDEVICE_80862004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861004::SUBDEVICE_0E110049: return "NC7132 Gigabit Upgrade Module";
        case PciSubDevice80861004::SUBDEVICE_0E11B1A4: return "NC7131 Gigabit Server Adapter";
        case PciSubDevice80861004::SUBDEVICE_101410F2: return "Gigabit Ethernet Server Adapter";
        case PciSubDevice80861004::SUBDEVICE_80861004: return "PRO/1000 T Server Adapter";
        case PciSubDevice80861004::SUBDEVICE_80862004: return "PRO/1000 T Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861004_H
