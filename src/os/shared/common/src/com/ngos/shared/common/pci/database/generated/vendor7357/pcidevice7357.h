// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7357_PCIDEVICE7357_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7357_PCIDEVICE7357_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice7357: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7910 = 0x7910
};



inline const char8* enumToString(PciDevice7357 device7357) // TEST: NO
{
    // COMMON_LT((" | device7357 = %u", device7357)); // Commented to avoid bad looking logs



    switch (device7357)
    {
        case PciDevice7357::NONE:        return "NONE";
        case PciDevice7357::DEVICE_7910: return "DEVICE_7910";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice7357 device7357) // TEST: NO
{
    // COMMON_LT((" | device7357 = %u", device7357)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device7357, enumToString(device7357));

    return res;
}



inline const char8* enumToHumanString(PciDevice7357 device7357) // TEST: NO
{
    // COMMON_LT((" | device7357 = %u", device7357)); // Commented to avoid bad looking logs



    switch (device7357)
    {
        case PciDevice7357::DEVICE_7910: return "7910 [Althea]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7357_PCIDEVICE7357_H
