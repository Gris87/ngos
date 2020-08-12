// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B66_PCIDEVICE1B66_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B66_PCIDEVICE1B66_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B66: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0007 = 0x0007
};



inline const char8* enumToString(PciDevice1B66 device1B66) // TEST: NO
{
    // COMMON_LT((" | device1B66 = %u", device1B66)); // Commented to avoid bad looking logs



    switch (device1B66)
    {
        case PciDevice1B66::NONE:        return "NONE";
        case PciDevice1B66::DEVICE_0007: return "DEVICE_0007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B66 device1B66) // TEST: NO
{
    // COMMON_LT((" | device1B66 = %u", device1B66)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B66, enumToString(device1B66));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B66 device1B66) // TEST: NO
{
    // COMMON_LT((" | device1B66 = %u", device1B66)); // Commented to avoid bad looking logs



    switch (device1B66)
    {
        case PciDevice1B66::DEVICE_0007: return "DELTA-3G-elp-d";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B66_PCIDEVICE1B66_H
