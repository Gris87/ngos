// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025046_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025046_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025046: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020004 = 0x10020004,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020014 = 0x10020014,
    SUBDEVICE_10020018 = 0x10020018,
    SUBDEVICE_10020028 = 0x10020028,
    SUBDEVICE_1002002A = 0x1002002A,
    SUBDEVICE_10020048 = 0x10020048,
    SUBDEVICE_10022000 = 0x10022000,
    SUBDEVICE_10022001 = 0x10022001
};



inline const char8* enumToString(PciSubDevice10025046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025046::NONE:               return "NONE";
        case PciSubDevice10025046::SUBDEVICE_10020004: return "SUBDEVICE_10020004";
        case PciSubDevice10025046::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice10025046::SUBDEVICE_10020014: return "SUBDEVICE_10020014";
        case PciSubDevice10025046::SUBDEVICE_10020018: return "SUBDEVICE_10020018";
        case PciSubDevice10025046::SUBDEVICE_10020028: return "SUBDEVICE_10020028";
        case PciSubDevice10025046::SUBDEVICE_1002002A: return "SUBDEVICE_1002002A";
        case PciSubDevice10025046::SUBDEVICE_10020048: return "SUBDEVICE_10020048";
        case PciSubDevice10025046::SUBDEVICE_10022000: return "SUBDEVICE_10022000";
        case PciSubDevice10025046::SUBDEVICE_10022001: return "SUBDEVICE_10022001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025046::SUBDEVICE_10020004: return "Rage Fury Pro";
        case PciSubDevice10025046::SUBDEVICE_10020008: return "Rage Fury Pro/Xpert 2000 Pro";
        case PciSubDevice10025046::SUBDEVICE_10020014: return "Rage Fury Pro";
        case PciSubDevice10025046::SUBDEVICE_10020018: return "Rage Fury Pro/Xpert 2000 Pro";
        case PciSubDevice10025046::SUBDEVICE_10020028: return "Rage 128 Pro AIW AGP";
        case PciSubDevice10025046::SUBDEVICE_1002002A: return "Rage 128 Pro AIW AGP";
        case PciSubDevice10025046::SUBDEVICE_10020048: return "Rage Fury Pro";
        case PciSubDevice10025046::SUBDEVICE_10022000: return "Rage Fury MAXX AGP 4x (TMDS) (VGA device)";
        case PciSubDevice10025046::SUBDEVICE_10022001: return "Rage Fury MAXX AGP 4x (TMDS) (Extra device?!)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025046_H
