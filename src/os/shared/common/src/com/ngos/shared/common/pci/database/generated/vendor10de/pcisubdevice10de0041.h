// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0041_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0041_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0041: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043817B = 0x1043817B,
    SUBDEVICE_107D2992 = 0x107D2992,
    SUBDEVICE_1458310F = 0x1458310F
};



inline const char8* enumToString(PciSubDevice10DE0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0041::NONE:               return "NONE";
        case PciSubDevice10DE0041::SUBDEVICE_1043817B: return "SUBDEVICE_1043817B";
        case PciSubDevice10DE0041::SUBDEVICE_107D2992: return "SUBDEVICE_107D2992";
        case PciSubDevice10DE0041::SUBDEVICE_1458310F: return "SUBDEVICE_1458310F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0041 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0041::SUBDEVICE_1043817B: return "V9999 Gamer Edition";
        case PciSubDevice10DE0041::SUBDEVICE_107D2992: return "WinFast A400";
        case PciSubDevice10DE0041::SUBDEVICE_1458310F: return "Geforce 6800 GV-N6812";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0041_H
