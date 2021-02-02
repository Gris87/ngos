// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1385_PCIDEVICE1385_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1385_PCIDEVICE1385_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1385: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_006B = 0x006B,
    DEVICE_4100 = 0x4100,
    DEVICE_4601 = 0x4601,
    DEVICE_620A = 0x620A,
    DEVICE_630A = 0x630A
};



inline const char8* enumToString(PciDevice1385 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1385::NONE:        return "NONE";
        case PciDevice1385::DEVICE_006B: return "DEVICE_006B";
        case PciDevice1385::DEVICE_4100: return "DEVICE_4100";
        case PciDevice1385::DEVICE_4601: return "DEVICE_4601";
        case PciDevice1385::DEVICE_620A: return "DEVICE_620A";
        case PciDevice1385::DEVICE_630A: return "DEVICE_630A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1385 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1385 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1385::DEVICE_006B: return "WA301 802.11b Wireless PCI Adapter";
        case PciDevice1385::DEVICE_4100: return "MA301 802.11b Wireless PCI Adapter";
        case PciDevice1385::DEVICE_4601: return "WAG511 802.11a/b/g Dual Band Wireless PC Card";
        case PciDevice1385::DEVICE_620A: return "GA620 Gigabit Ethernet";
        case PciDevice1385::DEVICE_630A: return "GA630 Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1385_PCIDEVICE1385_H
