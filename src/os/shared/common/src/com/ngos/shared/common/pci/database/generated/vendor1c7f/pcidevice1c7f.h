// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7F_PCIDEVICE1C7F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7F_PCIDEVICE1C7F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C7F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5100 = 0x5100
};



inline const char8* enumToString(PciDevice1C7F device1C7F) // TEST: NO
{
    // COMMON_LT((" | device1C7F = %u", device1C7F)); // Commented to avoid bad looking logs



    switch (device1C7F)
    {
        case PciDevice1C7F::NONE:        return "NONE";
        case PciDevice1C7F::DEVICE_5100: return "DEVICE_5100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C7F device1C7F) // TEST: NO
{
    // COMMON_LT((" | device1C7F = %u", device1C7F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C7F, enumToString(device1C7F));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C7F device1C7F) // TEST: NO
{
    // COMMON_LT((" | device1C7F = %u", device1C7F)); // Commented to avoid bad looking logs



    switch (device1C7F)
    {
        case PciDevice1C7F::DEVICE_5100: return "EB5100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7F_PCIDEVICE1C7F_H
