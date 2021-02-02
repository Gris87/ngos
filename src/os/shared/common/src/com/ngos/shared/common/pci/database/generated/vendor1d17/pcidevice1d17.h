// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D17_PCIDEVICE1D17_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D17_PCIDEVICE1D17_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D17: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_070F = 0x070F,
    DEVICE_0710 = 0x0710,
    DEVICE_0711 = 0x0711,
    DEVICE_0712 = 0x0712,
    DEVICE_0713 = 0x0713,
    DEVICE_0714 = 0x0714,
    DEVICE_0715 = 0x0715,
    DEVICE_0716 = 0x0716,
    DEVICE_0717 = 0x0717,
    DEVICE_0718 = 0x0718,
    DEVICE_0719 = 0x0719,
    DEVICE_071A = 0x071A,
    DEVICE_071B = 0x071B,
    DEVICE_071C = 0x071C,
    DEVICE_071D = 0x071D,
    DEVICE_071E = 0x071E,
    DEVICE_071F = 0x071F,
    DEVICE_0720 = 0x0720,
    DEVICE_0721 = 0x0721,
    DEVICE_0722 = 0x0722,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1003 = 0x1003,
    DEVICE_3001 = 0x3001,
    DEVICE_300A = 0x300A,
    DEVICE_3038 = 0x3038,
    DEVICE_3104 = 0x3104,
    DEVICE_31B0 = 0x31B0,
    DEVICE_31B1 = 0x31B1,
    DEVICE_31B2 = 0x31B2,
    DEVICE_31B3 = 0x31B3,
    DEVICE_31B4 = 0x31B4,
    DEVICE_31B5 = 0x31B5,
    DEVICE_31B7 = 0x31B7,
    DEVICE_31B8 = 0x31B8,
    DEVICE_3288 = 0x3288,
    DEVICE_345B = 0x345B,
    DEVICE_3A02 = 0x3A02,
    DEVICE_3A03 = 0x3A03,
    DEVICE_3A04 = 0x3A04,
    DEVICE_9002 = 0x9002,
    DEVICE_9003 = 0x9003,
    DEVICE_9045 = 0x9045,
    DEVICE_9046 = 0x9046,
    DEVICE_9083 = 0x9083,
    DEVICE_9084 = 0x9084,
    DEVICE_9100 = 0x9100,
    DEVICE_9101 = 0x9101,
    DEVICE_9141 = 0x9141,
    DEVICE_9142 = 0x9142,
    DEVICE_9144 = 0x9144,
    DEVICE_9180 = 0x9180,
    DEVICE_9202 = 0x9202,
    DEVICE_9203 = 0x9203,
    DEVICE_9204 = 0x9204,
    DEVICE_9286 = 0x9286,
    DEVICE_9300 = 0x9300,
    DEVICE_95D0 = 0x95D0,
    DEVICE_F410 = 0xF410
};



