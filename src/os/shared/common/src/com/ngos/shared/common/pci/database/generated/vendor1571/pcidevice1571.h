// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1571_PCIDEVICE1571_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1571_PCIDEVICE1571_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1571: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A001 = 0xA001,
    DEVICE_A002 = 0xA002,
    DEVICE_A003 = 0xA003,
    DEVICE_A004 = 0xA004,
    DEVICE_A005 = 0xA005,
    DEVICE_A006 = 0xA006,
    DEVICE_A007 = 0xA007,
    DEVICE_A008 = 0xA008,
    DEVICE_A009 = 0xA009,
    DEVICE_A00A = 0xA00A,
    DEVICE_A00B = 0xA00B,
    DEVICE_A00C = 0xA00C,
    DEVICE_A00D = 0xA00D,
    DEVICE_A201 = 0xA201,
    DEVICE_A202 = 0xA202,
    DEVICE_A203 = 0xA203,
    DEVICE_A204 = 0xA204,
    DEVICE_A205 = 0xA205,
    DEVICE_A206 = 0xA206
};



inline const char8* enumToString(PciDevice1571 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1571::NONE:        return "NONE";
        case PciDevice1571::DEVICE_A001: return "DEVICE_A001";
        case PciDevice1571::DEVICE_A002: return "DEVICE_A002";
        case PciDevice1571::DEVICE_A003: return "DEVICE_A003";
        case PciDevice1571::DEVICE_A004: return "DEVICE_A004";
        case PciDevice1571::DEVICE_A005: return "DEVICE_A005";
        case PciDevice1571::DEVICE_A006: return "DEVICE_A006";
        case PciDevice1571::DEVICE_A007: return "DEVICE_A007";
        case PciDevice1571::DEVICE_A008: return "DEVICE_A008";
        case PciDevice1571::DEVICE_A009: return "DEVICE_A009";
        case PciDevice1571::DEVICE_A00A: return "DEVICE_A00A";
        case PciDevice1571::DEVICE_A00B: return "DEVICE_A00B";
        case PciDevice1571::DEVICE_A00C: return "DEVICE_A00C";
        case PciDevice1571::DEVICE_A00D: return "DEVICE_A00D";
        case PciDevice1571::DEVICE_A201: return "DEVICE_A201";
        case PciDevice1571::DEVICE_A202: return "DEVICE_A202";
        case PciDevice1571::DEVICE_A203: return "DEVICE_A203";
        case PciDevice1571::DEVICE_A204: return "DEVICE_A204";
        case PciDevice1571::DEVICE_A205: return "DEVICE_A205";
        case PciDevice1571::DEVICE_A206: return "DEVICE_A206";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1571 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1571 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1571::DEVICE_A001: return "CCSI PCI20-485 ARCnet";
        case PciDevice1571::DEVICE_A002: return "CCSI PCI20-485D ARCnet";
        case PciDevice1571::DEVICE_A003: return "CCSI PCI20-485X ARCnet";
        case PciDevice1571::DEVICE_A004: return "CCSI PCI20-CXB ARCnet";
        case PciDevice1571::DEVICE_A005: return "CCSI PCI20-CXS ARCnet";
        case PciDevice1571::DEVICE_A006: return "CCSI PCI20-FOG-SMA ARCnet";
        case PciDevice1571::DEVICE_A007: return "CCSI PCI20-FOG-ST ARCnet";
        case PciDevice1571::DEVICE_A008: return "CCSI PCI20-TB5 ARCnet";
        case PciDevice1571::DEVICE_A009: return "CCSI PCI20-5-485 5Mbit ARCnet";
        case PciDevice1571::DEVICE_A00A: return "CCSI PCI20-5-485D 5Mbit ARCnet";
        case PciDevice1571::DEVICE_A00B: return "CCSI PCI20-5-485X 5Mbit ARCnet";
        case PciDevice1571::DEVICE_A00C: return "CCSI PCI20-5-FOG-ST 5Mbit ARCnet";
        case PciDevice1571::DEVICE_A00D: return "CCSI PCI20-5-FOG-SMA 5Mbit ARCnet";
        case PciDevice1571::DEVICE_A201: return "CCSI PCI22-485 10Mbit ARCnet";
        case PciDevice1571::DEVICE_A202: return "CCSI PCI22-485D 10Mbit ARCnet";
        case PciDevice1571::DEVICE_A203: return "CCSI PCI22-485X 10Mbit ARCnet";
        case PciDevice1571::DEVICE_A204: return "CCSI PCI22-CHB 10Mbit ARCnet";
        case PciDevice1571::DEVICE_A205: return "CCSI PCI22-FOG_ST 10Mbit ARCnet";
        case PciDevice1571::DEVICE_A206: return "CCSI PCI22-THB 10Mbit ARCnet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1571_PCIDEVICE1571_H
