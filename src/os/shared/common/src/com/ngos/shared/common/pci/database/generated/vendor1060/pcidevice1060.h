// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1060_PCIDEVICE1060_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1060_PCIDEVICE1060_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1060: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0101 = 0x0101,
    DEVICE_0881 = 0x0881,
    DEVICE_0886 = 0x0886,
    DEVICE_0891 = 0x0891,
    DEVICE_1001 = 0x1001,
    DEVICE_673A = 0x673A,
    DEVICE_673B = 0x673B,
    DEVICE_8710 = 0x8710,
    DEVICE_886A = 0x886A,
    DEVICE_8881 = 0x8881,
    DEVICE_8886 = 0x8886,
    DEVICE_888A = 0x888A,
    DEVICE_8891 = 0x8891,
    DEVICE_9017 = 0x9017,
    DEVICE_9018 = 0x9018,
    DEVICE_9026 = 0x9026,
    DEVICE_E881 = 0xE881,
    DEVICE_E886 = 0xE886,
    DEVICE_E88A = 0xE88A,
    DEVICE_E891 = 0xE891
};



inline const char8* enumToString(PciDevice1060 device1060) // TEST: NO
{
    // COMMON_LT((" | device1060 = %u", device1060)); // Commented to avoid bad looking logs



    switch (device1060)
    {
        case PciDevice1060::NONE:        return "NONE";
        case PciDevice1060::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1060::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1060::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1060::DEVICE_0881: return "DEVICE_0881";
        case PciDevice1060::DEVICE_0886: return "DEVICE_0886";
        case PciDevice1060::DEVICE_0891: return "DEVICE_0891";
        case PciDevice1060::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1060::DEVICE_673A: return "DEVICE_673A";
        case PciDevice1060::DEVICE_673B: return "DEVICE_673B";
        case PciDevice1060::DEVICE_8710: return "DEVICE_8710";
        case PciDevice1060::DEVICE_886A: return "DEVICE_886A";
        case PciDevice1060::DEVICE_8881: return "DEVICE_8881";
        case PciDevice1060::DEVICE_8886: return "DEVICE_8886";
        case PciDevice1060::DEVICE_888A: return "DEVICE_888A";
        case PciDevice1060::DEVICE_8891: return "DEVICE_8891";
        case PciDevice1060::DEVICE_9017: return "DEVICE_9017";
        case PciDevice1060::DEVICE_9018: return "DEVICE_9018";
        case PciDevice1060::DEVICE_9026: return "DEVICE_9026";
        case PciDevice1060::DEVICE_E881: return "DEVICE_E881";
        case PciDevice1060::DEVICE_E886: return "DEVICE_E886";
        case PciDevice1060::DEVICE_E88A: return "DEVICE_E88A";
        case PciDevice1060::DEVICE_E891: return "DEVICE_E891";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1060 device1060) // TEST: NO
{
    // COMMON_LT((" | device1060 = %u", device1060)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1060, enumToString(device1060));

    return res;
}



inline const char8* enumToHumanString(PciDevice1060 device1060) // TEST: NO
{
    // COMMON_LT((" | device1060 = %u", device1060)); // Commented to avoid bad looking logs



    switch (device1060)
    {
        case PciDevice1060::DEVICE_0001: return "UM82C881";
        case PciDevice1060::DEVICE_0002: return "UM82C886";
        case PciDevice1060::DEVICE_0101: return "UM8673F";
        case PciDevice1060::DEVICE_0881: return "UM8881";
        case PciDevice1060::DEVICE_0886: return "UM8886F";
        case PciDevice1060::DEVICE_0891: return "UM8891A";
        case PciDevice1060::DEVICE_1001: return "UM886A";
        case PciDevice1060::DEVICE_673A: return "UM8886BF";
        case PciDevice1060::DEVICE_673B: return "EIDE Master/DMA";
        case PciDevice1060::DEVICE_8710: return "UM8710";
        case PciDevice1060::DEVICE_886A: return "UM8886A";
        case PciDevice1060::DEVICE_8881: return "UM8881F";
        case PciDevice1060::DEVICE_8886: return "UM8886F";
        case PciDevice1060::DEVICE_888A: return "UM8886A";
        case PciDevice1060::DEVICE_8891: return "UM8891A";
        case PciDevice1060::DEVICE_9017: return "UM9017F";
        case PciDevice1060::DEVICE_9018: return "UM9018";
        case PciDevice1060::DEVICE_9026: return "UM9026";
        case PciDevice1060::DEVICE_E881: return "UM8881N";
        case PciDevice1060::DEVICE_E886: return "UM8886N";
        case PciDevice1060::DEVICE_E88A: return "UM8886N";
        case PciDevice1060::DEVICE_E891: return "UM8891N";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1060_PCIDEVICE1060_H
