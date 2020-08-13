// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FE_PCIDEVICE11FE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FE_PCIDEVICE11FE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11FE: u16 // Ignore CppEnumVerifier
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
    DEVICE_000E = 0x000E,
    DEVICE_000F = 0x000F,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0043 = 0x0043,
    DEVICE_0044 = 0x0044,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_0047 = 0x0047,
    DEVICE_0048 = 0x0048,
    DEVICE_004A = 0x004A,
    DEVICE_004B = 0x004B,
    DEVICE_004C = 0x004C,
    DEVICE_004D = 0x004D,
    DEVICE_004E = 0x004E,
    DEVICE_004F = 0x004F,
    DEVICE_0050 = 0x0050,
    DEVICE_0051 = 0x0051,
    DEVICE_0052 = 0x0052,
    DEVICE_0060 = 0x0060,
    DEVICE_0061 = 0x0061,
    DEVICE_0062 = 0x0062,
    DEVICE_0063 = 0x0063,
    DEVICE_0064 = 0x0064,
    DEVICE_0065 = 0x0065,
    DEVICE_0066 = 0x0066,
    DEVICE_0067 = 0x0067,
    DEVICE_0068 = 0x0068,
    DEVICE_006F = 0x006F,
    DEVICE_0072 = 0x0072,
    DEVICE_0801 = 0x0801,
    DEVICE_0802 = 0x0802,
    DEVICE_0803 = 0x0803,
    DEVICE_0805 = 0x0805,
    DEVICE_080B = 0x080B,
    DEVICE_080C = 0x080C,
    DEVICE_080D = 0x080D,
    DEVICE_080E = 0x080E,
    DEVICE_080F = 0x080F,
    DEVICE_0810 = 0x0810,
    DEVICE_0811 = 0x0811,
    DEVICE_0812 = 0x0812,
    DEVICE_0813 = 0x0813,
    DEVICE_0814 = 0x0814,
    DEVICE_0903 = 0x0903,
    DEVICE_8015 = 0x8015,
    DEVICE_8805 = 0x8805,
    DEVICE_880B = 0x880B,
    DEVICE_8812 = 0x8812
};



