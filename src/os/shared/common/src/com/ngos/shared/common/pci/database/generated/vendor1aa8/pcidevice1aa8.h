// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA8_PCIDEVICE1AA8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA8_PCIDEVICE1AA8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AA8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A
};



inline const char8* enumToString(PciDevice1AA8 device1AA8) // TEST: NO
{
    // COMMON_LT((" | device1AA8 = %u", device1AA8)); // Commented to avoid bad looking logs



    switch (device1AA8)
    {
        case PciDevice1AA8::NONE:        return "NONE";
        case PciDevice1AA8::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1AA8::DEVICE_000A: return "DEVICE_000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AA8 device1AA8) // TEST: NO
{
    // COMMON_LT((" | device1AA8 = %u", device1AA8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1AA8, enumToString(device1AA8));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AA8 device1AA8) // TEST: NO
{
    // COMMON_LT((" | device1AA8 = %u", device1AA8)); // Commented to avoid bad looking logs



    switch (device1AA8)
    {
        case PciDevice1AA8::DEVICE_0009: return "RAIDCore Controller";
        case PciDevice1AA8::DEVICE_000A: return "RAIDCore Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA8_PCIDEVICE1AA8_H
