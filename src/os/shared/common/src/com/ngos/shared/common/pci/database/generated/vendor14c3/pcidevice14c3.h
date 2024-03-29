// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14C3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0608 = 0x0608,
    DEVICE_0616 = 0x0616,
    DEVICE_7612 = 0x7612,
    DEVICE_7615 = 0x7615,
    DEVICE_7630 = 0x7630,
    DEVICE_7662 = 0x7662,
    DEVICE_7915 = 0x7915,
    DEVICE_7961 = 0x7961
};



inline const char8* enumToString(PciDevice14C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14C3::NONE:        return "NONE";
        case PciDevice14C3::DEVICE_0608: return "DEVICE_0608";
        case PciDevice14C3::DEVICE_0616: return "DEVICE_0616";
        case PciDevice14C3::DEVICE_7612: return "DEVICE_7612";
        case PciDevice14C3::DEVICE_7615: return "DEVICE_7615";
        case PciDevice14C3::DEVICE_7630: return "DEVICE_7630";
        case PciDevice14C3::DEVICE_7662: return "DEVICE_7662";
        case PciDevice14C3::DEVICE_7915: return "DEVICE_7915";
        case PciDevice14C3::DEVICE_7961: return "DEVICE_7961";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14C3::DEVICE_0608: return "MT7921K (RZ608) Wi-Fi 6E 80MHz";
        case PciDevice14C3::DEVICE_0616: return "MT7922 802.11ax PCI Express Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7612: return "MT7612E 802.11acbgn PCI Express Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7615: return "MT7615E 802.11ac PCI Express Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7630: return "MT7630e 802.11bgn Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7662: return "MT7662E 802.11ac PCI Express Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7915: return "MT7915E 802.11ax PCI Express Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7961: return "MT7921 802.11ax PCI Express Wireless Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H
