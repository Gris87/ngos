// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1266: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1910 = 0x1910
};



inline const char8* enumToString(PciDevice1266 device1266) // TEST: NO
{
    // COMMON_LT((" | device1266 = %u", device1266)); // Commented to avoid bad looking logs



    switch (device1266)
    {
        case PciDevice1266::NONE:        return "NONE";
        case PciDevice1266::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1266::DEVICE_1910: return "DEVICE_1910";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1266 device1266) // TEST: NO
{
    // COMMON_LT((" | device1266 = %u", device1266)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1266, enumToString(device1266));

    return res;
}



inline const char8* enumToHumanString(PciDevice1266 device1266) // TEST: NO
{
    // COMMON_LT((" | device1266 = %u", device1266)); // Commented to avoid bad looking logs



    switch (device1266)
    {
        case PciDevice1266::DEVICE_0001: return "NE10/100 Adapter (i82557B)";
        case PciDevice1266::DEVICE_1910: return "NE2000Plus (RT8029) Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H
