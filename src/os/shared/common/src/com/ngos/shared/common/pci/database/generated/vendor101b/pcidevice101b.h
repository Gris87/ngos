// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101B_PCIDEVICE101B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101B_PCIDEVICE101B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice101B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0452 = 0x0452
};



inline const char8* enumToString(PciDevice101B device101B) // TEST: NO
{
    // COMMON_LT((" | device101B = %u", device101B)); // Commented to avoid bad looking logs



    switch (device101B)
    {
        case PciDevice101B::NONE:        return "NONE";
        case PciDevice101B::DEVICE_0452: return "DEVICE_0452";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice101B device101B) // TEST: NO
{
    // COMMON_LT((" | device101B = %u", device101B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device101B, enumToString(device101B));

    return res;
}



inline const char8* enumToHumanString(PciDevice101B device101B) // TEST: NO
{
    // COMMON_LT((" | device101B = %u", device101B)); // Commented to avoid bad looking logs



    switch (device101B)
    {
        case PciDevice101B::DEVICE_0452: return "VSC452 [SuperBMC]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101B_PCIDEVICE101B_H
