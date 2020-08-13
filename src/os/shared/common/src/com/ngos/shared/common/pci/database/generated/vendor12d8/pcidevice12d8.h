// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCIDEVICE12D8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCIDEVICE12D8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12D8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_01A7 = 0x01A7,
    DEVICE_0303 = 0x0303,
    DEVICE_0508 = 0x0508,
    DEVICE_2304 = 0x2304,
    DEVICE_2404 = 0x2404,
    DEVICE_2608 = 0x2608,
    DEVICE_400A = 0x400A,
    DEVICE_400E = 0x400E,
    DEVICE_400F = 0x400F,
    DEVICE_71E2 = 0x71E2,
    DEVICE_71E3 = 0x71E3,
    DEVICE_8140 = 0x8140,
    DEVICE_8148 = 0x8148,
    DEVICE_8150 = 0x8150,
    DEVICE_8152 = 0x8152,
    DEVICE_8154 = 0x8154,
    DEVICE_E110 = 0xE110,
    DEVICE_E111 = 0xE111,
    DEVICE_E130 = 0xE130
};



inline const char8* enumToString(PciDevice12D8 device12D8) // TEST: NO
{
    // COMMON_LT((" | device12D8 = %u", device12D8)); // Commented to avoid bad looking logs



    switch (device12D8)
    {
        case PciDevice12D8::NONE:        return "NONE";
        case PciDevice12D8::DEVICE_01A7: return "DEVICE_01A7";
        case PciDevice12D8::DEVICE_0303: return "DEVICE_0303";
        case PciDevice12D8::DEVICE_0508: return "DEVICE_0508";
        case PciDevice12D8::DEVICE_2304: return "DEVICE_2304";
        case PciDevice12D8::DEVICE_2404: return "DEVICE_2404";
        case PciDevice12D8::DEVICE_2608: return "DEVICE_2608";
        case PciDevice12D8::DEVICE_400A: return "DEVICE_400A";
        case PciDevice12D8::DEVICE_400E: return "DEVICE_400E";
        case PciDevice12D8::DEVICE_400F: return "DEVICE_400F";
        case PciDevice12D8::DEVICE_71E2: return "DEVICE_71E2";
        case PciDevice12D8::DEVICE_71E3: return "DEVICE_71E3";
        case PciDevice12D8::DEVICE_8140: return "DEVICE_8140";
        case PciDevice12D8::DEVICE_8148: return "DEVICE_8148";
        case PciDevice12D8::DEVICE_8150: return "DEVICE_8150";
        case PciDevice12D8::DEVICE_8152: return "DEVICE_8152";
        case PciDevice12D8::DEVICE_8154: return "DEVICE_8154";
        case PciDevice12D8::DEVICE_E110: return "DEVICE_E110";
        case PciDevice12D8::DEVICE_E111: return "DEVICE_E111";
        case PciDevice12D8::DEVICE_E130: return "DEVICE_E130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12D8 device12D8) // TEST: NO
{
    // COMMON_LT((" | device12D8 = %u", device12D8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12D8, enumToString(device12D8));

    return res;
}



inline const char8* enumToHumanString(PciDevice12D8 device12D8) // TEST: NO
{
    // COMMON_LT((" | device12D8 = %u", device12D8)); // Commented to avoid bad looking logs



    switch (device12D8)
    {
        case PciDevice12D8::DEVICE_01A7: return "7C21P100 2-port PCI-X to PCI-X Bridge";
        case PciDevice12D8::DEVICE_0303: return "PCI Express Switch 3-3";
        case PciDevice12D8::DEVICE_0508: return "PI7C9X20508GP PCI Express Switch 5Port-8Lane";
        case PciDevice12D8::DEVICE_2304: return "PI7C9X2G304 EL/SL PCIe2 3-Port/4-Lane Packet Switch";
        case PciDevice12D8::DEVICE_2404: return "PI7C9X2G404 EL/SL PCIe2 4-Port/4-Lane Packet Switch";
        case PciDevice12D8::DEVICE_2608: return "PI7C9X2G608GP PCIe2 6-Port/8-Lane Packet Switch";
        case PciDevice12D8::DEVICE_400A: return "PI7C9X442SL PCI Express Bridge Port";
        case PciDevice12D8::DEVICE_400E: return "PI7C9X442SL USB OHCI Controller";
        case PciDevice12D8::DEVICE_400F: return "PI7C9X442SL USB EHCI Controller";
        case PciDevice12D8::DEVICE_71E2: return "PI7C7300A/PI7C7300D PCI-to-PCI Bridge";
        case PciDevice12D8::DEVICE_71E3: return "PI7C7300A/PI7C7300D PCI-to-PCI Bridge (Secondary Bus 2)";
        case PciDevice12D8::DEVICE_8140: return "PI7C8140A PCI-to-PCI Bridge";
        case PciDevice12D8::DEVICE_8148: return "PI7C8148A/PI7C8148B PCI-to-PCI Bridge";
        case PciDevice12D8::DEVICE_8150: return "PCI to PCI Bridge";
        case PciDevice12D8::DEVICE_8152: return "PI7C8152A/PI7C8152B/PI7C8152BI PCI-to-PCI Bridge";
        case PciDevice12D8::DEVICE_8154: return "PI7C8154A/PI7C8154B/PI7C8154BI PCI-to-PCI Bridge";
        case PciDevice12D8::DEVICE_E110: return "PI7C9X110 PCI Express to PCI bridge";
        case PciDevice12D8::DEVICE_E111: return "PI7C9X111SL PCIe-to-PCI Reversible Bridge";
        case PciDevice12D8::DEVICE_E130: return "PCI Express to PCI-XPI7C9X130 PCI-X Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCIDEVICE12D8_H
