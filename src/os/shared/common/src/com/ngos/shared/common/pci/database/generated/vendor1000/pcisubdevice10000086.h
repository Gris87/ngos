// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000086_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000086_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000086: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15D90690 = 0x15D90690,
    SUBDEVICE_15D90691 = 0x15D90691
};



inline const char8* enumToString(PciSubDevice10000086 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000086::NONE:               return "NONE";
        case PciSubDevice10000086::SUBDEVICE_15D90690: return "SUBDEVICE_15D90690";
        case PciSubDevice10000086::SUBDEVICE_15D90691: return "SUBDEVICE_15D90691";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000086 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000086 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000086::SUBDEVICE_15D90690: return "Onboard MegaRAID SAS2208 [Thunderbolt]";
        case PciSubDevice10000086::SUBDEVICE_15D90691: return "Onboard SAS2308 PCI-Express Fusion-MPT SAS-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000086_H
