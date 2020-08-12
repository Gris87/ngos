// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126C_PCIDEVICE126C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126C_PCIDEVICE126C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice126C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1211 = 0x1211,
    DEVICE_126C = 0x126C
};



inline const char8* enumToString(PciDevice126C device126C) // TEST: NO
{
    // COMMON_LT((" | device126C = %u", device126C)); // Commented to avoid bad looking logs



    switch (device126C)
    {
        case PciDevice126C::NONE:        return "NONE";
        case PciDevice126C::DEVICE_1211: return "DEVICE_1211";
        case PciDevice126C::DEVICE_126C: return "DEVICE_126C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice126C device126C) // TEST: NO
{
    // COMMON_LT((" | device126C = %u", device126C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device126C, enumToString(device126C));

    return res;
}



inline const char8* enumToHumanString(PciDevice126C device126C) // TEST: NO
{
    // COMMON_LT((" | device126C = %u", device126C)); // Commented to avoid bad looking logs



    switch (device126C)
    {
        case PciDevice126C::DEVICE_1211: return "10/100BaseTX [RTL81xx]";
        case PciDevice126C::DEVICE_126C: return "802.11b Wireless Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR126C_PCIDEVICE126C_H
