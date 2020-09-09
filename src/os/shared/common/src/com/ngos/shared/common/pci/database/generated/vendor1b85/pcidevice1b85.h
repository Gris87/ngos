// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B85_PCIDEVICE1B85_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B85_PCIDEVICE1B85_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B85: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1041 = 0x1041,
    DEVICE_6018 = 0x6018,
    DEVICE_8788 = 0x8788
};



inline const char8* enumToString(PciDevice1B85 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B85::NONE:        return "NONE";
        case PciDevice1B85::DEVICE_1041: return "DEVICE_1041";
        case PciDevice1B85::DEVICE_6018: return "DEVICE_6018";
        case PciDevice1B85::DEVICE_8788: return "DEVICE_8788";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B85 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B85 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B85::DEVICE_1041: return "RevoDrive 3 X2 PCI-Express SSD 240 GB (Marvell Controller)";
        case PciDevice1B85::DEVICE_6018: return "RD400/400A SSD";
        case PciDevice1B85::DEVICE_8788: return "RevoDrive Hybrid";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B85_PCIDEVICE1B85_H
