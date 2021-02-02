// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1045_PCIDEVICE1045_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1045_PCIDEVICE1045_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1045: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A0F8 = 0xA0F8,
    DEVICE_C101 = 0xC101,
    DEVICE_C178 = 0xC178,
    DEVICE_C556 = 0xC556,
    DEVICE_C557 = 0xC557,
    DEVICE_C558 = 0xC558,
    DEVICE_C567 = 0xC567,
    DEVICE_C568 = 0xC568,
    DEVICE_C569 = 0xC569,
    DEVICE_C621 = 0xC621,
    DEVICE_C700 = 0xC700,
    DEVICE_C701 = 0xC701,
    DEVICE_C814 = 0xC814,
    DEVICE_C822 = 0xC822,
    DEVICE_C824 = 0xC824,
    DEVICE_C825 = 0xC825,
    DEVICE_C832 = 0xC832,
    DEVICE_C861 = 0xC861,
    DEVICE_C881 = 0xC881,
    DEVICE_C895 = 0xC895,
    DEVICE_C935 = 0xC935,
    DEVICE_D568 = 0xD568,
    DEVICE_D721 = 0xD721
};



inline const char8* enumToString(PciDevice1045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1045::NONE:        return "NONE";
        case PciDevice1045::DEVICE_A0F8: return "DEVICE_A0F8";
        case PciDevice1045::DEVICE_C101: return "DEVICE_C101";
        case PciDevice1045::DEVICE_C178: return "DEVICE_C178";
        case PciDevice1045::DEVICE_C556: return "DEVICE_C556";
        case PciDevice1045::DEVICE_C557: return "DEVICE_C557";
        case PciDevice1045::DEVICE_C558: return "DEVICE_C558";
        case PciDevice1045::DEVICE_C567: return "DEVICE_C567";
        case PciDevice1045::DEVICE_C568: return "DEVICE_C568";
        case PciDevice1045::DEVICE_C569: return "DEVICE_C569";
        case PciDevice1045::DEVICE_C621: return "DEVICE_C621";
        case PciDevice1045::DEVICE_C700: return "DEVICE_C700";
        case PciDevice1045::DEVICE_C701: return "DEVICE_C701";
        case PciDevice1045::DEVICE_C814: return "DEVICE_C814";
        case PciDevice1045::DEVICE_C822: return "DEVICE_C822";
        case PciDevice1045::DEVICE_C824: return "DEVICE_C824";
        case PciDevice1045::DEVICE_C825: return "DEVICE_C825";
        case PciDevice1045::DEVICE_C832: return "DEVICE_C832";
        case PciDevice1045::DEVICE_C861: return "DEVICE_C861";
        case PciDevice1045::DEVICE_C881: return "DEVICE_C881";
        case PciDevice1045::DEVICE_C895: return "DEVICE_C895";
        case PciDevice1045::DEVICE_C935: return "DEVICE_C935";
        case PciDevice1045::DEVICE_D568: return "DEVICE_D568";
        case PciDevice1045::DEVICE_D721: return "DEVICE_D721";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1045::DEVICE_A0F8: return "82C750 [Vendetta] USB Controller";
        case PciDevice1045::DEVICE_C101: return "92C264";
        case PciDevice1045::DEVICE_C178: return "92C178";
        case PciDevice1045::DEVICE_C556: return "82X556 [Viper]";
        case PciDevice1045::DEVICE_C557: return "82C557 [Viper-M]";
        case PciDevice1045::DEVICE_C558: return "82C558 [Viper-M ISA+IDE]";
        case PciDevice1045::DEVICE_C567: return "82C750 [Vendetta], device 0";
        case PciDevice1045::DEVICE_C568: return "82C750 [Vendetta], device 1";
        case PciDevice1045::DEVICE_C569: return "82C579 [Viper XPress+ Chipset]";
        case PciDevice1045::DEVICE_C621: return "82C621 [Viper-M/N+]";
        case PciDevice1045::DEVICE_C700: return "82C700 [FireStar]";
        case PciDevice1045::DEVICE_C701: return "82C701 [FireStar Plus]";
        case PciDevice1045::DEVICE_C814: return "82C814 [Firebridge 1]";
        case PciDevice1045::DEVICE_C822: return "82C822";
        case PciDevice1045::DEVICE_C824: return "82C824";
        case PciDevice1045::DEVICE_C825: return "82C825 [Firebridge 2]";
        case PciDevice1045::DEVICE_C832: return "82C832";
        case PciDevice1045::DEVICE_C861: return "82C861 OHCI USB Host";
        case PciDevice1045::DEVICE_C881: return "82C881 [FireLink] 1394 OHCI Link Controller";
        case PciDevice1045::DEVICE_C895: return "82C895";
        case PciDevice1045::DEVICE_C935: return "EV1935 ECTIVA MachOne PCIAudio";
        case PciDevice1045::DEVICE_D568: return "82C825 [Firebridge 2]";
        case PciDevice1045::DEVICE_D721: return "IDE [FireStar]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1045_PCIDEVICE1045_H
