// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1462: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3483 = 0x3483,
    DEVICE_7C56 = 0x7C56,
    DEVICE_AAF0 = 0xAAF0
};



inline const char8* enumToString(PciDevice1462 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1462::NONE:        return "NONE";
        case PciDevice1462::DEVICE_3483: return "DEVICE_3483";
        case PciDevice1462::DEVICE_7C56: return "DEVICE_7C56";
        case PciDevice1462::DEVICE_AAF0: return "DEVICE_AAF0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1462 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1462 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1462::DEVICE_3483: return "MSI USB 3.0 (VIA VL80x-based xHCI USB Controller)";
        case PciDevice1462::DEVICE_7C56: return "Realtek Ethernet controller RTL8111H";
        case PciDevice1462::DEVICE_AAF0: return "Radeon RX 580 Gaming X 8G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1462_PCIDEVICE1462_H
