// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1458_PCIDEVICE1458_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1458_PCIDEVICE1458_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1458: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_22E8 = 0x22E8,
    DEVICE_3483 = 0x3483
};



inline const char8* enumToString(PciDevice1458 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1458::NONE:        return "NONE";
        case PciDevice1458::DEVICE_22E8: return "DEVICE_22E8";
        case PciDevice1458::DEVICE_3483: return "DEVICE_3483";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1458 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1458 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1458::DEVICE_22E8: return "Ellesmere [Radeon RX 480]";
        case PciDevice1458::DEVICE_3483: return "USB 3.0 Controller (VIA VL80x-based xHCI Controller)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1458_PCIDEVICE1458_H
