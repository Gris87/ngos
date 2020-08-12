// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1098_PCIDEVICE1098_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1098_PCIDEVICE1098_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1098: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1098 device1098) // TEST: NO
{
    // COMMON_LT((" | device1098 = %u", device1098)); // Commented to avoid bad looking logs



    switch (device1098)
    {
        case PciDevice1098::NONE:        return "NONE";
        case PciDevice1098::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1098::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1098 device1098) // TEST: NO
{
    // COMMON_LT((" | device1098 = %u", device1098)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1098, enumToString(device1098));

    return res;
}



inline const char8* enumToHumanString(PciDevice1098 device1098) // TEST: NO
{
    // COMMON_LT((" | device1098 = %u", device1098)); // Commented to avoid bad looking logs



    switch (device1098)
    {
        case PciDevice1098::DEVICE_0001: return "QD-8500";
        case PciDevice1098::DEVICE_0002: return "QD-8580";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1098_PCIDEVICE1098_H
