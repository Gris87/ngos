// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCIDEVICE001C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCIDEVICE001C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice001C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice001C device001C) // TEST: NO
{
    // COMMON_LT((" | device001C = %u", device001C)); // Commented to avoid bad looking logs



    switch (device001C)
    {
        case PciDevice001C::NONE:        return "NONE";
        case PciDevice001C::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice001C device001C) // TEST: NO
{
    // COMMON_LT((" | device001C = %u", device001C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device001C, enumToString(device001C));

    return res;
}



inline const char8* enumToHumanString(PciDevice001C device001C) // TEST: NO
{
    // COMMON_LT((" | device001C = %u", device001C)); // Commented to avoid bad looking logs



    switch (device001C)
    {
        case PciDevice001C::DEVICE_0001: return "PCAN-PCI CAN-Bus controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCIDEVICE001C_H
