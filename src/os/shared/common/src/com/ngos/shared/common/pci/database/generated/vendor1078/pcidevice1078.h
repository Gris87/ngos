// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1078_PCIDEVICE1078_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1078_PCIDEVICE1078_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1078: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0400 = 0x0400,
    DEVICE_0401 = 0x0401,
    DEVICE_0402 = 0x0402,
    DEVICE_0403 = 0x0403
};



inline const char8* enumToString(PciDevice1078 device1078) // TEST: NO
{
    // COMMON_LT((" | device1078 = %u", device1078)); // Commented to avoid bad looking logs



    switch (device1078)
    {
        case PciDevice1078::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1078::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1078::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1078::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1078::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1078::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1078::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1078::DEVICE_0104: return "DEVICE_0104";
        case PciDevice1078::DEVICE_0400: return "DEVICE_0400";
        case PciDevice1078::DEVICE_0401: return "DEVICE_0401";
        case PciDevice1078::DEVICE_0402: return "DEVICE_0402";
        case PciDevice1078::DEVICE_0403: return "DEVICE_0403";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1078 device1078) // TEST: NO
{
    // COMMON_LT((" | device1078 = %u", device1078)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1078, enumToString(device1078));

    return res;
}



inline const char8* enumToHumanString(PciDevice1078 device1078) // TEST: NO
{
    // COMMON_LT((" | device1078 = %u", device1078)); // Commented to avoid bad looking logs



    switch (device1078)
    {
        case PciDevice1078::DEVICE_0000: return "5510 [Grappa]";
        case PciDevice1078::DEVICE_0001: return "PCI Master";
        case PciDevice1078::DEVICE_0002: return "5520 [Cognac]";
        case PciDevice1078::DEVICE_0100: return "5530 Legacy [Kahlua]";
        case PciDevice1078::DEVICE_0101: return "5530 SMI [Kahlua]";
        case PciDevice1078::DEVICE_0102: return "5530 IDE [Kahlua]";
        case PciDevice1078::DEVICE_0103: return "5530 Audio [Kahlua]";
        case PciDevice1078::DEVICE_0104: return "5530 Video [Kahlua]";
        case PciDevice1078::DEVICE_0400: return "ZFMicro PCI Bridge";
        case PciDevice1078::DEVICE_0401: return "ZFMicro Chipset SMI";
        case PciDevice1078::DEVICE_0402: return "ZFMicro Chipset IDE";
        case PciDevice1078::DEVICE_0403: return "ZFMicro Expansion Bus";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1078_PCIDEVICE1078_H
