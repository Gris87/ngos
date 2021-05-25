// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCIDEVICE177D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCIDEVICE177D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcisubdevice177d9702.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcisubdevice177d9712.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcisubdevice177da002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcisubdevice177da008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor177d/pcisubdevice177da01c.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice177D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030,
    DEVICE_0040 = 0x0040,
    DEVICE_0050 = 0x0050,
    DEVICE_0070 = 0x0070,
    DEVICE_0080 = 0x0080,
    DEVICE_0090 = 0x0090,
    DEVICE_0091 = 0x0091,
    DEVICE_0092 = 0x0092,
    DEVICE_0093 = 0x0093,
    DEVICE_0094 = 0x0094,
    DEVICE_0095 = 0x0095,
    DEVICE_0096 = 0x0096,
    DEVICE_9700 = 0x9700,
    DEVICE_9702 = 0x9702,
    DEVICE_9703 = 0x9703,
    DEVICE_9712 = 0x9712,
    DEVICE_9713 = 0x9713,
    DEVICE_9800 = 0x9800,
    DEVICE_A001 = 0xA001,
    DEVICE_A002 = 0xA002,
    DEVICE_A008 = 0xA008,
    DEVICE_A009 = 0xA009,
    DEVICE_A00A = 0xA00A,
    DEVICE_A00B = 0xA00B,
    DEVICE_A00C = 0xA00C,
    DEVICE_A00D = 0xA00D,
    DEVICE_A00E = 0xA00E,
    DEVICE_A00F = 0xA00F,
    DEVICE_A010 = 0xA010,
    DEVICE_A011 = 0xA011,
    DEVICE_A012 = 0xA012,
    DEVICE_A013 = 0xA013,
    DEVICE_A014 = 0xA014,
    DEVICE_A015 = 0xA015,
    DEVICE_A016 = 0xA016,
    DEVICE_A017 = 0xA017,
    DEVICE_A018 = 0xA018,
    DEVICE_A019 = 0xA019,
    DEVICE_A01A = 0xA01A,
    DEVICE_A01B = 0xA01B,
    DEVICE_A01C = 0xA01C,
    DEVICE_A01D = 0xA01D,
    DEVICE_A01E = 0xA01E,
    DEVICE_A01F = 0xA01F,
    DEVICE_A020 = 0xA020,
    DEVICE_A021 = 0xA021,
    DEVICE_A022 = 0xA022,
    DEVICE_A023 = 0xA023,
    DEVICE_A024 = 0xA024,
    DEVICE_A025 = 0xA025,
    DEVICE_A026 = 0xA026,
    DEVICE_A027 = 0xA027,
    DEVICE_A029 = 0xA029,
    DEVICE_A02A = 0xA02A,
    DEVICE_A02B = 0xA02B,
    DEVICE_A02C = 0xA02C,
    DEVICE_A02D = 0xA02D,
    DEVICE_A02E = 0xA02E,
    DEVICE_A02F = 0xA02F,
    DEVICE_A030 = 0xA030,
    DEVICE_A031 = 0xA031,
    DEVICE_A032 = 0xA032,
    DEVICE_A033 = 0xA033,
    DEVICE_A034 = 0xA034,
    DEVICE_A035 = 0xA035,
    DEVICE_A036 = 0xA036,
    DEVICE_A037 = 0xA037,
    DEVICE_A040 = 0xA040,
    DEVICE_A100 = 0xA100,
    DEVICE_A200 = 0xA200,
    DEVICE_A300 = 0xA300,
    DEVICE_AF00 = 0xAF00,
    DEVICE_AF84 = 0xAF84
};



