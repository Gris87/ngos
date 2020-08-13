// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B9_PCIDEVICE14B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B9_PCIDEVICE14B9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14B9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0340 = 0x0340,
    DEVICE_0350 = 0x0350,
    DEVICE_4500 = 0x4500,
    DEVICE_4800 = 0x4800,
    DEVICE_A504 = 0xA504,
    DEVICE_A505 = 0xA505,
    DEVICE_A506 = 0xA506
};



inline const char8* enumToString(PciDevice14B9 device14B9) // TEST: NO
{
    // COMMON_LT((" | device14B9 = %u", device14B9)); // Commented to avoid bad looking logs



    switch (device14B9)
    {
        case PciDevice14B9::NONE:        return "NONE";
        case PciDevice14B9::DEVICE_0001: return "DEVICE_0001";
        case PciDevice14B9::DEVICE_0340: return "DEVICE_0340";
        case PciDevice14B9::DEVICE_0350: return "DEVICE_0350";
        case PciDevice14B9::DEVICE_4500: return "DEVICE_4500";
        case PciDevice14B9::DEVICE_4800: return "DEVICE_4800";
        case PciDevice14B9::DEVICE_A504: return "DEVICE_A504";
        case PciDevice14B9::DEVICE_A505: return "DEVICE_A505";
        case PciDevice14B9::DEVICE_A506: return "DEVICE_A506";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14B9 device14B9) // TEST: NO
{
    // COMMON_LT((" | device14B9 = %u", device14B9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14B9, enumToString(device14B9));

    return res;
}



inline const char8* enumToHumanString(PciDevice14B9 device14B9) // TEST: NO
{
    // COMMON_LT((" | device14B9 = %u", device14B9)); // Commented to avoid bad looking logs



    switch (device14B9)
    {
        case PciDevice14B9::DEVICE_0001: return "PC4800";
        case PciDevice14B9::DEVICE_0340: return "PC4800";
        case PciDevice14B9::DEVICE_0350: return "350 series 802.11b Wireless LAN Adapter";
        case PciDevice14B9::DEVICE_4500: return "PC4500";
        case PciDevice14B9::DEVICE_4800: return "Cisco Aironet 340 802.11b Wireless LAN Adapter/Aironet PC4800";
        case PciDevice14B9::DEVICE_A504: return "Cisco Aironet Wireless 802.11b";
        case PciDevice14B9::DEVICE_A505: return "Cisco Aironet CB20a 802.11a Wireless LAN Adapter";
        case PciDevice14B9::DEVICE_A506: return "Cisco Aironet Mini PCI b/g";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B9_PCIDEVICE14B9_H
