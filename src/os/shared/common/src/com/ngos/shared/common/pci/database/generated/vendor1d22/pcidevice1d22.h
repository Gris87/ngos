// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D22_PCIDEVICE1D22_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D22_PCIDEVICE1D22_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D22: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1380 = 0x1380,
    DEVICE_3684 = 0x3684,
    DEVICE_3685 = 0x3685
};



inline const char8* enumToString(PciDevice1D22 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D22::NONE:        return "NONE";
        case PciDevice1D22::DEVICE_1380: return "DEVICE_1380";
        case PciDevice1D22::DEVICE_3684: return "DEVICE_3684";
        case PciDevice1D22::DEVICE_3685: return "DEVICE_3685";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D22 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D22 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D22::DEVICE_1380: return "Cloud Storage Device";
        case PciDevice1D22::DEVICE_3684: return "Kunlun AI Accelerator";
        case PciDevice1D22::DEVICE_3685: return "Kunlun2 AI Accelerator [VF]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D22_PCIDEVICE1D22_H
