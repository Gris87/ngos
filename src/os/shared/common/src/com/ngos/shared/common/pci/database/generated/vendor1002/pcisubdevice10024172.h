// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024172_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024172_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024172: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020003 = 0x10020003,
    SUBDEVICE_10024773 = 0x10024773,
    SUBDEVICE_1043C003 = 0x1043C003,
    SUBDEVICE_1043C01B = 0x1043C01B,
    SUBDEVICE_174B7C28 = 0x174B7C28,
    SUBDEVICE_17874003 = 0x17874003
};



inline const char8* enumToString(PciSubDevice10024172 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024172::NONE:               return "NONE";
        case PciSubDevice10024172::SUBDEVICE_10020003: return "SUBDEVICE_10020003";
        case PciSubDevice10024172::SUBDEVICE_10024773: return "SUBDEVICE_10024773";
        case PciSubDevice10024172::SUBDEVICE_1043C003: return "SUBDEVICE_1043C003";
        case PciSubDevice10024172::SUBDEVICE_1043C01B: return "SUBDEVICE_1043C01B";
        case PciSubDevice10024172::SUBDEVICE_174B7C28: return "SUBDEVICE_174B7C28";
        case PciSubDevice10024172::SUBDEVICE_17874003: return "SUBDEVICE_17874003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024172 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024172 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024172::SUBDEVICE_10020003: return "Radeon 9600XT (Secondary)";
        case PciSubDevice10024172::SUBDEVICE_10024773: return "All-in-Wonder 9600 XT (Secondary)";
        case PciSubDevice10024172::SUBDEVICE_1043C003: return "A9600XT (Secondary)";
        case PciSubDevice10024172::SUBDEVICE_1043C01B: return "A9600XT/TD (Secondary)";
        case PciSubDevice10024172::SUBDEVICE_174B7C28: return "Radeon 9600XT (Secondary)";
        case PciSubDevice10024172::SUBDEVICE_17874003: return "Radeon 9600 XT (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024172_H
