// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR22B8_PCIDEVICE22B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR22B8_PCIDEVICE22B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice22B8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_22A0 = 0x22A0
};



inline const char8* enumToString(PciDevice22B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice22B8::NONE:        return "NONE";
        case PciDevice22B8::DEVICE_22A0: return "DEVICE_22A0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice22B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice22B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice22B8::DEVICE_22A0: return "Flex Logix InferX X1 Inference Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR22B8_PCIDEVICE22B8_H