inline const char8* enumToString(PciDevice1D17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D17::NONE:        return "NONE";
        case PciDevice1D17::DEVICE_070F: return "DEVICE_070F";
        case PciDevice1D17::DEVICE_0710: return "DEVICE_0710";
        case PciDevice1D17::DEVICE_0711: return "DEVICE_0711";
        case PciDevice1D17::DEVICE_0712: return "DEVICE_0712";
        case PciDevice1D17::DEVICE_0713: return "DEVICE_0713";
        case PciDevice1D17::DEVICE_0714: return "DEVICE_0714";
        case PciDevice1D17::DEVICE_0715: return "DEVICE_0715";
        case PciDevice1D17::DEVICE_0716: return "DEVICE_0716";
        case PciDevice1D17::DEVICE_0717: return "DEVICE_0717";
        case PciDevice1D17::DEVICE_0718: return "DEVICE_0718";
        case PciDevice1D17::DEVICE_0719: return "DEVICE_0719";
        case PciDevice1D17::DEVICE_071A: return "DEVICE_071A";
        case PciDevice1D17::DEVICE_071B: return "DEVICE_071B";
        case PciDevice1D17::DEVICE_071C: return "DEVICE_071C";
        case PciDevice1D17::DEVICE_071D: return "DEVICE_071D";
        case PciDevice1D17::DEVICE_071E: return "DEVICE_071E";
        case PciDevice1D17::DEVICE_071F: return "DEVICE_071F";
        case PciDevice1D17::DEVICE_0720: return "DEVICE_0720";
        case PciDevice1D17::DEVICE_0721: return "DEVICE_0721";
        case PciDevice1D17::DEVICE_0722: return "DEVICE_0722";
        case PciDevice1D17::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1D17::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1D17::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1D17::DEVICE_3001: return "DEVICE_3001";
        case PciDevice1D17::DEVICE_300A: return "DEVICE_300A";
        case PciDevice1D17::DEVICE_3038: return "DEVICE_3038";
        case PciDevice1D17::DEVICE_3104: return "DEVICE_3104";
        case PciDevice1D17::DEVICE_31B0: return "DEVICE_31B0";
        case PciDevice1D17::DEVICE_31B1: return "DEVICE_31B1";
        case PciDevice1D17::DEVICE_31B2: return "DEVICE_31B2";
        case PciDevice1D17::DEVICE_31B3: return "DEVICE_31B3";
        case PciDevice1D17::DEVICE_31B4: return "DEVICE_31B4";
        case PciDevice1D17::DEVICE_31B5: return "DEVICE_31B5";
        case PciDevice1D17::DEVICE_31B7: return "DEVICE_31B7";
        case PciDevice1D17::DEVICE_31B8: return "DEVICE_31B8";
        case PciDevice1D17::DEVICE_3288: return "DEVICE_3288";
        case PciDevice1D17::DEVICE_345B: return "DEVICE_345B";
        case PciDevice1D17::DEVICE_3A02: return "DEVICE_3A02";
        case PciDevice1D17::DEVICE_3A03: return "DEVICE_3A03";
        case PciDevice1D17::DEVICE_3A04: return "DEVICE_3A04";
        case PciDevice1D17::DEVICE_9002: return "DEVICE_9002";
        case PciDevice1D17::DEVICE_9003: return "DEVICE_9003";
        case PciDevice1D17::DEVICE_9045: return "DEVICE_9045";
        case PciDevice1D17::DEVICE_9046: return "DEVICE_9046";
        case PciDevice1D17::DEVICE_9083: return "DEVICE_9083";
        case PciDevice1D17::DEVICE_9084: return "DEVICE_9084";
        case PciDevice1D17::DEVICE_9100: return "DEVICE_9100";
        case PciDevice1D17::DEVICE_9101: return "DEVICE_9101";
        case PciDevice1D17::DEVICE_9141: return "DEVICE_9141";
        case PciDevice1D17::DEVICE_9142: return "DEVICE_9142";
        case PciDevice1D17::DEVICE_9144: return "DEVICE_9144";
        case PciDevice1D17::DEVICE_9180: return "DEVICE_9180";
        case PciDevice1D17::DEVICE_9202: return "DEVICE_9202";
        case PciDevice1D17::DEVICE_9203: return "DEVICE_9203";
        case PciDevice1D17::DEVICE_9204: return "DEVICE_9204";
        case PciDevice1D17::DEVICE_9286: return "DEVICE_9286";
        case PciDevice1D17::DEVICE_9300: return "DEVICE_9300";
        case PciDevice1D17::DEVICE_95D0: return "DEVICE_95D0";
        case PciDevice1D17::DEVICE_F410: return "DEVICE_F410";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D17::DEVICE_070F: return "ZX-100 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0710: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0711: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0712: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0713: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0714: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0715: return "ZX-100/ZX-200 PCI Express Root Port";
        case PciDevice1D17::DEVICE_0716: return "ZX-D PCI Express Root Port";
        case PciDevice1D17::DEVICE_0717: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_0718: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_0719: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071A: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071B: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071C: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071D: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071E: return "ZX-D/ZX-E PCI Express Root Port";
        case PciDevice1D17::DEVICE_071F: return "ZX-200 Upstream Port of PCI Express Switch";
        case PciDevice1D17::DEVICE_0720: return "ZX-200 PCIE RC6 controller";
        case PciDevice1D17::DEVICE_0721: return "ZX-200 Downstream Port of PCI Express Switch";
        case PciDevice1D17::DEVICE_0722: return "ZX-200 PCIE P2C bridge";
        case PciDevice1D17::DEVICE_1000: return "ZX-D Standard Host Bridge";
        case PciDevice1D17::DEVICE_1001: return "ZX-D/ZX-E Miscellaneous Bus";
        case PciDevice1D17::DEVICE_1003: return "ZX-E Standard Host Bridge";
        case PciDevice1D17::DEVICE_3001: return "ZX-100 Standard Host Bridge";
        case PciDevice1D17::DEVICE_300A: return "ZX-100 Miscellaneous Bus";
        case PciDevice1D17::DEVICE_3038: return "ZX-100/ZX-200/ZX-E Standard Universal PCI to USB Host Controller";
        case PciDevice1D17::DEVICE_3104: return "ZX-100/ZX-200/ZX-E Standard Enhanced PCI to USB Host Controller";
        case PciDevice1D17::DEVICE_31B0: return "ZX-100/ZX-D Standard Host Bridge";
        case PciDevice1D17::DEVICE_31B1: return "ZX-100/ZX-D Standard Host Bridge";
        case PciDevice1D17::DEVICE_31B2: return "ZX-100/ZX-D DRAM Controller";
        case PciDevice1D17::DEVICE_31B3: return "ZX-100/ZX-D Power Management Controller";
        case PciDevice1D17::DEVICE_31B4: return "ZX-100/ZX-D I/O APIC";
        case PciDevice1D17::DEVICE_31B5: return "ZX-100/ZX-D Scratch Device";
        case PciDevice1D17::DEVICE_31B7: return "ZX-100/ZX-D/ZX-E Standard Host Bridge";
        case PciDevice1D17::DEVICE_31B8: return "ZX-100/ZX-D PCI to PCI Bridge";
        case PciDevice1D17::DEVICE_3288: return "ZX-100/ZX-D/ZX-E High Definition Audio Controller";
        case PciDevice1D17::DEVICE_345B: return "ZX-100/ZX-D/ZX-E Miscellaneous Bus";
        case PciDevice1D17::DEVICE_3A02: return "ZX-100 C-320 GPU";
        case PciDevice1D17::DEVICE_3A03: return "ZX-D C-860 GPU";
        case PciDevice1D17::DEVICE_3A04: return "ZX-E C-960 GPU";
        case PciDevice1D17::DEVICE_9002: return "ZX-100/ZX-200 EIDE Controller";
        case PciDevice1D17::DEVICE_9003: return "ZX-100/ZX-E EIDE Controller";
        case PciDevice1D17::DEVICE_9045: return "ZX-100/ZX-D/ZX-E RAID Accelerator 0";
        case PciDevice1D17::DEVICE_9046: return "ZX-D/ZX-E RAID Accelerator 1";
        case PciDevice1D17::DEVICE_9083: return "ZX-100/ZX-200/ZX-E StorX AHCI Controller";
        case PciDevice1D17::DEVICE_9084: return "ZX-100 StorX AHCI Controller";
        case PciDevice1D17::DEVICE_9100: return "ZX-200 Cross bus";
        case PciDevice1D17::DEVICE_9101: return "ZX-200 Traffic Controller";
        case PciDevice1D17::DEVICE_9141: return "ZX-100 High Definition Audio Controller";
        case PciDevice1D17::DEVICE_9142: return "ZX-D High Definition Audio Controller";
        case PciDevice1D17::DEVICE_9144: return "ZX-E High Definition Audio Controller";
        case PciDevice1D17::DEVICE_9180: return "ZX-200 Networking Gigabit Ethernet Adapter";
        case PciDevice1D17::DEVICE_9202: return "ZX-100 USB eXtensible Host Controller";
        case PciDevice1D17::DEVICE_9203: return "ZX-200 USB eXtensible Host Controller";
        case PciDevice1D17::DEVICE_9204: return "ZX-E USB eXtensible Host Controller";
        case PciDevice1D17::DEVICE_9286: return "ZX-D eMMC Host Controller";
        case PciDevice1D17::DEVICE_9300: return "ZX-D/ZX-E eSPI Host Controller";
        case PciDevice1D17::DEVICE_95D0: return "ZX-100 Universal SD Host Controller";
        case PciDevice1D17::DEVICE_F410: return "ZX-100/ZX-D/ZX-E PCI Com Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D17_PCIDEVICE1D17_H
