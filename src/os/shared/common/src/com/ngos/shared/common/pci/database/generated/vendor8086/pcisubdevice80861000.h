// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861000: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0DF = 0x0E11B0DF,
    SUBDEVICE_0E11B0E0 = 0x0E11B0E0,
    SUBDEVICE_0E11B123 = 0x0E11B123,
    SUBDEVICE_10140119 = 0x10140119,
    SUBDEVICE_80861000 = 0x80861000
};



inline const char8* enumToString(PciSubDevice80861000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861000::NONE:               return "NONE";
        case PciSubDevice80861000::SUBDEVICE_0E11B0DF: return "SUBDEVICE_0E11B0DF";
        case PciSubDevice80861000::SUBDEVICE_0E11B0E0: return "SUBDEVICE_0E11B0E0";
        case PciSubDevice80861000::SUBDEVICE_0E11B123: return "SUBDEVICE_0E11B123";
        case PciSubDevice80861000::SUBDEVICE_10140119: return "SUBDEVICE_10140119";
        case PciSubDevice80861000::SUBDEVICE_80861000: return "SUBDEVICE_80861000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861000::SUBDEVICE_0E11B0DF: return "NC6132 Gigabit Ethernet Adapter (1000-SX)";
        case PciSubDevice80861000::SUBDEVICE_0E11B0E0: return "NC6133 Gigabit Ethernet Adapter (1000-LX)";
        case PciSubDevice80861000::SUBDEVICE_0E11B123: return "NC6134 Gigabit Ethernet Adapter (1000-LX)";
        case PciSubDevice80861000::SUBDEVICE_10140119: return "Netfinity Gigabit Ethernet SX Adapter";
        case PciSubDevice80861000::SUBDEVICE_80861000: return "PRO/1000 Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861000_H
