// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1592_PCIDEVICE1592_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1592_PCIDEVICE1592_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1592: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0781 = 0x0781,
    DEVICE_0782 = 0x0782,
    DEVICE_0783 = 0x0783,
    DEVICE_0785 = 0x0785,
    DEVICE_0786 = 0x0786,
    DEVICE_0787 = 0x0787,
    DEVICE_0788 = 0x0788,
    DEVICE_078A = 0x078A
};



inline const char8* enumToString(PciDevice1592 device1592) // TEST: NO
{
    // COMMON_LT((" | device1592 = %u", device1592)); // Commented to avoid bad looking logs



    switch (device1592)
    {
        case PciDevice1592::NONE:        return "NONE";
        case PciDevice1592::DEVICE_0781: return "DEVICE_0781";
        case PciDevice1592::DEVICE_0782: return "DEVICE_0782";
        case PciDevice1592::DEVICE_0783: return "DEVICE_0783";
        case PciDevice1592::DEVICE_0785: return "DEVICE_0785";
        case PciDevice1592::DEVICE_0786: return "DEVICE_0786";
        case PciDevice1592::DEVICE_0787: return "DEVICE_0787";
        case PciDevice1592::DEVICE_0788: return "DEVICE_0788";
        case PciDevice1592::DEVICE_078A: return "DEVICE_078A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1592 device1592) // TEST: NO
{
    // COMMON_LT((" | device1592 = %u", device1592)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1592, enumToString(device1592));

    return res;
}



inline const char8* enumToHumanString(PciDevice1592 device1592) // TEST: NO
{
    // COMMON_LT((" | device1592 = %u", device1592)); // Commented to avoid bad looking logs



    switch (device1592)
    {
        case PciDevice1592::DEVICE_0781: return "Multi-IO Card";
        case PciDevice1592::DEVICE_0782: return "Parallel Port Card 2xEPP";
        case PciDevice1592::DEVICE_0783: return "Multi-IO Card";
        case PciDevice1592::DEVICE_0785: return "Multi-IO Card";
        case PciDevice1592::DEVICE_0786: return "Multi-IO Card";
        case PciDevice1592::DEVICE_0787: return "Multi-IO Card";
        case PciDevice1592::DEVICE_0788: return "Multi-IO Card";
        case PciDevice1592::DEVICE_078A: return "Multi-IO Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1592_PCIDEVICE1592_H
