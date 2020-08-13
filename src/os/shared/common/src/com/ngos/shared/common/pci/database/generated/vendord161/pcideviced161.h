// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD161_PCIDEVICED161_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD161_PCIDEVICED161_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceD161: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0120 = 0x0120,
    DEVICE_0205 = 0x0205,
    DEVICE_0210 = 0x0210,
    DEVICE_0220 = 0x0220,
    DEVICE_0405 = 0x0405,
    DEVICE_0410 = 0x0410,
    DEVICE_0420 = 0x0420,
    DEVICE_0800 = 0x0800,
    DEVICE_1205 = 0x1205,
    DEVICE_1220 = 0x1220,
    DEVICE_1405 = 0x1405,
    DEVICE_1410 = 0x1410,
    DEVICE_1420 = 0x1420,
    DEVICE_1820 = 0x1820,
    DEVICE_2400 = 0x2400,
    DEVICE_3400 = 0x3400,
    DEVICE_8000 = 0x8000,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_8003 = 0x8003,
    DEVICE_8004 = 0x8004,
    DEVICE_8005 = 0x8005,
    DEVICE_8006 = 0x8006,
    DEVICE_8007 = 0x8007,
    DEVICE_8008 = 0x8008,
    DEVICE_800A = 0x800A,
    DEVICE_800B = 0x800B,
    DEVICE_800C = 0x800C,
    DEVICE_800D = 0x800D,
    DEVICE_800E = 0x800E,
    DEVICE_800F = 0x800F,
    DEVICE_8010 = 0x8010,
    DEVICE_8013 = 0x8013,
    DEVICE_B410 = 0xB410
};



