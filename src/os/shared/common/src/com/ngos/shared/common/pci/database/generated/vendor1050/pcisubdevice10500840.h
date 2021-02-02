// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10500840_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10500840_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10500840: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10500001 = 0x10500001,
    SUBDEVICE_10500840 = 0x10500840
};



inline const char8* enumToString(PciSubDevice10500840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10500840::NONE:               return "NONE";
        case PciSubDevice10500840::SUBDEVICE_10500001: return "SUBDEVICE_10500001";
        case PciSubDevice10500840::SUBDEVICE_10500840: return "SUBDEVICE_10500840";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10500840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10500840 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10500840::SUBDEVICE_10500001: return "W89C840 Ethernet Adapter";
        case PciSubDevice10500840::SUBDEVICE_10500840: return "W89C840 Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10500840_H
