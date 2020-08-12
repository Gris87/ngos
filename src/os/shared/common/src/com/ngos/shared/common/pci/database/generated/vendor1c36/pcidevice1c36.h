// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C36_PCIDEVICE1C36_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C36_PCIDEVICE1C36_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C36: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1C36 device1C36) // TEST: NO
{
    // COMMON_LT((" | device1C36 = %u", device1C36)); // Commented to avoid bad looking logs



    switch (device1C36)
    {
        case PciDevice1C36::NONE:        return "NONE";
        case PciDevice1C36::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1C36::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C36 device1C36) // TEST: NO
{
    // COMMON_LT((" | device1C36 = %u", device1C36)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C36, enumToString(device1C36));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C36 device1C36) // TEST: NO
{
    // COMMON_LT((" | device1C36 = %u", device1C36)); // Commented to avoid bad looking logs



    switch (device1C36)
    {
        case PciDevice1C36::DEVICE_0001: return "Gigabit Ethernet Adapter";
        case PciDevice1C36::DEVICE_0002: return "SFP+ 10G Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C36_PCIDEVICE1C36_H
