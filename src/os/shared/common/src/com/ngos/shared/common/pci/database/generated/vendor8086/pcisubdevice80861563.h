// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861563_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861563_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861563: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FA8 = 0x10281FA8,
    SUBDEVICE_10281FA9 = 0x10281FA9,
    SUBDEVICE_113702B2 = 0x113702B2,
    SUBDEVICE_113702B3 = 0x113702B3,
    SUBDEVICE_11700001 = 0x11700001,
    SUBDEVICE_14C01201 = 0x14C01201,
    SUBDEVICE_159000D1 = 0x159000D1,
    SUBDEVICE_159000D2 = 0x159000D2,
    SUBDEVICE_16B87217 = 0x16B87217,
    SUBDEVICE_18D40C08 = 0x18D40C08,
    SUBDEVICE_193D1008 = 0x193D1008,
    SUBDEVICE_193D1009 = 0x193D1009,
    SUBDEVICE_193D1011 = 0x193D1011,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_8086001A = 0x8086001A,
    SUBDEVICE_8086001B = 0x8086001B,
    SUBDEVICE_8086001D = 0x8086001D,
    SUBDEVICE_80860022 = 0x80860022
};



inline const char8* enumToString(PciSubDevice80861563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861563::NONE:               return "NONE";
        case PciSubDevice80861563::SUBDEVICE_10281FA8: return "SUBDEVICE_10281FA8";
        case PciSubDevice80861563::SUBDEVICE_10281FA9: return "SUBDEVICE_10281FA9";
        case PciSubDevice80861563::SUBDEVICE_113702B2: return "SUBDEVICE_113702B2";
        case PciSubDevice80861563::SUBDEVICE_113702B3: return "SUBDEVICE_113702B3";
        case PciSubDevice80861563::SUBDEVICE_11700001: return "SUBDEVICE_11700001";
        case PciSubDevice80861563::SUBDEVICE_14C01201: return "SUBDEVICE_14C01201";
        case PciSubDevice80861563::SUBDEVICE_159000D1: return "SUBDEVICE_159000D1";
        case PciSubDevice80861563::SUBDEVICE_159000D2: return "SUBDEVICE_159000D2";
        case PciSubDevice80861563::SUBDEVICE_16B87217: return "SUBDEVICE_16B87217";
        case PciSubDevice80861563::SUBDEVICE_18D40C08: return "SUBDEVICE_18D40C08";
        case PciSubDevice80861563::SUBDEVICE_193D1008: return "SUBDEVICE_193D1008";
        case PciSubDevice80861563::SUBDEVICE_193D1009: return "SUBDEVICE_193D1009";
        case PciSubDevice80861563::SUBDEVICE_193D1011: return "SUBDEVICE_193D1011";
        case PciSubDevice80861563::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861563::SUBDEVICE_8086001A: return "SUBDEVICE_8086001A";
        case PciSubDevice80861563::SUBDEVICE_8086001B: return "SUBDEVICE_8086001B";
        case PciSubDevice80861563::SUBDEVICE_8086001D: return "SUBDEVICE_8086001D";
        case PciSubDevice80861563::SUBDEVICE_80860022: return "SUBDEVICE_80860022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861563::SUBDEVICE_10281FA8: return "Ethernet 10G 4P X550/I350 rNDC";
        case PciSubDevice80861563::SUBDEVICE_10281FA9: return "Ethernet 10G 4P X550 rNDC";
        case PciSubDevice80861563::SUBDEVICE_113702B2: return "X550-TX 10 Gig LOM";
        case PciSubDevice80861563::SUBDEVICE_113702B3: return "X550-TX 10 Gig LOM";
        case PciSubDevice80861563::SUBDEVICE_11700001: return "Intel Ethernet Controller X550-T2 OCP card";
        case PciSubDevice80861563::SUBDEVICE_14C01201: return "X550 10Gb 2P RJ45 OCP Mezz";
        case PciSubDevice80861563::SUBDEVICE_159000D1: return "Ethernet 10Gb 2-port 562T Adapter";
        case PciSubDevice80861563::SUBDEVICE_159000D2: return "Ethernet 10Gb 2-port 562FLR-T Adapter";
        case PciSubDevice80861563::SUBDEVICE_16B87217: return "Twin10G Thunderbolt 3 Edition";
        case PciSubDevice80861563::SUBDEVICE_18D40C08: return "X550 10Gb 2-port RJ45 OCP Mezz Card MOP81-I-10GT2";
        case PciSubDevice80861563::SUBDEVICE_193D1008: return "560T-B";
        case PciSubDevice80861563::SUBDEVICE_193D1009: return "560T-L";
        case PciSubDevice80861563::SUBDEVICE_193D1011: return "UN-NIC-ETH563T-sL-2P";
        case PciSubDevice80861563::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter X550-T2";
        case PciSubDevice80861563::SUBDEVICE_8086001A: return "Ethernet Converged Network Adapter X550-T2";
        case PciSubDevice80861563::SUBDEVICE_8086001B: return "Ethernet Server Adapter X550-T2 for OCP";
        case PciSubDevice80861563::SUBDEVICE_8086001D: return "Ethernet 10G 2P X550-t Adapter";
        case PciSubDevice80861563::SUBDEVICE_80860022: return "Ethernet Converged Network Adapter X550-T2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861563_H
