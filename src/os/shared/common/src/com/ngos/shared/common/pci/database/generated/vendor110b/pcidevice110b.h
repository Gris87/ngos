// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110B_PCIDEVICE110B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110B_PCIDEVICE110B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice110B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0004 = 0x0004
};



inline const char8* enumToString(PciDevice110B device110B) // TEST: NO
{
    // COMMON_LT((" | device110B = %u", device110B)); // Commented to avoid bad looking logs



    switch (device110B)
    {
        case PciDevice110B::NONE:        return "NONE";
        case PciDevice110B::DEVICE_0001: return "DEVICE_0001";
        case PciDevice110B::DEVICE_0004: return "DEVICE_0004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice110B device110B) // TEST: NO
{
    // COMMON_LT((" | device110B = %u", device110B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device110B, enumToString(device110B));

    return res;
}



inline const char8* enumToHumanString(PciDevice110B device110B) // TEST: NO
{
    // COMMON_LT((" | device110B = %u", device110B)); // Commented to avoid bad looking logs



    switch (device110B)
    {
        case PciDevice110B::DEVICE_0001: return "Mpact Media Processor";
        case PciDevice110B::DEVICE_0004: return "Mpact 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110B_PCIDEVICE110B_H
