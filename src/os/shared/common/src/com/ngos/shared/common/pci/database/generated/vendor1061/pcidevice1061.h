// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1061_PCIDEVICE1061_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1061_PCIDEVICE1061_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1061: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1061 device1061) // TEST: NO
{
    // COMMON_LT((" | device1061 = %u", device1061)); // Commented to avoid bad looking logs



    switch (device1061)
    {
        case PciDevice1061::NONE:        return "NONE";
        case PciDevice1061::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1061::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1061 device1061) // TEST: NO
{
    // COMMON_LT((" | device1061 = %u", device1061)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1061, enumToString(device1061));

    return res;
}



inline const char8* enumToHumanString(PciDevice1061 device1061) // TEST: NO
{
    // COMMON_LT((" | device1061 = %u", device1061)); // Commented to avoid bad looking logs



    switch (device1061)
    {
        case PciDevice1061::DEVICE_0001: return "AGX016";
        case PciDevice1061::DEVICE_0002: return "IIT3204/3501";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1061_PCIDEVICE1061_H
