// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCIDEVICE1244_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCIDEVICE1244_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1244: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0700 = 0x0700,
    DEVICE_0800 = 0x0800,
    DEVICE_0A00 = 0x0A00,
    DEVICE_0E00 = 0x0E00,
    DEVICE_0E80 = 0x0E80,
    DEVICE_1100 = 0x1100,
    DEVICE_1200 = 0x1200,
    DEVICE_2700 = 0x2700,
    DEVICE_2900 = 0x2900
};



inline const char8* enumToString(PciDevice1244 device1244) // TEST: NO
{
    // COMMON_LT((" | device1244 = %u", device1244)); // Commented to avoid bad looking logs



    switch (device1244)
    {
        case PciDevice1244::NONE:        return "NONE";
        case PciDevice1244::DEVICE_0700: return "DEVICE_0700";
        case PciDevice1244::DEVICE_0800: return "DEVICE_0800";
        case PciDevice1244::DEVICE_0A00: return "DEVICE_0A00";
        case PciDevice1244::DEVICE_0E00: return "DEVICE_0E00";
        case PciDevice1244::DEVICE_0E80: return "DEVICE_0E80";
        case PciDevice1244::DEVICE_1100: return "DEVICE_1100";
        case PciDevice1244::DEVICE_1200: return "DEVICE_1200";
        case PciDevice1244::DEVICE_2700: return "DEVICE_2700";
        case PciDevice1244::DEVICE_2900: return "DEVICE_2900";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1244 device1244) // TEST: NO
{
    // COMMON_LT((" | device1244 = %u", device1244)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1244, enumToString(device1244));

    return res;
}



inline const char8* enumToHumanString(PciDevice1244 device1244) // TEST: NO
{
    // COMMON_LT((" | device1244 = %u", device1244)); // Commented to avoid bad looking logs



    switch (device1244)
    {
        case PciDevice1244::DEVICE_0700: return "B1 ISDN";
        case PciDevice1244::DEVICE_0800: return "C4 ISDN";
        case PciDevice1244::DEVICE_0A00: return "A1 ISDN [Fritz]";
        case PciDevice1244::DEVICE_0E00: return "Fritz!Card PCI v2.0 ISDN";
        case PciDevice1244::DEVICE_0E80: return "Fritz!Card PCI v2.1 ISDN";
        case PciDevice1244::DEVICE_1100: return "C2 ISDN";
        case PciDevice1244::DEVICE_1200: return "T1 ISDN";
        case PciDevice1244::DEVICE_2700: return "Fritz!Card DSL SL";
        case PciDevice1244::DEVICE_2900: return "Fritz!Card DSL v2.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCIDEVICE1244_H
