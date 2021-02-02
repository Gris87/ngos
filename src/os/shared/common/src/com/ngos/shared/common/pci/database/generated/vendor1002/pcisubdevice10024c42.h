// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C42_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C42_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C42: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0E7 = 0x0E11B0E7,
    SUBDEVICE_0E11B0E8 = 0x0E11B0E8,
    SUBDEVICE_0E11B10E = 0x0E11B10E,
    SUBDEVICE_10020040 = 0x10020040,
    SUBDEVICE_10020044 = 0x10020044,
    SUBDEVICE_10024C42 = 0x10024C42,
    SUBDEVICE_10028001 = 0x10028001,
    SUBDEVICE_10280085 = 0x10280085
};



inline const char8* enumToString(PciSubDevice10024C42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C42::NONE:               return "NONE";
        case PciSubDevice10024C42::SUBDEVICE_0E11B0E7: return "SUBDEVICE_0E11B0E7";
        case PciSubDevice10024C42::SUBDEVICE_0E11B0E8: return "SUBDEVICE_0E11B0E8";
        case PciSubDevice10024C42::SUBDEVICE_0E11B10E: return "SUBDEVICE_0E11B10E";
        case PciSubDevice10024C42::SUBDEVICE_10020040: return "SUBDEVICE_10020040";
        case PciSubDevice10024C42::SUBDEVICE_10020044: return "SUBDEVICE_10020044";
        case PciSubDevice10024C42::SUBDEVICE_10024C42: return "SUBDEVICE_10024C42";
        case PciSubDevice10024C42::SUBDEVICE_10028001: return "SUBDEVICE_10028001";
        case PciSubDevice10024C42::SUBDEVICE_10280085: return "SUBDEVICE_10280085";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C42::SUBDEVICE_0E11B0E7: return "Rage LT Pro (Compaq Presario 5240)";
        case PciSubDevice10024C42::SUBDEVICE_0E11B0E8: return "Rage 3D LT Pro";
        case PciSubDevice10024C42::SUBDEVICE_0E11B10E: return "3D Rage LT Pro (Compaq Armada 1750)";
        case PciSubDevice10024C42::SUBDEVICE_10020040: return "Rage LT Pro AGP 2X";
        case PciSubDevice10024C42::SUBDEVICE_10020044: return "Rage LT Pro AGP 2X";
        case PciSubDevice10024C42::SUBDEVICE_10024C42: return "Rage LT Pro AGP 2X";
        case PciSubDevice10024C42::SUBDEVICE_10028001: return "Rage LT Pro AGP 2X";
        case PciSubDevice10024C42::SUBDEVICE_10280085: return "Rage 3D LT Pro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C42_H