inline const char8* enumToString(PciDevice11FE device11FE) // TEST: NO
{
    // COMMON_LT((" | device11FE = %u", device11FE)); // Commented to avoid bad looking logs



    switch (device11FE)
    {
        case PciDevice11FE::NONE:        return "NONE";
        case PciDevice11FE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice11FE::DEVICE_0002: return "DEVICE_0002";
        case PciDevice11FE::DEVICE_0003: return "DEVICE_0003";
        case PciDevice11FE::DEVICE_0004: return "DEVICE_0004";
        case PciDevice11FE::DEVICE_0005: return "DEVICE_0005";
        case PciDevice11FE::DEVICE_0006: return "DEVICE_0006";
        case PciDevice11FE::DEVICE_0007: return "DEVICE_0007";
        case PciDevice11FE::DEVICE_0008: return "DEVICE_0008";
        case PciDevice11FE::DEVICE_0009: return "DEVICE_0009";
        case PciDevice11FE::DEVICE_000A: return "DEVICE_000A";
        case PciDevice11FE::DEVICE_000B: return "DEVICE_000B";
        case PciDevice11FE::DEVICE_000C: return "DEVICE_000C";
        case PciDevice11FE::DEVICE_000D: return "DEVICE_000D";
        case PciDevice11FE::DEVICE_000E: return "DEVICE_000E";
        case PciDevice11FE::DEVICE_000F: return "DEVICE_000F";
        case PciDevice11FE::DEVICE_0040: return "DEVICE_0040";
        case PciDevice11FE::DEVICE_0041: return "DEVICE_0041";
        case PciDevice11FE::DEVICE_0042: return "DEVICE_0042";
        case PciDevice11FE::DEVICE_0043: return "DEVICE_0043";
        case PciDevice11FE::DEVICE_0044: return "DEVICE_0044";
        case PciDevice11FE::DEVICE_0045: return "DEVICE_0045";
        case PciDevice11FE::DEVICE_0046: return "DEVICE_0046";
        case PciDevice11FE::DEVICE_0047: return "DEVICE_0047";
        case PciDevice11FE::DEVICE_0048: return "DEVICE_0048";
        case PciDevice11FE::DEVICE_004A: return "DEVICE_004A";
        case PciDevice11FE::DEVICE_004B: return "DEVICE_004B";
        case PciDevice11FE::DEVICE_004C: return "DEVICE_004C";
        case PciDevice11FE::DEVICE_004D: return "DEVICE_004D";
        case PciDevice11FE::DEVICE_004E: return "DEVICE_004E";
        case PciDevice11FE::DEVICE_004F: return "DEVICE_004F";
        case PciDevice11FE::DEVICE_0050: return "DEVICE_0050";
        case PciDevice11FE::DEVICE_0051: return "DEVICE_0051";
        case PciDevice11FE::DEVICE_0052: return "DEVICE_0052";
        case PciDevice11FE::DEVICE_0060: return "DEVICE_0060";
        case PciDevice11FE::DEVICE_0061: return "DEVICE_0061";
        case PciDevice11FE::DEVICE_0062: return "DEVICE_0062";
        case PciDevice11FE::DEVICE_0063: return "DEVICE_0063";
        case PciDevice11FE::DEVICE_0064: return "DEVICE_0064";
        case PciDevice11FE::DEVICE_0065: return "DEVICE_0065";
        case PciDevice11FE::DEVICE_0066: return "DEVICE_0066";
        case PciDevice11FE::DEVICE_0067: return "DEVICE_0067";
        case PciDevice11FE::DEVICE_0068: return "DEVICE_0068";
        case PciDevice11FE::DEVICE_006F: return "DEVICE_006F";
        case PciDevice11FE::DEVICE_0072: return "DEVICE_0072";
        case PciDevice11FE::DEVICE_0801: return "DEVICE_0801";
        case PciDevice11FE::DEVICE_0802: return "DEVICE_0802";
        case PciDevice11FE::DEVICE_0803: return "DEVICE_0803";
        case PciDevice11FE::DEVICE_0805: return "DEVICE_0805";
        case PciDevice11FE::DEVICE_080B: return "DEVICE_080B";
        case PciDevice11FE::DEVICE_080C: return "DEVICE_080C";
        case PciDevice11FE::DEVICE_080D: return "DEVICE_080D";
        case PciDevice11FE::DEVICE_080E: return "DEVICE_080E";
        case PciDevice11FE::DEVICE_080F: return "DEVICE_080F";
        case PciDevice11FE::DEVICE_0810: return "DEVICE_0810";
        case PciDevice11FE::DEVICE_0811: return "DEVICE_0811";
        case PciDevice11FE::DEVICE_0812: return "DEVICE_0812";
        case PciDevice11FE::DEVICE_0813: return "DEVICE_0813";
        case PciDevice11FE::DEVICE_0814: return "DEVICE_0814";
        case PciDevice11FE::DEVICE_0903: return "DEVICE_0903";
        case PciDevice11FE::DEVICE_8015: return "DEVICE_8015";
        case PciDevice11FE::DEVICE_8805: return "DEVICE_8805";
        case PciDevice11FE::DEVICE_880B: return "DEVICE_880B";
        case PciDevice11FE::DEVICE_8812: return "DEVICE_8812";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11FE device11FE) // TEST: NO
{
    // COMMON_LT((" | device11FE = %u", device11FE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11FE, enumToString(device11FE));

    return res;
}



inline const char8* enumToHumanString(PciDevice11FE device11FE) // TEST: NO
{
    // COMMON_LT((" | device11FE = %u", device11FE)); // Commented to avoid bad looking logs



    switch (device11FE)
    {
        case PciDevice11FE::DEVICE_0001: return "RocketPort PCI 32-port w/external I/F";
        case PciDevice11FE::DEVICE_0002: return "RocketPort PCI 8-port w/external I/F";
        case PciDevice11FE::DEVICE_0003: return "RocketPort PCI 16-port w/external I/F";
        case PciDevice11FE::DEVICE_0004: return "RocketPort PCI 4-port w/Quad Cable";
        case PciDevice11FE::DEVICE_0005: return "RocketPort PCI 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_0006: return "RocketPort PCI 8-port w/RJ11 connectors";
        case PciDevice11FE::DEVICE_0007: return "RocketPort PCI 4-port w/RJ45 connectors";
        case PciDevice11FE::DEVICE_0008: return "RocketPort PCI 8-port w/DB78 SNI connector (Siemens)";
        case PciDevice11FE::DEVICE_0009: return "RocketPort PCI 16-port w/DB78 SNI connector (Siemens)";
        case PciDevice11FE::DEVICE_000A: return "RocketPort PCI Plus 4-port w/Quad Cable";
        case PciDevice11FE::DEVICE_000B: return "RocketPort PCI Plus 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_000C: return "RocketModem II 6-port";
        case PciDevice11FE::DEVICE_000D: return "RocketModem 4-port";
        case PciDevice11FE::DEVICE_000E: return "RocketPort PCI Plus 2-port RS-232 w/DB9 connectors";
        case PciDevice11FE::DEVICE_000F: return "RocketPort PCI Plus 2-port SMPTE w/DB9 connectors";
        case PciDevice11FE::DEVICE_0040: return "RocketPort INFINITY 8-port w/Octa Cable RJ45";
        case PciDevice11FE::DEVICE_0041: return "RocketPort INFINITY 32-port w/external I/F";
        case PciDevice11FE::DEVICE_0042: return "RocketPort INFINITY 8-port w/external I/F";
        case PciDevice11FE::DEVICE_0043: return "RocketPort INFINITY 16-port w/external I/F";
        case PciDevice11FE::DEVICE_0044: return "RocketPort INFINITY 4-port w/Quad Cable DB";
        case PciDevice11FE::DEVICE_0045: return "RocketPort INFINITY 8-port w/Octa Cable DB";
        case PciDevice11FE::DEVICE_0046: return "RocketPort INFINITY 4-port w/external I/F";
        case PciDevice11FE::DEVICE_0047: return "RocketPort INFINITY 4J (4-port) w/RJ45 connectors";
        case PciDevice11FE::DEVICE_0048: return "RocketPort INFINITY 4J (4-port) w/RJ45 connectors";
        case PciDevice11FE::DEVICE_004A: return "RocketPort INFINITY Plus 4-port";
        case PciDevice11FE::DEVICE_004B: return "RocketPort INFINITY Plus 8-port";
        case PciDevice11FE::DEVICE_004C: return "RocketModem INFINITY III 8-port";
        case PciDevice11FE::DEVICE_004D: return "RocketModem INFINITY III 4-port";
        case PciDevice11FE::DEVICE_004E: return "RocketPort INFINITY Plus 2-port";
        case PciDevice11FE::DEVICE_004F: return "RocketPort INFINITY 2-port SMPTE w/DB9 connectors";
        case PciDevice11FE::DEVICE_0050: return "RocketPort INFINITY Plus 4-port RJ45";
        case PciDevice11FE::DEVICE_0051: return "RocketPort INFINITY Plus 8-port RJ11";
        case PciDevice11FE::DEVICE_0052: return "RocketPort INFINITY 8-port SMPTE w/DB9 Connectors";
        case PciDevice11FE::DEVICE_0060: return "RocketPort EXPRESS 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_0061: return "RocketPort EXPRESS 32-port w/external I/F";
        case PciDevice11FE::DEVICE_0062: return "RocketPort EXPRESS 8-Port w/external I/F";
        case PciDevice11FE::DEVICE_0063: return "RocketPort EXPRESS 16-port w/external I/F";
        case PciDevice11FE::DEVICE_0064: return "RocketPort EXPRESS 4-port w/Quad Cable";
        case PciDevice11FE::DEVICE_0065: return "RocketPort EXPRESS 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_0066: return "RocketPort EXPRESS 4-port w/external I/F";
        case PciDevice11FE::DEVICE_0067: return "RocketPort EXPRESS 4J (4-port) w/RJ45 connectors";
        case PciDevice11FE::DEVICE_0068: return "RocketPort EXPRESS 8J (8-port) w/RJ11 connectors";
        case PciDevice11FE::DEVICE_006F: return "RocketPort EXPRESS SMPTE 2-port";
        case PciDevice11FE::DEVICE_0072: return "RocketPort EXPRESS SMPTE 8-port w/external I/F";
        case PciDevice11FE::DEVICE_0801: return "RocketPort uPCI 32-port w/external I/F";
        case PciDevice11FE::DEVICE_0802: return "RocketPort uPCI 8-port w/external I/F";
        case PciDevice11FE::DEVICE_0803: return "RocketPort uPCI 16-port w/external I/F";
        case PciDevice11FE::DEVICE_0805: return "RocketPort uPCI 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_080B: return "RocketPort Plus uPCI 8-port w/Octa Cable";
        case PciDevice11FE::DEVICE_080C: return "RocketModem III 8-port";
        case PciDevice11FE::DEVICE_080D: return "RocketModem III 4-port";
        case PciDevice11FE::DEVICE_080E: return "RocketPort uPCI 2-port RS232 w/DB9 connectors";
        case PciDevice11FE::DEVICE_080F: return "RocketPort uPCI SMPTE 2-port";
        case PciDevice11FE::DEVICE_0810: return "RocketPort Plus uPCI 4J (4-port) w/RJ45 connectors";
        case PciDevice11FE::DEVICE_0811: return "RocketPort Plus uPCI 8J (8-port) w/RJ11 connectors";
        case PciDevice11FE::DEVICE_0812: return "RocketPort Plus uPCI 422 8-port";
        case PciDevice11FE::DEVICE_0813: return "RocketModem IV uPCI 8-port";
        case PciDevice11FE::DEVICE_0814: return "RocketModem IV uPCI 4-port";
        case PciDevice11FE::DEVICE_0903: return "RocketPort Compact PCI 16 port w/external I/F";
        case PciDevice11FE::DEVICE_8015: return "RocketPort 550 4-port";
        case PciDevice11FE::DEVICE_8805: return "RocketPort uPCI 4-port w/Quad Cable";
        case PciDevice11FE::DEVICE_880B: return "RocketPort Plus uPCI 4-port w/Quad Cable";
        case PciDevice11FE::DEVICE_8812: return "RocketPort Plus uPCI 4-port RS422 w/Quad Cable";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FE_PCIDEVICE11FE_H
