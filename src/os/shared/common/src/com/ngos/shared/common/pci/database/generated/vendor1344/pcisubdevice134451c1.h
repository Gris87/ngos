// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice134451C1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13441100 = 0x13441100,
    SUBDEVICE_13442000 = 0x13442000,
    SUBDEVICE_13442100 = 0x13442100,
    SUBDEVICE_13442600 = 0x13442600,
    SUBDEVICE_13442B00 = 0x13442B00,
    SUBDEVICE_13442D00 = 0x13442D00,
    SUBDEVICE_13443000 = 0x13443000,
    SUBDEVICE_13443E00 = 0x13443E00,
    SUBDEVICE_13443F00 = 0x13443F00,
    SUBDEVICE_13444000 = 0x13444000,
    SUBDEVICE_13445000 = 0x13445000
};



inline const char8* enumToString(PciSubDevice134451C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134451C1::NONE:               return "NONE";
        case PciSubDevice134451C1::SUBDEVICE_13441100: return "SUBDEVICE_13441100";
        case PciSubDevice134451C1::SUBDEVICE_13442000: return "SUBDEVICE_13442000";
        case PciSubDevice134451C1::SUBDEVICE_13442100: return "SUBDEVICE_13442100";
        case PciSubDevice134451C1::SUBDEVICE_13442600: return "SUBDEVICE_13442600";
        case PciSubDevice134451C1::SUBDEVICE_13442B00: return "SUBDEVICE_13442B00";
        case PciSubDevice134451C1::SUBDEVICE_13442D00: return "SUBDEVICE_13442D00";
        case PciSubDevice134451C1::SUBDEVICE_13443000: return "SUBDEVICE_13443000";
        case PciSubDevice134451C1::SUBDEVICE_13443E00: return "SUBDEVICE_13443E00";
        case PciSubDevice134451C1::SUBDEVICE_13443F00: return "SUBDEVICE_13443F00";
        case PciSubDevice134451C1::SUBDEVICE_13444000: return "SUBDEVICE_13444000";
        case PciSubDevice134451C1::SUBDEVICE_13445000: return "SUBDEVICE_13445000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice134451C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice134451C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice134451C1::SUBDEVICE_13441100: return "M.2 400GB";
        case PciSubDevice134451C1::SUBDEVICE_13442000: return "U.3 800GB";
        case PciSubDevice134451C1::SUBDEVICE_13442100: return "M.2 800GB";
        case PciSubDevice134451C1::SUBDEVICE_13442600: return "E1.S 800GB";
        case PciSubDevice134451C1::SUBDEVICE_13442B00: return "M.2 1600GB";
        case PciSubDevice134451C1::SUBDEVICE_13442D00: return "E1.S 1600GB";
        case PciSubDevice134451C1::SUBDEVICE_13443000: return "U.3 1600GB";
        case PciSubDevice134451C1::SUBDEVICE_13443E00: return "M.2 3200GB";
        case PciSubDevice134451C1::SUBDEVICE_13443F00: return "E1.S 3200GB";
        case PciSubDevice134451C1::SUBDEVICE_13444000: return "U.3 3200GB";
        case PciSubDevice134451C1::SUBDEVICE_13445000: return "U.3 6400GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCISUBDEVICE134451C1_H
