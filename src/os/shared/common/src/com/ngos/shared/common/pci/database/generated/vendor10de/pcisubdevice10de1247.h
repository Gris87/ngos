// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1247_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1247_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1247: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431752 = 0x10431752,
    SUBDEVICE_10432050 = 0x10432050,
    SUBDEVICE_10432051 = 0x10432051,
    SUBDEVICE_1043212A = 0x1043212A,
    SUBDEVICE_1043212B = 0x1043212B,
    SUBDEVICE_1043212C = 0x1043212C,
    SUBDEVICE_152D0930 = 0x152D0930
};



inline const char8* enumToString(PciSubDevice10DE1247 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1247::NONE:               return "NONE";
        case PciSubDevice10DE1247::SUBDEVICE_10431752: return "SUBDEVICE_10431752";
        case PciSubDevice10DE1247::SUBDEVICE_10432050: return "SUBDEVICE_10432050";
        case PciSubDevice10DE1247::SUBDEVICE_10432051: return "SUBDEVICE_10432051";
        case PciSubDevice10DE1247::SUBDEVICE_1043212A: return "SUBDEVICE_1043212A";
        case PciSubDevice10DE1247::SUBDEVICE_1043212B: return "SUBDEVICE_1043212B";
        case PciSubDevice10DE1247::SUBDEVICE_1043212C: return "SUBDEVICE_1043212C";
        case PciSubDevice10DE1247::SUBDEVICE_152D0930: return "SUBDEVICE_152D0930";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1247 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1247 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1247::SUBDEVICE_10431752: return "GeForce GT 555M";
        case PciSubDevice10DE1247::SUBDEVICE_10432050: return "GeForce GT 555M";
        case PciSubDevice10DE1247::SUBDEVICE_10432051: return "GeForce GT 555M";
        case PciSubDevice10DE1247::SUBDEVICE_1043212A: return "GeForce GT 635M";
        case PciSubDevice10DE1247::SUBDEVICE_1043212B: return "GeForce GT 635M";
        case PciSubDevice10DE1247::SUBDEVICE_1043212C: return "GeForce GT 635M";
        case PciSubDevice10DE1247::SUBDEVICE_152D0930: return "GeForce GT 635M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1247_H
