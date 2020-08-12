// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A84_PCIDEVICE1A84_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A84_PCIDEVICE1A84_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A84: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1A84 device1A84) // TEST: NO
{
    // COMMON_LT((" | device1A84 = %u", device1A84)); // Commented to avoid bad looking logs



    switch (device1A84)
    {
        case PciDevice1A84::NONE:        return "NONE";
        case PciDevice1A84::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A84 device1A84) // TEST: NO
{
    // COMMON_LT((" | device1A84 = %u", device1A84)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A84, enumToString(device1A84));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A84 device1A84) // TEST: NO
{
    // COMMON_LT((" | device1A84 = %u", device1A84)); // Commented to avoid bad looking logs



    switch (device1A84)
    {
        case PciDevice1A84::DEVICE_0001: return "Vulcan SP HT6210 10-Gigabit Ethernet (rev 02)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A84_PCIDEVICE1A84_H
