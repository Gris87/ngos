// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCIDEVICE1050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCIDEVICE1050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1050: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0033 = 0x0033,
    DEVICE_0105 = 0x0105,
    DEVICE_0840 = 0x0840,
    DEVICE_0940 = 0x0940,
    DEVICE_5A5A = 0x5A5A,
    DEVICE_6692 = 0x6692,
    DEVICE_9921 = 0x9921,
    DEVICE_9922 = 0x9922,
    DEVICE_9970 = 0x9970
};



inline const char8* enumToString(PciDevice1050 device1050) // TEST: NO
{
    // COMMON_LT((" | device1050 = %u", device1050)); // Commented to avoid bad looking logs



    switch (device1050)
    {
        case PciDevice1050::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1050::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1050::DEVICE_0033: return "DEVICE_0033";
        case PciDevice1050::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1050::DEVICE_0840: return "DEVICE_0840";
        case PciDevice1050::DEVICE_0940: return "DEVICE_0940";
        case PciDevice1050::DEVICE_5A5A: return "DEVICE_5A5A";
        case PciDevice1050::DEVICE_6692: return "DEVICE_6692";
        case PciDevice1050::DEVICE_9921: return "DEVICE_9921";
        case PciDevice1050::DEVICE_9922: return "DEVICE_9922";
        case PciDevice1050::DEVICE_9970: return "DEVICE_9970";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1050 device1050) // TEST: NO
{
    // COMMON_LT((" | device1050 = %u", device1050)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1050, enumToString(device1050));

    return res;
}



inline const char8* enumToHumanString(PciDevice1050 device1050) // TEST: NO
{
    // COMMON_LT((" | device1050 = %u", device1050)); // Commented to avoid bad looking logs



    switch (device1050)
    {
        case PciDevice1050::DEVICE_0000: return "NE2000";
        case PciDevice1050::DEVICE_0001: return "W83769F";
        case PciDevice1050::DEVICE_0033: return "W89C33D 802.11 a/b/g BB/MAC";
        case PciDevice1050::DEVICE_0105: return "W82C105";
        case PciDevice1050::DEVICE_0840: return "W89C840";
        case PciDevice1050::DEVICE_0940: return "W89C940";
        case PciDevice1050::DEVICE_5A5A: return "W89C940F";
        case PciDevice1050::DEVICE_6692: return "W6692";
        case PciDevice1050::DEVICE_9921: return "W99200F MPEG-1 Video Encoder";
        case PciDevice1050::DEVICE_9922: return "W99200F/W9922PF MPEG-1/2 Video Encoder";
        case PciDevice1050::DEVICE_9970: return "W9970CF";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCIDEVICE1050_H
