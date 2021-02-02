// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0110_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0110: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10434015 = 0x10434015,
    SUBDEVICE_10434021 = 0x10434021,
    SUBDEVICE_10434031 = 0x10434031,
    SUBDEVICE_10480C60 = 0x10480C60,
    SUBDEVICE_10480C61 = 0x10480C61,
    SUBDEVICE_10480C63 = 0x10480C63,
    SUBDEVICE_10480C64 = 0x10480C64,
    SUBDEVICE_10480C65 = 0x10480C65,
    SUBDEVICE_10480C66 = 0x10480C66,
    SUBDEVICE_10B00001 = 0x10B00001,
    SUBDEVICE_10DE0091 = 0x10DE0091,
    SUBDEVICE_10DE00A1 = 0x10DE00A1,
    SUBDEVICE_14628523 = 0x14628523,
    SUBDEVICE_14628817 = 0x14628817,
    SUBDEVICE_14AF7102 = 0x14AF7102,
    SUBDEVICE_14AF7103 = 0x14AF7103,
    SUBDEVICE_15450023 = 0x15450023,
    SUBDEVICE_15541081 = 0x15541081
};



inline const char8* enumToString(PciSubDevice10DE0110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0110::NONE:               return "NONE";
        case PciSubDevice10DE0110::SUBDEVICE_10434015: return "SUBDEVICE_10434015";
        case PciSubDevice10DE0110::SUBDEVICE_10434021: return "SUBDEVICE_10434021";
        case PciSubDevice10DE0110::SUBDEVICE_10434031: return "SUBDEVICE_10434031";
        case PciSubDevice10DE0110::SUBDEVICE_10480C60: return "SUBDEVICE_10480C60";
        case PciSubDevice10DE0110::SUBDEVICE_10480C61: return "SUBDEVICE_10480C61";
        case PciSubDevice10DE0110::SUBDEVICE_10480C63: return "SUBDEVICE_10480C63";
        case PciSubDevice10DE0110::SUBDEVICE_10480C64: return "SUBDEVICE_10480C64";
        case PciSubDevice10DE0110::SUBDEVICE_10480C65: return "SUBDEVICE_10480C65";
        case PciSubDevice10DE0110::SUBDEVICE_10480C66: return "SUBDEVICE_10480C66";
        case PciSubDevice10DE0110::SUBDEVICE_10B00001: return "SUBDEVICE_10B00001";
        case PciSubDevice10DE0110::SUBDEVICE_10DE0091: return "SUBDEVICE_10DE0091";
        case PciSubDevice10DE0110::SUBDEVICE_10DE00A1: return "SUBDEVICE_10DE00A1";
        case PciSubDevice10DE0110::SUBDEVICE_14628523: return "SUBDEVICE_14628523";
        case PciSubDevice10DE0110::SUBDEVICE_14628817: return "SUBDEVICE_14628817";
        case PciSubDevice10DE0110::SUBDEVICE_14AF7102: return "SUBDEVICE_14AF7102";
        case PciSubDevice10DE0110::SUBDEVICE_14AF7103: return "SUBDEVICE_14AF7103";
        case PciSubDevice10DE0110::SUBDEVICE_15450023: return "SUBDEVICE_15450023";
        case PciSubDevice10DE0110::SUBDEVICE_15541081: return "SUBDEVICE_15541081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0110::SUBDEVICE_10434015: return "AGP-V7100 Pro";
        case PciSubDevice10DE0110::SUBDEVICE_10434021: return "V7100 Deluxe Combo";
        case PciSubDevice10DE0110::SUBDEVICE_10434031: return "V7100 Pro with TV output";
        case PciSubDevice10DE0110::SUBDEVICE_10480C60: return "Gladiac MX";
        case PciSubDevice10DE0110::SUBDEVICE_10480C61: return "Gladiac 511PCI";
        case PciSubDevice10DE0110::SUBDEVICE_10480C63: return "Gladiac 511TV-OUT 32MB";
        case PciSubDevice10DE0110::SUBDEVICE_10480C64: return "Gladiac 511TV-OUT 64MB";
        case PciSubDevice10DE0110::SUBDEVICE_10480C65: return "Gladiac 511TWIN";
        case PciSubDevice10DE0110::SUBDEVICE_10480C66: return "Gladiac 311";
        case PciSubDevice10DE0110::SUBDEVICE_10B00001: return "GeForce2 MX Jumbo TV";
        case PciSubDevice10DE0110::SUBDEVICE_10DE0091: return "Dell OEM GeForce 2 MX 400";
        case PciSubDevice10DE0110::SUBDEVICE_10DE00A1: return "Apple OEM GeForce2 MX";
        case PciSubDevice10DE0110::SUBDEVICE_14628523: return "MS-8852";
        case PciSubDevice10DE0110::SUBDEVICE_14628817: return "MSI GeForce2 MX400 Pro32S [MS-8817]";
        case PciSubDevice10DE0110::SUBDEVICE_14AF7102: return "3D Prophet II MX";
        case PciSubDevice10DE0110::SUBDEVICE_14AF7103: return "3D Prophet II MX Dual-Display";
        case PciSubDevice10DE0110::SUBDEVICE_15450023: return "Xtasy Rev. B2";
        case PciSubDevice10DE0110::SUBDEVICE_15541081: return "MVGA-NVG11AM(400)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0110_H
