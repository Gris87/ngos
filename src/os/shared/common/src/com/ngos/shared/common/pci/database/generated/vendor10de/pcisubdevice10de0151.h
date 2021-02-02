// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0151_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0151_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0151: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043405F = 0x1043405F,
    SUBDEVICE_14625506 = 0x14625506,
    SUBDEVICE_14628364 = 0x14628364
};



inline const char8* enumToString(PciSubDevice10DE0151 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0151::NONE:               return "NONE";
        case PciSubDevice10DE0151::SUBDEVICE_1043405F: return "SUBDEVICE_1043405F";
        case PciSubDevice10DE0151::SUBDEVICE_14625506: return "SUBDEVICE_14625506";
        case PciSubDevice10DE0151::SUBDEVICE_14628364: return "SUBDEVICE_14628364";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0151 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0151 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0151::SUBDEVICE_1043405F: return "V7700Ti";
        case PciSubDevice10DE0151::SUBDEVICE_14625506: return "Creative 3D Blaster GeForce2 Titanium";
        case PciSubDevice10DE0151::SUBDEVICE_14628364: return "MS-8836";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0151_H
