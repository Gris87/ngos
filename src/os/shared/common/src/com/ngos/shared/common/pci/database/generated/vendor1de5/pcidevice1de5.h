// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DE5_PCIDEVICE1DE5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DE5_PCIDEVICE1DE5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DE5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_2000 = 0x2000,
    DEVICE_3000 = 0x3000
};



inline const char8* enumToString(PciDevice1DE5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DE5::NONE:        return "NONE";
        case PciDevice1DE5::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1DE5::DEVICE_2000: return "DEVICE_2000";
        case PciDevice1DE5::DEVICE_3000: return "DEVICE_3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DE5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DE5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DE5::DEVICE_1000: return "IO Memory Controller";
        case PciDevice1DE5::DEVICE_2000: return "NoLoad Hardware Development Kit";
        case PciDevice1DE5::DEVICE_3000: return "eBPF-based PCIe Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DE5_PCIDEVICE1DE5_H
