// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCIDEVICE1028_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCIDEVICE1028_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1028: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000C = 0x000C,
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
    DEVICE_0073 = 0x0073
};



inline const char8* enumToString(PciDevice1028 device1028) // TEST: NO
{
    // COMMON_LT((" | device1028 = %u", device1028)); // Commented to avoid bad looking logs



    switch (device1028)
    {
        case PciDevice1028::NONE:        return "NONE";
        case PciDevice1028::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1028::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1028::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1028::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1028::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1028::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1028::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1028::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1028::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1028::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1028::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1028::DEVICE_000E: return "DEVICE_000E";
        case PciDevice1028::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1028::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1028::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1028::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1028::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1028::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1028::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1028::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1028::DEVICE_0073: return "DEVICE_0073";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1028 device1028) // TEST: NO
{
    // COMMON_LT((" | device1028 = %u", device1028)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1028, enumToString(device1028));

    return res;
}



inline const char8* enumToHumanString(PciDevice1028 device1028) // TEST: NO
{
    // COMMON_LT((" | device1028 = %u", device1028)); // Commented to avoid bad looking logs



    switch (device1028)
    {
        case PciDevice1028::DEVICE_0001: return "PowerEdge Expandable RAID Controller 2/Si";
        case PciDevice1028::DEVICE_0002: return "PowerEdge Expandable RAID Controller 3/Di";
        case PciDevice1028::DEVICE_0003: return "PowerEdge Expandable RAID Controller 3/Si";
        case PciDevice1028::DEVICE_0004: return "PowerEdge Expandable RAID Controller 3/Di [Iguana]";
        case PciDevice1028::DEVICE_0006: return "PowerEdge Expandable RAID Controller 3/Di";
        case PciDevice1028::DEVICE_0007: return "Remote Access Card III";
        case PciDevice1028::DEVICE_0008: return "Remote Access Card III";
        case PciDevice1028::DEVICE_0009: return "Remote Access Card III: BMC/SMIC device not present";
        case PciDevice1028::DEVICE_000A: return "PowerEdge Expandable RAID Controller 3/Di";
        case PciDevice1028::DEVICE_000C: return "Embedded Remote Access or ERA/O";
        case PciDevice1028::DEVICE_000D: return "Embedded Remote Access: BMC/SMIC device";
        case PciDevice1028::DEVICE_000E: return "PowerEdge Expandable RAID controller 4/Di";
        case PciDevice1028::DEVICE_000F: return "PowerEdge Expandable RAID controller 4/Di";
        case PciDevice1028::DEVICE_0010: return "Remote Access Card 4";
        case PciDevice1028::DEVICE_0011: return "Remote Access Card 4 Daughter Card";
        case PciDevice1028::DEVICE_0012: return "Remote Access Card 4 Daughter Card Virtual UART";
        case PciDevice1028::DEVICE_0013: return "PowerEdge Expandable RAID controller 4";
        case PciDevice1028::DEVICE_0014: return "Remote Access Card 4 Daughter Card SMIC interface";
        case PciDevice1028::DEVICE_0015: return "PowerEdge Expandable RAID controller 5";
        case PciDevice1028::DEVICE_0016: return "PowerEdge Expandable RAID controller S300";
        case PciDevice1028::DEVICE_0073: return "NV-RAM Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCIDEVICE1028_H
