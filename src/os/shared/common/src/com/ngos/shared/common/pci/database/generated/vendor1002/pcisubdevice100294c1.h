// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100294C1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280211 = 0x10280211,
    SUBDEVICE_10280D02 = 0x10280D02
};



inline const char8* enumToString(PciSubDevice100294C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100294C1::NONE:               return "NONE";
        case PciSubDevice100294C1::SUBDEVICE_10280211: return "SUBDEVICE_10280211";
        case PciSubDevice100294C1::SUBDEVICE_10280D02: return "SUBDEVICE_10280D02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100294C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100294C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100294C1::SUBDEVICE_10280211: return "Optiplex 755";
        case PciSubDevice100294C1::SUBDEVICE_10280D02: return "Optiplex 755";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C1_H
