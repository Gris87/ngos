// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE9_PCIDEVICE1AE9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE9_PCIDEVICE1AE9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AE9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0310 = 0x0310
};



inline const char8* enumToString(PciDevice1AE9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE9::NONE:        return "NONE";
        case PciDevice1AE9::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1AE9::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1AE9::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1AE9::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1AE9::DEVICE_0302: return "DEVICE_0302";
        case PciDevice1AE9::DEVICE_0310: return "DEVICE_0310";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AE9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AE9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE9::DEVICE_0101: return "Wil6200 PCI Express Upstream Port";
        case PciDevice1AE9::DEVICE_0200: return "Wil6200 PCI Express Port";
        case PciDevice1AE9::DEVICE_0201: return "Wil6200 Wireless PCI Express Port";
        case PciDevice1AE9::DEVICE_0301: return "Wil6200 802.11ad Wireless Network Adapter";
        case PciDevice1AE9::DEVICE_0302: return "Wil6200 802.11ad Wireless Network Adapter";
        case PciDevice1AE9::DEVICE_0310: return "Wil6200 802.11ad Wireless Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE9_PCIDEVICE1AE9_H
