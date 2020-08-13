// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1830_PCIDEVICE1830_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1830_PCIDEVICE1830_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1830: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8000 = 0x8000,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_8003 = 0x8003
};



inline const char8* enumToString(PciDevice1830 device1830) // TEST: NO
{
    // COMMON_LT((" | device1830 = %u", device1830)); // Commented to avoid bad looking logs



    switch (device1830)
    {
        case PciDevice1830::NONE:        return "NONE";
        case PciDevice1830::DEVICE_8000: return "DEVICE_8000";
        case PciDevice1830::DEVICE_8001: return "DEVICE_8001";
        case PciDevice1830::DEVICE_8002: return "DEVICE_8002";
        case PciDevice1830::DEVICE_8003: return "DEVICE_8003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1830 device1830) // TEST: NO
{
    // COMMON_LT((" | device1830 = %u", device1830)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1830, enumToString(device1830));

    return res;
}



inline const char8* enumToHumanString(PciDevice1830 device1830) // TEST: NO
{
    // COMMON_LT((" | device1830 = %u", device1830)); // Commented to avoid bad looking logs



    switch (device1830)
    {
        case PciDevice1830::DEVICE_8000: return "CPIn";
        case PciDevice1830::DEVICE_8001: return "CPId";
        case PciDevice1830::DEVICE_8002: return "CPIx";
        case PciDevice1830::DEVICE_8003: return "CPIq";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1830_PCIDEVICE1830_H
