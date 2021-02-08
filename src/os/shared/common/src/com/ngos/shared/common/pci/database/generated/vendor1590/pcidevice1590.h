// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1590_PCIDEVICE1590_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1590_PCIDEVICE1590_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1590: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_A01D = 0xA01D
};



inline const char8* enumToString(PciDevice1590 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1590::NONE:        return "NONE";
        case PciDevice1590::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1590::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1590::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1590::DEVICE_A01D: return "DEVICE_A01D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1590 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1590 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1590::DEVICE_0001: return "Eagle Cluster Manager";
        case PciDevice1590::DEVICE_0002: return "Osprey Cluster Manager";
        case PciDevice1590::DEVICE_0003: return "Harrier Cluster Manager";
        case PciDevice1590::DEVICE_A01D: return "FC044X Fibre Channel HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1590_PCIDEVICE1590_H
