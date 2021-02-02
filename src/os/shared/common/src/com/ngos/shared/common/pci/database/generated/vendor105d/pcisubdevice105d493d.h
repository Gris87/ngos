// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D493D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D493D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105D493D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11A4000A = 0x11A4000A,
    SUBDEVICE_11A4000B = 0x11A4000B,
    SUBDEVICE_13CC0002 = 0x13CC0002,
    SUBDEVICE_13CC0003 = 0x13CC0003,
    SUBDEVICE_13CC0007 = 0x13CC0007,
    SUBDEVICE_13CC0008 = 0x13CC0008,
    SUBDEVICE_13CC0009 = 0x13CC0009,
    SUBDEVICE_13CC000A = 0x13CC000A
};



inline const char8* enumToString(PciSubDevice105D493D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D493D::NONE:               return "NONE";
        case PciSubDevice105D493D::SUBDEVICE_11A4000A: return "SUBDEVICE_11A4000A";
        case PciSubDevice105D493D::SUBDEVICE_11A4000B: return "SUBDEVICE_11A4000B";
        case PciSubDevice105D493D::SUBDEVICE_13CC0002: return "SUBDEVICE_13CC0002";
        case PciSubDevice105D493D::SUBDEVICE_13CC0003: return "SUBDEVICE_13CC0003";
        case PciSubDevice105D493D::SUBDEVICE_13CC0007: return "SUBDEVICE_13CC0007";
        case PciSubDevice105D493D::SUBDEVICE_13CC0008: return "SUBDEVICE_13CC0008";
        case PciSubDevice105D493D::SUBDEVICE_13CC0009: return "SUBDEVICE_13CC0009";
        case PciSubDevice105D493D::SUBDEVICE_13CC000A: return "SUBDEVICE_13CC000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105D493D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105D493D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D493D::SUBDEVICE_11A4000A: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_11A4000B: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC0002: return "Metheus 4 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC0003: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC0007: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC0008: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC0009: return "Metheus 5 Megapixel, Dual Head";
        case PciSubDevice105D493D::SUBDEVICE_13CC000A: return "Metheus 5 Megapixel, Dual Head";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D493D_H
