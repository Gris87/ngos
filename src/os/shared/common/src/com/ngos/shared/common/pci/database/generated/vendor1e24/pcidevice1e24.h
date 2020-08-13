// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E24_PCIDEVICE1E24_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E24_PCIDEVICE1E24_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E24: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0215 = 0x0215,
    DEVICE_021F = 0x021F,
    DEVICE_1525 = 0x1525,
    DEVICE_1533 = 0x1533,
    DEVICE_1633 = 0x1633,
    DEVICE_1635 = 0x1635
};



inline const char8* enumToString(PciDevice1E24 device1E24) // TEST: NO
{
    // COMMON_LT((" | device1E24 = %u", device1E24)); // Commented to avoid bad looking logs



    switch (device1E24)
    {
        case PciDevice1E24::NONE:        return "NONE";
        case PciDevice1E24::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1E24::DEVICE_0215: return "DEVICE_0215";
        case PciDevice1E24::DEVICE_021F: return "DEVICE_021F";
        case PciDevice1E24::DEVICE_1525: return "DEVICE_1525";
        case PciDevice1E24::DEVICE_1533: return "DEVICE_1533";
        case PciDevice1E24::DEVICE_1633: return "DEVICE_1633";
        case PciDevice1E24::DEVICE_1635: return "DEVICE_1635";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E24 device1E24) // TEST: NO
{
    // COMMON_LT((" | device1E24 = %u", device1E24)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E24, enumToString(device1E24));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E24 device1E24) // TEST: NO
{
    // COMMON_LT((" | device1E24 = %u", device1E24)); // Commented to avoid bad looking logs



    switch (device1E24)
    {
        case PciDevice1E24::DEVICE_0101: return "Acorn CLE-101";
        case PciDevice1E24::DEVICE_0215: return "Acorn CLE-215";
        case PciDevice1E24::DEVICE_021F: return "Acorn CLE-215+";
        case PciDevice1E24::DEVICE_1525: return "Xilinx BCU-1525";
        case PciDevice1E24::DEVICE_1533: return "ForestKitten 33";
        case PciDevice1E24::DEVICE_1633: return "JCM33";
        case PciDevice1E24::DEVICE_1635: return "JCM35";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E24_PCIDEVICE1E24_H
