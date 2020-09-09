// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A501_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A501_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1044A501: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1044C001 = 0x1044C001,
    SUBDEVICE_1044C002 = 0x1044C002,
    SUBDEVICE_1044C003 = 0x1044C003,
    SUBDEVICE_1044C004 = 0x1044C004,
    SUBDEVICE_1044C005 = 0x1044C005,
    SUBDEVICE_1044C00A = 0x1044C00A,
    SUBDEVICE_1044C00B = 0x1044C00B,
    SUBDEVICE_1044C00C = 0x1044C00C,
    SUBDEVICE_1044C00D = 0x1044C00D,
    SUBDEVICE_1044C00E = 0x1044C00E,
    SUBDEVICE_1044C00F = 0x1044C00F,
    SUBDEVICE_1044C014 = 0x1044C014,
    SUBDEVICE_1044C015 = 0x1044C015,
    SUBDEVICE_1044C016 = 0x1044C016,
    SUBDEVICE_1044C01E = 0x1044C01E,
    SUBDEVICE_1044C01F = 0x1044C01F,
    SUBDEVICE_1044C020 = 0x1044C020,
    SUBDEVICE_1044C021 = 0x1044C021,
    SUBDEVICE_1044C028 = 0x1044C028,
    SUBDEVICE_1044C029 = 0x1044C029,
    SUBDEVICE_1044C02A = 0x1044C02A,
    SUBDEVICE_1044C03C = 0x1044C03C,
    SUBDEVICE_1044C03D = 0x1044C03D,
    SUBDEVICE_1044C03E = 0x1044C03E,
    SUBDEVICE_1044C046 = 0x1044C046,
    SUBDEVICE_1044C047 = 0x1044C047,
    SUBDEVICE_1044C048 = 0x1044C048,
    SUBDEVICE_1044C050 = 0x1044C050,
    SUBDEVICE_1044C051 = 0x1044C051,
    SUBDEVICE_1044C052 = 0x1044C052,
    SUBDEVICE_1044C05A = 0x1044C05A,
    SUBDEVICE_1044C05B = 0x1044C05B,
    SUBDEVICE_1044C064 = 0x1044C064,
    SUBDEVICE_1044C065 = 0x1044C065,
    SUBDEVICE_1044C066 = 0x1044C066
};



