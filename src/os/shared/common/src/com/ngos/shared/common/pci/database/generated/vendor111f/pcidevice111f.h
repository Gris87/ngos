// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111F_PCIDEVICE111F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111F_PCIDEVICE111F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice111F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4A47 = 0x4A47,
    DEVICE_5243 = 0x5243
};



inline const char8* enumToString(PciDevice111F device111F) // TEST: NO
{
    // COMMON_LT((" | device111F = %u", device111F)); // Commented to avoid bad looking logs



    switch (device111F)
    {
        case PciDevice111F::NONE:        return "NONE";
        case PciDevice111F::DEVICE_4A47: return "DEVICE_4A47";
        case PciDevice111F::DEVICE_5243: return "DEVICE_5243";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice111F device111F) // TEST: NO
{
    // COMMON_LT((" | device111F = %u", device111F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device111F, enumToString(device111F));

    return res;
}



inline const char8* enumToHumanString(PciDevice111F device111F) // TEST: NO
{
    // COMMON_LT((" | device111F = %u", device111F)); // Commented to avoid bad looking logs



    switch (device111F)
    {
        case PciDevice111F::DEVICE_4A47: return "Precision MX Video engine interface";
        case PciDevice111F::DEVICE_5243: return "Frame capture bus interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111F_PCIDEVICE111F_H
