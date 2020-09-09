// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000040_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000040_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000040: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000033 = 0x10000033,
    SUBDEVICE_10000066 = 0x10000066
};



inline const char8* enumToString(PciSubDevice10000040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000040::NONE:               return "NONE";
        case PciSubDevice10000040::SUBDEVICE_10000033: return "SUBDEVICE_10000033";
        case PciSubDevice10000040::SUBDEVICE_10000066: return "SUBDEVICE_10000066";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000040::SUBDEVICE_10000033: return "MegaRAID SCSI 320-2XR";
        case PciSubDevice10000040::SUBDEVICE_10000066: return "MegaRAID SCSI 320-2XRWS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000040_H
