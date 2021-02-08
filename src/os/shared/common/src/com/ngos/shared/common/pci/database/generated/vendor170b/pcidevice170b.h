// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR170B_PCIDEVICE170B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR170B_PCIDEVICE170B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice170B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice170B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice170B::NONE:        return "NONE";
        case PciDevice170B::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice170B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice170B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice170B::DEVICE_0100: return "NSP2000-SSL crypto accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR170B_PCIDEVICE170B_H