inline const char8* enumToString(PciSubDevice1044A501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1044A501::NONE:               return "NONE";
        case PciSubDevice1044A501::SUBDEVICE_1044C001: return "SUBDEVICE_1044C001";
        case PciSubDevice1044A501::SUBDEVICE_1044C002: return "SUBDEVICE_1044C002";
        case PciSubDevice1044A501::SUBDEVICE_1044C003: return "SUBDEVICE_1044C003";
        case PciSubDevice1044A501::SUBDEVICE_1044C004: return "SUBDEVICE_1044C004";
        case PciSubDevice1044A501::SUBDEVICE_1044C005: return "SUBDEVICE_1044C005";
        case PciSubDevice1044A501::SUBDEVICE_1044C00A: return "SUBDEVICE_1044C00A";
        case PciSubDevice1044A501::SUBDEVICE_1044C00B: return "SUBDEVICE_1044C00B";
        case PciSubDevice1044A501::SUBDEVICE_1044C00C: return "SUBDEVICE_1044C00C";
        case PciSubDevice1044A501::SUBDEVICE_1044C00D: return "SUBDEVICE_1044C00D";
        case PciSubDevice1044A501::SUBDEVICE_1044C00E: return "SUBDEVICE_1044C00E";
        case PciSubDevice1044A501::SUBDEVICE_1044C00F: return "SUBDEVICE_1044C00F";
        case PciSubDevice1044A501::SUBDEVICE_1044C014: return "SUBDEVICE_1044C014";
        case PciSubDevice1044A501::SUBDEVICE_1044C015: return "SUBDEVICE_1044C015";
        case PciSubDevice1044A501::SUBDEVICE_1044C016: return "SUBDEVICE_1044C016";
        case PciSubDevice1044A501::SUBDEVICE_1044C01E: return "SUBDEVICE_1044C01E";
        case PciSubDevice1044A501::SUBDEVICE_1044C01F: return "SUBDEVICE_1044C01F";
        case PciSubDevice1044A501::SUBDEVICE_1044C020: return "SUBDEVICE_1044C020";
        case PciSubDevice1044A501::SUBDEVICE_1044C021: return "SUBDEVICE_1044C021";
        case PciSubDevice1044A501::SUBDEVICE_1044C028: return "SUBDEVICE_1044C028";
        case PciSubDevice1044A501::SUBDEVICE_1044C029: return "SUBDEVICE_1044C029";
        case PciSubDevice1044A501::SUBDEVICE_1044C02A: return "SUBDEVICE_1044C02A";
        case PciSubDevice1044A501::SUBDEVICE_1044C03C: return "SUBDEVICE_1044C03C";
        case PciSubDevice1044A501::SUBDEVICE_1044C03D: return "SUBDEVICE_1044C03D";
        case PciSubDevice1044A501::SUBDEVICE_1044C03E: return "SUBDEVICE_1044C03E";
        case PciSubDevice1044A501::SUBDEVICE_1044C046: return "SUBDEVICE_1044C046";
        case PciSubDevice1044A501::SUBDEVICE_1044C047: return "SUBDEVICE_1044C047";
        case PciSubDevice1044A501::SUBDEVICE_1044C048: return "SUBDEVICE_1044C048";
        case PciSubDevice1044A501::SUBDEVICE_1044C050: return "SUBDEVICE_1044C050";
        case PciSubDevice1044A501::SUBDEVICE_1044C051: return "SUBDEVICE_1044C051";
        case PciSubDevice1044A501::SUBDEVICE_1044C052: return "SUBDEVICE_1044C052";
        case PciSubDevice1044A501::SUBDEVICE_1044C05A: return "SUBDEVICE_1044C05A";
        case PciSubDevice1044A501::SUBDEVICE_1044C05B: return "SUBDEVICE_1044C05B";
        case PciSubDevice1044A501::SUBDEVICE_1044C064: return "SUBDEVICE_1044C064";
        case PciSubDevice1044A501::SUBDEVICE_1044C065: return "SUBDEVICE_1044C065";
        case PciSubDevice1044A501::SUBDEVICE_1044C066: return "SUBDEVICE_1044C066";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1044A501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1044A501 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1044A501::SUBDEVICE_1044C001: return "PM1554U2 Ultra2 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C002: return "PM1654U2 Ultra2 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C003: return "PM1564U3 Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C004: return "PM1564U3 Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C005: return "PM1554U2 Ultra2 Single Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C00A: return "PM2554U2 Ultra2 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C00B: return "PM2654U2 Ultra2 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C00C: return "PM2664U3 Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C00D: return "PM2664U3 Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C00E: return "PM2554U2 Ultra2 Single Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C00F: return "PM2654U2 Ultra2 Single Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C014: return "PM3754U2 Ultra2 Single Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C015: return "PM3755U2B Ultra2 Single Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C016: return "PM3755F Fibre Channel (NON ACPI)";
        case PciSubDevice1044A501::SUBDEVICE_1044C01E: return "PM3757U2 Ultra2 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C01F: return "PM3757U2 Ultra2 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C020: return "PM3767U3 Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C021: return "PM3767U3 Ultra3 Quad Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C028: return "PM2865U3 Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C029: return "PM2865U3 Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C02A: return "PM2865F Fibre Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C03C: return "2000S Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C03D: return "2000S Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C03E: return "2000F Fibre Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C046: return "3000S Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C047: return "3000S Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C048: return "3000F Fibre Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C050: return "5000S Ultra3 Single Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C051: return "5000S Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C052: return "5000F Fibre Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C05A: return "2400A UDMA Four Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C05B: return "2400A UDMA Four Channel DAC";
        case PciSubDevice1044A501::SUBDEVICE_1044C064: return "3010S Ultra3 Dual Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C065: return "3410S Ultra160 Four Channel";
        case PciSubDevice1044A501::SUBDEVICE_1044C066: return "3010S Fibre Channel";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A501_H
