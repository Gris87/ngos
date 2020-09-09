// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000409_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000409_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000409: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003004 = 0x10003004,
    SUBDEVICE_10003008 = 0x10003008,
    SUBDEVICE_80863008 = 0x80863008,
    SUBDEVICE_80863431 = 0x80863431,
    SUBDEVICE_80863499 = 0x80863499
};



inline const char8* enumToString(PciSubDevice10000409 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000409::NONE:               return "NONE";
        case PciSubDevice10000409::SUBDEVICE_10003004: return "SUBDEVICE_10003004";
        case PciSubDevice10000409::SUBDEVICE_10003008: return "SUBDEVICE_10003008";
        case PciSubDevice10000409::SUBDEVICE_80863008: return "SUBDEVICE_80863008";
        case PciSubDevice10000409::SUBDEVICE_80863431: return "SUBDEVICE_80863431";
        case PciSubDevice10000409::SUBDEVICE_80863499: return "SUBDEVICE_80863499";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000409 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000409 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000409::SUBDEVICE_10003004: return "MegaRAID SATA 300-4X RAID Controller";
        case PciSubDevice10000409::SUBDEVICE_10003008: return "MegaRAID SATA 300-8X RAID Controller";
        case PciSubDevice10000409::SUBDEVICE_80863008: return "MegaRAID RAID Controller SRCS28X";
        case PciSubDevice10000409::SUBDEVICE_80863431: return "MegaRAID RAID Controller Alief SROMBU42E";
        case PciSubDevice10000409::SUBDEVICE_80863499: return "MegaRAID RAID Controller Harwich SROMBU42E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000409_H
