// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17CB0001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13855C00 = 0x13855C00,
    SUBDEVICE_17370045 = 0x17370045
};



inline const char8* enumToString(PciSubDevice17CB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17CB0001::NONE:               return "NONE";
        case PciSubDevice17CB0001::SUBDEVICE_13855C00: return "SUBDEVICE_13855C00";
        case PciSubDevice17CB0001::SUBDEVICE_17370045: return "SUBDEVICE_17370045";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17CB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17CB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17CB0001::SUBDEVICE_13855C00: return "WGM511 Pre-N 802.11g Wireless CardBus Adapter";
        case PciSubDevice17CB0001::SUBDEVICE_17370045: return "WMP54GX v1 802.11g Wireless-G PCI Adapter with SRX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCISUBDEVICE17CB0001_H
