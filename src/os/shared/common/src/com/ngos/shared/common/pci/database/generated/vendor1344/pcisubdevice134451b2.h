// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451B2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451B2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice134451B2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13444000 = 0x13444000,
    SUBDEVICE_13445000 = 0x13445000,
    SUBDEVICE_13446000 = 0x13446000
};



inline const char8* enumToString(PciSubDevice134451B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134451B2::NONE:               return "NONE";
        case PciSubDevice134451B2::SUBDEVICE_13444000: return "SUBDEVICE_13444000";
        case PciSubDevice134451B2::SUBDEVICE_13445000: return "SUBDEVICE_13445000";
        case PciSubDevice134451B2::SUBDEVICE_13446000: return "SUBDEVICE_13446000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice134451B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice134451B2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134451B2::SUBDEVICE_13444000: return "3.2TB U.2";
        case PciSubDevice134451B2::SUBDEVICE_13445000: return "6.4 TB U.2";
        case PciSubDevice134451B2::SUBDEVICE_13446000: return "12.8TB U.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451B2_H
