// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1407_PCIDEVICE1407_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1407_PCIDEVICE1407_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1407: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0110 = 0x0110,
    DEVICE_0111 = 0x0111,
    DEVICE_0120 = 0x0120,
    DEVICE_0121 = 0x0121,
    DEVICE_0180 = 0x0180,
    DEVICE_0181 = 0x0181,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0202 = 0x0202,
    DEVICE_0220 = 0x0220,
    DEVICE_0221 = 0x0221,
    DEVICE_0400 = 0x0400,
    DEVICE_0500 = 0x0500,
    DEVICE_0520 = 0x0520,
    DEVICE_0600 = 0x0600,
    DEVICE_8000 = 0x8000,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_8003 = 0x8003,
    DEVICE_8800 = 0x8800
};



inline const char8* enumToString(PciDevice1407 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1407::NONE:        return "NONE";
        case PciDevice1407::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1407::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1407::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1407::DEVICE_0110: return "DEVICE_0110";
        case PciDevice1407::DEVICE_0111: return "DEVICE_0111";
        case PciDevice1407::DEVICE_0120: return "DEVICE_0120";
        case PciDevice1407::DEVICE_0121: return "DEVICE_0121";
        case PciDevice1407::DEVICE_0180: return "DEVICE_0180";
        case PciDevice1407::DEVICE_0181: return "DEVICE_0181";
        case PciDevice1407::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1407::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1407::DEVICE_0202: return "DEVICE_0202";
        case PciDevice1407::DEVICE_0220: return "DEVICE_0220";
        case PciDevice1407::DEVICE_0221: return "DEVICE_0221";
        case PciDevice1407::DEVICE_0400: return "DEVICE_0400";
        case PciDevice1407::DEVICE_0500: return "DEVICE_0500";
        case PciDevice1407::DEVICE_0520: return "DEVICE_0520";
        case PciDevice1407::DEVICE_0600: return "DEVICE_0600";
        case PciDevice1407::DEVICE_8000: return "DEVICE_8000";
        case PciDevice1407::DEVICE_8001: return "DEVICE_8001";
        case PciDevice1407::DEVICE_8002: return "DEVICE_8002";
        case PciDevice1407::DEVICE_8003: return "DEVICE_8003";
        case PciDevice1407::DEVICE_8800: return "DEVICE_8800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1407 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1407 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1407::DEVICE_0100: return "Lava Dual Serial";
        case PciDevice1407::DEVICE_0101: return "Lava Quatro A";
        case PciDevice1407::DEVICE_0102: return "Lava Quatro B";
        case PciDevice1407::DEVICE_0110: return "Lava DSerial-PCI Port A";
        case PciDevice1407::DEVICE_0111: return "Lava DSerial-PCI Port B";
        case PciDevice1407::DEVICE_0120: return "Quattro-PCI A";
        case PciDevice1407::DEVICE_0121: return "Quattro-PCI B";
        case PciDevice1407::DEVICE_0180: return "Lava Octo A";
        case PciDevice1407::DEVICE_0181: return "Lava Octo B";
        case PciDevice1407::DEVICE_0200: return "Lava Port Plus";
        case PciDevice1407::DEVICE_0201: return "Lava Quad A";
        case PciDevice1407::DEVICE_0202: return "Lava Quad B";
        case PciDevice1407::DEVICE_0220: return "Lava Quattro PCI Ports A/B";
        case PciDevice1407::DEVICE_0221: return "Lava Quattro PCI Ports C/D";
        case PciDevice1407::DEVICE_0400: return "Lava 8255-PIO-PCI";
        case PciDevice1407::DEVICE_0500: return "Lava Single Serial";
        case PciDevice1407::DEVICE_0520: return "Lava RS422-SS-PCI";
        case PciDevice1407::DEVICE_0600: return "Lava Port 650";
        case PciDevice1407::DEVICE_8000: return "Lava Parallel";
        case PciDevice1407::DEVICE_8001: return "Dual parallel port controller A";
        case PciDevice1407::DEVICE_8002: return "Lava Dual Parallel port A";
        case PciDevice1407::DEVICE_8003: return "Lava Dual Parallel port B";
        case PciDevice1407::DEVICE_8800: return "BOCA Research IOPPAR";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1407_PCIDEVICE1407_H
