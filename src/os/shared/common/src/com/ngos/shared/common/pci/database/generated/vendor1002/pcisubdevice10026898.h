// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026898_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026898_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026898: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B00 = 0x10020B00,
    SUBDEVICE_106B00D0 = 0x106B00D0,
    SUBDEVICE_14628032 = 0x14628032,
    SUBDEVICE_174B6870 = 0x174B6870
};



inline const char8* enumToString(PciSubDevice10026898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026898::NONE:               return "NONE";
        case PciSubDevice10026898::SUBDEVICE_10020B00: return "SUBDEVICE_10020B00";
        case PciSubDevice10026898::SUBDEVICE_106B00D0: return "SUBDEVICE_106B00D0";
        case PciSubDevice10026898::SUBDEVICE_14628032: return "SUBDEVICE_14628032";
        case PciSubDevice10026898::SUBDEVICE_174B6870: return "SUBDEVICE_174B6870";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026898::SUBDEVICE_10020B00: return "Radeon HD 5870 Eyefinity⁶ Edition";
        case PciSubDevice10026898::SUBDEVICE_106B00D0: return "Radeon HD 5870 Mac Edition";
        case PciSubDevice10026898::SUBDEVICE_14628032: return "Radeon HD 5870 1 GB GDDR5";
        case PciSubDevice10026898::SUBDEVICE_174B6870: return "Radeon HD 6870 1600SP Edition";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026898_H
