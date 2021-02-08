// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000D1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003080 = 0x10003080,
    SUBDEVICE_10003090 = 0x10003090
};



inline const char8* enumToString(PciSubDevice100000D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000D1::NONE:               return "NONE";
        case PciSubDevice100000D1::SUBDEVICE_10003080: return "SUBDEVICE_10003080";
        case PciSubDevice100000D1::SUBDEVICE_10003090: return "SUBDEVICE_10003090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000D1::SUBDEVICE_10003080: return "HBA 9405W-16e";
        case PciSubDevice100000D1::SUBDEVICE_10003090: return "HBA 9405W-16i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D1_H