inline const char8* enumToString(PciDeviceD161 deviceD161) // TEST: NO
{
    // COMMON_LT((" | deviceD161 = %u", deviceD161)); // Commented to avoid bad looking logs



    switch (deviceD161)
    {
        case PciDeviceD161::NONE:        return "NONE";
        case PciDeviceD161::DEVICE_0120: return "DEVICE_0120";
        case PciDeviceD161::DEVICE_0205: return "DEVICE_0205";
        case PciDeviceD161::DEVICE_0210: return "DEVICE_0210";
        case PciDeviceD161::DEVICE_0220: return "DEVICE_0220";
        case PciDeviceD161::DEVICE_0405: return "DEVICE_0405";
        case PciDeviceD161::DEVICE_0410: return "DEVICE_0410";
        case PciDeviceD161::DEVICE_0420: return "DEVICE_0420";
        case PciDeviceD161::DEVICE_0800: return "DEVICE_0800";
        case PciDeviceD161::DEVICE_1205: return "DEVICE_1205";
        case PciDeviceD161::DEVICE_1220: return "DEVICE_1220";
        case PciDeviceD161::DEVICE_1405: return "DEVICE_1405";
        case PciDeviceD161::DEVICE_1410: return "DEVICE_1410";
        case PciDeviceD161::DEVICE_1420: return "DEVICE_1420";
        case PciDeviceD161::DEVICE_1820: return "DEVICE_1820";
        case PciDeviceD161::DEVICE_2400: return "DEVICE_2400";
        case PciDeviceD161::DEVICE_3400: return "DEVICE_3400";
        case PciDeviceD161::DEVICE_8000: return "DEVICE_8000";
        case PciDeviceD161::DEVICE_8001: return "DEVICE_8001";
        case PciDeviceD161::DEVICE_8002: return "DEVICE_8002";
        case PciDeviceD161::DEVICE_8003: return "DEVICE_8003";
        case PciDeviceD161::DEVICE_8004: return "DEVICE_8004";
        case PciDeviceD161::DEVICE_8005: return "DEVICE_8005";
        case PciDeviceD161::DEVICE_8006: return "DEVICE_8006";
        case PciDeviceD161::DEVICE_8007: return "DEVICE_8007";
        case PciDeviceD161::DEVICE_8008: return "DEVICE_8008";
        case PciDeviceD161::DEVICE_800A: return "DEVICE_800A";
        case PciDeviceD161::DEVICE_800B: return "DEVICE_800B";
        case PciDeviceD161::DEVICE_800C: return "DEVICE_800C";
        case PciDeviceD161::DEVICE_800D: return "DEVICE_800D";
        case PciDeviceD161::DEVICE_800E: return "DEVICE_800E";
        case PciDeviceD161::DEVICE_800F: return "DEVICE_800F";
        case PciDeviceD161::DEVICE_8010: return "DEVICE_8010";
        case PciDeviceD161::DEVICE_8013: return "DEVICE_8013";
        case PciDeviceD161::DEVICE_B410: return "DEVICE_B410";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceD161 deviceD161) // TEST: NO
{
    // COMMON_LT((" | deviceD161 = %u", deviceD161)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceD161, enumToString(deviceD161));

    return res;
}



inline const char8* enumToHumanString(PciDeviceD161 deviceD161) // TEST: NO
{
    // COMMON_LT((" | deviceD161 = %u", deviceD161)); // Commented to avoid bad looking logs



    switch (deviceD161)
    {
        case PciDeviceD161::DEVICE_0120: return "Wildcard TE120P single-span T1/E1/J1 card";
        case PciDeviceD161::DEVICE_0205: return "Wildcard TE205P/TE207P dual-span T1/E1/J1 card 5.0V";
        case PciDeviceD161::DEVICE_0210: return "Wildcard TE210P/TE212P dual-span T1/E1/J1 card 3.3V";
        case PciDeviceD161::DEVICE_0220: return "Wildcard TE220 dual-span T1/E1/J1 card 3.3V (PCI-Express)";
        case PciDeviceD161::DEVICE_0405: return "Wildcard TE405P/TE407P quad-span T1/E1/J1 card 5.0V";
        case PciDeviceD161::DEVICE_0410: return "Wildcard TE410P/TE412P quad-span T1/E1/J1 card 3.3V";
        case PciDeviceD161::DEVICE_0420: return "Wildcard TE420P quad-span T1/E1/J1 card 3.3V (PCI-Express)";
        case PciDeviceD161::DEVICE_0800: return "Wildcard TDM800P 8-port analog card";
        case PciDeviceD161::DEVICE_1205: return "Wildcard TE205P/TE207P dual-span T1/E1/J1 card 5.0V (u1)";
        case PciDeviceD161::DEVICE_1220: return "Wildcard TE220 dual-span T1/E1/J1 card 3.3V (PCI-Express) (5th gen)";
        case PciDeviceD161::DEVICE_1405: return "Wildcard TE405P/TE407P quad-span T1/E1/J1 card 5.0V (u1)";
        case PciDeviceD161::DEVICE_1410: return "Wildcard TE410P quad-span T1/E1/J1 card 3.3V (5th Gen)";
        case PciDeviceD161::DEVICE_1420: return "Wildcard TE420 quad-span T1/E1/J1 card 3.3V (PCI-Express) (5th gen)";
        case PciDeviceD161::DEVICE_1820: return "Wildcard TE820 octal-span T1/E1/J1 card 3.3V (PCI-Express)";
        case PciDeviceD161::DEVICE_2400: return "Wildcard TDM2400P 24-port analog card";
        case PciDeviceD161::DEVICE_3400: return "Wildcard TC400P transcoder base card";
        case PciDeviceD161::DEVICE_8000: return "Wildcard TE121 single-span T1/E1/J1 card (PCI-Express)";
        case PciDeviceD161::DEVICE_8001: return "Wildcard TE122 single-span T1/E1/J1 card";
        case PciDeviceD161::DEVICE_8002: return "Wildcard AEX800 8-port analog card (PCI-Express)";
        case PciDeviceD161::DEVICE_8003: return "Wildcard AEX2400 24-port analog card (PCI-Express)";
        case PciDeviceD161::DEVICE_8004: return "Wildcard TCE400P transcoder base card";
        case PciDeviceD161::DEVICE_8005: return "Wildcard TDM410 4-port analog card";
        case PciDeviceD161::DEVICE_8006: return "Wildcard AEX410 4-port analog card (PCI-Express)";
        case PciDeviceD161::DEVICE_8007: return "Hx8 Series 8-port Base Card";
        case PciDeviceD161::DEVICE_8008: return "Hx8 Series 8-port Base Card (PCI-Express)";
        case PciDeviceD161::DEVICE_800A: return "Wildcard TE133 single-span T1/E1/J1 card (PCI Express)";
        case PciDeviceD161::DEVICE_800B: return "Wildcard TE134 single-span T1/E1/J1 card";
        case PciDeviceD161::DEVICE_800C: return "Wildcard A8A 8-port analog card";
        case PciDeviceD161::DEVICE_800D: return "Wildcard A8B 8-port analog card (PCI-Express)";
        case PciDeviceD161::DEVICE_800E: return "Wildcard TE235/TE435 quad-span T1/E1/J1 card (PCI-Express)";
        case PciDeviceD161::DEVICE_800F: return "Wildcard A4A 4-port analog card";
        case PciDeviceD161::DEVICE_8010: return "Wildcard A4B 4-port analog card (PCI-Express)";
        case PciDeviceD161::DEVICE_8013: return "Wildcard TE236/TE436 quad-span T1/E1/J1 card";
        case PciDeviceD161::DEVICE_B410: return "Wildcard B410 quad-BRI card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORD161_PCIDEVICED161_H
