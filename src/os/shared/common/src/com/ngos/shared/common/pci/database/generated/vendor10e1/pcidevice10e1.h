// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0391 = 0x0391,
    DEVICE_690C = 0x690C,
    DEVICE_DC29 = 0xDC29
};



inline const char8* enumToString(PciDevice10E1 device10E1) // TEST: NO
{
    // COMMON_LT((" | device10E1 = %u", device10E1)); // Commented to avoid bad looking logs



    switch (device10E1)
    {
        case PciDevice10E1::NONE:        return "NONE";
        case PciDevice10E1::DEVICE_0391: return "DEVICE_0391";
        case PciDevice10E1::DEVICE_690C: return "DEVICE_690C";
        case PciDevice10E1::DEVICE_DC29: return "DEVICE_DC29";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E1 device10E1) // TEST: NO
{
    // COMMON_LT((" | device10E1 = %u", device10E1)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10E1, enumToString(device10E1));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E1 device10E1) // TEST: NO
{
    // COMMON_LT((" | device10E1 = %u", device10E1)); // Commented to avoid bad looking logs



    switch (device10E1)
    {
        case PciDevice10E1::DEVICE_0391: return "TRM-S1040";
        case PciDevice10E1::DEVICE_690C: return "DC-690c";
        case PciDevice10E1::DEVICE_DC29: return "DC-290";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H
