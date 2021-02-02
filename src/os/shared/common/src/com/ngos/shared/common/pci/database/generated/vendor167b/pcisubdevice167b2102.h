// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCISUBDEVICE167B2102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCISUBDEVICE167B2102_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice167B2102: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_187E3406 = 0x187E3406,
    SUBDEVICE_187E3407 = 0x187E3407
};



inline const char8* enumToString(PciSubDevice167B2102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice167B2102::NONE:               return "NONE";
        case PciSubDevice167B2102::SUBDEVICE_187E3406: return "SUBDEVICE_187E3406";
        case PciSubDevice167B2102::SUBDEVICE_187E3407: return "SUBDEVICE_187E3407";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice167B2102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice167B2102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice167B2102::SUBDEVICE_187E3406: return "ZyAIR B-122 CardBus 11Mbs Wireless LAN Card";
        case PciSubDevice167B2102::SUBDEVICE_187E3407: return "ZyAIR B-320 802.11b Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCISUBDEVICE167B2102_H
