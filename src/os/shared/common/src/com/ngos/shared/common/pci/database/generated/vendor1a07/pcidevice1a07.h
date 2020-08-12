// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A07_PCIDEVICE1A07_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A07_PCIDEVICE1A07_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A07: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009
};



inline const char8* enumToString(PciDevice1A07 device1A07) // TEST: NO
{
    // COMMON_LT((" | device1A07 = %u", device1A07)); // Commented to avoid bad looking logs



    switch (device1A07)
    {
        case PciDevice1A07::NONE:        return "NONE";
        case PciDevice1A07::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1A07::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1A07::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1A07::DEVICE_0009: return "DEVICE_0009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A07 device1A07) // TEST: NO
{
    // COMMON_LT((" | device1A07 = %u", device1A07)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A07, enumToString(device1A07));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A07 device1A07) // TEST: NO
{
    // COMMON_LT((" | device1A07 = %u", device1A07)); // Commented to avoid bad looking logs



    switch (device1A07)
    {
        case PciDevice1A07::DEVICE_0006: return "CAN interface PC104+ HS/HS";
        case PciDevice1A07::DEVICE_0007: return "CAN interface PCIcanx II HS or HS/HS";
        case PciDevice1A07::DEVICE_0008: return "CAN interface PCIEcan HS or HS/HS";
        case PciDevice1A07::DEVICE_0009: return "CAN interface PCI104 HS/HS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A07_PCIDEVICE1A07_H
