// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404B5 = 0x101404B5,
    SUBDEVICE_103C1777 = 0x103C1777,
    SUBDEVICE_103C17C9 = 0x103C17C9,
    SUBDEVICE_103C18CE = 0x103C18CE,
    SUBDEVICE_103C18CF = 0x103C18CF,
    SUBDEVICE_103C18D6 = 0x103C18D6,
    SUBDEVICE_15B30025 = 0x15B30025,
    SUBDEVICE_15B30026 = 0x15B30026,
    SUBDEVICE_15B30028 = 0x15B30028,
    SUBDEVICE_15B30059 = 0x15B30059,
    SUBDEVICE_15B30064 = 0x15B30064,
    SUBDEVICE_15B30065 = 0x15B30065,
    SUBDEVICE_15B30066 = 0x15B30066,
    SUBDEVICE_15B30067 = 0x15B30067,
    SUBDEVICE_15B30071 = 0x15B30071,
    SUBDEVICE_15B30078 = 0x15B30078,
    SUBDEVICE_15B30079 = 0x15B30079,
    SUBDEVICE_15B30080 = 0x15B30080
};



inline const char8* enumToString(PciSubDevice15B31003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31003::NONE:               return "NONE";
        case PciSubDevice15B31003::SUBDEVICE_101404B5: return "SUBDEVICE_101404B5";
        case PciSubDevice15B31003::SUBDEVICE_103C1777: return "SUBDEVICE_103C1777";
        case PciSubDevice15B31003::SUBDEVICE_103C17C9: return "SUBDEVICE_103C17C9";
        case PciSubDevice15B31003::SUBDEVICE_103C18CE: return "SUBDEVICE_103C18CE";
        case PciSubDevice15B31003::SUBDEVICE_103C18CF: return "SUBDEVICE_103C18CF";
        case PciSubDevice15B31003::SUBDEVICE_103C18D6: return "SUBDEVICE_103C18D6";
        case PciSubDevice15B31003::SUBDEVICE_15B30025: return "SUBDEVICE_15B30025";
        case PciSubDevice15B31003::SUBDEVICE_15B30026: return "SUBDEVICE_15B30026";
        case PciSubDevice15B31003::SUBDEVICE_15B30028: return "SUBDEVICE_15B30028";
        case PciSubDevice15B31003::SUBDEVICE_15B30059: return "SUBDEVICE_15B30059";
        case PciSubDevice15B31003::SUBDEVICE_15B30064: return "SUBDEVICE_15B30064";
        case PciSubDevice15B31003::SUBDEVICE_15B30065: return "SUBDEVICE_15B30065";
        case PciSubDevice15B31003::SUBDEVICE_15B30066: return "SUBDEVICE_15B30066";
        case PciSubDevice15B31003::SUBDEVICE_15B30067: return "SUBDEVICE_15B30067";
        case PciSubDevice15B31003::SUBDEVICE_15B30071: return "SUBDEVICE_15B30071";
        case PciSubDevice15B31003::SUBDEVICE_15B30078: return "SUBDEVICE_15B30078";
        case PciSubDevice15B31003::SUBDEVICE_15B30079: return "SUBDEVICE_15B30079";
        case PciSubDevice15B31003::SUBDEVICE_15B30080: return "SUBDEVICE_15B30080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31003::SUBDEVICE_101404B5: return "PCIe3 40GbE RoCE Converged Host Bus Adapter for Power";
        case PciSubDevice15B31003::SUBDEVICE_103C1777: return "InfiniBand FDR/EN 10/40Gb Dual Port 544FLR-QSFP Adapter (Rev Cx)";
        case PciSubDevice15B31003::SUBDEVICE_103C17C9: return "Infiniband QDR/Ethernet 10Gb 2-port 544i Adapter";
        case PciSubDevice15B31003::SUBDEVICE_103C18CE: return "InfiniBand QDR/EN 10Gb Dual Port 544M Adapter";
        case PciSubDevice15B31003::SUBDEVICE_103C18CF: return "InfiniBand FDR/EN 10/40Gb Dual Port 544M Adapter";
        case PciSubDevice15B31003::SUBDEVICE_103C18D6: return "InfiniBand FDR/EN 10/40Gb Dual Port 544QSFP Adapter";
        case PciSubDevice15B31003::SUBDEVICE_15B30025: return "ConnectX-3 IB QDR Dual Port Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30026: return "ConnectX-3 IB FDR Dual Port Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30028: return "ConnectX-3 VPI Dual QSFP+ Port QDR Infiniband 40Gb/s or 10Gb Ethernet";
        case PciSubDevice15B31003::SUBDEVICE_15B30059: return "ConnectX-3 VPI IB FDR/40 GbE Single Port QSFP+ Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30064: return "ConnectX-3 EN 10/40 GbE Single Port QSFP+ Adapter (MCX313A-BCBT)";
        case PciSubDevice15B31003::SUBDEVICE_15B30065: return "ConnectX-3 VPI IB FDR/40 GbE Dual Port QSFP+ Adapter";
        case PciSubDevice15B31003::SUBDEVICE_15B30066: return "ConnectX-3 IB FDR10 Dual Port Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30067: return "ConnectX-3 VPI IB FDR/40 GbE Single Port QSFP+ Adapter";
        case PciSubDevice15B31003::SUBDEVICE_15B30071: return "ConnectX-3 VPI IB FDR/40 GbE Dual Port QSFP+ Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30078: return "ConnectX-3 10 GbE Dual Port KR Mezzanine Card";
        case PciSubDevice15B31003::SUBDEVICE_15B30079: return "ConnectX-3 40 GbE Dual Port QSFP+ Adapter";
        case PciSubDevice15B31003::SUBDEVICE_15B30080: return "ConnectX-3 10 GbE Dual Port SFP+ Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31003_H
