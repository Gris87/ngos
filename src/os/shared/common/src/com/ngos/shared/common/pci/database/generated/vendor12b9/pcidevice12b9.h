// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12B9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008
};



inline const char8* enumToString(PciDevice12B9 device12B9) // TEST: NO
{
    // COMMON_LT((" | device12B9 = %u", device12B9)); // Commented to avoid bad looking logs



    switch (device12B9)
    {
        case PciDevice12B9::NONE:        return "NONE";
        case PciDevice12B9::DEVICE_1006: return "DEVICE_1006";
        case PciDevice12B9::DEVICE_1007: return "DEVICE_1007";
        case PciDevice12B9::DEVICE_1008: return "DEVICE_1008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12B9 device12B9) // TEST: NO
{
    // COMMON_LT((" | device12B9 = %u", device12B9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12B9, enumToString(device12B9));

    return res;
}



inline const char8* enumToHumanString(PciDevice12B9 device12B9) // TEST: NO
{
    // COMMON_LT((" | device12B9 = %u", device12B9)); // Commented to avoid bad looking logs



    switch (device12B9)
    {
        case PciDevice12B9::DEVICE_1006: return "WinModem";
        case PciDevice12B9::DEVICE_1007: return "USR 56k Internal WinModem";
        case PciDevice12B9::DEVICE_1008: return "56K FaxModem Model 5610";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H
