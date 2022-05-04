// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000C4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000C4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000C4: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003190 = 0x10003190,
    SUBDEVICE_100031A0 = 0x100031A0,
    SUBDEVICE_11700002 = 0x11700002
};



inline const char8* enumToString(PciSubDevice100000C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000C4::NONE:               return "NONE";
        case PciSubDevice100000C4::SUBDEVICE_10003190: return "SUBDEVICE_10003190";
        case PciSubDevice100000C4::SUBDEVICE_100031A0: return "SUBDEVICE_100031A0";
        case PciSubDevice100000C4::SUBDEVICE_11700002: return "SUBDEVICE_11700002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000C4::SUBDEVICE_10003190: return "SAS9305-16i";
        case PciSubDevice100000C4::SUBDEVICE_100031A0: return "SAS9305-24i";
        case PciSubDevice100000C4::SUBDEVICE_11700002: return "SAS3224 PCI Express to 12Gb HBA MEZZ CARD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000C4_H
