// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140170_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140170_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140170: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10920172 = 0x10920172,
    SUBDEVICE_10920173 = 0x10920173,
    SUBDEVICE_10920174 = 0x10920174,
    SUBDEVICE_10920184 = 0x10920184
};



inline const char8* enumToString(PciSubDevice10140170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140170::NONE:               return "NONE";
        case PciSubDevice10140170::SUBDEVICE_10920172: return "SUBDEVICE_10920172";
        case PciSubDevice10140170::SUBDEVICE_10920173: return "SUBDEVICE_10920173";
        case PciSubDevice10140170::SUBDEVICE_10920174: return "SUBDEVICE_10920174";
        case PciSubDevice10140170::SUBDEVICE_10920184: return "SUBDEVICE_10920184";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140170::SUBDEVICE_10920172: return "Fire GL2";
        case PciSubDevice10140170::SUBDEVICE_10920173: return "Fire GL3";
        case PciSubDevice10140170::SUBDEVICE_10920174: return "Fire GL4";
        case PciSubDevice10140170::SUBDEVICE_10920184: return "Fire GL4s";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140170_H
