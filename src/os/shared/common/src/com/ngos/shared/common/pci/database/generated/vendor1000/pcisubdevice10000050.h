// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000050: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F04 = 0x10281F04,
    SUBDEVICE_10281F09 = 0x10281F09
};



inline const char8* enumToString(PciSubDevice10000050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000050::NONE:               return "NONE";
        case PciSubDevice10000050::SUBDEVICE_10281F04: return "SUBDEVICE_10281F04";
        case PciSubDevice10000050::SUBDEVICE_10281F09: return "SUBDEVICE_10281F09";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000050::SUBDEVICE_10281F04: return "SAS 5/E";
        case PciSubDevice10000050::SUBDEVICE_10281F09: return "SAS 5i/R";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000050_H
