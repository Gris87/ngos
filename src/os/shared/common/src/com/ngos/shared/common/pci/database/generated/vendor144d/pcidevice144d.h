// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice144D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1600 = 0x1600,
    DEVICE_A800 = 0xA800,
    DEVICE_A802 = 0xA802,
    DEVICE_A804 = 0xA804,
    DEVICE_A808 = 0xA808,
    DEVICE_A820 = 0xA820,
    DEVICE_A821 = 0xA821,
    DEVICE_A822 = 0xA822,
    DEVICE_A824 = 0xA824
};



inline const char8* enumToString(PciDevice144D device144D) // TEST: NO
{
    // COMMON_LT((" | device144D = %u", device144D)); // Commented to avoid bad looking logs



    switch (device144D)
    {
        case PciDevice144D::NONE:        return "NONE";
        case PciDevice144D::DEVICE_1600: return "DEVICE_1600";
        case PciDevice144D::DEVICE_A800: return "DEVICE_A800";
        case PciDevice144D::DEVICE_A802: return "DEVICE_A802";
        case PciDevice144D::DEVICE_A804: return "DEVICE_A804";
        case PciDevice144D::DEVICE_A808: return "DEVICE_A808";
        case PciDevice144D::DEVICE_A820: return "DEVICE_A820";
        case PciDevice144D::DEVICE_A821: return "DEVICE_A821";
        case PciDevice144D::DEVICE_A822: return "DEVICE_A822";
        case PciDevice144D::DEVICE_A824: return "DEVICE_A824";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice144D device144D) // TEST: NO
{
    // COMMON_LT((" | device144D = %u", device144D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device144D, enumToString(device144D));

    return res;
}



inline const char8* enumToHumanString(PciDevice144D device144D) // TEST: NO
{
    // COMMON_LT((" | device144D = %u", device144D)); // Commented to avoid bad looking logs



    switch (device144D)
    {
        case PciDevice144D::DEVICE_1600: return "Apple PCIe SSD";
        case PciDevice144D::DEVICE_A800: return "XP941 PCIe SSD";
        case PciDevice144D::DEVICE_A802: return "NVMe SSD Controller SM951/PM951";
        case PciDevice144D::DEVICE_A804: return "NVMe SSD Controller SM961/PM961";
        case PciDevice144D::DEVICE_A808: return "NVMe SSD Controller SM981/PM981/PM983";
        case PciDevice144D::DEVICE_A820: return "NVMe SSD Controller 171X";
        case PciDevice144D::DEVICE_A821: return "NVMe SSD Controller 172X";
        case PciDevice144D::DEVICE_A822: return "NVMe SSD Controller 172Xa/172Xb";
        case PciDevice144D::DEVICE_A824: return "NVMe SSD Controller PM173X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H
