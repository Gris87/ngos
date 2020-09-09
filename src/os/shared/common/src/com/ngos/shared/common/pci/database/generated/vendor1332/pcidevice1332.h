// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1332_PCIDEVICE1332_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1332_PCIDEVICE1332_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1332: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5415 = 0x5415,
    DEVICE_5425 = 0x5425,
    DEVICE_6140 = 0x6140
};



inline const char8* enumToString(PciDevice1332 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1332::NONE:        return "NONE";
        case PciDevice1332::DEVICE_5415: return "DEVICE_5415";
        case PciDevice1332::DEVICE_5425: return "DEVICE_5425";
        case PciDevice1332::DEVICE_6140: return "DEVICE_6140";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1332 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1332 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1332::DEVICE_5415: return "MM-5415CN PCI Memory Module with Battery Backup";
        case PciDevice1332::DEVICE_5425: return "MM-5425CN PCI 64/66 Memory Module with Battery Backup";
        case PciDevice1332::DEVICE_6140: return "MM-6140D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1332_PCIDEVICE1332_H
