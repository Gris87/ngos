// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280015_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280015_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10280015: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F01 = 0x10281F01,
    SUBDEVICE_10281F02 = 0x10281F02,
    SUBDEVICE_10281F03 = 0x10281F03
};



inline const char8* enumToString(PciSubDevice10280015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280015::NONE:               return "NONE";
        case PciSubDevice10280015::SUBDEVICE_10281F01: return "SUBDEVICE_10281F01";
        case PciSubDevice10280015::SUBDEVICE_10281F02: return "SUBDEVICE_10281F02";
        case PciSubDevice10280015::SUBDEVICE_10281F03: return "SUBDEVICE_10281F03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10280015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10280015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280015::SUBDEVICE_10281F01: return "PERC 5/E Adapter RAID Controller";
        case PciSubDevice10280015::SUBDEVICE_10281F02: return "PERC 5/i Adapter RAID Controller";
        case PciSubDevice10280015::SUBDEVICE_10281F03: return "PERC 5/i Integrated RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280015_H
