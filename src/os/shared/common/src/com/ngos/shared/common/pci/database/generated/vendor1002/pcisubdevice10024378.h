// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024378_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024378_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024378: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250080 = 0x10250080,
    SUBDEVICE_103C308B = 0x103C308B,
    SUBDEVICE_14620131 = 0x14620131
};



inline const char8* enumToString(PciSubDevice10024378 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024378::NONE:               return "NONE";
        case PciSubDevice10024378::SUBDEVICE_10250080: return "SUBDEVICE_10250080";
        case PciSubDevice10024378::SUBDEVICE_103C308B: return "SUBDEVICE_103C308B";
        case PciSubDevice10024378::SUBDEVICE_14620131: return "SUBDEVICE_14620131";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024378 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024378 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024378::SUBDEVICE_10250080: return "Aspire 5024WLMMi";
        case PciSubDevice10024378::SUBDEVICE_103C308B: return "MX6125";
        case PciSubDevice10024378::SUBDEVICE_14620131: return "MS-1013 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024378_H
