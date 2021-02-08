// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0FD2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028054F = 0x1028054F,
    SUBDEVICE_1028055F = 0x1028055F,
    SUBDEVICE_10280595 = 0x10280595,
    SUBDEVICE_102805B2 = 0x102805B2
};



inline const char8* enumToString(PciSubDevice10DE0FD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FD2::NONE:               return "NONE";
        case PciSubDevice10DE0FD2::SUBDEVICE_1028054F: return "SUBDEVICE_1028054F";
        case PciSubDevice10DE0FD2::SUBDEVICE_1028055F: return "SUBDEVICE_1028055F";
        case PciSubDevice10DE0FD2::SUBDEVICE_10280595: return "SUBDEVICE_10280595";
        case PciSubDevice10DE0FD2::SUBDEVICE_102805B2: return "SUBDEVICE_102805B2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0FD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0FD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0FD2::SUBDEVICE_1028054F: return "GeForce GT 640M";
        case PciSubDevice10DE0FD2::SUBDEVICE_1028055F: return "GeForce GT 640M";
        case PciSubDevice10DE0FD2::SUBDEVICE_10280595: return "GeForce GT 640M LE";
        case PciSubDevice10DE0FD2::SUBDEVICE_102805B2: return "GeForce GT 640M LE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0FD2_H
