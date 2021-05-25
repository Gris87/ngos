// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA3_PCIDEVICE1DA3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA3_PCIDEVICE1DA3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DA3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1000 = 0x1000,
    DEVICE_1010 = 0x1010
};



inline const char8* enumToString(PciDevice1DA3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DA3::NONE:        return "NONE";
        case PciDevice1DA3::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1DA3::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1DA3::DEVICE_1010: return "DEVICE_1010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DA3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DA3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DA3::DEVICE_0001: return "HL-1000 AI Inference Accelerator [Goya]";
        case PciDevice1DA3::DEVICE_1000: return "HL-2000 AI Training Accelerator [Gaudi]";
        case PciDevice1DA3::DEVICE_1010: return "HL-2000 AI Training Accelerator [Gaudi secured]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA3_PCIDEVICE1DA3_H
