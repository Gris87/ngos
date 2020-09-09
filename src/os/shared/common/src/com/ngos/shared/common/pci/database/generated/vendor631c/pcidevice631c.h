// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR631C_PCIDEVICE631C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR631C_PCIDEVICE631C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice631C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1652 = 0x1652,
    DEVICE_2504 = 0x2504
};



inline const char8* enumToString(PciDevice631C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice631C::NONE:        return "NONE";
        case PciDevice631C::DEVICE_1652: return "DEVICE_1652";
        case PciDevice631C::DEVICE_2504: return "DEVICE_2504";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice631C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice631C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice631C::DEVICE_1652: return "PXI-1652 Signal Generator";
        case PciDevice631C::DEVICE_2504: return "PXI-2504 Signal Interrogator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR631C_PCIDEVICE631C_H
