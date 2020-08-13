// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCIDEVICE1814_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCIDEVICE1814_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1814: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0401 = 0x0401,
    DEVICE_0601 = 0x0601,
    DEVICE_0681 = 0x0681,
    DEVICE_0701 = 0x0701,
    DEVICE_0781 = 0x0781,
    DEVICE_3060 = 0x3060,
    DEVICE_3062 = 0x3062,
    DEVICE_3090 = 0x3090,
    DEVICE_3091 = 0x3091,
    DEVICE_3092 = 0x3092,
    DEVICE_3290 = 0x3290,
    DEVICE_3298 = 0x3298,
    DEVICE_3592 = 0x3592,
    DEVICE_359F = 0x359F,
    DEVICE_5360 = 0x5360,
    DEVICE_5362 = 0x5362,
    DEVICE_5390 = 0x5390,
    DEVICE_5392 = 0x5392,
    DEVICE_539B = 0x539B,
    DEVICE_539F = 0x539F,
    DEVICE_5592 = 0x5592,
    DEVICE_E932 = 0xE932
};



inline const char8* enumToString(PciDevice1814 device1814) // TEST: NO
{
    // COMMON_LT((" | device1814 = %u", device1814)); // Commented to avoid bad looking logs



    switch (device1814)
    {
        case PciDevice1814::NONE:        return "NONE";
        case PciDevice1814::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1814::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1814::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1814::DEVICE_0300: return "DEVICE_0300";
        case PciDevice1814::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1814::DEVICE_0302: return "DEVICE_0302";
        case PciDevice1814::DEVICE_0401: return "DEVICE_0401";
        case PciDevice1814::DEVICE_0601: return "DEVICE_0601";
        case PciDevice1814::DEVICE_0681: return "DEVICE_0681";
        case PciDevice1814::DEVICE_0701: return "DEVICE_0701";
        case PciDevice1814::DEVICE_0781: return "DEVICE_0781";
        case PciDevice1814::DEVICE_3060: return "DEVICE_3060";
        case PciDevice1814::DEVICE_3062: return "DEVICE_3062";
        case PciDevice1814::DEVICE_3090: return "DEVICE_3090";
        case PciDevice1814::DEVICE_3091: return "DEVICE_3091";
        case PciDevice1814::DEVICE_3092: return "DEVICE_3092";
        case PciDevice1814::DEVICE_3290: return "DEVICE_3290";
        case PciDevice1814::DEVICE_3298: return "DEVICE_3298";
        case PciDevice1814::DEVICE_3592: return "DEVICE_3592";
        case PciDevice1814::DEVICE_359F: return "DEVICE_359F";
        case PciDevice1814::DEVICE_5360: return "DEVICE_5360";
        case PciDevice1814::DEVICE_5362: return "DEVICE_5362";
        case PciDevice1814::DEVICE_5390: return "DEVICE_5390";
        case PciDevice1814::DEVICE_5392: return "DEVICE_5392";
        case PciDevice1814::DEVICE_539B: return "DEVICE_539B";
        case PciDevice1814::DEVICE_539F: return "DEVICE_539F";
        case PciDevice1814::DEVICE_5592: return "DEVICE_5592";
        case PciDevice1814::DEVICE_E932: return "DEVICE_E932";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1814 device1814) // TEST: NO
{
    // COMMON_LT((" | device1814 = %u", device1814)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1814, enumToString(device1814));

    return res;
}



inline const char8* enumToHumanString(PciDevice1814 device1814) // TEST: NO
{
    // COMMON_LT((" | device1814 = %u", device1814)); // Commented to avoid bad looking logs



    switch (device1814)
    {
        case PciDevice1814::DEVICE_0101: return "Wireless PCI Adapter RT2400 / RT2460";
        case PciDevice1814::DEVICE_0200: return "RT2500 802.11g PCI [PC54G2]";
        case PciDevice1814::DEVICE_0201: return "RT2500 Wireless 802.11bg";
        case PciDevice1814::DEVICE_0300: return "Wireless Adapter Canyon CN-WF511";
        case PciDevice1814::DEVICE_0301: return "RT2561/RT61 802.11g PCI";
        case PciDevice1814::DEVICE_0302: return "RT2561/RT61 rev B 802.11g";
        case PciDevice1814::DEVICE_0401: return "RT2600 802.11 MIMO";
        case PciDevice1814::DEVICE_0601: return "RT2800 802.11n PCI";
        case PciDevice1814::DEVICE_0681: return "RT2890 Wireless 802.11n PCIe";
        case PciDevice1814::DEVICE_0701: return "RT2760 Wireless 802.11n 1T/2R";
        case PciDevice1814::DEVICE_0781: return "RT2790 Wireless 802.11n 1T/2R PCIe";
        case PciDevice1814::DEVICE_3060: return "RT3060 Wireless 802.11n 1T/1R";
        case PciDevice1814::DEVICE_3062: return "RT3062 Wireless 802.11n 2T/2R";
        case PciDevice1814::DEVICE_3090: return "RT3090 Wireless 802.11n 1T/1R PCIe";
        case PciDevice1814::DEVICE_3091: return "RT3091 Wireless 802.11n 1T/2R PCIe";
        case PciDevice1814::DEVICE_3092: return "RT3092 Wireless 802.11n 2T/2R PCIe";
        case PciDevice1814::DEVICE_3290: return "RT3290 Wireless 802.11n 1T/1R PCIe";
        case PciDevice1814::DEVICE_3298: return "RT3290 Bluetooth";
        case PciDevice1814::DEVICE_3592: return "RT3592 Wireless 802.11abgn 2T/2R PCIe";
        case PciDevice1814::DEVICE_359F: return "RT3592 PCIe Wireless Network Adapter";
        case PciDevice1814::DEVICE_5360: return "RT5360 Wireless 802.11n 1T/1R";
        case PciDevice1814::DEVICE_5362: return "RT5362 PCI 802.11n Wireless Network Adapter";
        case PciDevice1814::DEVICE_5390: return "RT5390 Wireless 802.11n 1T/1R PCIe";
        case PciDevice1814::DEVICE_5392: return "RT5392 PCIe Wireless Network Adapter";
        case PciDevice1814::DEVICE_539B: return "RT5390R 802.11bgn PCIe Wireless Network Adapter";
        case PciDevice1814::DEVICE_539F: return "RT5390 [802.11 b/g/n 1T1R G-band PCI Express Single Chip]";
        case PciDevice1814::DEVICE_5592: return "RT5592 PCIe Wireless Network Adapter";
        case PciDevice1814::DEVICE_E932: return "RT2560F 802.11 b/g PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCIDEVICE1814_H
