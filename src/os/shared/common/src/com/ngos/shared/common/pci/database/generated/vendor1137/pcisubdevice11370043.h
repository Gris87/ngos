// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370043_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370043_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11370043: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370047 = 0x11370047,
    SUBDEVICE_11370048 = 0x11370048,
    SUBDEVICE_1137004F = 0x1137004F,
    SUBDEVICE_11370084 = 0x11370084,
    SUBDEVICE_11370085 = 0x11370085,
    SUBDEVICE_113700CD = 0x113700CD,
    SUBDEVICE_113700CE = 0x113700CE,
    SUBDEVICE_1137012A = 0x1137012A,
    SUBDEVICE_1137012C = 0x1137012C,
    SUBDEVICE_1137012E = 0x1137012E,
    SUBDEVICE_11370137 = 0x11370137,
    SUBDEVICE_1137014D = 0x1137014D,
    SUBDEVICE_1137015D = 0x1137015D,
    SUBDEVICE_11370215 = 0x11370215,
    SUBDEVICE_11370216 = 0x11370216,
    SUBDEVICE_11370217 = 0x11370217,
    SUBDEVICE_11370218 = 0x11370218,
    SUBDEVICE_11370219 = 0x11370219,
    SUBDEVICE_1137021A = 0x1137021A,
    SUBDEVICE_1137024A = 0x1137024A,
    SUBDEVICE_1137024B = 0x1137024B
};



inline const char8* enumToString(PciSubDevice11370043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370043::NONE:               return "NONE";
        case PciSubDevice11370043::SUBDEVICE_11370047: return "SUBDEVICE_11370047";
        case PciSubDevice11370043::SUBDEVICE_11370048: return "SUBDEVICE_11370048";
        case PciSubDevice11370043::SUBDEVICE_1137004F: return "SUBDEVICE_1137004F";
        case PciSubDevice11370043::SUBDEVICE_11370084: return "SUBDEVICE_11370084";
        case PciSubDevice11370043::SUBDEVICE_11370085: return "SUBDEVICE_11370085";
        case PciSubDevice11370043::SUBDEVICE_113700CD: return "SUBDEVICE_113700CD";
        case PciSubDevice11370043::SUBDEVICE_113700CE: return "SUBDEVICE_113700CE";
        case PciSubDevice11370043::SUBDEVICE_1137012A: return "SUBDEVICE_1137012A";
        case PciSubDevice11370043::SUBDEVICE_1137012C: return "SUBDEVICE_1137012C";
        case PciSubDevice11370043::SUBDEVICE_1137012E: return "SUBDEVICE_1137012E";
        case PciSubDevice11370043::SUBDEVICE_11370137: return "SUBDEVICE_11370137";
        case PciSubDevice11370043::SUBDEVICE_1137014D: return "SUBDEVICE_1137014D";
        case PciSubDevice11370043::SUBDEVICE_1137015D: return "SUBDEVICE_1137015D";
        case PciSubDevice11370043::SUBDEVICE_11370215: return "SUBDEVICE_11370215";
        case PciSubDevice11370043::SUBDEVICE_11370216: return "SUBDEVICE_11370216";
        case PciSubDevice11370043::SUBDEVICE_11370217: return "SUBDEVICE_11370217";
        case PciSubDevice11370043::SUBDEVICE_11370218: return "SUBDEVICE_11370218";
        case PciSubDevice11370043::SUBDEVICE_11370219: return "SUBDEVICE_11370219";
        case PciSubDevice11370043::SUBDEVICE_1137021A: return "SUBDEVICE_1137021A";
        case PciSubDevice11370043::SUBDEVICE_1137024A: return "SUBDEVICE_1137024A";
        case PciSubDevice11370043::SUBDEVICE_1137024B: return "SUBDEVICE_1137024B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11370043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11370043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370043::SUBDEVICE_11370047: return "VIC P81E PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370048: return "VIC M81KR Mezzanine Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137004F: return "VIC 1280 Mezzanine Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370084: return "VIC 1240 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370085: return "VIC 1225 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_113700CD: return "VIC 1285 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_113700CE: return "VIC 1225T PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137012A: return "VIC M4308 Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137012C: return "VIC 1340 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137012E: return "VIC 1227 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370137: return "VIC 1380 Mezzanine Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137014D: return "VIC 1385 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137015D: return "VIC 1387 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370215: return "VIC 1440 Mezzanine Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370216: return "VIC 1480 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370217: return "VIC 1455 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370218: return "VIC 1457 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_11370219: return "VIC 1485 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137021A: return "VIC 1487 MLOM Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137024A: return "VIC 1495 PCIe Ethernet NIC";
        case PciSubDevice11370043::SUBDEVICE_1137024B: return "VIC 1497 MLOM Ethernet NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370043_H
