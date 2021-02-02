// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C4_PCIDEVICE12C4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C4_PCIDEVICE12C4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12C4: bad_uint16 // Ignore CppEnumVerifier
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
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_0100 = 0x0100,
    DEVICE_0201 = 0x0201,
    DEVICE_0202 = 0x0202,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0310 = 0x0310,
    DEVICE_0311 = 0x0311,
    DEVICE_0312 = 0x0312,
    DEVICE_0320 = 0x0320,
    DEVICE_0321 = 0x0321,
    DEVICE_0322 = 0x0322,
    DEVICE_0330 = 0x0330,
    DEVICE_0331 = 0x0331,
    DEVICE_0332 = 0x0332
};



inline const char8* enumToString(PciDevice12C4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12C4::NONE:        return "NONE";
        case PciDevice12C4::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12C4::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12C4::DEVICE_0003: return "DEVICE_0003";
        case PciDevice12C4::DEVICE_0004: return "DEVICE_0004";
        case PciDevice12C4::DEVICE_0005: return "DEVICE_0005";
        case PciDevice12C4::DEVICE_0006: return "DEVICE_0006";
        case PciDevice12C4::DEVICE_0007: return "DEVICE_0007";
        case PciDevice12C4::DEVICE_0008: return "DEVICE_0008";
        case PciDevice12C4::DEVICE_0009: return "DEVICE_0009";
        case PciDevice12C4::DEVICE_000A: return "DEVICE_000A";
        case PciDevice12C4::DEVICE_000B: return "DEVICE_000B";
        case PciDevice12C4::DEVICE_000C: return "DEVICE_000C";
        case PciDevice12C4::DEVICE_000D: return "DEVICE_000D";
        case PciDevice12C4::DEVICE_0100: return "DEVICE_0100";
        case PciDevice12C4::DEVICE_0201: return "DEVICE_0201";
        case PciDevice12C4::DEVICE_0202: return "DEVICE_0202";
        case PciDevice12C4::DEVICE_0300: return "DEVICE_0300";
        case PciDevice12C4::DEVICE_0301: return "DEVICE_0301";
        case PciDevice12C4::DEVICE_0302: return "DEVICE_0302";
        case PciDevice12C4::DEVICE_0310: return "DEVICE_0310";
        case PciDevice12C4::DEVICE_0311: return "DEVICE_0311";
        case PciDevice12C4::DEVICE_0312: return "DEVICE_0312";
        case PciDevice12C4::DEVICE_0320: return "DEVICE_0320";
        case PciDevice12C4::DEVICE_0321: return "DEVICE_0321";
        case PciDevice12C4::DEVICE_0322: return "DEVICE_0322";
        case PciDevice12C4::DEVICE_0330: return "DEVICE_0330";
        case PciDevice12C4::DEVICE_0331: return "DEVICE_0331";
        case PciDevice12C4::DEVICE_0332: return "DEVICE_0332";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12C4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12C4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12C4::DEVICE_0001: return "Blue HEAT/PCI 8 (RS232/CL/RJ11)";
        case PciDevice12C4::DEVICE_0002: return "Blue HEAT/PCI 4 (RS232)";
        case PciDevice12C4::DEVICE_0003: return "Blue HEAT/PCI 2 (RS232)";
        case PciDevice12C4::DEVICE_0004: return "Blue HEAT/PCI 8 (UNIV, RS485)";
        case PciDevice12C4::DEVICE_0005: return "Blue HEAT/PCI 4+4/6+2 (UNIV, RS232/485)";
        case PciDevice12C4::DEVICE_0006: return "Blue HEAT/PCI 4 (OPTO, RS485)";
        case PciDevice12C4::DEVICE_0007: return "Blue HEAT/PCI 2+2 (RS232/485)";
        case PciDevice12C4::DEVICE_0008: return "Blue HEAT/PCI 2 (OPTO, Tx, RS485)";
        case PciDevice12C4::DEVICE_0009: return "Blue HEAT/PCI 2+6 (RS232/485)";
        case PciDevice12C4::DEVICE_000A: return "Blue HEAT/PCI 8 (Tx, RS485)";
        case PciDevice12C4::DEVICE_000B: return "Blue HEAT/PCI 4 (Tx, RS485)";
        case PciDevice12C4::DEVICE_000C: return "Blue HEAT/PCI 2 (20 MHz, RS485)";
        case PciDevice12C4::DEVICE_000D: return "Blue HEAT/PCI 2 PTM";
        case PciDevice12C4::DEVICE_0100: return "NT960/PCI";
        case PciDevice12C4::DEVICE_0201: return "cPCI Titan - 2 Port";
        case PciDevice12C4::DEVICE_0202: return "cPCI Titan - 4 Port";
        case PciDevice12C4::DEVICE_0300: return "CTI PCI UART 2 (RS232)";
        case PciDevice12C4::DEVICE_0301: return "CTI PCI UART 4 (RS232)";
        case PciDevice12C4::DEVICE_0302: return "CTI PCI UART 8 (RS232)";
        case PciDevice12C4::DEVICE_0310: return "CTI PCI UART 1+1 (RS232/485)";
        case PciDevice12C4::DEVICE_0311: return "CTI PCI UART 2+2 (RS232/485)";
        case PciDevice12C4::DEVICE_0312: return "CTI PCI UART 4+4 (RS232/485)";
        case PciDevice12C4::DEVICE_0320: return "CTI PCI UART 2";
        case PciDevice12C4::DEVICE_0321: return "CTI PCI UART 4";
        case PciDevice12C4::DEVICE_0322: return "CTI PCI UART 8";
        case PciDevice12C4::DEVICE_0330: return "CTI PCI UART 2 (RS485)";
        case PciDevice12C4::DEVICE_0331: return "CTI PCI UART 4 (RS485)";
        case PciDevice12C4::DEVICE_0332: return "CTI PCI UART 8 (RS485)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C4_PCIDEVICE12C4_H
