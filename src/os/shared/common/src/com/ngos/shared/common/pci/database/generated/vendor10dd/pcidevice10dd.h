// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCIDEVICE10DD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCIDEVICE10DD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10DD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice10DD device10DD) // TEST: NO
{
    // COMMON_LT((" | device10DD = %u", device10DD)); // Commented to avoid bad looking logs



    switch (device10DD)
    {
        case PciDevice10DD::NONE:        return "NONE";
        case PciDevice10DD::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10DD device10DD) // TEST: NO
{
    // COMMON_LT((" | device10DD = %u", device10DD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10DD, enumToString(device10DD));

    return res;
}



inline const char8* enumToHumanString(PciDevice10DD device10DD) // TEST: NO
{
    // COMMON_LT((" | device10DD = %u", device10DD)); // Commented to avoid bad looking logs



    switch (device10DD)
    {
        case PciDevice10DD::DEVICE_0100: return "Lightning 1200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCIDEVICE10DD_H
