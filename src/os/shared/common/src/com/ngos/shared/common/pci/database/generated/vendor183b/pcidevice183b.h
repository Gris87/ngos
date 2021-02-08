// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR183B_PCIDEVICE183B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR183B_PCIDEVICE183B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice183B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_08A7 = 0x08A7,
    DEVICE_08A8 = 0x08A8,
    DEVICE_08A9 = 0x08A9,
    DEVICE_08B0 = 0x08B0
};



inline const char8* enumToString(PciDevice183B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice183B::NONE:        return "NONE";
        case PciDevice183B::DEVICE_08A7: return "DEVICE_08A7";
        case PciDevice183B::DEVICE_08A8: return "DEVICE_08A8";
        case PciDevice183B::DEVICE_08A9: return "DEVICE_08A9";
        case PciDevice183B::DEVICE_08B0: return "DEVICE_08B0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice183B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice183B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice183B::DEVICE_08A7: return "MVC100 DVI";
        case PciDevice183B::DEVICE_08A8: return "MVC101 SDI";
        case PciDevice183B::DEVICE_08A9: return "MVC102 DVI+Audio";
        case PciDevice183B::DEVICE_08B0: return "MVC200-DC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR183B_PCIDEVICE183B_H
