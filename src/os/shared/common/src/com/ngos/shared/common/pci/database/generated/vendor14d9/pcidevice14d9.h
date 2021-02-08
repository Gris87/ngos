// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D9_PCIDEVICE14D9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D9_PCIDEVICE14D9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14D9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_9000 = 0x9000
};



inline const char8* enumToString(PciDevice14D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D9::NONE:        return "NONE";
        case PciDevice14D9::DEVICE_0010: return "DEVICE_0010";
        case PciDevice14D9::DEVICE_9000: return "DEVICE_9000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D9::DEVICE_0010: return "AP1011/SP1011 HyperTransport-PCI Bridge [Sturgeon]";
        case PciDevice14D9::DEVICE_9000: return "AS90L10204/10208 HyperTransport to PCI-X Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D9_PCIDEVICE14D9_H
