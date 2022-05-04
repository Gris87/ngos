// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCIDEVICE1014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCIDEVICE1014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014002e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140031.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014003e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140090.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140096.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice101400b7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140142.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140144.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140170.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140180.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice101401bd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice101401ef.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140219.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014028c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice101402bd.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014032d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice10140339.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014033d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice1014034a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1014/pcisubdevice101404da.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1014: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0005 = 0x0005,
    DEVICE_0007 = 0x0007,
    DEVICE_000A = 0x000A,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D,
    DEVICE_0020 = 0x0020,
    DEVICE_0022 = 0x0022,
    DEVICE_002D = 0x002D,
    DEVICE_002E = 0x002E,
    DEVICE_0031 = 0x0031,
    DEVICE_0036 = 0x0036,
    DEVICE_0037 = 0x0037,
    DEVICE_003A = 0x003A,
    DEVICE_003C = 0x003C,
    DEVICE_003E = 0x003E,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_0047 = 0x0047,
    DEVICE_0048 = 0x0048,
    DEVICE_0049 = 0x0049,
    DEVICE_004E = 0x004E,
    DEVICE_004F = 0x004F,
    DEVICE_0050 = 0x0050,
    DEVICE_0053 = 0x0053,
    DEVICE_0054 = 0x0054,
    DEVICE_0057 = 0x0057,
    DEVICE_0058 = 0x0058,
    DEVICE_005E = 0x005E,
    DEVICE_007C = 0x007C,
    DEVICE_007D = 0x007D,
    DEVICE_008B = 0x008B,
    DEVICE_008E = 0x008E,
    DEVICE_0090 = 0x0090,
    DEVICE_0091 = 0x0091,
    DEVICE_0095 = 0x0095,
    DEVICE_0096 = 0x0096,
    DEVICE_009F = 0x009F,
    DEVICE_00A5 = 0x00A5,
    DEVICE_00A6 = 0x00A6,
    DEVICE_00B7 = 0x00B7,
    DEVICE_00B8 = 0x00B8,
    DEVICE_00BE = 0x00BE,
    DEVICE_00DC = 0x00DC,
    DEVICE_00FC = 0x00FC,
    DEVICE_0105 = 0x0105,
    DEVICE_010F = 0x010F,
    DEVICE_0142 = 0x0142,
    DEVICE_0144 = 0x0144,
    DEVICE_0156 = 0x0156,
    DEVICE_015E = 0x015E,
    DEVICE_0160 = 0x0160,
    DEVICE_016E = 0x016E,
    DEVICE_0170 = 0x0170,
    DEVICE_017D = 0x017D,
    DEVICE_0180 = 0x0180,
    DEVICE_0188 = 0x0188,
    DEVICE_01A7 = 0x01A7,
    DEVICE_01BD = 0x01BD,
    DEVICE_01C1 = 0x01C1,
    DEVICE_01E6 = 0x01E6,
    DEVICE_01EF = 0x01EF,
    DEVICE_01FF = 0x01FF,
    DEVICE_0219 = 0x0219,
    DEVICE_021B = 0x021B,
    DEVICE_021C = 0x021C,
    DEVICE_0233 = 0x0233,
    DEVICE_025A = 0x025A,
    DEVICE_028C = 0x028C,
    DEVICE_02A1 = 0x02A1,
    DEVICE_02BD = 0x02BD,
    DEVICE_0302 = 0x0302,
    DEVICE_0308 = 0x0308,
    DEVICE_0311 = 0x0311,
    DEVICE_0314 = 0x0314,
    DEVICE_032D = 0x032D,
    DEVICE_0339 = 0x0339,
    DEVICE_033D = 0x033D,
    DEVICE_034A = 0x034A,
    DEVICE_03DC = 0x03DC,
    DEVICE_044B = 0x044B,
    DEVICE_04AA = 0x04AA,
    DEVICE_04C1 = 0x04C1,
    DEVICE_04DA = 0x04DA,
    DEVICE_04ED = 0x04ED,
    DEVICE_3022 = 0x3022,
    DEVICE_4022 = 0x4022,
    DEVICE_FFFF = 0xFFFF
};



