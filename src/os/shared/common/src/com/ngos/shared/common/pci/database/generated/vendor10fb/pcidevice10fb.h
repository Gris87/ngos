// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FB_PCIDEVICE10FB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FB_PCIDEVICE10FB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10FB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_186F = 0x186F
};



inline const char8* enumToString(PciDevice10FB device10FB) // TEST: NO
{
    // COMMON_LT((" | device10FB = %u", device10FB)); // Commented to avoid bad looking logs



    switch (device10FB)
    {
        case PciDevice10FB::NONE:        return "NONE";
        case PciDevice10FB::DEVICE_186F: return "DEVICE_186F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10FB device10FB) // TEST: NO
{
    // COMMON_LT((" | device10FB = %u", device10FB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10FB, enumToString(device10FB));

    return res;
}



inline const char8* enumToHumanString(PciDevice10FB device10FB) // TEST: NO
{
    // COMMON_LT((" | device10FB = %u", device10FB)); // Commented to avoid bad looking logs



    switch (device10FB)
    {
        case PciDevice10FB::DEVICE_186F: return "TH 6255";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FB_PCIDEVICE10FB_H
