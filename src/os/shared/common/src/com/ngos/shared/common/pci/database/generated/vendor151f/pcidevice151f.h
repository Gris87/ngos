// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151F_PCIDEVICE151F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151F_PCIDEVICE151F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice151F: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice151F device151F) // TEST: NO
{
    // COMMON_LT((" | device151F = %u", device151F)); // Commented to avoid bad looking logs



    switch (device151F)
    {
        case PciDevice151F::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice151F device151F) // TEST: NO
{
    // COMMON_LT((" | device151F = %u", device151F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device151F, enumToString(device151F));

    return res;
}



inline const char8* enumToHumanString(PciDevice151F device151F) // TEST: NO
{
    // COMMON_LT((" | device151F = %u", device151F)); // Commented to avoid bad looking logs



    switch (device151F)
    {
        case PciDevice151F::DEVICE_0000: return "TP560 Data/Fax/Voice 56k modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151F_PCIDEVICE151F_H
