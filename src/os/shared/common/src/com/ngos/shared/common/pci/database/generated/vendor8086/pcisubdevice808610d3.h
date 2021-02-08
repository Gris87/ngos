// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610D3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1785 = 0x103C1785,
    SUBDEVICE_103C3250 = 0x103C3250,
    SUBDEVICE_10438369 = 0x10438369,
    SUBDEVICE_109376E9 = 0x109376E9,
    SUBDEVICE_10A98029 = 0x10A98029,
    SUBDEVICE_15D90605 = 0x15D90605,
    SUBDEVICE_15D9060A = 0x15D9060A,
    SUBDEVICE_15D9060D = 0x15D9060D,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80863578 = 0x80863578,
    SUBDEVICE_8086357A = 0x8086357A,
    SUBDEVICE_8086A01F = 0x8086A01F,
    SUBDEVICE_E4BF50C1 = 0xE4BF50C1,
    SUBDEVICE_E4BF50C2 = 0xE4BF50C2
};



inline const char8* enumToString(PciSubDevice808610D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610D3::NONE:               return "NONE";
        case PciSubDevice808610D3::SUBDEVICE_103C1785: return "SUBDEVICE_103C1785";
        case PciSubDevice808610D3::SUBDEVICE_103C3250: return "SUBDEVICE_103C3250";
        case PciSubDevice808610D3::SUBDEVICE_10438369: return "SUBDEVICE_10438369";
        case PciSubDevice808610D3::SUBDEVICE_109376E9: return "SUBDEVICE_109376E9";
        case PciSubDevice808610D3::SUBDEVICE_10A98029: return "SUBDEVICE_10A98029";
        case PciSubDevice808610D3::SUBDEVICE_15D90605: return "SUBDEVICE_15D90605";
        case PciSubDevice808610D3::SUBDEVICE_15D9060A: return "SUBDEVICE_15D9060A";
        case PciSubDevice808610D3::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";
        case PciSubDevice808610D3::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice808610D3::SUBDEVICE_80863578: return "SUBDEVICE_80863578";
        case PciSubDevice808610D3::SUBDEVICE_8086357A: return "SUBDEVICE_8086357A";
        case PciSubDevice808610D3::SUBDEVICE_8086A01F: return "SUBDEVICE_8086A01F";
        case PciSubDevice808610D3::SUBDEVICE_E4BF50C1: return "SUBDEVICE_E4BF50C1";
        case PciSubDevice808610D3::SUBDEVICE_E4BF50C2: return "SUBDEVICE_E4BF50C2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610D3::SUBDEVICE_103C1785: return "NC112i 1-port Ethernet Server Adapter";
        case PciSubDevice808610D3::SUBDEVICE_103C3250: return "NC112T PCI Express single Port Gigabit Server Adapter";
        case PciSubDevice808610D3::SUBDEVICE_10438369: return "Motherboard";
        case PciSubDevice808610D3::SUBDEVICE_109376E9: return "PCIe-8233 Ethernet Adapter";
        case PciSubDevice808610D3::SUBDEVICE_10A98029: return "Prism XL Single Port Gigabit Ethernet";
        case PciSubDevice808610D3::SUBDEVICE_15D90605: return "X8SIL";
        case PciSubDevice808610D3::SUBDEVICE_15D9060A: return "X7SPA-H/X7SPA-HF Motherboard";
        case PciSubDevice808610D3::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";
        case PciSubDevice808610D3::SUBDEVICE_80860001: return "Gigabit CT2 Desktop Adapter";
        case PciSubDevice808610D3::SUBDEVICE_80863578: return "Server Board S1200BTLR";
        case PciSubDevice808610D3::SUBDEVICE_8086357A: return "Server Board S1200BTS";
        case PciSubDevice808610D3::SUBDEVICE_8086A01F: return "Gigabit CT Desktop Adapter";
        case PciSubDevice808610D3::SUBDEVICE_E4BF50C1: return "PC1-GROOVE";
        case PciSubDevice808610D3::SUBDEVICE_E4BF50C2: return "PC2-LIMBO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610D3_H
