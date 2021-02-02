// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D1_PCIDEVICE13D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D1_PCIDEVICE13D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13D1: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_AB02 = 0xAB02,
    DEVICE_AB03 = 0xAB03,
    DEVICE_AB06 = 0xAB06,
    DEVICE_AB08 = 0xAB08
};



inline const char8* enumToString(PciDevice13D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13D1::NONE:        return "NONE";
        case PciDevice13D1::DEVICE_AB02: return "DEVICE_AB02";
        case PciDevice13D1::DEVICE_AB03: return "DEVICE_AB03";
        case PciDevice13D1::DEVICE_AB06: return "DEVICE_AB06";
        case PciDevice13D1::DEVICE_AB08: return "DEVICE_AB08";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13D1::DEVICE_AB02: return "ADMtek Centaur-C rev 17 [D-Link DFE-680TX] CardBus Fast Ethernet Adapter";
        case PciDevice13D1::DEVICE_AB03: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice13D1::DEVICE_AB06: return "RTL8139 [FE2000VX] CardBus Fast Ethernet Attached Port Adapter";
        case PciDevice13D1::DEVICE_AB08: return "21x4x DEC-Tulip compatible 10/100 Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13D1_PCIDEVICE13D1_H
