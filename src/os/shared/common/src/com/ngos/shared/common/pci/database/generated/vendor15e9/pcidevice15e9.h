// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E9_PCIDEVICE15E9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E9_PCIDEVICE15E9_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15E9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1841 = 0x1841
};



inline const char8* enumToString(PciDevice15E9 device15E9) // TEST: NO
{
    // COMMON_LT((" | device15E9 = %u", device15E9)); // Commented to avoid bad looking logs



    switch (device15E9)
    {
        case PciDevice15E9::NONE:        return "NONE";
        case PciDevice15E9::DEVICE_1841: return "DEVICE_1841";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15E9 device15E9) // TEST: NO
{
    // COMMON_LT((" | device15E9 = %u", device15E9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15E9, enumToString(device15E9));

    return res;
}



inline const char8* enumToHumanString(PciDevice15E9 device15E9) // TEST: NO
{
    // COMMON_LT((" | device15E9 = %u", device15E9)); // Commented to avoid bad looking logs



    switch (device15E9)
    {
        case PciDevice15E9::DEVICE_1841: return "ADMA-100 DiscStaQ ATA Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E9_PCIDEVICE15E9_H
