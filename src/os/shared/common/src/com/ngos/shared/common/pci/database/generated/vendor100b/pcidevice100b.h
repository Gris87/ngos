// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCIDEVICE100B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCIDEVICE100B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice100B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_000E = 0x000E,
    DEVICE_000F = 0x000F,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0028 = 0x0028,
    DEVICE_002A = 0x002A,
    DEVICE_002B = 0x002B,
    DEVICE_002D = 0x002D,
    DEVICE_002E = 0x002E,
    DEVICE_002F = 0x002F,
    DEVICE_0030 = 0x0030,
    DEVICE_0035 = 0x0035,
    DEVICE_0500 = 0x0500,
    DEVICE_0501 = 0x0501,
    DEVICE_0502 = 0x0502,
    DEVICE_0503 = 0x0503,
    DEVICE_0504 = 0x0504,
    DEVICE_0505 = 0x0505,
    DEVICE_0510 = 0x0510,
    DEVICE_0511 = 0x0511,
    DEVICE_0515 = 0x0515,
    DEVICE_D001 = 0xD001
};



inline const char8* enumToString(PciDevice100B device100B) // TEST: NO
{
    // COMMON_LT((" | device100B = %u", device100B)); // Commented to avoid bad looking logs



    switch (device100B)
    {
        case PciDevice100B::NONE:        return "NONE";
        case PciDevice100B::DEVICE_0001: return "DEVICE_0001";
        case PciDevice100B::DEVICE_0002: return "DEVICE_0002";
        case PciDevice100B::DEVICE_000E: return "DEVICE_000E";
        case PciDevice100B::DEVICE_000F: return "DEVICE_000F";
        case PciDevice100B::DEVICE_0011: return "DEVICE_0011";
        case PciDevice100B::DEVICE_0012: return "DEVICE_0012";
        case PciDevice100B::DEVICE_0020: return "DEVICE_0020";
        case PciDevice100B::DEVICE_0021: return "DEVICE_0021";
        case PciDevice100B::DEVICE_0022: return "DEVICE_0022";
        case PciDevice100B::DEVICE_0028: return "DEVICE_0028";
        case PciDevice100B::DEVICE_002A: return "DEVICE_002A";
        case PciDevice100B::DEVICE_002B: return "DEVICE_002B";
        case PciDevice100B::DEVICE_002D: return "DEVICE_002D";
        case PciDevice100B::DEVICE_002E: return "DEVICE_002E";
        case PciDevice100B::DEVICE_002F: return "DEVICE_002F";
        case PciDevice100B::DEVICE_0030: return "DEVICE_0030";
        case PciDevice100B::DEVICE_0035: return "DEVICE_0035";
        case PciDevice100B::DEVICE_0500: return "DEVICE_0500";
        case PciDevice100B::DEVICE_0501: return "DEVICE_0501";
        case PciDevice100B::DEVICE_0502: return "DEVICE_0502";
        case PciDevice100B::DEVICE_0503: return "DEVICE_0503";
        case PciDevice100B::DEVICE_0504: return "DEVICE_0504";
        case PciDevice100B::DEVICE_0505: return "DEVICE_0505";
        case PciDevice100B::DEVICE_0510: return "DEVICE_0510";
        case PciDevice100B::DEVICE_0511: return "DEVICE_0511";
        case PciDevice100B::DEVICE_0515: return "DEVICE_0515";
        case PciDevice100B::DEVICE_D001: return "DEVICE_D001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice100B device100B) // TEST: NO
{
    // COMMON_LT((" | device100B = %u", device100B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device100B, enumToString(device100B));

    return res;
}



inline const char8* enumToHumanString(PciDevice100B device100B) // TEST: NO
{
    // COMMON_LT((" | device100B = %u", device100B)); // Commented to avoid bad looking logs



    switch (device100B)
    {
        case PciDevice100B::DEVICE_0001: return "DP83810";
        case PciDevice100B::DEVICE_0002: return "87415/87560 IDE";
        case PciDevice100B::DEVICE_000E: return "87560 Legacy I/O";
        case PciDevice100B::DEVICE_000F: return "FireWire Controller";
        case PciDevice100B::DEVICE_0011: return "NS87560 National PCI System I/O";
        case PciDevice100B::DEVICE_0012: return "USB Controller";
        case PciDevice100B::DEVICE_0020: return "DP83815 (MacPhyter) Ethernet Controller";
        case PciDevice100B::DEVICE_0021: return "PC87200 PCI to ISA Bridge";
        case PciDevice100B::DEVICE_0022: return "DP83820 10/100/1000 Ethernet Controller";
        case PciDevice100B::DEVICE_0028: return "Geode GX2 Host Bridge";
        case PciDevice100B::DEVICE_002A: return "CS5535 South Bridge";
        case PciDevice100B::DEVICE_002B: return "CS5535 ISA bridge";
        case PciDevice100B::DEVICE_002D: return "CS5535 IDE";
        case PciDevice100B::DEVICE_002E: return "CS5535 Audio";
        case PciDevice100B::DEVICE_002F: return "CS5535 USB";
        case PciDevice100B::DEVICE_0030: return "Geode GX2 Graphics Processor";
        case PciDevice100B::DEVICE_0035: return "DP83065 [Saturn] 10/100/1000 Ethernet Controller";
        case PciDevice100B::DEVICE_0500: return "SCx200 Bridge";
        case PciDevice100B::DEVICE_0501: return "SCx200 SMI";
        case PciDevice100B::DEVICE_0502: return "SCx200, SC1100 IDE controller";
        case PciDevice100B::DEVICE_0503: return "SCx200, SC1100 Audio Controller";
        case PciDevice100B::DEVICE_0504: return "SCx200 Video";
        case PciDevice100B::DEVICE_0505: return "SCx200 XBus";
        case PciDevice100B::DEVICE_0510: return "SC1100 Bridge";
        case PciDevice100B::DEVICE_0511: return "SC1100 SMI & ACPI";
        case PciDevice100B::DEVICE_0515: return "SC1100 XBus";
        case PciDevice100B::DEVICE_D001: return "87410 IDE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCIDEVICE100B_H
