// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10136003: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10134280 = 0x10134280,
    SUBDEVICE_10140153 = 0x10140153,
    SUBDEVICE_153B112E = 0x153B112E,
    SUBDEVICE_153B1136 = 0x153B1136,
    SUBDEVICE_16810050 = 0x16810050,
    SUBDEVICE_1681A010 = 0x1681A010,
    SUBDEVICE_1681A011 = 0x1681A011,
    SUBDEVICE_50533357 = 0x50533357
};



inline const char8* enumToString(PciSubDevice10136003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136003::NONE:               return "NONE";
        case PciSubDevice10136003::SUBDEVICE_10134280: return "SUBDEVICE_10134280";
        case PciSubDevice10136003::SUBDEVICE_10140153: return "SUBDEVICE_10140153";
        case PciSubDevice10136003::SUBDEVICE_153B112E: return "SUBDEVICE_153B112E";
        case PciSubDevice10136003::SUBDEVICE_153B1136: return "SUBDEVICE_153B1136";
        case PciSubDevice10136003::SUBDEVICE_16810050: return "SUBDEVICE_16810050";
        case PciSubDevice10136003::SUBDEVICE_1681A010: return "SUBDEVICE_1681A010";
        case PciSubDevice10136003::SUBDEVICE_1681A011: return "SUBDEVICE_1681A011";
        case PciSubDevice10136003::SUBDEVICE_50533357: return "SUBDEVICE_50533357";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10136003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10136003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136003::SUBDEVICE_10134280: return "Crystal SoundFusion PCI Audio Accelerator";
        case PciSubDevice10136003::SUBDEVICE_10140153: return "ThinkPad 600X/A20m";
        case PciSubDevice10136003::SUBDEVICE_153B112E: return "DMX XFire 1024";
        case PciSubDevice10136003::SUBDEVICE_153B1136: return "SiXPack 5.1+";
        case PciSubDevice10136003::SUBDEVICE_16810050: return "Game Theater XP";
        case PciSubDevice10136003::SUBDEVICE_1681A010: return "Gamesurround Fortissimo II";
        case PciSubDevice10136003::SUBDEVICE_1681A011: return "Gamesurround Fortissimo III 7.1";
        case PciSubDevice10136003::SUBDEVICE_50533357: return "Santa Cruz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136003_H
