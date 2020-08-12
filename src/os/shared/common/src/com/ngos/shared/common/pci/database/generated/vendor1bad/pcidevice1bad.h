// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BAD_PCIDEVICE1BAD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BAD_PCIDEVICE1BAD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BAD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C001 = 0xC001,
    DEVICE_C002 = 0xC002
};



inline const char8* enumToString(PciDevice1BAD device1BAD) // TEST: NO
{
    // COMMON_LT((" | device1BAD = %u", device1BAD)); // Commented to avoid bad looking logs



    switch (device1BAD)
    {
        case PciDevice1BAD::NONE:        return "NONE";
        case PciDevice1BAD::DEVICE_C001: return "DEVICE_C001";
        case PciDevice1BAD::DEVICE_C002: return "DEVICE_C002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BAD device1BAD) // TEST: NO
{
    // COMMON_LT((" | device1BAD = %u", device1BAD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1BAD, enumToString(device1BAD));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BAD device1BAD) // TEST: NO
{
    // COMMON_LT((" | device1BAD = %u", device1BAD)); // Commented to avoid bad looking logs



    switch (device1BAD)
    {
        case PciDevice1BAD::DEVICE_C001: return "XpressGXA10-LP1150";
        case PciDevice1BAD::DEVICE_C002: return "XpressGXA10-LP1151";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BAD_PCIDEVICE1BAD_H