inline const char8* enumToString(PciDevice177D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice177D::NONE:        return "NONE";
        case PciDevice177D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice177D::DEVICE_0003: return "DEVICE_0003";
        case PciDevice177D::DEVICE_0004: return "DEVICE_0004";
        case PciDevice177D::DEVICE_0005: return "DEVICE_0005";
        case PciDevice177D::DEVICE_0006: return "DEVICE_0006";
        case PciDevice177D::DEVICE_0010: return "DEVICE_0010";
        case PciDevice177D::DEVICE_0011: return "DEVICE_0011";
        case PciDevice177D::DEVICE_0012: return "DEVICE_0012";
        case PciDevice177D::DEVICE_0020: return "DEVICE_0020";
        case PciDevice177D::DEVICE_0030: return "DEVICE_0030";
        case PciDevice177D::DEVICE_0040: return "DEVICE_0040";
        case PciDevice177D::DEVICE_0050: return "DEVICE_0050";
        case PciDevice177D::DEVICE_0070: return "DEVICE_0070";
        case PciDevice177D::DEVICE_0080: return "DEVICE_0080";
        case PciDevice177D::DEVICE_0090: return "DEVICE_0090";
        case PciDevice177D::DEVICE_0091: return "DEVICE_0091";
        case PciDevice177D::DEVICE_0092: return "DEVICE_0092";
        case PciDevice177D::DEVICE_0093: return "DEVICE_0093";
        case PciDevice177D::DEVICE_0094: return "DEVICE_0094";
        case PciDevice177D::DEVICE_0095: return "DEVICE_0095";
        case PciDevice177D::DEVICE_0096: return "DEVICE_0096";
        case PciDevice177D::DEVICE_9700: return "DEVICE_9700";
        case PciDevice177D::DEVICE_9702: return "DEVICE_9702";
        case PciDevice177D::DEVICE_9703: return "DEVICE_9703";
        case PciDevice177D::DEVICE_9712: return "DEVICE_9712";
        case PciDevice177D::DEVICE_9713: return "DEVICE_9713";
        case PciDevice177D::DEVICE_9800: return "DEVICE_9800";
        case PciDevice177D::DEVICE_A001: return "DEVICE_A001";
        case PciDevice177D::DEVICE_A002: return "DEVICE_A002";
        case PciDevice177D::DEVICE_A008: return "DEVICE_A008";
        case PciDevice177D::DEVICE_A009: return "DEVICE_A009";
        case PciDevice177D::DEVICE_A00A: return "DEVICE_A00A";
        case PciDevice177D::DEVICE_A00B: return "DEVICE_A00B";
        case PciDevice177D::DEVICE_A00C: return "DEVICE_A00C";
        case PciDevice177D::DEVICE_A00D: return "DEVICE_A00D";
        case PciDevice177D::DEVICE_A00E: return "DEVICE_A00E";
        case PciDevice177D::DEVICE_A00F: return "DEVICE_A00F";
        case PciDevice177D::DEVICE_A010: return "DEVICE_A010";
        case PciDevice177D::DEVICE_A011: return "DEVICE_A011";
        case PciDevice177D::DEVICE_A012: return "DEVICE_A012";
        case PciDevice177D::DEVICE_A013: return "DEVICE_A013";
        case PciDevice177D::DEVICE_A014: return "DEVICE_A014";
        case PciDevice177D::DEVICE_A015: return "DEVICE_A015";
        case PciDevice177D::DEVICE_A016: return "DEVICE_A016";
        case PciDevice177D::DEVICE_A017: return "DEVICE_A017";
        case PciDevice177D::DEVICE_A018: return "DEVICE_A018";
        case PciDevice177D::DEVICE_A019: return "DEVICE_A019";
        case PciDevice177D::DEVICE_A01A: return "DEVICE_A01A";
        case PciDevice177D::DEVICE_A01B: return "DEVICE_A01B";
        case PciDevice177D::DEVICE_A01C: return "DEVICE_A01C";
        case PciDevice177D::DEVICE_A01D: return "DEVICE_A01D";
        case PciDevice177D::DEVICE_A01E: return "DEVICE_A01E";
        case PciDevice177D::DEVICE_A01F: return "DEVICE_A01F";
        case PciDevice177D::DEVICE_A020: return "DEVICE_A020";
        case PciDevice177D::DEVICE_A021: return "DEVICE_A021";
        case PciDevice177D::DEVICE_A022: return "DEVICE_A022";
        case PciDevice177D::DEVICE_A023: return "DEVICE_A023";
        case PciDevice177D::DEVICE_A024: return "DEVICE_A024";
        case PciDevice177D::DEVICE_A025: return "DEVICE_A025";
        case PciDevice177D::DEVICE_A026: return "DEVICE_A026";
        case PciDevice177D::DEVICE_A027: return "DEVICE_A027";
        case PciDevice177D::DEVICE_A029: return "DEVICE_A029";
        case PciDevice177D::DEVICE_A02A: return "DEVICE_A02A";
        case PciDevice177D::DEVICE_A02B: return "DEVICE_A02B";
        case PciDevice177D::DEVICE_A02C: return "DEVICE_A02C";
        case PciDevice177D::DEVICE_A02D: return "DEVICE_A02D";
        case PciDevice177D::DEVICE_A02E: return "DEVICE_A02E";
        case PciDevice177D::DEVICE_A02F: return "DEVICE_A02F";
        case PciDevice177D::DEVICE_A030: return "DEVICE_A030";
        case PciDevice177D::DEVICE_A031: return "DEVICE_A031";
        case PciDevice177D::DEVICE_A032: return "DEVICE_A032";
        case PciDevice177D::DEVICE_A033: return "DEVICE_A033";
        case PciDevice177D::DEVICE_A034: return "DEVICE_A034";
        case PciDevice177D::DEVICE_A035: return "DEVICE_A035";
        case PciDevice177D::DEVICE_A036: return "DEVICE_A036";
        case PciDevice177D::DEVICE_A037: return "DEVICE_A037";
        case PciDevice177D::DEVICE_A040: return "DEVICE_A040";
        case PciDevice177D::DEVICE_A100: return "DEVICE_A100";
        case PciDevice177D::DEVICE_A200: return "DEVICE_A200";
        case PciDevice177D::DEVICE_A300: return "DEVICE_A300";
        case PciDevice177D::DEVICE_AF00: return "DEVICE_AF00";
        case PciDevice177D::DEVICE_AF84: return "DEVICE_AF84";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice177D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice177D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice177D::DEVICE_0001: return "Nitrox XL N1";
        case PciDevice177D::DEVICE_0003: return "Nitrox XL N1 Lite";
        case PciDevice177D::DEVICE_0004: return "Octeon (and older) FIPS";
        case PciDevice177D::DEVICE_0005: return "Octeon CN38XX Network Processor Pass 3.x";
        case PciDevice177D::DEVICE_0006: return "RoHS";
        case PciDevice177D::DEVICE_0010: return "CN15XX/CN16XX [Nitrox PX]";
        case PciDevice177D::DEVICE_0011: return "CNN35XX [Nitrox III]";
        case PciDevice177D::DEVICE_0012: return "CNN55XX [Nitrox V]";
        case PciDevice177D::DEVICE_0020: return "Octeon CN31XX Network Processor";
        case PciDevice177D::DEVICE_0030: return "Octeon CN30XX Network Processor";
        case PciDevice177D::DEVICE_0040: return "Octeon CN58XX Network Processor";
        case PciDevice177D::DEVICE_0050: return "Octeon CN57XX Network Processor (CN54XX/CN55XX/CN56XX)";
        case PciDevice177D::DEVICE_0070: return "Octeon CN50XX Network Processor";
        case PciDevice177D::DEVICE_0080: return "Octeon CN52XX Network Processor";
        case PciDevice177D::DEVICE_0090: return "Octeon II CN63XX Network Processor";
        case PciDevice177D::DEVICE_0091: return "Octeon II CN68XX Network Processor";
        case PciDevice177D::DEVICE_0092: return "Octeon II CN65XX Network Processor";
        case PciDevice177D::DEVICE_0093: return "Octeon II CN61XX Network Processor";
        case PciDevice177D::DEVICE_0094: return "Octeon Fusion CNF71XX Cell processor";
        case PciDevice177D::DEVICE_0095: return "Octeon III CN78XX Network Processor";
        case PciDevice177D::DEVICE_0096: return "Octeon III CN70XX Network Processor";
        case PciDevice177D::DEVICE_9700: return "Octeon III CN73XX Network Processor";
        case PciDevice177D::DEVICE_9702: return "CN23XX [LiquidIO II] Intelligent Adapter";
        case PciDevice177D::DEVICE_9703: return "CN23XX [LiquidIO II] NVMe Controller";
        case PciDevice177D::DEVICE_9712: return "CN23XX [LiquidIO II] SRIOV Virtual Function";
        case PciDevice177D::DEVICE_9713: return "CN23XX [LiquidIO II] NVMe SRIOV Virtual Function";
        case PciDevice177D::DEVICE_9800: return "Octeon Fusion CNF75XX Processor";
        case PciDevice177D::DEVICE_A001: return "ThunderX MRML(Master RML Bridge to RSL devices)";
        case PciDevice177D::DEVICE_A002: return "THUNDERX PCC Bridge";
        case PciDevice177D::DEVICE_A008: return "THUNDERX SMMU";
        case PciDevice177D::DEVICE_A009: return "THUNDERX Generic Interrupt Controller";
        case PciDevice177D::DEVICE_A00A: return "THUNDERX GPIO Controller";
        case PciDevice177D::DEVICE_A00B: return "THUNDERX MPI / SPI Controller";
        case PciDevice177D::DEVICE_A00C: return "THUNDERX MIO-PTP Controller";
        case PciDevice177D::DEVICE_A00D: return "THUNDERX MIX Network Controller";
        case PciDevice177D::DEVICE_A00E: return "THUNDERX Reset Controller";
        case PciDevice177D::DEVICE_A00F: return "THUNDERX UART Controller";
        case PciDevice177D::DEVICE_A010: return "THUNDERX eMMC/SD Controller";
        case PciDevice177D::DEVICE_A011: return "THUNDERX MIO-BOOT Controller";
        case PciDevice177D::DEVICE_A012: return "THUNDERX TWSI / I2C Controller";
        case PciDevice177D::DEVICE_A013: return "THUNDERX CCPI (Multi-node connect)";
        case PciDevice177D::DEVICE_A014: return "THUNDERX Voltage Regulator Module";
        case PciDevice177D::DEVICE_A015: return "THUNDERX PCIe Switch Logic Interface";
        case PciDevice177D::DEVICE_A016: return "THUNDERX Key Memory";
        case PciDevice177D::DEVICE_A017: return "THUNDERX GTI (Global System Timers)";
        case PciDevice177D::DEVICE_A018: return "THUNDERX Random Number Generator";
        case PciDevice177D::DEVICE_A019: return "THUNDERX DFA";
        case PciDevice177D::DEVICE_A01A: return "THUNDERX Zip Coprocessor";
        case PciDevice177D::DEVICE_A01B: return "THUNDERX xHCI USB Controller";
        case PciDevice177D::DEVICE_A01C: return "THUNDERX AHCI SATA Controller";
        case PciDevice177D::DEVICE_A01D: return "THUNDERX RAID Coprocessor";
        case PciDevice177D::DEVICE_A01E: return "THUNDERX Network Interface Controller";
        case PciDevice177D::DEVICE_A01F: return "THUNDERX Traffic Network Switch";
        case PciDevice177D::DEVICE_A020: return "THUNDERX PEM (PCI Express Interface)";
        case PciDevice177D::DEVICE_A021: return "THUNDERX L2C (Level-2 Cache Controller)";
        case PciDevice177D::DEVICE_A022: return "THUNDERX LMC (DRAM Controller)";
        case PciDevice177D::DEVICE_A023: return "THUNDERX OCLA (On-Chip Logic Analyzer)";
        case PciDevice177D::DEVICE_A024: return "THUNDERX OSM";
        case PciDevice177D::DEVICE_A025: return "THUNDERX GSER (General Serializer/Deserializer)";
        case PciDevice177D::DEVICE_A026: return "THUNDERX BGX (Common Ethernet Interface)";
        case PciDevice177D::DEVICE_A027: return "THUNDERX IOBN";
        case PciDevice177D::DEVICE_A029: return "THUNDERX NCSI (Network Controller Sideband Interface)";
        case PciDevice177D::DEVICE_A02A: return "ThunderX SGPIO (Serial GPIO controller for SATA disk lights)";
        case PciDevice177D::DEVICE_A02B: return "THUNDERX SMI / MDIO Controller";
        case PciDevice177D::DEVICE_A02C: return "THUNDERX DAP (Debug Access Port)";
        case PciDevice177D::DEVICE_A02D: return "THUNDERX PCIERC (PCIe Root Complex)";
        case PciDevice177D::DEVICE_A02E: return "ThunderX L2C-TAD (Level 2 cache tag and data)";
        case PciDevice177D::DEVICE_A02F: return "THUNDERX L2C-CBC";
        case PciDevice177D::DEVICE_A030: return "THUNDERX L2C-MCI";
        case PciDevice177D::DEVICE_A031: return "THUNDERX MIO-FUS (Fuse Access Controller)";
        case PciDevice177D::DEVICE_A032: return "THUNDERX FUSF (Fuse Controller)";
        case PciDevice177D::DEVICE_A033: return "THUNDERX Random Number Generator virtual function";
        case PciDevice177D::DEVICE_A034: return "THUNDERX Network Interface Controller virtual function";
        case PciDevice177D::DEVICE_A035: return "THUNDERX Parallel Bus";
        case PciDevice177D::DEVICE_A036: return "ThunderX RAD (RAID acceleration engine) virtual function";
        case PciDevice177D::DEVICE_A037: return "THUNDERX ZIP virtual function";
        case PciDevice177D::DEVICE_A040: return "THUNDERX CPT Cryptographic Accelerator";
        case PciDevice177D::DEVICE_A100: return "THUNDERX CN88XX 48 core SoC";
        case PciDevice177D::DEVICE_A200: return "OCTEON TX CN81XX/CN80XX";
        case PciDevice177D::DEVICE_A300: return "OCTEON TX CN83XX";
        case PciDevice177D::DEVICE_AF00: return "CN99xx [ThunderX2] Integrated PCI Host bridge";
        case PciDevice177D::DEVICE_AF84: return "CN99xx [ThunderX2] Integrated PCI Express RP Bridge";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice177D device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice177D::DEVICE_0001: return "Unknown device";
        case PciDevice177D::DEVICE_0003: return "Unknown device";
        case PciDevice177D::DEVICE_0004: return "Unknown device";
        case PciDevice177D::DEVICE_0005: return "Unknown device";
        case PciDevice177D::DEVICE_0006: return "Unknown device";
        case PciDevice177D::DEVICE_0010: return "Unknown device";
        case PciDevice177D::DEVICE_0011: return "Unknown device";
        case PciDevice177D::DEVICE_0012: return "Unknown device";
        case PciDevice177D::DEVICE_0020: return "Unknown device";
        case PciDevice177D::DEVICE_0030: return "Unknown device";
        case PciDevice177D::DEVICE_0040: return "Unknown device";
        case PciDevice177D::DEVICE_0050: return "Unknown device";
        case PciDevice177D::DEVICE_0070: return "Unknown device";
        case PciDevice177D::DEVICE_0080: return "Unknown device";
        case PciDevice177D::DEVICE_0090: return "Unknown device";
        case PciDevice177D::DEVICE_0091: return "Unknown device";
        case PciDevice177D::DEVICE_0092: return "Unknown device";
        case PciDevice177D::DEVICE_0093: return "Unknown device";
        case PciDevice177D::DEVICE_0094: return "Unknown device";
        case PciDevice177D::DEVICE_0095: return "Unknown device";
        case PciDevice177D::DEVICE_0096: return "Unknown device";
        case PciDevice177D::DEVICE_9700: return "Unknown device";
        case PciDevice177D::DEVICE_9702: return enumToHumanString((PciSubDevice177D9702)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice177D::DEVICE_9703: return "Unknown device";
        case PciDevice177D::DEVICE_9712: return enumToHumanString((PciSubDevice177D9712)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice177D::DEVICE_9713: return "Unknown device";
        case PciDevice177D::DEVICE_9800: return "Unknown device";
        case PciDevice177D::DEVICE_A001: return "Unknown device";
        case PciDevice177D::DEVICE_A002: return enumToHumanString((PciSubDevice177DA002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice177D::DEVICE_A008: return enumToHumanString((PciSubDevice177DA008)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice177D::DEVICE_A009: return "Unknown device";
        case PciDevice177D::DEVICE_A00A: return "Unknown device";
        case PciDevice177D::DEVICE_A00B: return "Unknown device";
        case PciDevice177D::DEVICE_A00C: return "Unknown device";
        case PciDevice177D::DEVICE_A00D: return "Unknown device";
        case PciDevice177D::DEVICE_A00E: return "Unknown device";
        case PciDevice177D::DEVICE_A00F: return "Unknown device";
        case PciDevice177D::DEVICE_A010: return "Unknown device";
        case PciDevice177D::DEVICE_A011: return "Unknown device";
        case PciDevice177D::DEVICE_A012: return "Unknown device";
        case PciDevice177D::DEVICE_A013: return "Unknown device";
        case PciDevice177D::DEVICE_A014: return "Unknown device";
        case PciDevice177D::DEVICE_A015: return "Unknown device";
        case PciDevice177D::DEVICE_A016: return "Unknown device";
        case PciDevice177D::DEVICE_A017: return "Unknown device";
        case PciDevice177D::DEVICE_A018: return "Unknown device";
        case PciDevice177D::DEVICE_A019: return "Unknown device";
        case PciDevice177D::DEVICE_A01A: return "Unknown device";
        case PciDevice177D::DEVICE_A01B: return "Unknown device";
        case PciDevice177D::DEVICE_A01C: return enumToHumanString((PciSubDevice177DA01C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice177D::DEVICE_A01D: return "Unknown device";
        case PciDevice177D::DEVICE_A01E: return "Unknown device";
        case PciDevice177D::DEVICE_A01F: return "Unknown device";
        case PciDevice177D::DEVICE_A020: return "Unknown device";
        case PciDevice177D::DEVICE_A021: return "Unknown device";
        case PciDevice177D::DEVICE_A022: return "Unknown device";
        case PciDevice177D::DEVICE_A023: return "Unknown device";
        case PciDevice177D::DEVICE_A024: return "Unknown device";
        case PciDevice177D::DEVICE_A025: return "Unknown device";
        case PciDevice177D::DEVICE_A026: return "Unknown device";
        case PciDevice177D::DEVICE_A027: return "Unknown device";
        case PciDevice177D::DEVICE_A029: return "Unknown device";
        case PciDevice177D::DEVICE_A02A: return "Unknown device";
        case PciDevice177D::DEVICE_A02B: return "Unknown device";
        case PciDevice177D::DEVICE_A02C: return "Unknown device";
        case PciDevice177D::DEVICE_A02D: return "Unknown device";
        case PciDevice177D::DEVICE_A02E: return "Unknown device";
        case PciDevice177D::DEVICE_A02F: return "Unknown device";
        case PciDevice177D::DEVICE_A030: return "Unknown device";
        case PciDevice177D::DEVICE_A031: return "Unknown device";
        case PciDevice177D::DEVICE_A032: return "Unknown device";
        case PciDevice177D::DEVICE_A033: return "Unknown device";
        case PciDevice177D::DEVICE_A034: return "Unknown device";
        case PciDevice177D::DEVICE_A035: return "Unknown device";
        case PciDevice177D::DEVICE_A036: return "Unknown device";
        case PciDevice177D::DEVICE_A037: return "Unknown device";
        case PciDevice177D::DEVICE_A040: return "Unknown device";
        case PciDevice177D::DEVICE_A100: return "Unknown device";
        case PciDevice177D::DEVICE_A200: return "Unknown device";
        case PciDevice177D::DEVICE_A300: return "Unknown device";
        case PciDevice177D::DEVICE_AF00: return "Unknown device";
        case PciDevice177D::DEVICE_AF84: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCIDEVICE177D_H
