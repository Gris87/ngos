// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267B1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104304DD = 0x104304DD,
    SUBDEVICE_148C2358 = 0x148C2358,
    SUBDEVICE_174BE324 = 0x174BE324
};



inline const char8* enumToString(PciSubDevice100267B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267B1::NONE:               return "NONE";
        case PciSubDevice100267B1::SUBDEVICE_104304DD: return "SUBDEVICE_104304DD";
        case PciSubDevice100267B1::SUBDEVICE_148C2358: return "SUBDEVICE_148C2358";
        case PciSubDevice100267B1::SUBDEVICE_174BE324: return "SUBDEVICE_174BE324";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267B1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267B1::SUBDEVICE_104304DD: return "STRIX R9 390";
        case PciSubDevice100267B1::SUBDEVICE_148C2358: return "Radeon R9 390";
        case PciSubDevice100267B1::SUBDEVICE_174BE324: return "Sapphire Nitro R9 390";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267B1_H
