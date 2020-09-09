// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1629_PCIDEVICE1629_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1629_PCIDEVICE1629_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1629: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1003 = 0x1003,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_2002 = 0x2002,
    DEVICE_3100 = 0x3100,
    DEVICE_3200 = 0x3200,
    DEVICE_4002 = 0x4002,
    DEVICE_5001 = 0x5001,
    DEVICE_6001 = 0x6001
};



inline const char8* enumToString(PciDevice1629 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1629::NONE:        return "NONE";
        case PciDevice1629::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1629::DEVICE_1006: return "DEVICE_1006";
        case PciDevice1629::DEVICE_1007: return "DEVICE_1007";
        case PciDevice1629::DEVICE_2002: return "DEVICE_2002";
        case PciDevice1629::DEVICE_3100: return "DEVICE_3100";
        case PciDevice1629::DEVICE_3200: return "DEVICE_3200";
        case PciDevice1629::DEVICE_4002: return "DEVICE_4002";
        case PciDevice1629::DEVICE_5001: return "DEVICE_5001";
        case PciDevice1629::DEVICE_6001: return "DEVICE_6001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1629 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1629 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1629::DEVICE_1003: return "Format synchronizer v3.0";
        case PciDevice1629::DEVICE_1006: return "Format synchronizer, model 10500";
        case PciDevice1629::DEVICE_1007: return "Format synchronizer, model 21000";
        case PciDevice1629::DEVICE_2002: return "Fast Universal Data Output";
        case PciDevice1629::DEVICE_3100: return "IO31000 Frame Synchronizer and I/O";
        case PciDevice1629::DEVICE_3200: return "IO32000 Frame Synchronizer and I/O";
        case PciDevice1629::DEVICE_4002: return "High Rate Demodulator";
        case PciDevice1629::DEVICE_5001: return "High Rate FEC";
        case PciDevice1629::DEVICE_6001: return "High Rate Demodulator and FEC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1629_PCIDEVICE1629_H
