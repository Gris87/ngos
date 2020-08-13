// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCIDEVICE1969_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCIDEVICE1969_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1969: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1026 = 0x1026,
    DEVICE_1048 = 0x1048,
    DEVICE_1062 = 0x1062,
    DEVICE_1063 = 0x1063,
    DEVICE_1066 = 0x1066,
    DEVICE_1067 = 0x1067,
    DEVICE_1073 = 0x1073,
    DEVICE_1083 = 0x1083,
    DEVICE_1090 = 0x1090,
    DEVICE_1091 = 0x1091,
    DEVICE_10A0 = 0x10A0,
    DEVICE_10A1 = 0x10A1,
    DEVICE_2048 = 0x2048,
    DEVICE_2060 = 0x2060,
    DEVICE_2062 = 0x2062,
    DEVICE_E091 = 0xE091,
    DEVICE_E0A1 = 0xE0A1,
    DEVICE_E0B1 = 0xE0B1
};



inline const char8* enumToString(PciDevice1969 device1969) // TEST: NO
{
    // COMMON_LT((" | device1969 = %u", device1969)); // Commented to avoid bad looking logs



    switch (device1969)
    {
        case PciDevice1969::NONE:        return "NONE";
        case PciDevice1969::DEVICE_1026: return "DEVICE_1026";
        case PciDevice1969::DEVICE_1048: return "DEVICE_1048";
        case PciDevice1969::DEVICE_1062: return "DEVICE_1062";
        case PciDevice1969::DEVICE_1063: return "DEVICE_1063";
        case PciDevice1969::DEVICE_1066: return "DEVICE_1066";
        case PciDevice1969::DEVICE_1067: return "DEVICE_1067";
        case PciDevice1969::DEVICE_1073: return "DEVICE_1073";
        case PciDevice1969::DEVICE_1083: return "DEVICE_1083";
        case PciDevice1969::DEVICE_1090: return "DEVICE_1090";
        case PciDevice1969::DEVICE_1091: return "DEVICE_1091";
        case PciDevice1969::DEVICE_10A0: return "DEVICE_10A0";
        case PciDevice1969::DEVICE_10A1: return "DEVICE_10A1";
        case PciDevice1969::DEVICE_2048: return "DEVICE_2048";
        case PciDevice1969::DEVICE_2060: return "DEVICE_2060";
        case PciDevice1969::DEVICE_2062: return "DEVICE_2062";
        case PciDevice1969::DEVICE_E091: return "DEVICE_E091";
        case PciDevice1969::DEVICE_E0A1: return "DEVICE_E0A1";
        case PciDevice1969::DEVICE_E0B1: return "DEVICE_E0B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1969 device1969) // TEST: NO
{
    // COMMON_LT((" | device1969 = %u", device1969)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1969, enumToString(device1969));

    return res;
}



inline const char8* enumToHumanString(PciDevice1969 device1969) // TEST: NO
{
    // COMMON_LT((" | device1969 = %u", device1969)); // Commented to avoid bad looking logs



    switch (device1969)
    {
        case PciDevice1969::DEVICE_1026: return "AR8121/AR8113/AR8114 Gigabit or Fast Ethernet";
        case PciDevice1969::DEVICE_1048: return "Attansic L1 Gigabit Ethernet";
        case PciDevice1969::DEVICE_1062: return "AR8132 Fast Ethernet";
        case PciDevice1969::DEVICE_1063: return "AR8131 Gigabit Ethernet";
        case PciDevice1969::DEVICE_1066: return "Attansic L2c Gigabit Ethernet";
        case PciDevice1969::DEVICE_1067: return "Attansic L1c Gigabit Ethernet";
        case PciDevice1969::DEVICE_1073: return "AR8151 v1.0 Gigabit Ethernet";
        case PciDevice1969::DEVICE_1083: return "AR8151 v2.0 Gigabit Ethernet";
        case PciDevice1969::DEVICE_1090: return "AR8162 Fast Ethernet";
        case PciDevice1969::DEVICE_1091: return "AR8161 Gigabit Ethernet";
        case PciDevice1969::DEVICE_10A0: return "QCA8172 Fast Ethernet";
        case PciDevice1969::DEVICE_10A1: return "QCA8171 Gigabit Ethernet";
        case PciDevice1969::DEVICE_2048: return "Attansic L2 Fast Ethernet";
        case PciDevice1969::DEVICE_2060: return "AR8152 v1.1 Fast Ethernet";
        case PciDevice1969::DEVICE_2062: return "AR8152 v2.0 Fast Ethernet";
        case PciDevice1969::DEVICE_E091: return "Killer E220x Gigabit Ethernet Controller";
        case PciDevice1969::DEVICE_E0A1: return "Killer E2400 Gigabit Ethernet Controller";
        case PciDevice1969::DEVICE_E0B1: return "Killer E2500 Gigabit Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCIDEVICE1969_H
