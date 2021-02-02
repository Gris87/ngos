// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B6000B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B6000B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B6000B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B60008 = 0x10B60008,
    SUBDEVICE_10B6000B = 0x10B6000B
};



inline const char8* enumToString(PciSubDevice10B6000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B6000B::NONE:               return "NONE";
        case PciSubDevice10B6000B::SUBDEVICE_10B60008: return "SUBDEVICE_10B60008";
        case PciSubDevice10B6000B::SUBDEVICE_10B6000B: return "SUBDEVICE_10B6000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B6000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B6000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B6000B::SUBDEVICE_10B60008: return "16/4 CardBus Adapter Mk2";
        case PciSubDevice10B6000B::SUBDEVICE_10B6000B: return "16/4 Cardbus Adapter Mk2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCISUBDEVICE10B6000B_H
