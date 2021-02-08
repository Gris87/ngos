// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DE9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DE9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0DE9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250692 = 0x10250692,
    SUBDEVICE_10250725 = 0x10250725,
    SUBDEVICE_10250728 = 0x10250728,
    SUBDEVICE_1025072B = 0x1025072B,
    SUBDEVICE_1025072E = 0x1025072E,
    SUBDEVICE_10250753 = 0x10250753,
    SUBDEVICE_10250754 = 0x10250754,
    SUBDEVICE_17AA3977 = 0x17AA3977,
    SUBDEVICE_1B0A2210 = 0x1B0A2210
};



inline const char8* enumToString(PciSubDevice10DE0DE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0DE9::NONE:               return "NONE";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250692: return "SUBDEVICE_10250692";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250725: return "SUBDEVICE_10250725";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250728: return "SUBDEVICE_10250728";
        case PciSubDevice10DE0DE9::SUBDEVICE_1025072B: return "SUBDEVICE_1025072B";
        case PciSubDevice10DE0DE9::SUBDEVICE_1025072E: return "SUBDEVICE_1025072E";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250753: return "SUBDEVICE_10250753";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250754: return "SUBDEVICE_10250754";
        case PciSubDevice10DE0DE9::SUBDEVICE_17AA3977: return "SUBDEVICE_17AA3977";
        case PciSubDevice10DE0DE9::SUBDEVICE_1B0A2210: return "SUBDEVICE_1B0A2210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0DE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0DE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0DE9::SUBDEVICE_10250692: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250725: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250728: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_1025072B: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_1025072E: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250753: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_10250754: return "GeForce GT 620M";
        case PciSubDevice10DE0DE9::SUBDEVICE_17AA3977: return "GeForce GT 640M LE";
        case PciSubDevice10DE0DE9::SUBDEVICE_1B0A2210: return "GeForce GT 635M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DE9_H
