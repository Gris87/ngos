// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026818_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026818_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026818: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B05 = 0x10020B05,
    SUBDEVICE_174B8B04 = 0x174B8B04
};



inline const char8* enumToString(PciSubDevice10026818 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026818::NONE:               return "NONE";
        case PciSubDevice10026818::SUBDEVICE_10020B05: return "SUBDEVICE_10020B05";
        case PciSubDevice10026818::SUBDEVICE_174B8B04: return "SUBDEVICE_174B8B04";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026818 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026818 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026818::SUBDEVICE_10020B05: return "Radeon HD 8870 OEM";
        case PciSubDevice10026818::SUBDEVICE_174B8B04: return "Radeon HD 8860";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026818_H
