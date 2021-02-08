// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1112_PCIDEVICE1112_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1112_PCIDEVICE1112_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1112: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2200 = 0x2200,
    DEVICE_2300 = 0x2300,
    DEVICE_2340 = 0x2340,
    DEVICE_2400 = 0x2400
};



inline const char8* enumToString(PciDevice1112 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1112::NONE:        return "NONE";
        case PciDevice1112::DEVICE_2200: return "DEVICE_2200";
        case PciDevice1112::DEVICE_2300: return "DEVICE_2300";
        case PciDevice1112::DEVICE_2340: return "DEVICE_2340";
        case PciDevice1112::DEVICE_2400: return "DEVICE_2400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1112 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1112 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1112::DEVICE_2200: return "FDDI Adapter";
        case PciDevice1112::DEVICE_2300: return "Fast Ethernet Adapter";
        case PciDevice1112::DEVICE_2340: return "4 Port Fast Ethernet Adapter";
        case PciDevice1112::DEVICE_2400: return "ATM Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1112_PCIDEVICE1112_H
