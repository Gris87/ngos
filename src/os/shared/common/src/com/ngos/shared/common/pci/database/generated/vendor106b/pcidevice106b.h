// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCIDEVICE106B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCIDEVICE106B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice106B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0007 = 0x0007,
    DEVICE_000C = 0x000C,
    DEVICE_000E = 0x000E,
    DEVICE_0010 = 0x0010,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001E = 0x001E,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027,
    DEVICE_0028 = 0x0028,
    DEVICE_0029 = 0x0029,
    DEVICE_002D = 0x002D,
    DEVICE_002E = 0x002E,
    DEVICE_002F = 0x002F,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031,
    DEVICE_0032 = 0x0032,
    DEVICE_0033 = 0x0033,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0036 = 0x0036,
    DEVICE_003B = 0x003B,
    DEVICE_003E = 0x003E,
    DEVICE_003F = 0x003F,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0043 = 0x0043,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_0047 = 0x0047,
    DEVICE_0048 = 0x0048,
    DEVICE_0049 = 0x0049,
    DEVICE_004A = 0x004A,
    DEVICE_004B = 0x004B,
    DEVICE_004C = 0x004C,
    DEVICE_004F = 0x004F,
    DEVICE_0050 = 0x0050,
    DEVICE_0051 = 0x0051,
    DEVICE_0052 = 0x0052,
    DEVICE_0053 = 0x0053,
    DEVICE_0054 = 0x0054,
    DEVICE_0055 = 0x0055,
    DEVICE_0056 = 0x0056,
    DEVICE_0057 = 0x0057,
    DEVICE_0058 = 0x0058,
    DEVICE_0059 = 0x0059,
    DEVICE_005B = 0x005B,
    DEVICE_0066 = 0x0066,
    DEVICE_0067 = 0x0067,
    DEVICE_0068 = 0x0068,
    DEVICE_0069 = 0x0069,
    DEVICE_006A = 0x006A,
    DEVICE_006B = 0x006B,
    DEVICE_0074 = 0x0074,
    DEVICE_1645 = 0x1645,
    DEVICE_1801 = 0x1801,
    DEVICE_1802 = 0x1802,
    DEVICE_1803 = 0x1803,
    DEVICE_2001 = 0x2001,
    DEVICE_2002 = 0x2002,
    DEVICE_2003 = 0x2003,
    DEVICE_2005 = 0x2005
};



