// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1796_PCIDEVICE1796_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1796_PCIDEVICE1796_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1796: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000D = 0x000D,
    DEVICE_000E = 0x000E,
    DEVICE_000F = 0x000F,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_001C = 0x001C,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031
};



inline const char8* enumToString(PciDevice1796 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1796::NONE:        return "NONE";
        case PciDevice1796::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1796::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1796::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1796::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1796::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1796::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1796::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1796::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1796::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1796::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1796::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1796::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1796::DEVICE_000E: return "DEVICE_000E";
        case PciDevice1796::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1796::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1796::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1796::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1796::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1796::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1796::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1796::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1796::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1796::DEVICE_0018: return "DEVICE_0018";
        case PciDevice1796::DEVICE_0019: return "DEVICE_0019";
        case PciDevice1796::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1796::DEVICE_001C: return "DEVICE_001C";
        case PciDevice1796::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1796::DEVICE_0031: return "DEVICE_0031";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1796 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1796 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1796::DEVICE_0001: return "SIS1100 [Gigabit link]";
        case PciDevice1796::DEVICE_0002: return "HOTlink";
        case PciDevice1796::DEVICE_0003: return "Counter Timer";
        case PciDevice1796::DEVICE_0004: return "CAMAC Controller";
        case PciDevice1796::DEVICE_0005: return "PROFIBUS";
        case PciDevice1796::DEVICE_0006: return "AMCC HOTlink";
        case PciDevice1796::DEVICE_0007: return "LVD Cable Bus";
        case PciDevice1796::DEVICE_0008: return "100MHz, 64bit Sequence Generator based on VirtexII";
        case PciDevice1796::DEVICE_0009: return "double 14bit-ADC";
        case PciDevice1796::DEVICE_000A: return "SIS1100 with N110 TDC";
        case PciDevice1796::DEVICE_000B: return "double 14bit-ADC with memory";
        case PciDevice1796::DEVICE_000D: return "Synchronisation Slave";
        case PciDevice1796::DEVICE_000E: return "SIS1100-eCMC";
        case PciDevice1796::DEVICE_000F: return "TDC (GPX)";
        case PciDevice1796::DEVICE_0010: return "PCIe Counter Timer";
        case PciDevice1796::DEVICE_0011: return "SIS1100-e single link";
        case PciDevice1796::DEVICE_0012: return "SIS1100-e quad link";
        case PciDevice1796::DEVICE_0013: return "4x2.5GHz SFP to 4 lane PCIe bridge";
        case PciDevice1796::DEVICE_0014: return "SIS1100 with GPX piggy back";
        case PciDevice1796::DEVICE_0015: return "SIS8100 [Gigabit link, MicroTCA]";
        case PciDevice1796::DEVICE_0016: return "SIS1100e with 4 lanes";
        case PciDevice1796::DEVICE_0017: return "Quad 14bit, 50MHz ADC with 2.5GHz SFP";
        case PciDevice1796::DEVICE_0018: return "SIS8300 4-lane PCI Express, Micro TCA for Physics ADC";
        case PciDevice1796::DEVICE_0019: return "SIS SIS8300-Lx MTCA.4 Digitizer";
        case PciDevice1796::DEVICE_001A: return "100MHz, 64bit Sequence Generator based on VirtexII";
        case PciDevice1796::DEVICE_001C: return "Quad 16bit, 150MHz ADC with 2.5GHz SFP";
        case PciDevice1796::DEVICE_0030: return "100MHz, 64bit Sequence Generator based on Spartan6";
        case PciDevice1796::DEVICE_0031: return "200MHz 64bit Sequence Generator based on Spartan7";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1796_PCIDEVICE1796_H
