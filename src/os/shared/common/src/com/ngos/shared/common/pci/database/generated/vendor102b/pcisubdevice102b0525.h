// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0525_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0525_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0525: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B16F = 0x0E11B16F,
    SUBDEVICE_102B0328 = 0x102B0328,
    SUBDEVICE_102B0338 = 0x102B0338,
    SUBDEVICE_102B0378 = 0x102B0378,
    SUBDEVICE_102B0541 = 0x102B0541,
    SUBDEVICE_102B0542 = 0x102B0542,
    SUBDEVICE_102B0543 = 0x102B0543,
    SUBDEVICE_102B0641 = 0x102B0641,
    SUBDEVICE_102B0642 = 0x102B0642,
    SUBDEVICE_102B0643 = 0x102B0643,
    SUBDEVICE_102B07C0 = 0x102B07C0,
    SUBDEVICE_102B07C1 = 0x102B07C1,
    SUBDEVICE_102B0D41 = 0x102B0D41,
    SUBDEVICE_102B0D42 = 0x102B0D42,
    SUBDEVICE_102B0D43 = 0x102B0D43,
    SUBDEVICE_102B0E00 = 0x102B0E00,
    SUBDEVICE_102B0E01 = 0x102B0E01,
    SUBDEVICE_102B0E02 = 0x102B0E02,
    SUBDEVICE_102B0E03 = 0x102B0E03,
    SUBDEVICE_102B0F80 = 0x102B0F80,
    SUBDEVICE_102B0F81 = 0x102B0F81,
    SUBDEVICE_102B0F82 = 0x102B0F82,
    SUBDEVICE_102B0F83 = 0x102B0F83,
    SUBDEVICE_102B19D8 = 0x102B19D8,
    SUBDEVICE_102B19F8 = 0x102B19F8,
    SUBDEVICE_102B2159 = 0x102B2159,
    SUBDEVICE_102B2179 = 0x102B2179,
    SUBDEVICE_102B217D = 0x102B217D,
    SUBDEVICE_102B23C0 = 0x102B23C0,
    SUBDEVICE_102B23C1 = 0x102B23C1,
    SUBDEVICE_102B23C2 = 0x102B23C2,
    SUBDEVICE_102B23C3 = 0x102B23C3,
    SUBDEVICE_102B2F58 = 0x102B2F58,
    SUBDEVICE_102B2F78 = 0x102B2F78,
    SUBDEVICE_102B3693 = 0x102B3693,
    SUBDEVICE_102B5DD0 = 0x102B5DD0,
    SUBDEVICE_102B5F50 = 0x102B5F50,
    SUBDEVICE_102B5F51 = 0x102B5F51,
    SUBDEVICE_102B5F52 = 0x102B5F52,
    SUBDEVICE_102B9010 = 0x102B9010,
    SUBDEVICE_14580400 = 0x14580400,
    SUBDEVICE_17050001 = 0x17050001,
    SUBDEVICE_17050002 = 0x17050002,
    SUBDEVICE_17050003 = 0x17050003,
    SUBDEVICE_17050004 = 0x17050004
};



