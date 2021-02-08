// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861079_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861079_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861079: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C12A6 = 0x103C12A6,
    SUBDEVICE_103C12CF = 0x103C12CF,
    SUBDEVICE_177510D0 = 0x177510D0,
    SUBDEVICE_1775CE90 = 0x1775CE90,
    SUBDEVICE_1FC10027 = 0x1FC10027,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_4C5310B0 = 0x4C5310B0,
    SUBDEVICE_80860079 = 0x80860079,
    SUBDEVICE_80861079 = 0x80861079,
    SUBDEVICE_80861179 = 0x80861179,
    SUBDEVICE_8086117A = 0x8086117A
};



inline const char8* enumToString(PciSubDevice80861079 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861079::NONE:               return "NONE";
        case PciSubDevice80861079::SUBDEVICE_103C12A6: return "SUBDEVICE_103C12A6";
        case PciSubDevice80861079::SUBDEVICE_103C12CF: return "SUBDEVICE_103C12CF";
        case PciSubDevice80861079::SUBDEVICE_177510D0: return "SUBDEVICE_177510D0";
        case PciSubDevice80861079::SUBDEVICE_1775CE90: return "SUBDEVICE_1775CE90";
        case PciSubDevice80861079::SUBDEVICE_1FC10027: return "SUBDEVICE_1FC10027";
        case PciSubDevice80861079::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice80861079::SUBDEVICE_4C5310B0: return "SUBDEVICE_4C5310B0";
        case PciSubDevice80861079::SUBDEVICE_80860079: return "SUBDEVICE_80860079";
        case PciSubDevice80861079::SUBDEVICE_80861079: return "SUBDEVICE_80861079";
        case PciSubDevice80861079::SUBDEVICE_80861179: return "SUBDEVICE_80861179";
        case PciSubDevice80861079::SUBDEVICE_8086117A: return "SUBDEVICE_8086117A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861079 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861079 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861079::SUBDEVICE_103C12A6: return "Dual Port 1000Base-T [A9900A]";
        case PciSubDevice80861079::SUBDEVICE_103C12CF: return "Core Dual Port 1000Base-T [AB352A]";
        case PciSubDevice80861079::SUBDEVICE_177510D0: return "V5D Single Board Computer Gigabit Ethernet";
        case PciSubDevice80861079::SUBDEVICE_1775CE90: return "CE9";
        case PciSubDevice80861079::SUBDEVICE_1FC10027: return "Niagara 2261 Failover NIC";
        case PciSubDevice80861079::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";
        case PciSubDevice80861079::SUBDEVICE_4C5310B0: return "CL9 mainboard";
        case PciSubDevice80861079::SUBDEVICE_80860079: return "PRO/1000 MT Dual Port Network Connection";
        case PciSubDevice80861079::SUBDEVICE_80861079: return "PRO/1000 MT Dual Port Network Connection";
        case PciSubDevice80861079::SUBDEVICE_80861179: return "PRO/1000 MT Dual Port Server Adapter";
        case PciSubDevice80861079::SUBDEVICE_8086117A: return "PRO/1000 MT Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861079_H
