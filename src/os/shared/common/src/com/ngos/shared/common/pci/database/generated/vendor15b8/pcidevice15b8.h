// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B8_PCIDEVICE15B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B8_PCIDEVICE15B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15B8: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1006 = 0x1006,
    DEVICE_100A = 0x100A,
    DEVICE_3001 = 0x3001,
    DEVICE_300F = 0x300F,
    DEVICE_7001 = 0x7001,
    DEVICE_7002 = 0x7002
};



inline const char8* enumToString(PciDevice15B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15B8::NONE:        return "NONE";
        case PciDevice15B8::DEVICE_1001: return "DEVICE_1001";
        case PciDevice15B8::DEVICE_1003: return "DEVICE_1003";
        case PciDevice15B8::DEVICE_1004: return "DEVICE_1004";
        case PciDevice15B8::DEVICE_1005: return "DEVICE_1005";
        case PciDevice15B8::DEVICE_1006: return "DEVICE_1006";
        case PciDevice15B8::DEVICE_100A: return "DEVICE_100A";
        case PciDevice15B8::DEVICE_3001: return "DEVICE_3001";
        case PciDevice15B8::DEVICE_300F: return "DEVICE_300F";
        case PciDevice15B8::DEVICE_7001: return "DEVICE_7001";
        case PciDevice15B8::DEVICE_7002: return "DEVICE_7002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15B8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15B8::DEVICE_1001: return "APCI1516 SP controller (16 digi outputs)";
        case PciDevice15B8::DEVICE_1003: return "APCI1032 SP controller (32 digi inputs w/ opto coupler)";
        case PciDevice15B8::DEVICE_1004: return "APCI2032 SP controller (32 digi outputs)";
        case PciDevice15B8::DEVICE_1005: return "APCI2200 SP controller (8/16 digi outputs (relay))";
        case PciDevice15B8::DEVICE_1006: return "APCI1564 SP controller (32 digi ins, 32 digi outs)";
        case PciDevice15B8::DEVICE_100A: return "APCbad_int1696 SP controller (96 TTL I/Os)";
        case PciDevice15B8::DEVICE_3001: return "APCI3501 SP controller (analog output board)";
        case PciDevice15B8::DEVICE_300F: return "APCI3600 Noise and vibration measurement board";
        case PciDevice15B8::DEVICE_7001: return "APCI7420 2-port Serial Controller";
        case PciDevice15B8::DEVICE_7002: return "APCI7300 Serial Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B8_PCIDEVICE15B8_H
