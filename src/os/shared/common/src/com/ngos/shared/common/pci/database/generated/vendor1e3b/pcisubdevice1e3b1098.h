// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B1098_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B1098_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E3B1098: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1E3B0001 = 0x1E3B0001,
    SUBDEVICE_1E3B0002 = 0x1E3B0002,
    SUBDEVICE_1E3B0004 = 0x1E3B0004,
    SUBDEVICE_1E3B0005 = 0x1E3B0005,
    SUBDEVICE_1E3B0009 = 0x1E3B0009,
    SUBDEVICE_1E3B000A = 0x1E3B000A,
    SUBDEVICE_1E3B000C = 0x1E3B000C,
    SUBDEVICE_1E3B000D = 0x1E3B000D,
    SUBDEVICE_1E3B0014 = 0x1E3B0014,
    SUBDEVICE_1E3B0015 = 0x1E3B0015,
    SUBDEVICE_1E3B0021 = 0x1E3B0021,
    SUBDEVICE_1E3B0022 = 0x1E3B0022,
    SUBDEVICE_1E3B0052 = 0x1E3B0052,
    SUBDEVICE_1E3B0053 = 0x1E3B0053,
    SUBDEVICE_1E3B0059 = 0x1E3B0059,
    SUBDEVICE_1E3B0061 = 0x1E3B0061,
    SUBDEVICE_1E3B0062 = 0x1E3B0062,
    SUBDEVICE_1E3B0064 = 0x1E3B0064,
    SUBDEVICE_1E3B0065 = 0x1E3B0065,
    SUBDEVICE_1E3B006C = 0x1E3B006C,
    SUBDEVICE_1E3B006D = 0x1E3B006D,
    SUBDEVICE_1E3B006F = 0x1E3B006F,
    SUBDEVICE_1E3B0070 = 0x1E3B0070,
    SUBDEVICE_1E3B007C = 0x1E3B007C,
    SUBDEVICE_1E3B007D = 0x1E3B007D,
    SUBDEVICE_1E3B007F = 0x1E3B007F,
    SUBDEVICE_1E3B0080 = 0x1E3B0080,
    SUBDEVICE_1E3B008A = 0x1E3B008A,
    SUBDEVICE_1E3B008B = 0x1E3B008B,
    SUBDEVICE_1E3B0091 = 0x1E3B0091
};



inline const char8* enumToString(PciSubDevice1E3B1098 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E3B1098::NONE:               return "NONE";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0001: return "SUBDEVICE_1E3B0001";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0002: return "SUBDEVICE_1E3B0002";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0004: return "SUBDEVICE_1E3B0004";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0005: return "SUBDEVICE_1E3B0005";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0009: return "SUBDEVICE_1E3B0009";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000A: return "SUBDEVICE_1E3B000A";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000C: return "SUBDEVICE_1E3B000C";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000D: return "SUBDEVICE_1E3B000D";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0014: return "SUBDEVICE_1E3B0014";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0015: return "SUBDEVICE_1E3B0015";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0021: return "SUBDEVICE_1E3B0021";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0022: return "SUBDEVICE_1E3B0022";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0052: return "SUBDEVICE_1E3B0052";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0053: return "SUBDEVICE_1E3B0053";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0059: return "SUBDEVICE_1E3B0059";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0061: return "SUBDEVICE_1E3B0061";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0062: return "SUBDEVICE_1E3B0062";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0064: return "SUBDEVICE_1E3B0064";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0065: return "SUBDEVICE_1E3B0065";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006C: return "SUBDEVICE_1E3B006C";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006D: return "SUBDEVICE_1E3B006D";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006F: return "SUBDEVICE_1E3B006F";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0070: return "SUBDEVICE_1E3B0070";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007C: return "SUBDEVICE_1E3B007C";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007D: return "SUBDEVICE_1E3B007D";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007F: return "SUBDEVICE_1E3B007F";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0080: return "SUBDEVICE_1E3B0080";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B008A: return "SUBDEVICE_1E3B008A";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B008B: return "SUBDEVICE_1E3B008B";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0091: return "SUBDEVICE_1E3B0091";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E3B1098 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E3B1098 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0001: return "Enterprise NVMe SSD U.2 0.8TB (H2100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0002: return "Enterprise NVMe SSD U.2 0.96TB (H2200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0004: return "Enterprise NVMe SSD U.2 1.6TB (H2100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0005: return "Enterprise NVMe SSD U.2 1.92TB (H2200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0009: return "Enterprise NVMe SSD U.2 0.8TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000A: return "Enterprise NVMe SSD U.2 0.96TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000C: return "Enterprise NVMe SSD U.2 1.6TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B000D: return "Enterprise NVMe SSD U.2 1.92TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0014: return "Enterprise NVMe SSD U.2 3.2TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0015: return "Enterprise NVMe SSD U.2 3.84TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0021: return "Enterprise NVMe SSD U.2 6.4TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0022: return "Enterprise NVMe SSD U.2 7.68TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0052: return "Enterprise NVMe SSD U.2 0.8TB (H3900)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0053: return "Enterprise NVMe SSD U.2 1.6TB (H3900)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0059: return "Enterprise NVMe SSD U.2 0.75TB (H3900)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0061: return "Enterprise NVMe SSD HHHL 0.8TB (H2100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0062: return "Enterprise NVMe SSD HHHL 0.96TB (H2200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0064: return "Enterprise NVMe SSD HHHL 1.6TB (H2100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0065: return "Enterprise NVMe SSD HHHL 1.92TB (H2200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006C: return "Enterprise NVMe SSD HHHL 0.8TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006D: return "Enterprise NVMe SSD HHHL 0.96TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B006F: return "Enterprise NVMe SSD HHHL 1.6TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0070: return "Enterprise NVMe SSD HHHL 1.92TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007C: return "Enterprise NVMe SSD HHHL 3.2TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007D: return "Enterprise NVMe SSD HHHL 3.84TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B007F: return "Enterprise NVMe SSD HHHL 6.4TB (H3100)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0080: return "Enterprise NVMe SSD HHHL 7.68TB (H3200)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B008A: return "Enterprise NVMe SSD HHHL 0.8TB (H3900)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B008B: return "Enterprise NVMe SSD HHHL 1.6TB (H3900)";
        case PciSubDevice1E3B1098::SUBDEVICE_1E3B0091: return "Enterprise NVMe SSD HHHL 0.75TB (H3900)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCISUBDEVICE1E3B1098_H
