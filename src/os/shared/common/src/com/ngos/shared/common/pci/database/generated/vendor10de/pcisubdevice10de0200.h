// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0200: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043402F = 0x1043402F,
    SUBDEVICE_10480C70 = 0x10480C70
};



inline const char8* enumToString(PciSubDevice10DE0200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0200::NONE:               return "NONE";
        case PciSubDevice10DE0200::SUBDEVICE_1043402F: return "SUBDEVICE_1043402F";
        case PciSubDevice10DE0200::SUBDEVICE_10480C70: return "SUBDEVICE_10480C70";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0200::SUBDEVICE_1043402F: return "AGP-V8200 DDR";
        case PciSubDevice10DE0200::SUBDEVICE_10480C70: return "GLADIAC 920";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0200_H
