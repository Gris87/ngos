// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F03_PCIDEVICE1F03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F03_PCIDEVICE1F03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1F03: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1202 = 0x1202,
    DEVICE_2262 = 0x2262,
    DEVICE_2263 = 0x2263,
    DEVICE_5216 = 0x5216,
    DEVICE_5220 = 0x5220,
    DEVICE_5236 = 0x5236,
    DEVICE_5636 = 0x5636
};



inline const char8* enumToString(PciDevice1F03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F03::NONE:        return "NONE";
        case PciDevice1F03::DEVICE_1202: return "DEVICE_1202";
        case PciDevice1F03::DEVICE_2262: return "DEVICE_2262";
        case PciDevice1F03::DEVICE_2263: return "DEVICE_2263";
        case PciDevice1F03::DEVICE_5216: return "DEVICE_5216";
        case PciDevice1F03::DEVICE_5220: return "DEVICE_5220";
        case PciDevice1F03::DEVICE_5236: return "DEVICE_5236";
        case PciDevice1F03::DEVICE_5636: return "DEVICE_5636";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1F03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1F03 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F03::DEVICE_1202: return "MAP1202-Based NVMe SSD";
        case PciDevice1F03::DEVICE_2262: return "SM2262EN-based OEM SSD";
        case PciDevice1F03::DEVICE_2263: return "SM2263XT-Base NVMe SSD";
        case PciDevice1F03::DEVICE_5216: return "IG5216-based NVMe SSD";
        case PciDevice1F03::DEVICE_5220: return "IG5220-Based NVMe SSD";
        case PciDevice1F03::DEVICE_5236: return "IG5236-Based NVMe SSD";
        case PciDevice1F03::DEVICE_5636: return "IG5636-Based NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F03_PCIDEVICE1F03_H
