// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1409: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7168 = 0x7168,
    DEVICE_7268 = 0x7268
};



inline const char8* enumToString(PciDevice1409 device1409) // TEST: NO
{
    // COMMON_LT((" | device1409 = %u", device1409)); // Commented to avoid bad looking logs



    switch (device1409)
    {
        case PciDevice1409::NONE:        return "NONE";
        case PciDevice1409::DEVICE_7168: return "DEVICE_7168";
        case PciDevice1409::DEVICE_7268: return "DEVICE_7268";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1409 device1409) // TEST: NO
{
    // COMMON_LT((" | device1409 = %u", device1409)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1409, enumToString(device1409));

    return res;
}



inline const char8* enumToHumanString(PciDevice1409 device1409) // TEST: NO
{
    // COMMON_LT((" | device1409 = %u", device1409)); // Commented to avoid bad looking logs



    switch (device1409)
    {
        case PciDevice1409::DEVICE_7168: return "PCI2S550 (Dual 16550 UART)";
        case PciDevice1409::DEVICE_7268: return "SUN1888 (Dual IEEE1284 parallel port)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H
