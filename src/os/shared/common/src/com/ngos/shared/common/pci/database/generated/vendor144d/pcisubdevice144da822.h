// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA822_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA822_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA822: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140621 = 0x10140621,
    SUBDEVICE_10140622 = 0x10140622,
    SUBDEVICE_10140629 = 0x10140629,
    SUBDEVICE_1014064A = 0x1014064A,
    SUBDEVICE_1014064B = 0x1014064B,
    SUBDEVICE_1014064C = 0x1014064C,
    SUBDEVICE_10281FD9 = 0x10281FD9,
    SUBDEVICE_10281FDA = 0x10281FDA,
    SUBDEVICE_10281FDB = 0x10281FDB,
    SUBDEVICE_10281FDC = 0x10281FDC,
    SUBDEVICE_10281FDD = 0x10281FDD,
    SUBDEVICE_10281FDE = 0x10281FDE,
    SUBDEVICE_10281FDF = 0x10281FDF,
    SUBDEVICE_10281FF3 = 0x10281FF3,
    SUBDEVICE_10281FF4 = 0x10281FF4,
    SUBDEVICE_10281FF5 = 0x10281FF5,
    SUBDEVICE_10281FF6 = 0x10281FF6,
    SUBDEVICE_10281FF7 = 0x10281FF7,
    SUBDEVICE_10281FF8 = 0x10281FF8,
    SUBDEVICE_10281FF9 = 0x10281FF9,
    SUBDEVICE_10281FFA = 0x10281FFA
};



inline const char8* enumToString(PciSubDevice144DA822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA822::NONE:               return "NONE";
        case PciSubDevice144DA822::SUBDEVICE_10140621: return "SUBDEVICE_10140621";
        case PciSubDevice144DA822::SUBDEVICE_10140622: return "SUBDEVICE_10140622";
        case PciSubDevice144DA822::SUBDEVICE_10140629: return "SUBDEVICE_10140629";
        case PciSubDevice144DA822::SUBDEVICE_1014064A: return "SUBDEVICE_1014064A";
        case PciSubDevice144DA822::SUBDEVICE_1014064B: return "SUBDEVICE_1014064B";
        case PciSubDevice144DA822::SUBDEVICE_1014064C: return "SUBDEVICE_1014064C";
        case PciSubDevice144DA822::SUBDEVICE_10281FD9: return "SUBDEVICE_10281FD9";
        case PciSubDevice144DA822::SUBDEVICE_10281FDA: return "SUBDEVICE_10281FDA";
        case PciSubDevice144DA822::SUBDEVICE_10281FDB: return "SUBDEVICE_10281FDB";
        case PciSubDevice144DA822::SUBDEVICE_10281FDC: return "SUBDEVICE_10281FDC";
        case PciSubDevice144DA822::SUBDEVICE_10281FDD: return "SUBDEVICE_10281FDD";
        case PciSubDevice144DA822::SUBDEVICE_10281FDE: return "SUBDEVICE_10281FDE";
        case PciSubDevice144DA822::SUBDEVICE_10281FDF: return "SUBDEVICE_10281FDF";
        case PciSubDevice144DA822::SUBDEVICE_10281FF3: return "SUBDEVICE_10281FF3";
        case PciSubDevice144DA822::SUBDEVICE_10281FF4: return "SUBDEVICE_10281FF4";
        case PciSubDevice144DA822::SUBDEVICE_10281FF5: return "SUBDEVICE_10281FF5";
        case PciSubDevice144DA822::SUBDEVICE_10281FF6: return "SUBDEVICE_10281FF6";
        case PciSubDevice144DA822::SUBDEVICE_10281FF7: return "SUBDEVICE_10281FF7";
        case PciSubDevice144DA822::SUBDEVICE_10281FF8: return "SUBDEVICE_10281FF8";
        case PciSubDevice144DA822::SUBDEVICE_10281FF9: return "SUBDEVICE_10281FF9";
        case PciSubDevice144DA822::SUBDEVICE_10281FFA: return "SUBDEVICE_10281FFA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA822::SUBDEVICE_10140621: return "PCIe3 1.6TB NVMe Flash Adapter II x8";
        case PciSubDevice144DA822::SUBDEVICE_10140622: return "PCIe3 3.2TB NVMe Flash Adapter II x8";
        case PciSubDevice144DA822::SUBDEVICE_10140629: return "PCIe3 6.4TB NVMe Flash Adapter II x8";
        case PciSubDevice144DA822::SUBDEVICE_1014064A: return "PCIe3 1.6TB NVMe Flash Adapter III x8";
        case PciSubDevice144DA822::SUBDEVICE_1014064B: return "PCIe3 3.2TB NVMe Flash Adapter III x8";
        case PciSubDevice144DA822::SUBDEVICE_1014064C: return "PCIe3 6.4TB NVMe Flash Adapter III x8";
        case PciSubDevice144DA822::SUBDEVICE_10281FD9: return "Express Flash PM1725a 800GB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FDA: return "Express Flash PM1725a 1.6TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FDB: return "Express Flash PM1725a 3.2TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FDC: return "Express Flash PM1725a 6.4TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FDD: return "Express Flash PM1725a 1.6TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FDE: return "Express Flash PM1725a 3.2TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FDF: return "Express Flash PM1725a 6.4TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FF3: return "Express Flash PM1725b 1.6TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FF4: return "Express Flash PM1725b 3.2TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FF5: return "Express Flash PM1725b 6.4TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FF6: return "Express Flash PM1725b 12.8TB SFF";
        case PciSubDevice144DA822::SUBDEVICE_10281FF7: return "Express Flash PM1725b 1.6TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FF8: return "Express Flash PM1725b 3.2TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FF9: return "Express Flash PM1725b 6.4TB AIC";
        case PciSubDevice144DA822::SUBDEVICE_10281FFA: return "Express Flash PM1725b 12.8TB AIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA822_H