inline const char8* enumToString(PciDevice1014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1014::NONE:        return "NONE";
        case PciDevice1014::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1014::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1014::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1014::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1014::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1014::DEVICE_0018: return "DEVICE_0018";
        case PciDevice1014::DEVICE_001B: return "DEVICE_001B";
        case PciDevice1014::DEVICE_001C: return "DEVICE_001C";
        case PciDevice1014::DEVICE_001D: return "DEVICE_001D";
        case PciDevice1014::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1014::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1014::DEVICE_002D: return "DEVICE_002D";
        case PciDevice1014::DEVICE_002E: return "DEVICE_002E";
        case PciDevice1014::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1014::DEVICE_0036: return "DEVICE_0036";
        case PciDevice1014::DEVICE_0037: return "DEVICE_0037";
        case PciDevice1014::DEVICE_003A: return "DEVICE_003A";
        case PciDevice1014::DEVICE_003C: return "DEVICE_003C";
        case PciDevice1014::DEVICE_003E: return "DEVICE_003E";
        case PciDevice1014::DEVICE_0045: return "DEVICE_0045";
        case PciDevice1014::DEVICE_0046: return "DEVICE_0046";
        case PciDevice1014::DEVICE_0047: return "DEVICE_0047";
        case PciDevice1014::DEVICE_0048: return "DEVICE_0048";
        case PciDevice1014::DEVICE_0049: return "DEVICE_0049";
        case PciDevice1014::DEVICE_004E: return "DEVICE_004E";
        case PciDevice1014::DEVICE_004F: return "DEVICE_004F";
        case PciDevice1014::DEVICE_0050: return "DEVICE_0050";
        case PciDevice1014::DEVICE_0053: return "DEVICE_0053";
        case PciDevice1014::DEVICE_0054: return "DEVICE_0054";
        case PciDevice1014::DEVICE_0057: return "DEVICE_0057";
        case PciDevice1014::DEVICE_0058: return "DEVICE_0058";
        case PciDevice1014::DEVICE_005E: return "DEVICE_005E";
        case PciDevice1014::DEVICE_007C: return "DEVICE_007C";
        case PciDevice1014::DEVICE_007D: return "DEVICE_007D";
        case PciDevice1014::DEVICE_008B: return "DEVICE_008B";
        case PciDevice1014::DEVICE_008E: return "DEVICE_008E";
        case PciDevice1014::DEVICE_0090: return "DEVICE_0090";
        case PciDevice1014::DEVICE_0091: return "DEVICE_0091";
        case PciDevice1014::DEVICE_0095: return "DEVICE_0095";
        case PciDevice1014::DEVICE_0096: return "DEVICE_0096";
        case PciDevice1014::DEVICE_009F: return "DEVICE_009F";
        case PciDevice1014::DEVICE_00A5: return "DEVICE_00A5";
        case PciDevice1014::DEVICE_00A6: return "DEVICE_00A6";
        case PciDevice1014::DEVICE_00B7: return "DEVICE_00B7";
        case PciDevice1014::DEVICE_00B8: return "DEVICE_00B8";
        case PciDevice1014::DEVICE_00BE: return "DEVICE_00BE";
        case PciDevice1014::DEVICE_00DC: return "DEVICE_00DC";
        case PciDevice1014::DEVICE_00FC: return "DEVICE_00FC";
        case PciDevice1014::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1014::DEVICE_010F: return "DEVICE_010F";
        case PciDevice1014::DEVICE_0142: return "DEVICE_0142";
        case PciDevice1014::DEVICE_0144: return "DEVICE_0144";
        case PciDevice1014::DEVICE_0156: return "DEVICE_0156";
        case PciDevice1014::DEVICE_015E: return "DEVICE_015E";
        case PciDevice1014::DEVICE_0160: return "DEVICE_0160";
        case PciDevice1014::DEVICE_016E: return "DEVICE_016E";
        case PciDevice1014::DEVICE_0170: return "DEVICE_0170";
        case PciDevice1014::DEVICE_017D: return "DEVICE_017D";
        case PciDevice1014::DEVICE_0180: return "DEVICE_0180";
        case PciDevice1014::DEVICE_0188: return "DEVICE_0188";
        case PciDevice1014::DEVICE_01A7: return "DEVICE_01A7";
        case PciDevice1014::DEVICE_01BD: return "DEVICE_01BD";
        case PciDevice1014::DEVICE_01C1: return "DEVICE_01C1";
        case PciDevice1014::DEVICE_01E6: return "DEVICE_01E6";
        case PciDevice1014::DEVICE_01EF: return "DEVICE_01EF";
        case PciDevice1014::DEVICE_01FF: return "DEVICE_01FF";
        case PciDevice1014::DEVICE_0219: return "DEVICE_0219";
        case PciDevice1014::DEVICE_021B: return "DEVICE_021B";
        case PciDevice1014::DEVICE_021C: return "DEVICE_021C";
        case PciDevice1014::DEVICE_0233: return "DEVICE_0233";
        case PciDevice1014::DEVICE_025A: return "DEVICE_025A";
        case PciDevice1014::DEVICE_028C: return "DEVICE_028C";
        case PciDevice1014::DEVICE_02A1: return "DEVICE_02A1";
        case PciDevice1014::DEVICE_02BD: return "DEVICE_02BD";
        case PciDevice1014::DEVICE_0302: return "DEVICE_0302";
        case PciDevice1014::DEVICE_0308: return "DEVICE_0308";
        case PciDevice1014::DEVICE_0311: return "DEVICE_0311";
        case PciDevice1014::DEVICE_0314: return "DEVICE_0314";
        case PciDevice1014::DEVICE_032D: return "DEVICE_032D";
        case PciDevice1014::DEVICE_0339: return "DEVICE_0339";
        case PciDevice1014::DEVICE_033D: return "DEVICE_033D";
        case PciDevice1014::DEVICE_034A: return "DEVICE_034A";
        case PciDevice1014::DEVICE_03DC: return "DEVICE_03DC";
        case PciDevice1014::DEVICE_044B: return "DEVICE_044B";
        case PciDevice1014::DEVICE_04AA: return "DEVICE_04AA";
        case PciDevice1014::DEVICE_04C1: return "DEVICE_04C1";
        case PciDevice1014::DEVICE_04DA: return "DEVICE_04DA";
        case PciDevice1014::DEVICE_04ED: return "DEVICE_04ED";
        case PciDevice1014::DEVICE_3022: return "DEVICE_3022";
        case PciDevice1014::DEVICE_4022: return "DEVICE_4022";
        case PciDevice1014::DEVICE_FFFF: return "DEVICE_FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1014::DEVICE_0002: return "PCI to MCA Bridge";
        case PciDevice1014::DEVICE_0005: return "Processor to I/O Controller [Alta Lite]";
        case PciDevice1014::DEVICE_0007: return "Processor to I/O Controller [Alta MP]";
        case PciDevice1014::DEVICE_000A: return "PCI to ISA Bridge (IBM27-82376) [Fire Coral]";
        case PciDevice1014::DEVICE_0017: return "CPU to PCI Bridge";
        case PciDevice1014::DEVICE_0018: return "TR Auto LANstreamer";
        case PciDevice1014::DEVICE_001B: return "GXT-150P";
        case PciDevice1014::DEVICE_001C: return "Carrera";
        case PciDevice1014::DEVICE_001D: return "SCSI-2 FAST PCI Adapter (82G2675)";
        case PciDevice1014::DEVICE_0020: return "GXT1000 Graphics Adapter";
        case PciDevice1014::DEVICE_0022: return "PCI to PCI Bridge (IBM27-82351)";
        case PciDevice1014::DEVICE_002D: return "Processor to I/O Controller [Python]";
        case PciDevice1014::DEVICE_002E: return "SCSI RAID Adapter [ServeRAID]";
        case PciDevice1014::DEVICE_0031: return "2 Port Serial Adapter";
        case PciDevice1014::DEVICE_0036: return "PCI to 32-bit LocalBus Bridge [Miami]";
        case PciDevice1014::DEVICE_0037: return "PowerPC to PCI Bridge (IBM27-82660)";
        case PciDevice1014::DEVICE_003A: return "CPU to PCI Bridge";
        case PciDevice1014::DEVICE_003C: return "GXT250P/GXT255P Graphics Adapter";
        case PciDevice1014::DEVICE_003E: return "16/4 Token ring UTP/STP controller";
        case PciDevice1014::DEVICE_0045: return "SSA Adapter";
        case PciDevice1014::DEVICE_0046: return "MPIC interrupt controller";
        case PciDevice1014::DEVICE_0047: return "PCI to PCI Bridge";
        case PciDevice1014::DEVICE_0048: return "PCI to PCI Bridge";
        case PciDevice1014::DEVICE_0049: return "Warhead SCSI Controller";
        case PciDevice1014::DEVICE_004E: return "ATM Controller (14104e00)";
        case PciDevice1014::DEVICE_004F: return "ATM Controller (14104f00)";
        case PciDevice1014::DEVICE_0050: return "ATM Controller (14105000)";
        case PciDevice1014::DEVICE_0053: return "25 MBit ATM Controller";
        case PciDevice1014::DEVICE_0054: return "GXT500P/GXT550P Graphics Adapter";
        case PciDevice1014::DEVICE_0057: return "MPEG PCI Bridge";
        case PciDevice1014::DEVICE_0058: return "SSA Adapter [Advanced SerialRAID/X]";
        case PciDevice1014::DEVICE_005E: return "GXT800P Graphics Adapter";
        case PciDevice1014::DEVICE_007C: return "ATM Controller (14107c00)";
        case PciDevice1014::DEVICE_007D: return "3780IDSP [MWave]";
        case PciDevice1014::DEVICE_008B: return "EADS PCI to PCI Bridge";
        case PciDevice1014::DEVICE_008E: return "GXT3000P Graphics Adapter";
        case PciDevice1014::DEVICE_0090: return "GXT 3000P";
        case PciDevice1014::DEVICE_0091: return "SSA Adapter";
        case PciDevice1014::DEVICE_0095: return "20H2999 PCI Docking Bridge";
        case PciDevice1014::DEVICE_0096: return "Chukar chipset SCSI controller";
        case PciDevice1014::DEVICE_009F: return "PCI 4758 Cryptographic Accelerator";
        case PciDevice1014::DEVICE_00A5: return "ATM Controller (1410a500)";
        case PciDevice1014::DEVICE_00A6: return "ATM 155MBPS MM Controller (1410a600)";
        case PciDevice1014::DEVICE_00B7: return "GXT2000P Graphics Adapter";
        case PciDevice1014::DEVICE_00B8: return "GXT2000P Graphics Adapter";
        case PciDevice1014::DEVICE_00BE: return "ATM 622MBPS Controller (1410be00)";
        case PciDevice1014::DEVICE_00DC: return "Advanced Systems Management Adapter (ASMA)";
        case PciDevice1014::DEVICE_00FC: return "CPC710 Dual Bridge and Memory Controller (PCI-64)";
        case PciDevice1014::DEVICE_0105: return "CPC710 Dual Bridge and Memory Controller (PCI-32)";
        case PciDevice1014::DEVICE_010F: return "Remote Supervisor Adapter (RSA)";
        case PciDevice1014::DEVICE_0142: return "Yotta Video Compositor Input";
        case PciDevice1014::DEVICE_0144: return "Yotta Video Compositor Output";
        case PciDevice1014::DEVICE_0156: return "405GP PLB to PCI Bridge";
        case PciDevice1014::DEVICE_015E: return "622Mbps ATM PCI Adapter";
        case PciDevice1014::DEVICE_0160: return "64bit/66MHz PCI ATM 155 MMF";
        case PciDevice1014::DEVICE_016E: return "GXT4000P Graphics Adapter";
        case PciDevice1014::DEVICE_0170: return "GXT6000P Graphics Adapter";
        case PciDevice1014::DEVICE_017D: return "GXT300P Graphics Adapter";
        case PciDevice1014::DEVICE_0180: return "Snipe chipset SCSI controller";
        case PciDevice1014::DEVICE_0188: return "EADS-X PCI-X to PCI-X Bridge";
        case PciDevice1014::DEVICE_01A7: return "PCI-X to PCI-X Bridge";
        case PciDevice1014::DEVICE_01BD: return "ServeRAID Controller";
        case PciDevice1014::DEVICE_01C1: return "64bit/66MHz PCI ATM 155 UTP";
        case PciDevice1014::DEVICE_01E6: return "Cryptographic Accelerator";
        case PciDevice1014::DEVICE_01EF: return "PowerPC 440GP PCI Bridge";
        case PciDevice1014::DEVICE_01FF: return "10/100 Mbps Ethernet";
        case PciDevice1014::DEVICE_0219: return "Multiport Serial Adapter";
        case PciDevice1014::DEVICE_021B: return "GXT6500P Graphics Adapter";
        case PciDevice1014::DEVICE_021C: return "GXT4500P Graphics Adapter";
        case PciDevice1014::DEVICE_0233: return "GXT135P Graphics Adapter";
        case PciDevice1014::DEVICE_025A: return "Drone card";
        case PciDevice1014::DEVICE_028C: return "Citrine chipset SCSI controller";
        case PciDevice1014::DEVICE_02A1: return "Calgary PCI-X Host Bridge";
        case PciDevice1014::DEVICE_02BD: return "Obsidian chipset SCSI controller";
        case PciDevice1014::DEVICE_0302: return "Winnipeg PCI-X Host Bridge";
        case PciDevice1014::DEVICE_0308: return "CalIOC2 PCI-E Root Port";
        case PciDevice1014::DEVICE_0311: return "FC 5740/1954 4-Port 10/100/1000 Base-TX PCI-X Adapter for POWER";
        case PciDevice1014::DEVICE_0314: return "ZISC 036 Neural accelerator card";
        case PciDevice1014::DEVICE_032D: return "Axon - Cell Companion Chip";
        case PciDevice1014::DEVICE_0339: return "Obsidian-E PCI-E SCSI controller";
        case PciDevice1014::DEVICE_033D: return "PCI-E IPR SAS Adapter (FPGA)";
        case PciDevice1014::DEVICE_034A: return "PCI-E IPR SAS Adapter (ASIC)";
        case PciDevice1014::DEVICE_03DC: return "POWER8 Host Bridge (PHB3)";
        case PciDevice1014::DEVICE_044B: return "GenWQE Accelerator Adapter";
        case PciDevice1014::DEVICE_04AA: return "Flash Adapter 90 (PCIe2 0.9TB)";
        case PciDevice1014::DEVICE_04C1: return "POWER9 Host Bridge (PHB4)";
        case PciDevice1014::DEVICE_04DA: return "PCI-E IPR SAS+ Adapter (ASIC)";
        case PciDevice1014::DEVICE_04ED: return "Internal Shared Memory (ISM) virtual PCI device";
        case PciDevice1014::DEVICE_3022: return "QLA3022 Network Adapter";
        case PciDevice1014::DEVICE_4022: return "QLA3022 Network Adapter";
        case PciDevice1014::DEVICE_FFFF: return "MPIC-2 interrupt controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1014 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1014::DEVICE_0002: return "Unknown device";
        case PciDevice1014::DEVICE_0005: return "Unknown device";
        case PciDevice1014::DEVICE_0007: return "Unknown device";
        case PciDevice1014::DEVICE_000A: return "Unknown device";
        case PciDevice1014::DEVICE_0017: return "Unknown device";
        case PciDevice1014::DEVICE_0018: return "Unknown device";
        case PciDevice1014::DEVICE_001B: return "Unknown device";
        case PciDevice1014::DEVICE_001C: return "Unknown device";
        case PciDevice1014::DEVICE_001D: return "Unknown device";
        case PciDevice1014::DEVICE_0020: return "Unknown device";
        case PciDevice1014::DEVICE_0022: return "Unknown device";
        case PciDevice1014::DEVICE_002D: return "Unknown device";
        case PciDevice1014::DEVICE_002E: return enumToHumanString((PciSubDevice1014002E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0031: return enumToHumanString((PciSubDevice10140031)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0036: return "Unknown device";
        case PciDevice1014::DEVICE_0037: return "Unknown device";
        case PciDevice1014::DEVICE_003A: return "Unknown device";
        case PciDevice1014::DEVICE_003C: return "Unknown device";
        case PciDevice1014::DEVICE_003E: return enumToHumanString((PciSubDevice1014003E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0045: return "Unknown device";
        case PciDevice1014::DEVICE_0046: return "Unknown device";
        case PciDevice1014::DEVICE_0047: return "Unknown device";
        case PciDevice1014::DEVICE_0048: return "Unknown device";
        case PciDevice1014::DEVICE_0049: return "Unknown device";
        case PciDevice1014::DEVICE_004E: return "Unknown device";
        case PciDevice1014::DEVICE_004F: return "Unknown device";
        case PciDevice1014::DEVICE_0050: return "Unknown device";
        case PciDevice1014::DEVICE_0053: return "Unknown device";
        case PciDevice1014::DEVICE_0054: return "Unknown device";
        case PciDevice1014::DEVICE_0057: return "Unknown device";
        case PciDevice1014::DEVICE_0058: return "Unknown device";
        case PciDevice1014::DEVICE_005E: return "Unknown device";
        case PciDevice1014::DEVICE_007C: return "Unknown device";
        case PciDevice1014::DEVICE_007D: return "Unknown device";
        case PciDevice1014::DEVICE_008B: return "Unknown device";
        case PciDevice1014::DEVICE_008E: return "Unknown device";
        case PciDevice1014::DEVICE_0090: return enumToHumanString((PciSubDevice10140090)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0091: return "Unknown device";
        case PciDevice1014::DEVICE_0095: return "Unknown device";
        case PciDevice1014::DEVICE_0096: return enumToHumanString((PciSubDevice10140096)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_009F: return "Unknown device";
        case PciDevice1014::DEVICE_00A5: return "Unknown device";
        case PciDevice1014::DEVICE_00A6: return "Unknown device";
        case PciDevice1014::DEVICE_00B7: return enumToHumanString((PciSubDevice101400B7)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_00B8: return "Unknown device";
        case PciDevice1014::DEVICE_00BE: return "Unknown device";
        case PciDevice1014::DEVICE_00DC: return "Unknown device";
        case PciDevice1014::DEVICE_00FC: return "Unknown device";
        case PciDevice1014::DEVICE_0105: return "Unknown device";
        case PciDevice1014::DEVICE_010F: return "Unknown device";
        case PciDevice1014::DEVICE_0142: return enumToHumanString((PciSubDevice10140142)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0144: return enumToHumanString((PciSubDevice10140144)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0156: return "Unknown device";
        case PciDevice1014::DEVICE_015E: return "Unknown device";
        case PciDevice1014::DEVICE_0160: return "Unknown device";
        case PciDevice1014::DEVICE_016E: return "Unknown device";
        case PciDevice1014::DEVICE_0170: return enumToHumanString((PciSubDevice10140170)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_017D: return "Unknown device";
        case PciDevice1014::DEVICE_0180: return enumToHumanString((PciSubDevice10140180)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0188: return "Unknown device";
        case PciDevice1014::DEVICE_01A7: return "Unknown device";
        case PciDevice1014::DEVICE_01BD: return enumToHumanString((PciSubDevice101401BD)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_01C1: return "Unknown device";
        case PciDevice1014::DEVICE_01E6: return "Unknown device";
        case PciDevice1014::DEVICE_01EF: return enumToHumanString((PciSubDevice101401EF)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_01FF: return "Unknown device";
        case PciDevice1014::DEVICE_0219: return enumToHumanString((PciSubDevice10140219)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_021B: return "Unknown device";
        case PciDevice1014::DEVICE_021C: return "Unknown device";
        case PciDevice1014::DEVICE_0233: return "Unknown device";
        case PciDevice1014::DEVICE_025A: return "Unknown device";
        case PciDevice1014::DEVICE_028C: return enumToHumanString((PciSubDevice1014028C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_02A1: return "Unknown device";
        case PciDevice1014::DEVICE_02BD: return enumToHumanString((PciSubDevice101402BD)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0302: return "Unknown device";
        case PciDevice1014::DEVICE_0308: return "Unknown device";
        case PciDevice1014::DEVICE_0311: return "Unknown device";
        case PciDevice1014::DEVICE_0314: return "Unknown device";
        case PciDevice1014::DEVICE_032D: return enumToHumanString((PciSubDevice1014032D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_0339: return enumToHumanString((PciSubDevice10140339)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_033D: return enumToHumanString((PciSubDevice1014033D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_034A: return enumToHumanString((PciSubDevice1014034A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_03DC: return "Unknown device";
        case PciDevice1014::DEVICE_044B: return "Unknown device";
        case PciDevice1014::DEVICE_04AA: return "Unknown device";
        case PciDevice1014::DEVICE_04C1: return "Unknown device";
        case PciDevice1014::DEVICE_04DA: return enumToHumanString((PciSubDevice101404DA)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1014::DEVICE_04ED: return "Unknown device";
        case PciDevice1014::DEVICE_3022: return "Unknown device";
        case PciDevice1014::DEVICE_4022: return "Unknown device";
        case PciDevice1014::DEVICE_FFFF: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCIDEVICE1014_H
