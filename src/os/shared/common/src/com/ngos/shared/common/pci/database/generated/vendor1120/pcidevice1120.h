// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1120_PCIDEVICE1120_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1120_PCIDEVICE1120_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1120: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2306 = 0x2306,
    DEVICE_2501 = 0x2501,
    DEVICE_2505 = 0x2505
};



inline const char8* enumToString(PciDevice1120 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1120::NONE:        return "NONE";
        case PciDevice1120::DEVICE_2306: return "DEVICE_2306";
        case PciDevice1120::DEVICE_2501: return "DEVICE_2501";
        case PciDevice1120::DEVICE_2505: return "DEVICE_2505";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1120 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1120 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1120::DEVICE_2306: return "Unity Fibre Channel Controller";
        case PciDevice1120::DEVICE_2501: return "Unity Ethernet Controller";
        case PciDevice1120::DEVICE_2505: return "Unity Fibre Channel Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1120_PCIDEVICE1120_H
