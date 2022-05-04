// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2646: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_2262 = 0x2262,
    DEVICE_2263 = 0x2263,
    DEVICE_5008 = 0x5008,
    DEVICE_500D = 0x500D,
    DEVICE_500E = 0x500E
};



inline const char8* enumToString(PciDevice2646 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2646::NONE:        return "NONE";
        case PciDevice2646::DEVICE_0010: return "DEVICE_0010";
        case PciDevice2646::DEVICE_2262: return "DEVICE_2262";
        case PciDevice2646::DEVICE_2263: return "DEVICE_2263";
        case PciDevice2646::DEVICE_5008: return "DEVICE_5008";
        case PciDevice2646::DEVICE_500D: return "DEVICE_500D";
        case PciDevice2646::DEVICE_500E: return "DEVICE_500E";

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
        case PciDevice2646::DEVICE_0010: return "HyperX Predator PCIe AHCI SSD";
        case PciDevice2646::DEVICE_2262: return "KC2000 NVMe SSD";
        case PciDevice2646::DEVICE_2263: return "A2000 NVMe SSD";
        case PciDevice2646::DEVICE_5008: return "U-SNS8154P3 NVMe SSD";
        case PciDevice2646::DEVICE_500D: return "OM3PDP3 NVMe SSD";
        case PciDevice2646::DEVICE_500E: return "SNVS2000G [NV1 NVMe PCIe SSD 2TB]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2646_PCIDEVICE2646_H
