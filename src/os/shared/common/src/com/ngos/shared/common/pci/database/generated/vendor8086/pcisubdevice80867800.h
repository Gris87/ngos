// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867800_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867800: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_003D0008 = 0x003D0008,
    SUBDEVICE_003D000B = 0x003D000B,
    SUBDEVICE_10920100 = 0x10920100,
    SUBDEVICE_10B4201A = 0x10B4201A,
    SUBDEVICE_10B4202F = 0x10B4202F,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860100 = 0x80860100
};



inline const char8* enumToString(PciSubDevice80867800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867800::NONE:               return "NONE";
        case PciSubDevice80867800::SUBDEVICE_003D0008: return "SUBDEVICE_003D0008";
        case PciSubDevice80867800::SUBDEVICE_003D000B: return "SUBDEVICE_003D000B";
        case PciSubDevice80867800::SUBDEVICE_10920100: return "SUBDEVICE_10920100";
        case PciSubDevice80867800::SUBDEVICE_10B4201A: return "SUBDEVICE_10B4201A";
        case PciSubDevice80867800::SUBDEVICE_10B4202F: return "SUBDEVICE_10B4202F";
        case PciSubDevice80867800::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80867800::SUBDEVICE_80860100: return "SUBDEVICE_80860100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867800::SUBDEVICE_003D0008: return "Starfighter AGP";
        case PciSubDevice80867800::SUBDEVICE_003D000B: return "Starfighter AGP";
        case PciSubDevice80867800::SUBDEVICE_10920100: return "Stealth II G460";
        case PciSubDevice80867800::SUBDEVICE_10B4201A: return "Lightspeed 740";
        case PciSubDevice80867800::SUBDEVICE_10B4202F: return "Lightspeed 740";
        case PciSubDevice80867800::SUBDEVICE_80860000: return "Terminator 2x/i";
        case PciSubDevice80867800::SUBDEVICE_80860100: return "Intel740 Graphics Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867800_H
