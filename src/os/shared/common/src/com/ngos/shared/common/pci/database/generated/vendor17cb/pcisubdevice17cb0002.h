// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17CB0002: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13856D00 = 0x13856D00,
    SUBDEVICE_17370054 = 0x17370054
};



inline const char8* enumToString(PciSubDevice17CB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17CB0002::NONE:               return "NONE";
        case PciSubDevice17CB0002::SUBDEVICE_13856D00: return "SUBDEVICE_13856D00";
        case PciSubDevice17CB0002::SUBDEVICE_17370054: return "SUBDEVICE_17370054";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17CB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17CB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17CB0002::SUBDEVICE_13856D00: return "WPNT511 RangeMax 240 Mbps Wireless CardBus Adapter";
        case PciSubDevice17CB0002::SUBDEVICE_17370054: return "WPC54GX4 v1 802.11g Wireless-G Notebook Adapter with SRX400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0002_H
