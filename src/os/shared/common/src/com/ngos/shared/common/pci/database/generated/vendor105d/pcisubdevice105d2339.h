// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D2339_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D2339_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105D2339: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105D0000 = 0x105D0000,
    SUBDEVICE_105D0001 = 0x105D0001,
    SUBDEVICE_105D0002 = 0x105D0002,
    SUBDEVICE_105D0003 = 0x105D0003,
    SUBDEVICE_105D0004 = 0x105D0004,
    SUBDEVICE_105D0005 = 0x105D0005,
    SUBDEVICE_105D0006 = 0x105D0006,
    SUBDEVICE_105D0007 = 0x105D0007,
    SUBDEVICE_105D0008 = 0x105D0008,
    SUBDEVICE_105D0009 = 0x105D0009,
    SUBDEVICE_105D000A = 0x105D000A,
    SUBDEVICE_105D000B = 0x105D000B,
    SUBDEVICE_11A4000A = 0x11A4000A,
    SUBDEVICE_13CC0000 = 0x13CC0000,
    SUBDEVICE_13CC0004 = 0x13CC0004,
    SUBDEVICE_13CC0005 = 0x13CC0005,
    SUBDEVICE_13CC0006 = 0x13CC0006,
    SUBDEVICE_13CC0008 = 0x13CC0008,
    SUBDEVICE_13CC0009 = 0x13CC0009,
    SUBDEVICE_13CC000A = 0x13CC000A,
    SUBDEVICE_13CC000C = 0x13CC000C
};



inline const char8* enumToString(PciSubDevice105D2339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D2339::NONE:               return "NONE";
        case PciSubDevice105D2339::SUBDEVICE_105D0000: return "SUBDEVICE_105D0000";
        case PciSubDevice105D2339::SUBDEVICE_105D0001: return "SUBDEVICE_105D0001";
        case PciSubDevice105D2339::SUBDEVICE_105D0002: return "SUBDEVICE_105D0002";
        case PciSubDevice105D2339::SUBDEVICE_105D0003: return "SUBDEVICE_105D0003";
        case PciSubDevice105D2339::SUBDEVICE_105D0004: return "SUBDEVICE_105D0004";
        case PciSubDevice105D2339::SUBDEVICE_105D0005: return "SUBDEVICE_105D0005";
        case PciSubDevice105D2339::SUBDEVICE_105D0006: return "SUBDEVICE_105D0006";
        case PciSubDevice105D2339::SUBDEVICE_105D0007: return "SUBDEVICE_105D0007";
        case PciSubDevice105D2339::SUBDEVICE_105D0008: return "SUBDEVICE_105D0008";
        case PciSubDevice105D2339::SUBDEVICE_105D0009: return "SUBDEVICE_105D0009";
        case PciSubDevice105D2339::SUBDEVICE_105D000A: return "SUBDEVICE_105D000A";
        case PciSubDevice105D2339::SUBDEVICE_105D000B: return "SUBDEVICE_105D000B";
        case PciSubDevice105D2339::SUBDEVICE_11A4000A: return "SUBDEVICE_11A4000A";
        case PciSubDevice105D2339::SUBDEVICE_13CC0000: return "SUBDEVICE_13CC0000";
        case PciSubDevice105D2339::SUBDEVICE_13CC0004: return "SUBDEVICE_13CC0004";
        case PciSubDevice105D2339::SUBDEVICE_13CC0005: return "SUBDEVICE_13CC0005";
        case PciSubDevice105D2339::SUBDEVICE_13CC0006: return "SUBDEVICE_13CC0006";
        case PciSubDevice105D2339::SUBDEVICE_13CC0008: return "SUBDEVICE_13CC0008";
        case PciSubDevice105D2339::SUBDEVICE_13CC0009: return "SUBDEVICE_13CC0009";
        case PciSubDevice105D2339::SUBDEVICE_13CC000A: return "SUBDEVICE_13CC000A";
        case PciSubDevice105D2339::SUBDEVICE_13CC000C: return "SUBDEVICE_13CC000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105D2339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105D2339 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105D2339::SUBDEVICE_105D0000: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0001: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0002: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0003: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0004: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0005: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0006: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0007: return "Imagine 128 series 2 4Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0008: return "Imagine 128 series 2e 4Mb DRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D0009: return "Imagine 128 series 2e 4Mb DRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D000A: return "Imagine 128 series 2 8Mb VRAM";
        case PciSubDevice105D2339::SUBDEVICE_105D000B: return "Imagine 128 series 2 8Mb H-VRAM";
        case PciSubDevice105D2339::SUBDEVICE_11A4000A: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0000: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0004: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0005: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0006: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0008: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC0009: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC000A: return "Metheus 5 Megapixel";
        case PciSubDevice105D2339::SUBDEVICE_13CC000C: return "Metheus 5 Megapixel";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCISUBDEVICE105D2339_H
