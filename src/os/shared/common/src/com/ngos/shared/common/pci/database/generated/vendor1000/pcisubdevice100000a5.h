// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000A5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000A5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000A5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10004600 = 0x10004600,
    SUBDEVICE_10004610 = 0x10004610,
    SUBDEVICE_10004620 = 0x10004620,
    SUBDEVICE_10004630 = 0x10004630,
    SUBDEVICE_10004640 = 0x10004640,
    SUBDEVICE_10004650 = 0x10004650,
    SUBDEVICE_10004660 = 0x10004660,
    SUBDEVICE_10004670 = 0x10004670,
    SUBDEVICE_10004680 = 0x10004680,
    SUBDEVICE_10004690 = 0x10004690,
    SUBDEVICE_100046A0 = 0x100046A0,
    SUBDEVICE_100046C0 = 0x100046C0,
    SUBDEVICE_100046D0 = 0x100046D0,
    SUBDEVICE_10282114 = 0x10282114,
    SUBDEVICE_10282115 = 0x10282115,
    SUBDEVICE_10282117 = 0x10282117,
    SUBDEVICE_1028213A = 0x1028213A,
    SUBDEVICE_1028213B = 0x1028213B,
    SUBDEVICE_1028213C = 0x1028213C,
    SUBDEVICE_1028213D = 0x1028213D,
    SUBDEVICE_1028213E = 0x1028213E,
    SUBDEVICE_1028213F = 0x1028213F,
    SUBDEVICE_10282140 = 0x10282140,
    SUBDEVICE_10282141 = 0x10282141,
    SUBDEVICE_10282142 = 0x10282142,
    SUBDEVICE_10282209 = 0x10282209,
    SUBDEVICE_1028220A = 0x1028220A
};



inline const char8* enumToString(PciSubDevice100000A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000A5::NONE:               return "NONE";
        case PciSubDevice100000A5::SUBDEVICE_10004600: return "SUBDEVICE_10004600";
        case PciSubDevice100000A5::SUBDEVICE_10004610: return "SUBDEVICE_10004610";
        case PciSubDevice100000A5::SUBDEVICE_10004620: return "SUBDEVICE_10004620";
        case PciSubDevice100000A5::SUBDEVICE_10004630: return "SUBDEVICE_10004630";
        case PciSubDevice100000A5::SUBDEVICE_10004640: return "SUBDEVICE_10004640";
        case PciSubDevice100000A5::SUBDEVICE_10004650: return "SUBDEVICE_10004650";
        case PciSubDevice100000A5::SUBDEVICE_10004660: return "SUBDEVICE_10004660";
        case PciSubDevice100000A5::SUBDEVICE_10004670: return "SUBDEVICE_10004670";
        case PciSubDevice100000A5::SUBDEVICE_10004680: return "SUBDEVICE_10004680";
        case PciSubDevice100000A5::SUBDEVICE_10004690: return "SUBDEVICE_10004690";
        case PciSubDevice100000A5::SUBDEVICE_100046A0: return "SUBDEVICE_100046A0";
        case PciSubDevice100000A5::SUBDEVICE_100046C0: return "SUBDEVICE_100046C0";
        case PciSubDevice100000A5::SUBDEVICE_100046D0: return "SUBDEVICE_100046D0";
        case PciSubDevice100000A5::SUBDEVICE_10282114: return "SUBDEVICE_10282114";
        case PciSubDevice100000A5::SUBDEVICE_10282115: return "SUBDEVICE_10282115";
        case PciSubDevice100000A5::SUBDEVICE_10282117: return "SUBDEVICE_10282117";
        case PciSubDevice100000A5::SUBDEVICE_1028213A: return "SUBDEVICE_1028213A";
        case PciSubDevice100000A5::SUBDEVICE_1028213B: return "SUBDEVICE_1028213B";
        case PciSubDevice100000A5::SUBDEVICE_1028213C: return "SUBDEVICE_1028213C";
        case PciSubDevice100000A5::SUBDEVICE_1028213D: return "SUBDEVICE_1028213D";
        case PciSubDevice100000A5::SUBDEVICE_1028213E: return "SUBDEVICE_1028213E";
        case PciSubDevice100000A5::SUBDEVICE_1028213F: return "SUBDEVICE_1028213F";
        case PciSubDevice100000A5::SUBDEVICE_10282140: return "SUBDEVICE_10282140";
        case PciSubDevice100000A5::SUBDEVICE_10282141: return "SUBDEVICE_10282141";
        case PciSubDevice100000A5::SUBDEVICE_10282142: return "SUBDEVICE_10282142";
        case PciSubDevice100000A5::SUBDEVICE_10282209: return "SUBDEVICE_10282209";
        case PciSubDevice100000A5::SUBDEVICE_1028220A: return "SUBDEVICE_1028220A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000A5::SUBDEVICE_10004600: return "MegaRAID 9670W-16i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004610: return "MegaRAID 9670-24i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004620: return "MegaRAID 9660-16i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004630: return "MegaRAID 9660-8i8e Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004640: return "eHBA 9600W-16i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004650: return "eHBA 9600W-16e Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004660: return "eHBA 9600-24i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004670: return "eHBA 9600-16i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004680: return "eHBA 9600-16e Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10004690: return "MegaRAID 9620-16i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_100046A0: return "MegaRAID 9660-24i Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_100046C0: return "eHBA 9680W-16e Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_100046D0: return "eHBA 9600-8i8e Tri-Mode Storage Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10282114: return "PERC H965i Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10282115: return "PERC H965i Front";
        case PciSubDevice100000A5::SUBDEVICE_10282117: return "PERC H965i MX";
        case PciSubDevice100000A5::SUBDEVICE_1028213A: return "PERC H965e Adapter";
        case PciSubDevice100000A5::SUBDEVICE_1028213B: return "PERC H765i Adapter";
        case PciSubDevice100000A5::SUBDEVICE_1028213C: return "PERC H765i Front";
        case PciSubDevice100000A5::SUBDEVICE_1028213D: return "PERC H765N Front";
        case PciSubDevice100000A5::SUBDEVICE_1028213E: return "PERC H765i MX";
        case PciSubDevice100000A5::SUBDEVICE_1028213F: return "PERC H365i Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10282140: return "PERC H365i Front";
        case PciSubDevice100000A5::SUBDEVICE_10282141: return "PERC H360 MX";
        case PciSubDevice100000A5::SUBDEVICE_10282142: return "HBA465e Adapter";
        case PciSubDevice100000A5::SUBDEVICE_10282209: return "HBA465i Adapter";
        case PciSubDevice100000A5::SUBDEVICE_1028220A: return "HBA465i Front";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000A5_H
