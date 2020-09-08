// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14C3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7630 = 0x7630,
    DEVICE_7662 = 0x7662
};



inline const char8* enumToString(PciDevice14C3 device14C3) // TEST: NO
{
    // COMMON_LT((" | device14C3 = %u", device14C3)); // Commented to avoid bad looking logs



    switch (device14C3)
    {
        case PciDevice14C3::NONE:        return "NONE";
        case PciDevice14C3::DEVICE_7630: return "DEVICE_7630";
        case PciDevice14C3::DEVICE_7662: return "DEVICE_7662";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14C3 device14C3) // TEST: NO
{
    // COMMON_LT((" | device14C3 = %u", device14C3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14C3, enumToString(device14C3));

    return res;
}



inline const char8* enumToHumanString(PciDevice14C3 device14C3) // TEST: NO
{
    // COMMON_LT((" | device14C3 = %u", device14C3)); // Commented to avoid bad looking logs



    switch (device14C3)
    {
        case PciDevice14C3::DEVICE_7630: return "MT7630e 802.11bgn Wireless Network Adapter";
        case PciDevice14C3::DEVICE_7662: return "MT7662E 802.11ac PCI Express Wireless Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C3_PCIDEVICE14C3_H