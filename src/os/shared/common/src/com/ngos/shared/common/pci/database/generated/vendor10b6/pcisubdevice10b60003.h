// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B60003: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0FD = 0x0E11B0FD,
    SUBDEVICE_10B60003 = 0x10B60003,
    SUBDEVICE_10B60007 = 0x10B60007
};



inline const char8* enumToString(PciSubDevice10B60003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B60003::NONE:               return "NONE";
        case PciSubDevice10B60003::SUBDEVICE_0E11B0FD: return "SUBDEVICE_0E11B0FD";
        case PciSubDevice10B60003::SUBDEVICE_10B60003: return "SUBDEVICE_10B60003";
        case PciSubDevice10B60003::SUBDEVICE_10B60007: return "SUBDEVICE_10B60007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B60003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B60003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B60003::SUBDEVICE_0E11B0FD: return "Compaq NC4621 PCI, 4/16, WOL";
        case PciSubDevice10B60003::SUBDEVICE_10B60003: return "Smart 16/4 PCI Ringnode Mk3";
        case PciSubDevice10B60003::SUBDEVICE_10B60007: return "Presto PCI Plus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60003_H
