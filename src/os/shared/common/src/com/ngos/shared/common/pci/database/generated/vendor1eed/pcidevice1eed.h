// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EED_PCIDEVICE1EED_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EED_PCIDEVICE1EED_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EED: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100,
    DEVICE_1101 = 0x1101,
    DEVICE_1200 = 0x1200,
    DEVICE_1201 = 0x1201,
    DEVICE_1300 = 0x1300,
    DEVICE_1301 = 0x1301,
    DEVICE_1400 = 0x1400,
    DEVICE_1401 = 0x1401,
    DEVICE_1500 = 0x1500,
    DEVICE_1501 = 0x1501,
    DEVICE_1600 = 0x1600,
    DEVICE_1601 = 0x1601,
    DEVICE_1700 = 0x1700,
    DEVICE_1701 = 0x1701,
    DEVICE_1800 = 0x1800,
    DEVICE_1801 = 0x1801,
    DEVICE_1900 = 0x1900,
    DEVICE_1901 = 0x1901
};



inline const char8* enumToString(PciDevice1EED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EED::NONE:        return "NONE";
        case PciDevice1EED::DEVICE_1100: return "DEVICE_1100";
        case PciDevice1EED::DEVICE_1101: return "DEVICE_1101";
        case PciDevice1EED::DEVICE_1200: return "DEVICE_1200";
        case PciDevice1EED::DEVICE_1201: return "DEVICE_1201";
        case PciDevice1EED::DEVICE_1300: return "DEVICE_1300";
        case PciDevice1EED::DEVICE_1301: return "DEVICE_1301";
        case PciDevice1EED::DEVICE_1400: return "DEVICE_1400";
        case PciDevice1EED::DEVICE_1401: return "DEVICE_1401";
        case PciDevice1EED::DEVICE_1500: return "DEVICE_1500";
        case PciDevice1EED::DEVICE_1501: return "DEVICE_1501";
        case PciDevice1EED::DEVICE_1600: return "DEVICE_1600";
        case PciDevice1EED::DEVICE_1601: return "DEVICE_1601";
        case PciDevice1EED::DEVICE_1700: return "DEVICE_1700";
        case PciDevice1EED::DEVICE_1701: return "DEVICE_1701";
        case PciDevice1EED::DEVICE_1800: return "DEVICE_1800";
        case PciDevice1EED::DEVICE_1801: return "DEVICE_1801";
        case PciDevice1EED::DEVICE_1900: return "DEVICE_1900";
        case PciDevice1EED::DEVICE_1901: return "DEVICE_1901";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EED::DEVICE_1100: return "XDX110 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1101: return "XDX110 Audio Controller";
        case PciDevice1EED::DEVICE_1200: return "XDX120 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1201: return "XDX120 Audio Controller";
        case PciDevice1EED::DEVICE_1300: return "XDX130 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1301: return "XDX130 Audio Controller";
        case PciDevice1EED::DEVICE_1400: return "XDX140 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1401: return "XDX140 Audio Controller";
        case PciDevice1EED::DEVICE_1500: return "XDX150 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1501: return "XDX150 Audio Controller";
        case PciDevice1EED::DEVICE_1600: return "XDX160 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1601: return "XDX160 Audio Controller";
        case PciDevice1EED::DEVICE_1700: return "XDX170 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1701: return "XDX170 Audio Controller";
        case PciDevice1EED::DEVICE_1800: return "XDX180 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1801: return "XDX180 Audio Controller";
        case PciDevice1EED::DEVICE_1900: return "XDX190 Graphic/VGA Controller";
        case PciDevice1EED::DEVICE_1901: return "XDX190 Audio Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EED_PCIDEVICE1EED_H
