// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11EC_PCIDEVICE11EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11EC_PCIDEVICE11EC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000D = 0x000D,
    DEVICE_1800 = 0x1800
};



inline const char8* enumToString(PciDevice11EC device11EC) // TEST: NO
{
    // COMMON_LT((" | device11EC = %u", device11EC)); // Commented to avoid bad looking logs



    switch (device11EC)
    {
        case PciDevice11EC::NONE:        return "NONE";
        case PciDevice11EC::DEVICE_000D: return "DEVICE_000D";
        case PciDevice11EC::DEVICE_1800: return "DEVICE_1800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11EC device11EC) // TEST: NO
{
    // COMMON_LT((" | device11EC = %u", device11EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11EC, enumToString(device11EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice11EC device11EC) // TEST: NO
{
    // COMMON_LT((" | device11EC = %u", device11EC)); // Commented to avoid bad looking logs



    switch (device11EC)
    {
        case PciDevice11EC::DEVICE_000D: return "Oculus-F/64P";
        case PciDevice11EC::DEVICE_1800: return "Cobra/C6";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11EC_PCIDEVICE11EC_H
