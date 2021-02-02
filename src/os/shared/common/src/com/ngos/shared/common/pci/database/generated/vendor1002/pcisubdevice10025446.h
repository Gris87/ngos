// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025446_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025446_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025446: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020004 = 0x10020004,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020018 = 0x10020018,
    SUBDEVICE_10020028 = 0x10020028,
    SUBDEVICE_10020029 = 0x10020029,
    SUBDEVICE_1002002A = 0x1002002A,
    SUBDEVICE_1002002B = 0x1002002B,
    SUBDEVICE_10020048 = 0x10020048
};



inline const char8* enumToString(PciSubDevice10025446 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025446::NONE:               return "NONE";
        case PciSubDevice10025446::SUBDEVICE_10020004: return "SUBDEVICE_10020004";
        case PciSubDevice10025446::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice10025446::SUBDEVICE_10020018: return "SUBDEVICE_10020018";
        case PciSubDevice10025446::SUBDEVICE_10020028: return "SUBDEVICE_10020028";
        case PciSubDevice10025446::SUBDEVICE_10020029: return "SUBDEVICE_10020029";
        case PciSubDevice10025446::SUBDEVICE_1002002A: return "SUBDEVICE_1002002A";
        case PciSubDevice10025446::SUBDEVICE_1002002B: return "SUBDEVICE_1002002B";
        case PciSubDevice10025446::SUBDEVICE_10020048: return "SUBDEVICE_10020048";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025446 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025446 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025446::SUBDEVICE_10020004: return "Rage Fury Pro";
        case PciSubDevice10025446::SUBDEVICE_10020008: return "Rage Fury Pro/Xpert 2000 Pro";
        case PciSubDevice10025446::SUBDEVICE_10020018: return "Rage Fury Pro/Xpert 2000 Pro";
        case PciSubDevice10025446::SUBDEVICE_10020028: return "Rage 128 AIW Pro AGP";
        case PciSubDevice10025446::SUBDEVICE_10020029: return "Rage 128 AIW";
        case PciSubDevice10025446::SUBDEVICE_1002002A: return "Rage 128 AIW Pro AGP";
        case PciSubDevice10025446::SUBDEVICE_1002002B: return "Rage 128 AIW";
        case PciSubDevice10025446::SUBDEVICE_10020048: return "Xpert 2000 Pro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025446_H
