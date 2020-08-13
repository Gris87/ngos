// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E0F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0007 = 0x0007
};



inline const char8* enumToString(PciDevice1E0F device1E0F) // TEST: NO
{
    // COMMON_LT((" | device1E0F = %u", device1E0F)); // Commented to avoid bad looking logs



    switch (device1E0F)
    {
        case PciDevice1E0F::NONE:        return "NONE";
        case PciDevice1E0F::DEVICE_0007: return "DEVICE_0007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E0F device1E0F) // TEST: NO
{
    // COMMON_LT((" | device1E0F = %u", device1E0F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E0F, enumToString(device1E0F));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E0F device1E0F) // TEST: NO
{
    // COMMON_LT((" | device1E0F = %u", device1E0F)); // Commented to avoid bad looking logs



    switch (device1E0F)
    {
        case PciDevice1E0F::DEVICE_0007: return "NVMe SSD Controller Cx6";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H
