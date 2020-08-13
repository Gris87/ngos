// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR145F_PCIDEVICE145F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR145F_PCIDEVICE145F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice145F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice145F device145F) // TEST: NO
{
    // COMMON_LT((" | device145F = %u", device145F)); // Commented to avoid bad looking logs



    switch (device145F)
    {
        case PciDevice145F::NONE:        return "NONE";
        case PciDevice145F::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice145F device145F) // TEST: NO
{
    // COMMON_LT((" | device145F = %u", device145F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device145F, enumToString(device145F));

    return res;
}



inline const char8* enumToHumanString(PciDevice145F device145F) // TEST: NO
{
    // COMMON_LT((" | device145F = %u", device145F)); // Commented to avoid bad looking logs



    switch (device145F)
    {
        case PciDevice145F::DEVICE_0001: return "NextMove PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR145F_PCIDEVICE145F_H
