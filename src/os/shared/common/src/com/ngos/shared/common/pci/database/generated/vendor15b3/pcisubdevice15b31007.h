// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404EB = 0x101404EB,
    SUBDEVICE_103C22F3 = 0x103C22F3,
    SUBDEVICE_103C22F4 = 0x103C22F4,
    SUBDEVICE_103C801F = 0x103C801F,
    SUBDEVICE_117C0090 = 0x117C0090,
    SUBDEVICE_117C0091 = 0x117C0091,
    SUBDEVICE_117C0092 = 0x117C0092,
    SUBDEVICE_117C0093 = 0x117C0093,
    SUBDEVICE_15B30006 = 0x15B30006,
    SUBDEVICE_15B30078 = 0x15B30078,
    SUBDEVICE_15B30079 = 0x15B30079,
    SUBDEVICE_15B30080 = 0x15B30080,
    SUBDEVICE_193D1002 = 0x193D1002
};



inline const char8* enumToString(PciSubDevice15B31007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31007::NONE:               return "NONE";
        case PciSubDevice15B31007::SUBDEVICE_101404EB: return "SUBDEVICE_101404EB";
        case PciSubDevice15B31007::SUBDEVICE_103C22F3: return "SUBDEVICE_103C22F3";
        case PciSubDevice15B31007::SUBDEVICE_103C22F4: return "SUBDEVICE_103C22F4";
        case PciSubDevice15B31007::SUBDEVICE_103C801F: return "SUBDEVICE_103C801F";
        case PciSubDevice15B31007::SUBDEVICE_117C0090: return "SUBDEVICE_117C0090";
        case PciSubDevice15B31007::SUBDEVICE_117C0091: return "SUBDEVICE_117C0091";
        case PciSubDevice15B31007::SUBDEVICE_117C0092: return "SUBDEVICE_117C0092";
        case PciSubDevice15B31007::SUBDEVICE_117C0093: return "SUBDEVICE_117C0093";
        case PciSubDevice15B31007::SUBDEVICE_15B30006: return "SUBDEVICE_15B30006";
        case PciSubDevice15B31007::SUBDEVICE_15B30078: return "SUBDEVICE_15B30078";
        case PciSubDevice15B31007::SUBDEVICE_15B30079: return "SUBDEVICE_15B30079";
        case PciSubDevice15B31007::SUBDEVICE_15B30080: return "SUBDEVICE_15B30080";
        case PciSubDevice15B31007::SUBDEVICE_193D1002: return "SUBDEVICE_193D1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31007::SUBDEVICE_101404EB: return "2-Port 10GbE NIC and RoCE SR PCIe3";
        case PciSubDevice15B31007::SUBDEVICE_103C22F3: return "InfiniBand FDR/Ethernet 10Gb/40Gb 2-port 544+QSFP Adapter";
        case PciSubDevice15B31007::SUBDEVICE_103C22F4: return "InfiniBand FDR/Ethernet 10Gb/40Gb 2-port 544+FLR-QSFP Adapter";
        case PciSubDevice15B31007::SUBDEVICE_103C801F: return "Ethernet 10G 2-port 546SFP+ Adapter";
        case PciSubDevice15B31007::SUBDEVICE_117C0090: return "FastFrame NQ41";
        case PciSubDevice15B31007::SUBDEVICE_117C0091: return "FastFrame NQ42";
        case PciSubDevice15B31007::SUBDEVICE_117C0092: return "FastFrame NQ11";
        case PciSubDevice15B31007::SUBDEVICE_117C0093: return "FastFrame NQ12";
        case PciSubDevice15B31007::SUBDEVICE_15B30006: return "Mellanox Technologies ConnectX-3 Pro Stand-up dual-port 40GbE MCX314A-BCCT";
        case PciSubDevice15B31007::SUBDEVICE_15B30078: return "ConnectX-3 Pro 10 GbE Dual Port KR Mezzanine Card";
        case PciSubDevice15B31007::SUBDEVICE_15B30079: return "ConnectX-3 Pro 40 GbE Dual Port QSFP+ Adapter";
        case PciSubDevice15B31007::SUBDEVICE_15B30080: return "ConnectX-3 Pro 10 GbE Dual Port SFP+ Adapter";
        case PciSubDevice15B31007::SUBDEVICE_193D1002: return "520F-B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31007_H
