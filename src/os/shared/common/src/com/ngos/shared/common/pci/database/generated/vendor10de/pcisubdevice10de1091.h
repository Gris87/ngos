// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1091_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1091_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1091: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE088E = 0x10DE088E,
    SUBDEVICE_10DE0891 = 0x10DE0891,
    SUBDEVICE_10DE0974 = 0x10DE0974,
    SUBDEVICE_10DE098D = 0x10DE098D
};



inline const char8* enumToString(PciSubDevice10DE1091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1091::NONE:               return "NONE";
        case PciSubDevice10DE1091::SUBDEVICE_10DE088E: return "SUBDEVICE_10DE088E";
        case PciSubDevice10DE1091::SUBDEVICE_10DE0891: return "SUBDEVICE_10DE0891";
        case PciSubDevice10DE1091::SUBDEVICE_10DE0974: return "SUBDEVICE_10DE0974";
        case PciSubDevice10DE1091::SUBDEVICE_10DE098D: return "SUBDEVICE_10DE098D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1091::SUBDEVICE_10DE088E: return "Tesla X2090";
        case PciSubDevice10DE1091::SUBDEVICE_10DE0891: return "Tesla X2090";
        case PciSubDevice10DE1091::SUBDEVICE_10DE0974: return "Tesla X2090";
        case PciSubDevice10DE1091::SUBDEVICE_10DE098D: return "Tesla X2090";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1091_H
