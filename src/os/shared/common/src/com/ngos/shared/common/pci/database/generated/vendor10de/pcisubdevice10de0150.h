// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0150_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0150_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0150: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10434016 = 0x10434016,
    SUBDEVICE_1043402A = 0x1043402A,
    SUBDEVICE_10480C50 = 0x10480C50,
    SUBDEVICE_10480C52 = 0x10480C52,
    SUBDEVICE_107D2840 = 0x107D2840,
    SUBDEVICE_107D2842 = 0x107D2842,
    SUBDEVICE_10DE002E = 0x10DE002E,
    SUBDEVICE_1462815A = 0x1462815A,
    SUBDEVICE_14628831 = 0x14628831
};



inline const char8* enumToString(PciSubDevice10DE0150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0150::NONE:               return "NONE";
        case PciSubDevice10DE0150::SUBDEVICE_10434016: return "SUBDEVICE_10434016";
        case PciSubDevice10DE0150::SUBDEVICE_1043402A: return "SUBDEVICE_1043402A";
        case PciSubDevice10DE0150::SUBDEVICE_10480C50: return "SUBDEVICE_10480C50";
        case PciSubDevice10DE0150::SUBDEVICE_10480C52: return "SUBDEVICE_10480C52";
        case PciSubDevice10DE0150::SUBDEVICE_107D2840: return "SUBDEVICE_107D2840";
        case PciSubDevice10DE0150::SUBDEVICE_107D2842: return "SUBDEVICE_107D2842";
        case PciSubDevice10DE0150::SUBDEVICE_10DE002E: return "SUBDEVICE_10DE002E";
        case PciSubDevice10DE0150::SUBDEVICE_1462815A: return "SUBDEVICE_1462815A";
        case PciSubDevice10DE0150::SUBDEVICE_14628831: return "SUBDEVICE_14628831";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0150::SUBDEVICE_10434016: return "V7700 AGP Video Card";
        case PciSubDevice10DE0150::SUBDEVICE_1043402A: return "AGP-V7700";
        case PciSubDevice10DE0150::SUBDEVICE_10480C50: return "Gladiac";
        case PciSubDevice10DE0150::SUBDEVICE_10480C52: return "Gladiac-64";
        case PciSubDevice10DE0150::SUBDEVICE_107D2840: return "WinFast GeForce2 GTS with TV output";
        case PciSubDevice10DE0150::SUBDEVICE_107D2842: return "WinFast GeForce 2 Pro";
        case PciSubDevice10DE0150::SUBDEVICE_10DE002E: return "GeForce2 GTS";
        case PciSubDevice10DE0150::SUBDEVICE_1462815A: return "MS-8815";
        case PciSubDevice10DE0150::SUBDEVICE_14628831: return "Creative GeForce2 Pro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0150_H