inline const char8* enumToString(PciDevice106B device106B) // TEST: NO
{
    // COMMON_LT((" | device106B = %u", device106B)); // Commented to avoid bad looking logs



    switch (device106B)
    {
        case PciDevice106B::NONE:        return "NONE";
        case PciDevice106B::DEVICE_0001: return "DEVICE_0001";
        case PciDevice106B::DEVICE_0002: return "DEVICE_0002";
        case PciDevice106B::DEVICE_0003: return "DEVICE_0003";
        case PciDevice106B::DEVICE_0004: return "DEVICE_0004";
        case PciDevice106B::DEVICE_0007: return "DEVICE_0007";
        case PciDevice106B::DEVICE_000C: return "DEVICE_000C";
        case PciDevice106B::DEVICE_000E: return "DEVICE_000E";
        case PciDevice106B::DEVICE_0010: return "DEVICE_0010";
        case PciDevice106B::DEVICE_0017: return "DEVICE_0017";
        case PciDevice106B::DEVICE_0018: return "DEVICE_0018";
        case PciDevice106B::DEVICE_0019: return "DEVICE_0019";
        case PciDevice106B::DEVICE_001E: return "DEVICE_001E";
        case PciDevice106B::DEVICE_001F: return "DEVICE_001F";
        case PciDevice106B::DEVICE_0020: return "DEVICE_0020";
        case PciDevice106B::DEVICE_0021: return "DEVICE_0021";
        case PciDevice106B::DEVICE_0022: return "DEVICE_0022";
        case PciDevice106B::DEVICE_0024: return "DEVICE_0024";
        case PciDevice106B::DEVICE_0025: return "DEVICE_0025";
        case PciDevice106B::DEVICE_0026: return "DEVICE_0026";
        case PciDevice106B::DEVICE_0027: return "DEVICE_0027";
        case PciDevice106B::DEVICE_0028: return "DEVICE_0028";
        case PciDevice106B::DEVICE_0029: return "DEVICE_0029";
        case PciDevice106B::DEVICE_002D: return "DEVICE_002D";
        case PciDevice106B::DEVICE_002E: return "DEVICE_002E";
        case PciDevice106B::DEVICE_002F: return "DEVICE_002F";
        case PciDevice106B::DEVICE_0030: return "DEVICE_0030";
        case PciDevice106B::DEVICE_0031: return "DEVICE_0031";
        case PciDevice106B::DEVICE_0032: return "DEVICE_0032";
        case PciDevice106B::DEVICE_0033: return "DEVICE_0033";
        case PciDevice106B::DEVICE_0034: return "DEVICE_0034";
        case PciDevice106B::DEVICE_0035: return "DEVICE_0035";
        case PciDevice106B::DEVICE_0036: return "DEVICE_0036";
        case PciDevice106B::DEVICE_003B: return "DEVICE_003B";
        case PciDevice106B::DEVICE_003E: return "DEVICE_003E";
        case PciDevice106B::DEVICE_003F: return "DEVICE_003F";
        case PciDevice106B::DEVICE_0040: return "DEVICE_0040";
        case PciDevice106B::DEVICE_0041: return "DEVICE_0041";
        case PciDevice106B::DEVICE_0042: return "DEVICE_0042";
        case PciDevice106B::DEVICE_0043: return "DEVICE_0043";
        case PciDevice106B::DEVICE_0045: return "DEVICE_0045";
        case PciDevice106B::DEVICE_0046: return "DEVICE_0046";
        case PciDevice106B::DEVICE_0047: return "DEVICE_0047";
        case PciDevice106B::DEVICE_0048: return "DEVICE_0048";
        case PciDevice106B::DEVICE_0049: return "DEVICE_0049";
        case PciDevice106B::DEVICE_004A: return "DEVICE_004A";
        case PciDevice106B::DEVICE_004B: return "DEVICE_004B";
        case PciDevice106B::DEVICE_004C: return "DEVICE_004C";
        case PciDevice106B::DEVICE_004F: return "DEVICE_004F";
        case PciDevice106B::DEVICE_0050: return "DEVICE_0050";
        case PciDevice106B::DEVICE_0051: return "DEVICE_0051";
        case PciDevice106B::DEVICE_0052: return "DEVICE_0052";
        case PciDevice106B::DEVICE_0053: return "DEVICE_0053";
        case PciDevice106B::DEVICE_0054: return "DEVICE_0054";
        case PciDevice106B::DEVICE_0055: return "DEVICE_0055";
        case PciDevice106B::DEVICE_0056: return "DEVICE_0056";
        case PciDevice106B::DEVICE_0057: return "DEVICE_0057";
        case PciDevice106B::DEVICE_0058: return "DEVICE_0058";
        case PciDevice106B::DEVICE_0059: return "DEVICE_0059";
        case PciDevice106B::DEVICE_005B: return "DEVICE_005B";
        case PciDevice106B::DEVICE_0066: return "DEVICE_0066";
        case PciDevice106B::DEVICE_0067: return "DEVICE_0067";
        case PciDevice106B::DEVICE_0068: return "DEVICE_0068";
        case PciDevice106B::DEVICE_0069: return "DEVICE_0069";
        case PciDevice106B::DEVICE_006A: return "DEVICE_006A";
        case PciDevice106B::DEVICE_006B: return "DEVICE_006B";
        case PciDevice106B::DEVICE_0074: return "DEVICE_0074";
        case PciDevice106B::DEVICE_1645: return "DEVICE_1645";
        case PciDevice106B::DEVICE_1801: return "DEVICE_1801";
        case PciDevice106B::DEVICE_1802: return "DEVICE_1802";
        case PciDevice106B::DEVICE_1803: return "DEVICE_1803";
        case PciDevice106B::DEVICE_2001: return "DEVICE_2001";
        case PciDevice106B::DEVICE_2002: return "DEVICE_2002";
        case PciDevice106B::DEVICE_2003: return "DEVICE_2003";
        case PciDevice106B::DEVICE_2005: return "DEVICE_2005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice106B device106B) // TEST: NO
{
    // COMMON_LT((" | device106B = %u", device106B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device106B, enumToString(device106B));

    return res;
}



inline const char8* enumToHumanString(PciDevice106B device106B) // TEST: NO
{
    // COMMON_LT((" | device106B = %u", device106B)); // Commented to avoid bad looking logs



    switch (device106B)
    {
        case PciDevice106B::DEVICE_0001: return "Bandit PowerPC host bridge";
        case PciDevice106B::DEVICE_0002: return "Grand Central I/O";
        case PciDevice106B::DEVICE_0003: return "Control Video";
        case PciDevice106B::DEVICE_0004: return "PlanB Video-In";
        case PciDevice106B::DEVICE_0007: return "O'Hare I/O";
        case PciDevice106B::DEVICE_000C: return "DOS on Mac";
        case PciDevice106B::DEVICE_000E: return "Hydra Mac I/O";
        case PciDevice106B::DEVICE_0010: return "Heathrow Mac I/O";
        case PciDevice106B::DEVICE_0017: return "Paddington Mac I/O";
        case PciDevice106B::DEVICE_0018: return "UniNorth FireWire";
        case PciDevice106B::DEVICE_0019: return "KeyLargo USB";
        case PciDevice106B::DEVICE_001E: return "UniNorth Internal PCI";
        case PciDevice106B::DEVICE_001F: return "UniNorth PCI";
        case PciDevice106B::DEVICE_0020: return "UniNorth AGP";
        case PciDevice106B::DEVICE_0021: return "UniNorth GMAC (Sun GEM)";
        case PciDevice106B::DEVICE_0022: return "KeyLargo Mac I/O";
        case PciDevice106B::DEVICE_0024: return "UniNorth/Pangea GMAC (Sun GEM)";
        case PciDevice106B::DEVICE_0025: return "KeyLargo/Pangea Mac I/O";
        case PciDevice106B::DEVICE_0026: return "KeyLargo/Pangea USB";
        case PciDevice106B::DEVICE_0027: return "UniNorth/Pangea AGP";
        case PciDevice106B::DEVICE_0028: return "UniNorth/Pangea PCI";
        case PciDevice106B::DEVICE_0029: return "UniNorth/Pangea Internal PCI";
        case PciDevice106B::DEVICE_002D: return "UniNorth 1.5 AGP";
        case PciDevice106B::DEVICE_002E: return "UniNorth 1.5 PCI";
        case PciDevice106B::DEVICE_002F: return "UniNorth 1.5 Internal PCI";
        case PciDevice106B::DEVICE_0030: return "UniNorth/Pangea FireWire";
        case PciDevice106B::DEVICE_0031: return "UniNorth 2 FireWire";
        case PciDevice106B::DEVICE_0032: return "UniNorth 2 GMAC (Sun GEM)";
        case PciDevice106B::DEVICE_0033: return "UniNorth 2 ATA/100";
        case PciDevice106B::DEVICE_0034: return "UniNorth 2 AGP";
        case PciDevice106B::DEVICE_0035: return "UniNorth 2 PCI";
        case PciDevice106B::DEVICE_0036: return "UniNorth 2 Internal PCI";
        case PciDevice106B::DEVICE_003B: return "UniNorth/Intrepid ATA/100";
        case PciDevice106B::DEVICE_003E: return "KeyLargo/Intrepid Mac I/O";
        case PciDevice106B::DEVICE_003F: return "KeyLargo/Intrepid USB";
        case PciDevice106B::DEVICE_0040: return "K2 KeyLargo USB";
        case PciDevice106B::DEVICE_0041: return "K2 KeyLargo Mac/IO";
        case PciDevice106B::DEVICE_0042: return "K2 FireWire";
        case PciDevice106B::DEVICE_0043: return "K2 ATA/100";
        case PciDevice106B::DEVICE_0045: return "K2 HT-PCI Bridge";
        case PciDevice106B::DEVICE_0046: return "K2 HT-PCI Bridge";
        case PciDevice106B::DEVICE_0047: return "K2 HT-PCI Bridge";
        case PciDevice106B::DEVICE_0048: return "K2 HT-PCI Bridge";
        case PciDevice106B::DEVICE_0049: return "K2 HT-PCI Bridge";
        case PciDevice106B::DEVICE_004A: return "CPC945 HT Bridge";
        case PciDevice106B::DEVICE_004B: return "U3 AGP";
        case PciDevice106B::DEVICE_004C: return "K2 GMAC (Sun GEM)";
        case PciDevice106B::DEVICE_004F: return "Shasta Mac I/O";
        case PciDevice106B::DEVICE_0050: return "Shasta IDE";
        case PciDevice106B::DEVICE_0051: return "Shasta (Sun GEM)";
        case PciDevice106B::DEVICE_0052: return "Shasta Firewire";
        case PciDevice106B::DEVICE_0053: return "Shasta PCI Bridge";
        case PciDevice106B::DEVICE_0054: return "Shasta PCI Bridge";
        case PciDevice106B::DEVICE_0055: return "Shasta PCI Bridge";
        case PciDevice106B::DEVICE_0056: return "U4 PCIe";
        case PciDevice106B::DEVICE_0057: return "U3 HT Bridge";
        case PciDevice106B::DEVICE_0058: return "U3L AGP Bridge";
        case PciDevice106B::DEVICE_0059: return "U3H AGP Bridge";
        case PciDevice106B::DEVICE_005B: return "CPC945 PCIe Bridge";
        case PciDevice106B::DEVICE_0066: return "Intrepid2 AGP Bridge";
        case PciDevice106B::DEVICE_0067: return "Intrepid2 PCI Bridge";
        case PciDevice106B::DEVICE_0068: return "Intrepid2 PCI Bridge";
        case PciDevice106B::DEVICE_0069: return "Intrepid2 ATA/100";
        case PciDevice106B::DEVICE_006A: return "Intrepid2 Firewire";
        case PciDevice106B::DEVICE_006B: return "Intrepid2 GMAC (Sun GEM)";
        case PciDevice106B::DEVICE_0074: return "U4 HT Bridge";
        case PciDevice106B::DEVICE_1645: return "Broadcom NetXtreme BCM5701 Gigabit Ethernet";
        case PciDevice106B::DEVICE_1801: return "T2 Bridge Controller";
        case PciDevice106B::DEVICE_1802: return "T2 Secure Enclave Processor";
        case PciDevice106B::DEVICE_1803: return "Apple Audio Device";
        case PciDevice106B::DEVICE_2001: return "S1X NVMe Controller";
        case PciDevice106B::DEVICE_2002: return "S3ELab NVMe Controller";
        case PciDevice106B::DEVICE_2003: return "S3X NVMe Controller";
        case PciDevice106B::DEVICE_2005: return "ANS2 NVMe Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCIDEVICE106B_H
