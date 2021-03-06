// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B60002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B60002 = 0x10B60002,
    SUBDEVICE_10B60006 = 0x10B60006
};



inline const char8* enumToString(PciSubDevice10B60002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B60002::NONE:               return "NONE";
        case PciSubDevice10B60002::SUBDEVICE_10B60002: return "SUBDEVICE_10B60002";
        case PciSubDevice10B60002::SUBDEVICE_10B60006: return "SUBDEVICE_10B60006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B60002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B60002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B60002::SUBDEVICE_10B60002: return "Smart 16/4 PCI Ringnode Mk2";
        case PciSubDevice10B60002::SUBDEVICE_10B60006: return "16/4 CardBus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B60002_H
