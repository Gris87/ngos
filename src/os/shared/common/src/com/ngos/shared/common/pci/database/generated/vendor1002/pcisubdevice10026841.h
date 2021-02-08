// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026841_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026841_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026841: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280561 = 0x10280561,
    SUBDEVICE_1028056C = 0x1028056C,
    SUBDEVICE_1028057F = 0x1028057F,
    SUBDEVICE_103C17F1 = 0x103C17F1,
    SUBDEVICE_103C17F4 = 0x103C17F4,
    SUBDEVICE_103C1813 = 0x103C1813,
    SUBDEVICE_103C183A = 0x103C183A,
    SUBDEVICE_103C183C = 0x103C183C,
    SUBDEVICE_103C183E = 0x103C183E,
    SUBDEVICE_103C1840 = 0x103C1840,
    SUBDEVICE_103C1842 = 0x103C1842,
    SUBDEVICE_103C1844 = 0x103C1844,
    SUBDEVICE_1043100A = 0x1043100A,
    SUBDEVICE_1043104B = 0x1043104B,
    SUBDEVICE_104310DC = 0x104310DC,
    SUBDEVICE_10432134 = 0x10432134,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11790002 = 0x11790002,
    SUBDEVICE_1179FB43 = 0x1179FB43,
    SUBDEVICE_1179FB91 = 0x1179FB91,
    SUBDEVICE_1179FB92 = 0x1179FB92,
    SUBDEVICE_1179FB93 = 0x1179FB93,
    SUBDEVICE_1179FBA2 = 0x1179FBA2,
    SUBDEVICE_1179FBA3 = 0x1179FBA3,
    SUBDEVICE_144DC0C7 = 0x144DC0C7
};



inline const char8* enumToString(PciSubDevice10026841 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026841::NONE:               return "NONE";
        case PciSubDevice10026841::SUBDEVICE_10280561: return "SUBDEVICE_10280561";
        case PciSubDevice10026841::SUBDEVICE_1028056C: return "SUBDEVICE_1028056C";
        case PciSubDevice10026841::SUBDEVICE_1028057F: return "SUBDEVICE_1028057F";
        case PciSubDevice10026841::SUBDEVICE_103C17F1: return "SUBDEVICE_103C17F1";
        case PciSubDevice10026841::SUBDEVICE_103C17F4: return "SUBDEVICE_103C17F4";
        case PciSubDevice10026841::SUBDEVICE_103C1813: return "SUBDEVICE_103C1813";
        case PciSubDevice10026841::SUBDEVICE_103C183A: return "SUBDEVICE_103C183A";
        case PciSubDevice10026841::SUBDEVICE_103C183C: return "SUBDEVICE_103C183C";
        case PciSubDevice10026841::SUBDEVICE_103C183E: return "SUBDEVICE_103C183E";
        case PciSubDevice10026841::SUBDEVICE_103C1840: return "SUBDEVICE_103C1840";
        case PciSubDevice10026841::SUBDEVICE_103C1842: return "SUBDEVICE_103C1842";
        case PciSubDevice10026841::SUBDEVICE_103C1844: return "SUBDEVICE_103C1844";
        case PciSubDevice10026841::SUBDEVICE_1043100A: return "SUBDEVICE_1043100A";
        case PciSubDevice10026841::SUBDEVICE_1043104B: return "SUBDEVICE_1043104B";
        case PciSubDevice10026841::SUBDEVICE_104310DC: return "SUBDEVICE_104310DC";
        case PciSubDevice10026841::SUBDEVICE_10432134: return "SUBDEVICE_10432134";
        case PciSubDevice10026841::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice10026841::SUBDEVICE_11790002: return "SUBDEVICE_11790002";
        case PciSubDevice10026841::SUBDEVICE_1179FB43: return "SUBDEVICE_1179FB43";
        case PciSubDevice10026841::SUBDEVICE_1179FB91: return "SUBDEVICE_1179FB91";
        case PciSubDevice10026841::SUBDEVICE_1179FB92: return "SUBDEVICE_1179FB92";
        case PciSubDevice10026841::SUBDEVICE_1179FB93: return "SUBDEVICE_1179FB93";
        case PciSubDevice10026841::SUBDEVICE_1179FBA2: return "SUBDEVICE_1179FBA2";
        case PciSubDevice10026841::SUBDEVICE_1179FBA3: return "SUBDEVICE_1179FBA3";
        case PciSubDevice10026841::SUBDEVICE_144DC0C7: return "SUBDEVICE_144DC0C7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026841 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026841 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026841::SUBDEVICE_10280561: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_1028056C: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_1028057F: return "Radeon HD 7570M";
        case PciSubDevice10026841::SUBDEVICE_103C17F1: return "Radeon HD 7570M";
        case PciSubDevice10026841::SUBDEVICE_103C17F4: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C1813: return "Radeon HD 7570M";
        case PciSubDevice10026841::SUBDEVICE_103C183A: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C183C: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C183E: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C1840: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C1842: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_103C1844: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_1043100A: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_1043104B: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_104310DC: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_10432134: return "Radeon HD 7650M";
        case PciSubDevice10026841::SUBDEVICE_11790001: return "Radeon HD 7570M";
        case PciSubDevice10026841::SUBDEVICE_11790002: return "Radeon HD 7570M";
        case PciSubDevice10026841::SUBDEVICE_1179FB43: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_1179FB91: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_1179FB92: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_1179FB93: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_1179FBA2: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_1179FBA3: return "Radeon HD 7550M";
        case PciSubDevice10026841::SUBDEVICE_144DC0C7: return "Radeon HD 7550M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026841_H
