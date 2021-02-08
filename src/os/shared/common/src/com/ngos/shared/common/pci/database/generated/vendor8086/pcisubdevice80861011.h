// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861011: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140268 = 0x10140268,
    SUBDEVICE_80861002 = 0x80861002,
    SUBDEVICE_80861003 = 0x80861003
};



inline const char8* enumToString(PciSubDevice80861011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861011::NONE:               return "NONE";
        case PciSubDevice80861011::SUBDEVICE_10140268: return "SUBDEVICE_10140268";
        case PciSubDevice80861011::SUBDEVICE_80861002: return "SUBDEVICE_80861002";
        case PciSubDevice80861011::SUBDEVICE_80861003: return "SUBDEVICE_80861003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861011::SUBDEVICE_10140268: return "iSeries Gigabit Ethernet Adapter";
        case PciSubDevice80861011::SUBDEVICE_80861002: return "PRO/1000 MF Server Adapter";
        case PciSubDevice80861011::SUBDEVICE_80861003: return "PRO/1000 MF Server Adapter (LX)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861011_H
