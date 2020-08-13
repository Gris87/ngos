// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1896_PCIDEVICE1896_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1896_PCIDEVICE1896_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1896: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4202 = 0x4202,
    DEVICE_4204 = 0x4204,
    DEVICE_4208 = 0x4208,
    DEVICE_4211 = 0x4211,
    DEVICE_4212 = 0x4212,
    DEVICE_4214 = 0x4214,
    DEVICE_BB10 = 0xBB10,
    DEVICE_BB11 = 0xBB11
};



inline const char8* enumToString(PciDevice1896 device1896) // TEST: NO
{
    // COMMON_LT((" | device1896 = %u", device1896)); // Commented to avoid bad looking logs



    switch (device1896)
    {
        case PciDevice1896::NONE:        return "NONE";
        case PciDevice1896::DEVICE_4202: return "DEVICE_4202";
        case PciDevice1896::DEVICE_4204: return "DEVICE_4204";
        case PciDevice1896::DEVICE_4208: return "DEVICE_4208";
        case PciDevice1896::DEVICE_4211: return "DEVICE_4211";
        case PciDevice1896::DEVICE_4212: return "DEVICE_4212";
        case PciDevice1896::DEVICE_4214: return "DEVICE_4214";
        case PciDevice1896::DEVICE_BB10: return "DEVICE_BB10";
        case PciDevice1896::DEVICE_BB11: return "DEVICE_BB11";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1896 device1896) // TEST: NO
{
    // COMMON_LT((" | device1896 = %u", device1896)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1896, enumToString(device1896));

    return res;
}



inline const char8* enumToHumanString(PciDevice1896 device1896) // TEST: NO
{
    // COMMON_LT((" | device1896 = %u", device1896)); // Commented to avoid bad looking logs



    switch (device1896)
    {
        case PciDevice1896::DEVICE_4202: return "MIport 3PCIU2 2-port Serial";
        case PciDevice1896::DEVICE_4204: return "MIport 3PCIU4 4-port Serial";
        case PciDevice1896::DEVICE_4208: return "MIport 3PCIU8 8-port Serial";
        case PciDevice1896::DEVICE_4211: return "MIport 3PCIOU1 1-port Isolated Serial";
        case PciDevice1896::DEVICE_4212: return "MIport 3PCIOU2 2-port Isolated Serial";
        case PciDevice1896::DEVICE_4214: return "MIport 3PCIOU4 4-port Isolated Serial";
        case PciDevice1896::DEVICE_BB10: return "3PCI2 2-Port Serial";
        case PciDevice1896::DEVICE_BB11: return "3PCIO1 1-Port Isolated Serial";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1896_PCIDEVICE1896_H
