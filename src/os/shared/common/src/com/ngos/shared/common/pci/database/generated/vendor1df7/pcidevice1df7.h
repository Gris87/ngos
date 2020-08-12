// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF7_PCIDEVICE1DF7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF7_PCIDEVICE1DF7_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DF7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice1DF7 device1DF7) // TEST: NO
{
    // COMMON_LT((" | device1DF7 = %u", device1DF7)); // Commented to avoid bad looking logs



    switch (device1DF7)
    {
        case PciDevice1DF7::NONE:        return "NONE";
        case PciDevice1DF7::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1DF7::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1DF7::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DF7 device1DF7) // TEST: NO
{
    // COMMON_LT((" | device1DF7 = %u", device1DF7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1DF7, enumToString(device1DF7));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DF7 device1DF7) // TEST: NO
{
    // COMMON_LT((" | device1DF7 = %u", device1DF7)); // Commented to avoid bad looking logs



    switch (device1DF7)
    {
        case PciDevice1DF7::DEVICE_0001: return "ml605";
        case PciDevice1DF7::DEVICE_0002: return "alst4";
        case PciDevice1DF7::DEVICE_0003: return "alst4x";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF7_PCIDEVICE1DF7_H
