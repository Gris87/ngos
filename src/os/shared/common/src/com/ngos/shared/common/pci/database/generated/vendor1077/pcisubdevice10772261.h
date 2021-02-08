// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772261_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772261_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772261: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770299 = 0x10770299,
    SUBDEVICE_1077029A = 0x1077029A,
    SUBDEVICE_1077029B = 0x1077029B,
    SUBDEVICE_1077029C = 0x1077029C,
    SUBDEVICE_107702A7 = 0x107702A7,
    SUBDEVICE_107702A8 = 0x107702A8,
    SUBDEVICE_107702AB = 0x107702AB,
    SUBDEVICE_107702AC = 0x107702AC,
    SUBDEVICE_107702B8 = 0x107702B8,
    SUBDEVICE_107702B9 = 0x107702B9,
    SUBDEVICE_159000F9 = 0x159000F9,
    SUBDEVICE_159000FA = 0x159000FA,
    SUBDEVICE_15900203 = 0x15900203,
    SUBDEVICE_15900204 = 0x15900204,
    SUBDEVICE_1590022D = 0x1590022D
};



inline const char8* enumToString(PciSubDevice10772261 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772261::NONE:               return "NONE";
        case PciSubDevice10772261::SUBDEVICE_10770299: return "SUBDEVICE_10770299";
        case PciSubDevice10772261::SUBDEVICE_1077029A: return "SUBDEVICE_1077029A";
        case PciSubDevice10772261::SUBDEVICE_1077029B: return "SUBDEVICE_1077029B";
        case PciSubDevice10772261::SUBDEVICE_1077029C: return "SUBDEVICE_1077029C";
        case PciSubDevice10772261::SUBDEVICE_107702A7: return "SUBDEVICE_107702A7";
        case PciSubDevice10772261::SUBDEVICE_107702A8: return "SUBDEVICE_107702A8";
        case PciSubDevice10772261::SUBDEVICE_107702AB: return "SUBDEVICE_107702AB";
        case PciSubDevice10772261::SUBDEVICE_107702AC: return "SUBDEVICE_107702AC";
        case PciSubDevice10772261::SUBDEVICE_107702B8: return "SUBDEVICE_107702B8";
        case PciSubDevice10772261::SUBDEVICE_107702B9: return "SUBDEVICE_107702B9";
        case PciSubDevice10772261::SUBDEVICE_159000F9: return "SUBDEVICE_159000F9";
        case PciSubDevice10772261::SUBDEVICE_159000FA: return "SUBDEVICE_159000FA";
        case PciSubDevice10772261::SUBDEVICE_15900203: return "SUBDEVICE_15900203";
        case PciSubDevice10772261::SUBDEVICE_15900204: return "SUBDEVICE_15900204";
        case PciSubDevice10772261::SUBDEVICE_1590022D: return "SUBDEVICE_1590022D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772261 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772261 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772261::SUBDEVICE_10770299: return "QLE2740 Single Port 32Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772261::SUBDEVICE_1077029A: return "QLE2742 Dual Port 32Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772261::SUBDEVICE_1077029B: return "QLE2690 Single Port 16Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772261::SUBDEVICE_1077029C: return "QLE2692 Dual Port 16Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772261::SUBDEVICE_107702A7: return "QLE2690 Single Port 16Gb FC to PCIe Gen3 x8 Adapter";
        case PciSubDevice10772261::SUBDEVICE_107702A8: return "QLE2692 Dual Port 16Gb FC to PCIe Gen3 x8 Adapter";
        case PciSubDevice10772261::SUBDEVICE_107702AB: return "QLE2740 Single Port 32Gb FC to PCIe Gen3 x8 Adapter";
        case PciSubDevice10772261::SUBDEVICE_107702AC: return "QLE2742 Dual Port 32Gb FC to PCIe Gen3 x8 Adapter";
        case PciSubDevice10772261::SUBDEVICE_107702B8: return "2x16Gb QME2692 FC HBA";
        case PciSubDevice10772261::SUBDEVICE_107702B9: return "2x32Gb QME2742 FC HBA";
        case PciSubDevice10772261::SUBDEVICE_159000F9: return "StoreFabric SN1100Q 16Gb Single Port Fibre Channel Host Bus Adapter";
        case PciSubDevice10772261::SUBDEVICE_159000FA: return "StoreFabric SN1100Q 16Gb Dual Port Fibre Channel Host Bus Adapter";
        case PciSubDevice10772261::SUBDEVICE_15900203: return "StoreFabric SN1600Q 32Gb Single Port Fibre Channel Host Bus Adapter";
        case PciSubDevice10772261::SUBDEVICE_15900204: return "StoreFabric SN1600Q 32Gb Dual Port Fibre Channel Host Bus Adapter";
        case PciSubDevice10772261::SUBDEVICE_1590022D: return "5830C 32Gb Dual Port Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772261_H