inline const char8* enumToString(PciSubDevice102B0525 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0525::NONE:               return "NONE";
        case PciSubDevice102B0525::SUBDEVICE_0E11B16F: return "SUBDEVICE_0E11B16F";
        case PciSubDevice102B0525::SUBDEVICE_102B0328: return "SUBDEVICE_102B0328";
        case PciSubDevice102B0525::SUBDEVICE_102B0338: return "SUBDEVICE_102B0338";
        case PciSubDevice102B0525::SUBDEVICE_102B0378: return "SUBDEVICE_102B0378";
        case PciSubDevice102B0525::SUBDEVICE_102B0541: return "SUBDEVICE_102B0541";
        case PciSubDevice102B0525::SUBDEVICE_102B0542: return "SUBDEVICE_102B0542";
        case PciSubDevice102B0525::SUBDEVICE_102B0543: return "SUBDEVICE_102B0543";
        case PciSubDevice102B0525::SUBDEVICE_102B0641: return "SUBDEVICE_102B0641";
        case PciSubDevice102B0525::SUBDEVICE_102B0642: return "SUBDEVICE_102B0642";
        case PciSubDevice102B0525::SUBDEVICE_102B0643: return "SUBDEVICE_102B0643";
        case PciSubDevice102B0525::SUBDEVICE_102B07C0: return "SUBDEVICE_102B07C0";
        case PciSubDevice102B0525::SUBDEVICE_102B07C1: return "SUBDEVICE_102B07C1";
        case PciSubDevice102B0525::SUBDEVICE_102B0D41: return "SUBDEVICE_102B0D41";
        case PciSubDevice102B0525::SUBDEVICE_102B0D42: return "SUBDEVICE_102B0D42";
        case PciSubDevice102B0525::SUBDEVICE_102B0D43: return "SUBDEVICE_102B0D43";
        case PciSubDevice102B0525::SUBDEVICE_102B0E00: return "SUBDEVICE_102B0E00";
        case PciSubDevice102B0525::SUBDEVICE_102B0E01: return "SUBDEVICE_102B0E01";
        case PciSubDevice102B0525::SUBDEVICE_102B0E02: return "SUBDEVICE_102B0E02";
        case PciSubDevice102B0525::SUBDEVICE_102B0E03: return "SUBDEVICE_102B0E03";
        case PciSubDevice102B0525::SUBDEVICE_102B0F80: return "SUBDEVICE_102B0F80";
        case PciSubDevice102B0525::SUBDEVICE_102B0F81: return "SUBDEVICE_102B0F81";
        case PciSubDevice102B0525::SUBDEVICE_102B0F82: return "SUBDEVICE_102B0F82";
        case PciSubDevice102B0525::SUBDEVICE_102B0F83: return "SUBDEVICE_102B0F83";
        case PciSubDevice102B0525::SUBDEVICE_102B19D8: return "SUBDEVICE_102B19D8";
        case PciSubDevice102B0525::SUBDEVICE_102B19F8: return "SUBDEVICE_102B19F8";
        case PciSubDevice102B0525::SUBDEVICE_102B2159: return "SUBDEVICE_102B2159";
        case PciSubDevice102B0525::SUBDEVICE_102B2179: return "SUBDEVICE_102B2179";
        case PciSubDevice102B0525::SUBDEVICE_102B217D: return "SUBDEVICE_102B217D";
        case PciSubDevice102B0525::SUBDEVICE_102B23C0: return "SUBDEVICE_102B23C0";
        case PciSubDevice102B0525::SUBDEVICE_102B23C1: return "SUBDEVICE_102B23C1";
        case PciSubDevice102B0525::SUBDEVICE_102B23C2: return "SUBDEVICE_102B23C2";
        case PciSubDevice102B0525::SUBDEVICE_102B23C3: return "SUBDEVICE_102B23C3";
        case PciSubDevice102B0525::SUBDEVICE_102B2F58: return "SUBDEVICE_102B2F58";
        case PciSubDevice102B0525::SUBDEVICE_102B2F78: return "SUBDEVICE_102B2F78";
        case PciSubDevice102B0525::SUBDEVICE_102B3693: return "SUBDEVICE_102B3693";
        case PciSubDevice102B0525::SUBDEVICE_102B5DD0: return "SUBDEVICE_102B5DD0";
        case PciSubDevice102B0525::SUBDEVICE_102B5F50: return "SUBDEVICE_102B5F50";
        case PciSubDevice102B0525::SUBDEVICE_102B5F51: return "SUBDEVICE_102B5F51";
        case PciSubDevice102B0525::SUBDEVICE_102B5F52: return "SUBDEVICE_102B5F52";
        case PciSubDevice102B0525::SUBDEVICE_102B9010: return "SUBDEVICE_102B9010";
        case PciSubDevice102B0525::SUBDEVICE_14580400: return "SUBDEVICE_14580400";
        case PciSubDevice102B0525::SUBDEVICE_17050001: return "SUBDEVICE_17050001";
        case PciSubDevice102B0525::SUBDEVICE_17050002: return "SUBDEVICE_17050002";
        case PciSubDevice102B0525::SUBDEVICE_17050003: return "SUBDEVICE_17050003";
        case PciSubDevice102B0525::SUBDEVICE_17050004: return "SUBDEVICE_17050004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0525 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0525 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0525::SUBDEVICE_0E11B16F: return "MGA-G400 AGP";
        case PciSubDevice102B0525::SUBDEVICE_102B0328: return "Millennium G400 16Mb SDRAM";
        case PciSubDevice102B0525::SUBDEVICE_102B0338: return "Millennium G400 16Mb SDRAM";
        case PciSubDevice102B0525::SUBDEVICE_102B0378: return "Millennium G400 32Mb SDRAM";
        case PciSubDevice102B0525::SUBDEVICE_102B0541: return "Millennium G450 Dual Head";
        case PciSubDevice102B0525::SUBDEVICE_102B0542: return "Millennium G450 Dual Head LX";
        case PciSubDevice102B0525::SUBDEVICE_102B0543: return "Millennium G450 Single Head LX";
        case PciSubDevice102B0525::SUBDEVICE_102B0641: return "Millennium G450 32Mb SDRAM Dual Head";
        case PciSubDevice102B0525::SUBDEVICE_102B0642: return "Millennium G450 32Mb SDRAM Dual Head LX";
        case PciSubDevice102B0525::SUBDEVICE_102B0643: return "Millennium G450 32Mb SDRAM Single Head LX";
        case PciSubDevice102B0525::SUBDEVICE_102B07C0: return "Millennium G450 Dual Head LE";
        case PciSubDevice102B0525::SUBDEVICE_102B07C1: return "Millennium G450 SDR Dual Head LE";
        case PciSubDevice102B0525::SUBDEVICE_102B0D41: return "Millennium G450 Dual Head PCI";
        case PciSubDevice102B0525::SUBDEVICE_102B0D42: return "Millennium G450 Dual Head LX PCI";
        case PciSubDevice102B0525::SUBDEVICE_102B0D43: return "Millennium G450 32Mb Dual Head PCI";
        case PciSubDevice102B0525::SUBDEVICE_102B0E00: return "Marvel G450 eTV";
        case PciSubDevice102B0525::SUBDEVICE_102B0E01: return "Marvel G450 eTV";
        case PciSubDevice102B0525::SUBDEVICE_102B0E02: return "Marvel G450 eTV";
        case PciSubDevice102B0525::SUBDEVICE_102B0E03: return "Marvel G450 eTV";
        case PciSubDevice102B0525::SUBDEVICE_102B0F80: return "Millennium G450 Low Profile";
        case PciSubDevice102B0525::SUBDEVICE_102B0F81: return "Millennium G450 Low Profile";
        case PciSubDevice102B0525::SUBDEVICE_102B0F82: return "Millennium G450 Low Profile DVI";
        case PciSubDevice102B0525::SUBDEVICE_102B0F83: return "Millennium G450 Low Profile DVI";
        case PciSubDevice102B0525::SUBDEVICE_102B19D8: return "Millennium G400 16Mb SGRAM";
        case PciSubDevice102B0525::SUBDEVICE_102B19F8: return "Millennium G400 32Mb SGRAM";
        case PciSubDevice102B0525::SUBDEVICE_102B2159: return "Millennium G400 Dual Head 16Mb";
        case PciSubDevice102B0525::SUBDEVICE_102B2179: return "Millennium G400 MAX/Dual Head 32Mb";
        case PciSubDevice102B0525::SUBDEVICE_102B217D: return "Millennium G400 Dual Head Max";
        case PciSubDevice102B0525::SUBDEVICE_102B23C0: return "Millennium G450";
        case PciSubDevice102B0525::SUBDEVICE_102B23C1: return "Millennium G450";
        case PciSubDevice102B0525::SUBDEVICE_102B23C2: return "Millennium G450 DVI";
        case PciSubDevice102B0525::SUBDEVICE_102B23C3: return "Millennium G450 DVI";
        case PciSubDevice102B0525::SUBDEVICE_102B2F58: return "Millennium G400";
        case PciSubDevice102B0525::SUBDEVICE_102B2F78: return "Millennium G400";
        case PciSubDevice102B0525::SUBDEVICE_102B3693: return "Marvel G400 AGP";
        case PciSubDevice102B0525::SUBDEVICE_102B5DD0: return "4Sight II";
        case PciSubDevice102B0525::SUBDEVICE_102B5F50: return "4Sight II";
        case PciSubDevice102B0525::SUBDEVICE_102B5F51: return "4Sight II";
        case PciSubDevice102B0525::SUBDEVICE_102B5F52: return "4Sight II";
        case PciSubDevice102B0525::SUBDEVICE_102B9010: return "Millennium G400 Dual Head";
        case PciSubDevice102B0525::SUBDEVICE_14580400: return "GA-G400";
        case PciSubDevice102B0525::SUBDEVICE_17050001: return "Millennium G450 32MB SGRAM";
        case PciSubDevice102B0525::SUBDEVICE_17050002: return "Millennium G450 16MB SGRAM";
        case PciSubDevice102B0525::SUBDEVICE_17050003: return "Millennium G450 32MB";
        case PciSubDevice102B0525::SUBDEVICE_17050004: return "Millennium G450 16MB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0525_H
