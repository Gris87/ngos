// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025246_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025246_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025246: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020004 = 0x10020004,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020028 = 0x10020028,
    SUBDEVICE_10020044 = 0x10020044,
    SUBDEVICE_10020068 = 0x10020068,
    SUBDEVICE_10020448 = 0x10020448
};



inline const char8* enumToString(PciSubDevice10025246 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025246::NONE:               return "NONE";
        case PciSubDevice10025246::SUBDEVICE_10020004: return "SUBDEVICE_10020004";
        case PciSubDevice10025246::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice10025246::SUBDEVICE_10020028: return "SUBDEVICE_10020028";
        case PciSubDevice10025246::SUBDEVICE_10020044: return "SUBDEVICE_10020044";
        case PciSubDevice10025246::SUBDEVICE_10020068: return "SUBDEVICE_10020068";
        case PciSubDevice10025246::SUBDEVICE_10020448: return "SUBDEVICE_10020448";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025246 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025246 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025246::SUBDEVICE_10020004: return "Magnum/Xpert 128/Xpert 99";
        case PciSubDevice10025246::SUBDEVICE_10020008: return "Rage 128 AGP 2x";
        case PciSubDevice10025246::SUBDEVICE_10020028: return "Rage 128 AIW AGP";
        case PciSubDevice10025246::SUBDEVICE_10020044: return "Rage Fury/Xpert 128/Xpert 2000";
        case PciSubDevice10025246::SUBDEVICE_10020068: return "Rage 128 AIW AGP";
        case PciSubDevice10025246::SUBDEVICE_10020448: return "Rage Fury";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025246_H
