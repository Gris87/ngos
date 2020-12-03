// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2646: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2263 = 0x2263,
    DEVICE_500D = 0x500D
};



inline const char8* enumToString(PciDevice2646 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2646::NONE:        return "NONE";
        case PciDevice2646::DEVICE_2263: return "DEVICE_2263";
        case PciDevice2646::DEVICE_500D: return "DEVICE_500D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2646 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice2646 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2646::DEVICE_2263: return "A2000 NVMe SSD";
        case PciDevice2646::DEVICE_500D: return "OM3PDP3 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H
