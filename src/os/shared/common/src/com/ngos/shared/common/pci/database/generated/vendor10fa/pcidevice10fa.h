// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FA_PCIDEVICE10FA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FA_PCIDEVICE10FA_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10FA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000C = 0x000C
};



inline const char8* enumToString(PciDevice10FA device10FA) // TEST: NO
{
    // COMMON_LT((" | device10FA = %u", device10FA)); // Commented to avoid bad looking logs



    switch (device10FA)
    {
        case PciDevice10FA::NONE:        return "NONE";
        case PciDevice10FA::DEVICE_000C: return "DEVICE_000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10FA device10FA) // TEST: NO
{
    // COMMON_LT((" | device10FA = %u", device10FA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10FA, enumToString(device10FA));

    return res;
}



inline const char8* enumToHumanString(PciDevice10FA device10FA) // TEST: NO
{
    // COMMON_LT((" | device10FA = %u", device10FA)); // Commented to avoid bad looking logs



    switch (device10FA)
    {
        case PciDevice10FA::DEVICE_000C: return "TARGA 1000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FA_PCIDEVICE10FA_H
