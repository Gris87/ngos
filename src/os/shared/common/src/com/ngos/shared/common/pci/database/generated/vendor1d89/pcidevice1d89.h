// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D89_PCIDEVICE1D89_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D89_PCIDEVICE1D89_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D89: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0280 = 0x0280
};



inline const char8* enumToString(PciDevice1D89 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D89::NONE:        return "NONE";
        case PciDevice1D89::DEVICE_0280: return "DEVICE_0280";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D89 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D89 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D89::DEVICE_0280: return "PCIe NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D89_PCIDEVICE1D89_H
