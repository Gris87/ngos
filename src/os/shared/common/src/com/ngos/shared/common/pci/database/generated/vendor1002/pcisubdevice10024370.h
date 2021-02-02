// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024370_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024370_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024370: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250079 = 0x10250079,
    SUBDEVICE_10250091 = 0x10250091,
    SUBDEVICE_103C2A05 = 0x103C2A05,
    SUBDEVICE_103C308B = 0x103C308B,
    SUBDEVICE_105B0C81 = 0x105B0C81,
    SUBDEVICE_107B0300 = 0x107B0300,
    SUBDEVICE_14620131 = 0x14620131
};



inline const char8* enumToString(PciSubDevice10024370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024370::NONE:               return "NONE";
        case PciSubDevice10024370::SUBDEVICE_10250079: return "SUBDEVICE_10250079";
        case PciSubDevice10024370::SUBDEVICE_10250091: return "SUBDEVICE_10250091";
        case PciSubDevice10024370::SUBDEVICE_103C2A05: return "SUBDEVICE_103C2A05";
        case PciSubDevice10024370::SUBDEVICE_103C308B: return "SUBDEVICE_103C308B";
        case PciSubDevice10024370::SUBDEVICE_105B0C81: return "SUBDEVICE_105B0C81";
        case PciSubDevice10024370::SUBDEVICE_107B0300: return "SUBDEVICE_107B0300";
        case PciSubDevice10024370::SUBDEVICE_14620131: return "SUBDEVICE_14620131";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024370 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024370::SUBDEVICE_10250079: return "Aspire 5024WLMMi";
        case PciSubDevice10024370::SUBDEVICE_10250091: return "Aspire 5032WXMi";
        case PciSubDevice10024370::SUBDEVICE_103C2A05: return "Pavilion t3030.de Desktop PC";
        case PciSubDevice10024370::SUBDEVICE_103C308B: return "MX6125";
        case PciSubDevice10024370::SUBDEVICE_105B0C81: return "Realtek ALC 653";
        case PciSubDevice10024370::SUBDEVICE_107B0300: return "MX6421";
        case PciSubDevice10024370::SUBDEVICE_14620131: return "MS-1013 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024370_H
