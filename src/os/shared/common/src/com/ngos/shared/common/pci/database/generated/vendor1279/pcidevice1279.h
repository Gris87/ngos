// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1279_PCIDEVICE1279_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1279_PCIDEVICE1279_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1279: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0060 = 0x0060,
    DEVICE_0061 = 0x0061,
    DEVICE_0295 = 0x0295,
    DEVICE_0395 = 0x0395,
    DEVICE_0396 = 0x0396,
    DEVICE_0397 = 0x0397
};



inline const char8* enumToString(PciDevice1279 device1279) // TEST: NO
{
    // COMMON_LT((" | device1279 = %u", device1279)); // Commented to avoid bad looking logs



    switch (device1279)
    {
        case PciDevice1279::NONE:        return "NONE";
        case PciDevice1279::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1279::DEVICE_0061: return "DEVICE_0061";
        case PciDevice1279::DEVICE_0295: return "DEVICE_0295";
        case PciDevice1279::DEVICE_0395: return "DEVICE_0395";
        case PciDevice1279::DEVICE_0396: return "DEVICE_0396";
        case PciDevice1279::DEVICE_0397: return "DEVICE_0397";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1279 device1279) // TEST: NO
{
    // COMMON_LT((" | device1279 = %u", device1279)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1279, enumToString(device1279));

    return res;
}



inline const char8* enumToHumanString(PciDevice1279 device1279) // TEST: NO
{
    // COMMON_LT((" | device1279 = %u", device1279)); // Commented to avoid bad looking logs



    switch (device1279)
    {
        case PciDevice1279::DEVICE_0060: return "TM8000 Northbridge";
        case PciDevice1279::DEVICE_0061: return "TM8000 AGP bridge";
        case PciDevice1279::DEVICE_0295: return "Northbridge";
        case PciDevice1279::DEVICE_0395: return "LongRun Northbridge";
        case PciDevice1279::DEVICE_0396: return "SDRAM controller";
        case PciDevice1279::DEVICE_0397: return "BIOS scratchpad";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1279_PCIDEVICE1279_H
