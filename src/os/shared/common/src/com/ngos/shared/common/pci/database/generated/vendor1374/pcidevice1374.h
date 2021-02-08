// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1374_PCIDEVICE1374_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1374_PCIDEVICE1374_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1374: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027,
    DEVICE_0029 = 0x0029,
    DEVICE_002A = 0x002A,
    DEVICE_002B = 0x002B,
    DEVICE_002C = 0x002C,
    DEVICE_002D = 0x002D,
    DEVICE_002E = 0x002E,
    DEVICE_002F = 0x002F,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031,
    DEVICE_0032 = 0x0032,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0036 = 0x0036,
    DEVICE_0037 = 0x0037,
    DEVICE_0038 = 0x0038,
    DEVICE_0039 = 0x0039,
    DEVICE_003A = 0x003A,
    DEVICE_003B = 0x003B,
    DEVICE_003C = 0x003C,
    DEVICE_003D = 0x003D,
    DEVICE_003E = 0x003E,
    DEVICE_003F = 0x003F,
    DEVICE_0040 = 0x0040,
    DEVICE_0042 = 0x0042,
    DEVICE_0043 = 0x0043,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_0047 = 0x0047,
    DEVICE_004A = 0x004A,
    DEVICE_004D = 0x004D,
    DEVICE_0401 = 0x0401,
    DEVICE_0420 = 0x0420,
    DEVICE_0460 = 0x0460,
    DEVICE_0461 = 0x0461,
    DEVICE_0462 = 0x0462,
    DEVICE_0470 = 0x0470,
    DEVICE_0482 = 0x0482,
    DEVICE_0483 = 0x0483
};



