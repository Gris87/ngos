// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3319_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3319_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A3319: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105A3319 = 0x105A3319,
    SUBDEVICE_80863427 = 0x80863427
};



inline const char8* enumToString(PciSubDevice105A3319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3319::NONE:               return "NONE";
        case PciSubDevice105A3319::SUBDEVICE_105A3319: return "SUBDEVICE_105A3319";
        case PciSubDevice105A3319::SUBDEVICE_80863427: return "SUBDEVICE_80863427";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A3319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A3319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3319::SUBDEVICE_105A3319: return "FastTrak S150 TX4 4 port SATA PCI board";
        case PciSubDevice105A3319::SUBDEVICE_80863427: return "S875WP1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3319_H
