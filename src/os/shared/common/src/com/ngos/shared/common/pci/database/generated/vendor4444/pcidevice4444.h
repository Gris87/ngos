// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCIDEVICE4444_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCIDEVICE4444_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4444: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0016 = 0x0016,
    DEVICE_0803 = 0x0803
};



inline const char8* enumToString(PciDevice4444 device4444) // TEST: NO
{
    // COMMON_LT((" | device4444 = %u", device4444)); // Commented to avoid bad looking logs



    switch (device4444)
    {
        case PciDevice4444::NONE:        return "NONE";
        case PciDevice4444::DEVICE_0016: return "DEVICE_0016";
        case PciDevice4444::DEVICE_0803: return "DEVICE_0803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4444 device4444) // TEST: NO
{
    // COMMON_LT((" | device4444 = %u", device4444)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4444, enumToString(device4444));

    return res;
}



inline const char8* enumToHumanString(PciDevice4444 device4444) // TEST: NO
{
    // COMMON_LT((" | device4444 = %u", device4444)); // Commented to avoid bad looking logs



    switch (device4444)
    {
        case PciDevice4444::DEVICE_0016: return "iTVC16 (CX23416) Video Decoder";
        case PciDevice4444::DEVICE_0803: return "iTVC15 (CX23415) Video Decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4444_PCIDEVICE4444_H
