// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025950_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025950_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025950: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250080 = 0x10250080,
    SUBDEVICE_103C280A = 0x103C280A,
    SUBDEVICE_103C2A20 = 0x103C2A20,
    SUBDEVICE_103C308B = 0x103C308B,
    SUBDEVICE_14620131 = 0x14620131,
    SUBDEVICE_14627217 = 0x14627217
};



inline const char8* enumToString(PciSubDevice10025950 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025950::NONE:               return "NONE";
        case PciSubDevice10025950::SUBDEVICE_10250080: return "SUBDEVICE_10250080";
        case PciSubDevice10025950::SUBDEVICE_103C280A: return "SUBDEVICE_103C280A";
        case PciSubDevice10025950::SUBDEVICE_103C2A20: return "SUBDEVICE_103C2A20";
        case PciSubDevice10025950::SUBDEVICE_103C308B: return "SUBDEVICE_103C308B";
        case PciSubDevice10025950::SUBDEVICE_14620131: return "SUBDEVICE_14620131";
        case PciSubDevice10025950::SUBDEVICE_14627217: return "SUBDEVICE_14627217";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025950 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025950 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025950::SUBDEVICE_10250080: return "Aspire 5024WLMMi";
        case PciSubDevice10025950::SUBDEVICE_103C280A: return "DC5750 Microtower";
        case PciSubDevice10025950::SUBDEVICE_103C2A20: return "Pavilion t3030.de Desktop PC";
        case PciSubDevice10025950::SUBDEVICE_103C308B: return "MX6125";
        case PciSubDevice10025950::SUBDEVICE_14620131: return "MS-1013 Notebook";
        case PciSubDevice10025950::SUBDEVICE_14627217: return "Aspire L250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025950_H
