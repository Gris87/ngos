// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6666_PCIDEVICE6666_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6666_PCIDEVICE6666_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice6666: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0004 = 0x0004,
    DEVICE_0101 = 0x0101,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_1011 = 0x1011,
    DEVICE_1021 = 0x1021,
    DEVICE_1022 = 0x1022,
    DEVICE_1025 = 0x1025,
    DEVICE_4000 = 0x4000
};



inline const char8* enumToString(PciDevice6666 device6666) // TEST: NO
{
    // COMMON_LT((" | device6666 = %u", device6666)); // Commented to avoid bad looking logs



    switch (device6666)
    {
        case PciDevice6666::NONE:        return "NONE";
        case PciDevice6666::DEVICE_0001: return "DEVICE_0001";
        case PciDevice6666::DEVICE_0002: return "DEVICE_0002";
        case PciDevice6666::DEVICE_0004: return "DEVICE_0004";
        case PciDevice6666::DEVICE_0101: return "DEVICE_0101";
        case PciDevice6666::DEVICE_0200: return "DEVICE_0200";
        case PciDevice6666::DEVICE_0201: return "DEVICE_0201";
        case PciDevice6666::DEVICE_1011: return "DEVICE_1011";
        case PciDevice6666::DEVICE_1021: return "DEVICE_1021";
        case PciDevice6666::DEVICE_1022: return "DEVICE_1022";
        case PciDevice6666::DEVICE_1025: return "DEVICE_1025";
        case PciDevice6666::DEVICE_4000: return "DEVICE_4000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice6666 device6666) // TEST: NO
{
    // COMMON_LT((" | device6666 = %u", device6666)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device6666, enumToString(device6666));

    return res;
}



inline const char8* enumToHumanString(PciDevice6666 device6666) // TEST: NO
{
    // COMMON_LT((" | device6666 = %u", device6666)); // Commented to avoid bad looking logs



    switch (device6666)
    {
        case PciDevice6666::DEVICE_0001: return "PCCOM4";
        case PciDevice6666::DEVICE_0002: return "PCCOM8";
        case PciDevice6666::DEVICE_0004: return "PCCOM2";
        case PciDevice6666::DEVICE_0101: return "PCI 8255/8254 I/O Card";
        case PciDevice6666::DEVICE_0200: return "12-bit AD/DA Card";
        case PciDevice6666::DEVICE_0201: return "14-bit AD/DA Card";
        case PciDevice6666::DEVICE_1011: return "Industrial Card";
        case PciDevice6666::DEVICE_1021: return "8 photo couple 8 relay Card";
        case PciDevice6666::DEVICE_1022: return "4 photo couple 4 relay Card";
        case PciDevice6666::DEVICE_1025: return "16 photo couple 16 relay Card";
        case PciDevice6666::DEVICE_4000: return "WatchDog Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6666_PCIDEVICE6666_H
