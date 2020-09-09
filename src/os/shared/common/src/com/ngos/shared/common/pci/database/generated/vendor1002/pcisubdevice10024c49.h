// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C49_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C49_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C49: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020004 = 0x10020004,
    SUBDEVICE_10020040 = 0x10020040,
    SUBDEVICE_10020044 = 0x10020044,
    SUBDEVICE_10024C49 = 0x10024C49
};



inline const char8* enumToString(PciSubDevice10024C49 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C49::NONE:               return "NONE";
        case PciSubDevice10024C49::SUBDEVICE_10020004: return "SUBDEVICE_10020004";
        case PciSubDevice10024C49::SUBDEVICE_10020040: return "SUBDEVICE_10020040";
        case PciSubDevice10024C49::SUBDEVICE_10020044: return "SUBDEVICE_10020044";
        case PciSubDevice10024C49::SUBDEVICE_10024C49: return "SUBDEVICE_10024C49";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C49 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C49 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C49::SUBDEVICE_10020004: return "Rage LT Pro";
        case PciSubDevice10024C49::SUBDEVICE_10020040: return "Rage LT Pro";
        case PciSubDevice10024C49::SUBDEVICE_10020044: return "Rage LT Pro";
        case PciSubDevice10024C49::SUBDEVICE_10024C49: return "Rage LT Pro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C49_H
