// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151C_PCIDEVICE151C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151C_PCIDEVICE151C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice151C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_4000 = 0x4000
};



inline const char8* enumToString(PciDevice151C device151C) // TEST: NO
{
    // COMMON_LT((" | device151C = %u", device151C)); // Commented to avoid bad looking logs



    switch (device151C)
    {
        case PciDevice151C::NONE:        return "NONE";
        case PciDevice151C::DEVICE_0003: return "DEVICE_0003";
        case PciDevice151C::DEVICE_4000: return "DEVICE_4000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice151C device151C) // TEST: NO
{
    // COMMON_LT((" | device151C = %u", device151C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device151C, enumToString(device151C));

    return res;
}



inline const char8* enumToHumanString(PciDevice151C device151C) // TEST: NO
{
    // COMMON_LT((" | device151C = %u", device151C)); // Commented to avoid bad looking logs



    switch (device151C)
    {
        case PciDevice151C::DEVICE_0003: return "Prodif T 2496";
        case PciDevice151C::DEVICE_4000: return "Prodif 88";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151C_PCIDEVICE151C_H
