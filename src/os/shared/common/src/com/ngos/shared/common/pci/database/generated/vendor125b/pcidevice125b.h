// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice125B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1400 = 0x1400
};



inline const char8* enumToString(PciDevice125B device125B) // TEST: NO
{
    // COMMON_LT((" | device125B = %u", device125B)); // Commented to avoid bad looking logs



    switch (device125B)
    {
        case PciDevice125B::NONE:        return "NONE";
        case PciDevice125B::DEVICE_1400: return "DEVICE_1400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice125B device125B) // TEST: NO
{
    // COMMON_LT((" | device125B = %u", device125B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device125B, enumToString(device125B));

    return res;
}



inline const char8* enumToHumanString(PciDevice125B device125B) // TEST: NO
{
    // COMMON_LT((" | device125B = %u", device125B)); // Commented to avoid bad looking logs



    switch (device125B)
    {
        case PciDevice125B::DEVICE_1400: return "AX88141 Fast Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H
