// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778020: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F64 = 0x10281F64,
    SUBDEVICE_103C3346 = 0x103C3346,
    SUBDEVICE_103C3733 = 0x103C3733,
    SUBDEVICE_10770203 = 0x10770203,
    SUBDEVICE_10770207 = 0x10770207,
    SUBDEVICE_1077020B = 0x1077020B,
    SUBDEVICE_1077020C = 0x1077020C,
    SUBDEVICE_1077020F = 0x1077020F,
    SUBDEVICE_10770210 = 0x10770210,
    SUBDEVICE_10770233 = 0x10770233
};



inline const char8* enumToString(PciSubDevice10778020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778020::NONE:               return "NONE";
        case PciSubDevice10778020::SUBDEVICE_10281F64: return "SUBDEVICE_10281F64";
        case PciSubDevice10778020::SUBDEVICE_103C3346: return "SUBDEVICE_103C3346";
        case PciSubDevice10778020::SUBDEVICE_103C3733: return "SUBDEVICE_103C3733";
        case PciSubDevice10778020::SUBDEVICE_10770203: return "SUBDEVICE_10770203";
        case PciSubDevice10778020::SUBDEVICE_10770207: return "SUBDEVICE_10770207";
        case PciSubDevice10778020::SUBDEVICE_1077020B: return "SUBDEVICE_1077020B";
        case PciSubDevice10778020::SUBDEVICE_1077020C: return "SUBDEVICE_1077020C";
        case PciSubDevice10778020::SUBDEVICE_1077020F: return "SUBDEVICE_1077020F";
        case PciSubDevice10778020::SUBDEVICE_10770210: return "SUBDEVICE_10770210";
        case PciSubDevice10778020::SUBDEVICE_10770233: return "SUBDEVICE_10770233";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778020::SUBDEVICE_10281F64: return "QMD8262-k 10G DP bNDC KR";
        case PciSubDevice10778020::SUBDEVICE_103C3346: return "CN1000Q Dual Port Converged Network Adapter";
        case PciSubDevice10778020::SUBDEVICE_103C3733: return "NC523SFP 10Gb 2-port Server Adapter";
        case PciSubDevice10778020::SUBDEVICE_10770203: return "8200 Series Single Port 10GbE Converged Network Adapter (TCP/IP Networking)";
        case PciSubDevice10778020::SUBDEVICE_10770207: return "8200 Series Dual Port 10GbE Converged Network Adapter (TCP/IP Networking)";
        case PciSubDevice10778020::SUBDEVICE_1077020B: return "3200 Series Dual Port 10Gb Intelligent Ethernet Adapter";
        case PciSubDevice10778020::SUBDEVICE_1077020C: return "3200 Series Quad Port 1Gb Intelligent Ethernet Adapter";
        case PciSubDevice10778020::SUBDEVICE_1077020F: return "3200 Series Single Port 10Gb Intelligent Ethernet Adapter";
        case PciSubDevice10778020::SUBDEVICE_10770210: return "QME8242-k 10GbE Dual Port Mezzanine Card";
        case PciSubDevice10778020::SUBDEVICE_10770233: return "QME8262-k 10GbE Dual Port Mezzanine Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778020_H
