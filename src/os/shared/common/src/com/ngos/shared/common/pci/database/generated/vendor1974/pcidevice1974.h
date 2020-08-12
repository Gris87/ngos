// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1974_PCIDEVICE1974_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1974_PCIDEVICE1974_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1974: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0009 = 0x0009,
    DEVICE_0011 = 0x0011
};



inline const char8* enumToString(PciDevice1974 device1974) // TEST: NO
{
    // COMMON_LT((" | device1974 = %u", device1974)); // Commented to avoid bad looking logs



    switch (device1974)
    {
        case PciDevice1974::NONE:        return "NONE";
        case PciDevice1974::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1974::DEVICE_0011: return "DEVICE_0011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1974 device1974) // TEST: NO
{
    // COMMON_LT((" | device1974 = %u", device1974)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1974, enumToString(device1974));

    return res;
}



inline const char8* enumToHumanString(PciDevice1974 device1974) // TEST: NO
{
    // COMMON_LT((" | device1974 = %u", device1974)); // Commented to avoid bad looking logs



    switch (device1974)
    {
        case PciDevice1974::DEVICE_0009: return "FlexCard PMC-II";
        case PciDevice1974::DEVICE_0011: return "FlexCard PMC-II Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1974_PCIDEVICE1974_H
