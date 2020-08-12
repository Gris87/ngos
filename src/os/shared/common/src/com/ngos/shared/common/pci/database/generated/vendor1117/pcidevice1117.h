// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1117_PCIDEVICE1117_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1117_PCIDEVICE1117_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1117: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9500 = 0x9500,
    DEVICE_9501 = 0x9501
};



inline const char8* enumToString(PciDevice1117 device1117) // TEST: NO
{
    // COMMON_LT((" | device1117 = %u", device1117)); // Commented to avoid bad looking logs



    switch (device1117)
    {
        case PciDevice1117::NONE:        return "NONE";
        case PciDevice1117::DEVICE_9500: return "DEVICE_9500";
        case PciDevice1117::DEVICE_9501: return "DEVICE_9501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1117 device1117) // TEST: NO
{
    // COMMON_LT((" | device1117 = %u", device1117)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1117, enumToString(device1117));

    return res;
}



inline const char8* enumToHumanString(PciDevice1117 device1117) // TEST: NO
{
    // COMMON_LT((" | device1117 = %u", device1117)); // Commented to avoid bad looking logs



    switch (device1117)
    {
        case PciDevice1117::DEVICE_9500: return "Max-1C SVGA card";
        case PciDevice1117::DEVICE_9501: return "Max-1C image processing";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1117_PCIDEVICE1117_H
