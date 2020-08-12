// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5145: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3031 = 0x3031
};



inline const char8* enumToString(PciDevice5145 device5145) // TEST: NO
{
    // COMMON_LT((" | device5145 = %u", device5145)); // Commented to avoid bad looking logs



    switch (device5145)
    {
        case PciDevice5145::NONE:        return "NONE";
        case PciDevice5145::DEVICE_3031: return "DEVICE_3031";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5145 device5145) // TEST: NO
{
    // COMMON_LT((" | device5145 = %u", device5145)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5145, enumToString(device5145));

    return res;
}



inline const char8* enumToHumanString(PciDevice5145 device5145) // TEST: NO
{
    // COMMON_LT((" | device5145 = %u", device5145)); // Commented to avoid bad looking logs



    switch (device5145)
    {
        case PciDevice5145::DEVICE_3031: return "Concert AudioPCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H
