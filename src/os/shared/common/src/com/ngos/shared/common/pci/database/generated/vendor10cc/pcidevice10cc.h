// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CC_PCIDEVICE10CC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CC_PCIDEVICE10CC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10CC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0660 = 0x0660,
    DEVICE_0661 = 0x0661
};



inline const char8* enumToString(PciDevice10CC device10CC) // TEST: NO
{
    // COMMON_LT((" | device10CC = %u", device10CC)); // Commented to avoid bad looking logs



    switch (device10CC)
    {
        case PciDevice10CC::NONE:        return "NONE";
        case PciDevice10CC::DEVICE_0660: return "DEVICE_0660";
        case PciDevice10CC::DEVICE_0661: return "DEVICE_0661";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10CC device10CC) // TEST: NO
{
    // COMMON_LT((" | device10CC = %u", device10CC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10CC, enumToString(device10CC));

    return res;
}



inline const char8* enumToHumanString(PciDevice10CC device10CC) // TEST: NO
{
    // COMMON_LT((" | device10CC = %u", device10CC)); // Commented to avoid bad looking logs



    switch (device10CC)
    {
        case PciDevice10CC::DEVICE_0660: return "Articia S Host Bridge";
        case PciDevice10CC::DEVICE_0661: return "Articia S PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10CC_PCIDEVICE10CC_H