inline const char8* enumToString(PciDevice1374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1374::NONE:        return "NONE";
        case PciDevice1374::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1374::DEVICE_0025: return "DEVICE_0025";
        case PciDevice1374::DEVICE_0026: return "DEVICE_0026";
        case PciDevice1374::DEVICE_0027: return "DEVICE_0027";
        case PciDevice1374::DEVICE_0029: return "DEVICE_0029";
        case PciDevice1374::DEVICE_002A: return "DEVICE_002A";
        case PciDevice1374::DEVICE_002B: return "DEVICE_002B";
        case PciDevice1374::DEVICE_002C: return "DEVICE_002C";
        case PciDevice1374::DEVICE_002D: return "DEVICE_002D";
        case PciDevice1374::DEVICE_002E: return "DEVICE_002E";
        case PciDevice1374::DEVICE_002F: return "DEVICE_002F";
        case PciDevice1374::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1374::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1374::DEVICE_0032: return "DEVICE_0032";
        case PciDevice1374::DEVICE_0034: return "DEVICE_0034";
        case PciDevice1374::DEVICE_0035: return "DEVICE_0035";
        case PciDevice1374::DEVICE_0036: return "DEVICE_0036";
        case PciDevice1374::DEVICE_0037: return "DEVICE_0037";
        case PciDevice1374::DEVICE_0038: return "DEVICE_0038";
        case PciDevice1374::DEVICE_0039: return "DEVICE_0039";
        case PciDevice1374::DEVICE_003A: return "DEVICE_003A";
        case PciDevice1374::DEVICE_003B: return "DEVICE_003B";
        case PciDevice1374::DEVICE_003C: return "DEVICE_003C";
        case PciDevice1374::DEVICE_003D: return "DEVICE_003D";
        case PciDevice1374::DEVICE_003E: return "DEVICE_003E";
        case PciDevice1374::DEVICE_003F: return "DEVICE_003F";
        case PciDevice1374::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1374::DEVICE_0042: return "DEVICE_0042";
        case PciDevice1374::DEVICE_0043: return "DEVICE_0043";
        case PciDevice1374::DEVICE_0045: return "DEVICE_0045";
        case PciDevice1374::DEVICE_0046: return "DEVICE_0046";
        case PciDevice1374::DEVICE_0047: return "DEVICE_0047";
        case PciDevice1374::DEVICE_004A: return "DEVICE_004A";
        case PciDevice1374::DEVICE_004D: return "DEVICE_004D";
        case PciDevice1374::DEVICE_0401: return "DEVICE_0401";
        case PciDevice1374::DEVICE_0420: return "DEVICE_0420";
        case PciDevice1374::DEVICE_0460: return "DEVICE_0460";
        case PciDevice1374::DEVICE_0461: return "DEVICE_0461";
        case PciDevice1374::DEVICE_0462: return "DEVICE_0462";
        case PciDevice1374::DEVICE_0470: return "DEVICE_0470";
        case PciDevice1374::DEVICE_0482: return "DEVICE_0482";
        case PciDevice1374::DEVICE_0483: return "DEVICE_0483";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1374::DEVICE_0024: return "Silicom Dual port Giga Ethernet BGE Bypass Server Adapter";
        case PciDevice1374::DEVICE_0025: return "Silicom Quad port Giga Ethernet BGE Bypass Server Adapter";
        case PciDevice1374::DEVICE_0026: return "Silicom Dual port Fiber Giga Ethernet 546 Bypass Server Adapter";
        case PciDevice1374::DEVICE_0027: return "Silicom Dual port Fiber LX Giga Ethernet 546 Bypass Server Adapter";
        case PciDevice1374::DEVICE_0029: return "Silicom Dual port Copper Giga Ethernet 546GB Bypass Server Adapter";
        case PciDevice1374::DEVICE_002A: return "Silicom Dual port Fiber Giga Ethernet 546 TAP/Bypass Server Adapter";
        case PciDevice1374::DEVICE_002B: return "Silicom Dual port Copper Fast Ethernet 546 TAP/Bypass Server Adapter (PXE2TBI)";
        case PciDevice1374::DEVICE_002C: return "Silicom Quad port Copper Giga Ethernet 546GB Bypass Server Adapter (PXG4BPI)";
        case PciDevice1374::DEVICE_002D: return "Silicom Quad port Fiber-SX Giga Ethernet 546GB Bypass Server Adapter (PXG4BPFI)";
        case PciDevice1374::DEVICE_002E: return "Silicom Quad port Fiber-LX Giga Ethernet 546GB Bypass Server Adapter (PXG4BPFI-LX)";
        case PciDevice1374::DEVICE_002F: return "Silicom Dual port Fiber-SX Giga Ethernet 546GB Low profile Bypass Server Adapter (PXG2BPFIL)";
        case PciDevice1374::DEVICE_0030: return "Silicom Dual port Fiber-LX Giga Ethernet 546GB Low profile Bypass Server Adapter";
        case PciDevice1374::DEVICE_0031: return "Silicom Quad port Copper Giga Ethernet PCI-E Bypass Server Adapter";
        case PciDevice1374::DEVICE_0032: return "Silicom Dual port Copper Fast Ethernet 546 TAP/Bypass Server Adapter";
        case PciDevice1374::DEVICE_0034: return "Silicom Dual port Copper Giga Ethernet PCI-E BGE Bypass Server Adapter";
        case PciDevice1374::DEVICE_0035: return "Silicom Quad port Copper Giga Ethernet PCI-E BGE Bypass Server Adapter";
        case PciDevice1374::DEVICE_0036: return "Silicom Dual port Fiber Giga Ethernet PCI-E BGE Bypass Server Adapter";
        case PciDevice1374::DEVICE_0037: return "Silicom Dual port Copper Ethernet PCI-E Intel based Bypass Server Adapter";
        case PciDevice1374::DEVICE_0038: return "Silicom Quad port Copper Ethernet PCI-E Intel based Bypass Server Adapter";
        case PciDevice1374::DEVICE_0039: return "Silicom Dual port Fiber-SX Ethernet PCI-E Intel based Bypass Server Adapter";
        case PciDevice1374::DEVICE_003A: return "Silicom Dual port Fiber-LX Ethernet PCI-E Intel based Bypass Server Adapter";
        case PciDevice1374::DEVICE_003B: return "Silicom Dual port Fiber Ethernet PMC Intel based Bypass Server Adapter (PMCX2BPFI)";
        case PciDevice1374::DEVICE_003C: return "Silicom Dual port Copper Ethernet PCI-X BGE based Bypass Server Adapter (PXG2BPRB)";
        case PciDevice1374::DEVICE_003D: return "2-port Copper GBE Bypass with Caviume 1010 PCI-X";
        case PciDevice1374::DEVICE_003E: return "Silicom Dual port Fiber Giga Ethernet PCI-E 571 TAP/Bypass Server Adapter (PEG2TBFI)";
        case PciDevice1374::DEVICE_003F: return "Silicom Dual port Copper Giga Ethernet PCI-X 546 TAP/Bypass Server Adapter (PXG2TBI)";
        case PciDevice1374::DEVICE_0040: return "Silicom Quad port Fiber-SX Giga Ethernet 571 Bypass Server Adapter (PEG4BPFI)";
        case PciDevice1374::DEVICE_0042: return "4-port Copper GBE PMC-X Bypass";
        case PciDevice1374::DEVICE_0043: return "Silicom Quad port Fiber-SX Giga Ethernet 546 Bypass Server Adapter (PXG4BPFID)";
        case PciDevice1374::DEVICE_0045: return "Silicom 6 port Copper Giga Ethernet 546 Bypass Server Adapter (PXG6BPI)";
        case PciDevice1374::DEVICE_0046: return "4-port bypass PCI-E w disconnect low profile";
        case PciDevice1374::DEVICE_0047: return "Silicom Dual port Fiber-SX Giga Ethernet 571 Bypass Disconnect Server Adapter (PEG2BPFID)";
        case PciDevice1374::DEVICE_004A: return "Silicom Quad port Fiber-LX Giga Ethernet 571 Bypass Server Adapter (PEG4BPFI-LX)";
        case PciDevice1374::DEVICE_004D: return "Dual port Copper Giga Ethernet PCI-E Bypass Server Adapter";
        case PciDevice1374::DEVICE_0401: return "Gigabit Ethernet ExpressModule Bypass Server Adapter";
        case PciDevice1374::DEVICE_0420: return "Gigabit Ethernet ExpressModule Bypass Server Adapter";
        case PciDevice1374::DEVICE_0460: return "Gigabit Ethernet Express Module Bypass Server Adapter";
        case PciDevice1374::DEVICE_0461: return "Gigabit Ethernet ExpressModule Bypass Server Adapter";
        case PciDevice1374::DEVICE_0462: return "Gigabit Ethernet ExpressModule Bypass Server Adapter";
        case PciDevice1374::DEVICE_0470: return "Octal-port Copper Gigabit Ethernet Express Module Bypass Server Adapter";
        case PciDevice1374::DEVICE_0482: return "Dual-port Fiber (SR) 10 Gigabit Ethernet ExpressModule Bypass Server Adapter";
        case PciDevice1374::DEVICE_0483: return "Dual-port Fiber (LR) 10 Gigabit Ethernet ExpressModule Bypass Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1374_PCIDEVICE1374_H
