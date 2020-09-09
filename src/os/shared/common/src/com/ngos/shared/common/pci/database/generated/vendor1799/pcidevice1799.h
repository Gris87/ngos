// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1799_PCIDEVICE1799_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1799_PCIDEVICE1799_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1799: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6001 = 0x6001,
    DEVICE_6020 = 0x6020,
    DEVICE_6060 = 0x6060,
    DEVICE_700F = 0x700F,
    DEVICE_701F = 0x701F
};



inline const char8* enumToString(PciDevice1799 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1799::NONE:        return "NONE";
        case PciDevice1799::DEVICE_6001: return "DEVICE_6001";
        case PciDevice1799::DEVICE_6020: return "DEVICE_6020";
        case PciDevice1799::DEVICE_6060: return "DEVICE_6060";
        case PciDevice1799::DEVICE_700F: return "DEVICE_700F";
        case PciDevice1799::DEVICE_701F: return "DEVICE_701F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1799 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1799 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1799::DEVICE_6001: return "F5D6001 Wireless PCI Card [Realtek RTL8180]";
        case PciDevice1799::DEVICE_6020: return "F5D6020 v3000 Wireless PCMCIA Card [Realtek RTL8180]";
        case PciDevice1799::DEVICE_6060: return "F5D6060 Wireless PDA Card";
        case PciDevice1799::DEVICE_700F: return "F5D7000 v7000 Wireless G Desktop Card [Realtek RTL8185]";
        case PciDevice1799::DEVICE_701F: return "F5D7010 v7000 Wireless G Notebook Card [Realtek RTL8185]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1799_PCIDEVICE1799_H
