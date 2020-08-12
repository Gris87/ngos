// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107F_PCIDEVICE107F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107F_PCIDEVICE107F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice107F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0802 = 0x0802
};



inline const char8* enumToString(PciDevice107F device107F) // TEST: NO
{
    // COMMON_LT((" | device107F = %u", device107F)); // Commented to avoid bad looking logs



    switch (device107F)
    {
        case PciDevice107F::NONE:        return "NONE";
        case PciDevice107F::DEVICE_0802: return "DEVICE_0802";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice107F device107F) // TEST: NO
{
    // COMMON_LT((" | device107F = %u", device107F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device107F, enumToString(device107F));

    return res;
}



inline const char8* enumToHumanString(PciDevice107F device107F) // TEST: NO
{
    // COMMON_LT((" | device107F = %u", device107F)); // Commented to avoid bad looking logs



    switch (device107F)
    {
        case PciDevice107F::DEVICE_0802: return "SL82C105";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107F_PCIDEVICE107F_H
