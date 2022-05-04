// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da802.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da804.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da808.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da80a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da820.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da821.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da822.h>
#include <com/ngos/shared/common/pci/database/generated/vendor144d/pcisubdevice144da824.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice144D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1600 = 0x1600,
    DEVICE_A544 = 0xA544,
    DEVICE_A800 = 0xA800,
    DEVICE_A802 = 0xA802,
    DEVICE_A804 = 0xA804,
    DEVICE_A808 = 0xA808,
    DEVICE_A809 = 0xA809,
    DEVICE_A80A = 0xA80A,
    DEVICE_A820 = 0xA820,
    DEVICE_A821 = 0xA821,
    DEVICE_A822 = 0xA822,
    DEVICE_A824 = 0xA824,
    DEVICE_A825 = 0xA825,
    DEVICE_A826 = 0xA826,
    DEVICE_ECEC = 0xECEC
};



inline const char8* enumToString(PciDevice144D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice144D::NONE:        return "NONE";
        case PciDevice144D::DEVICE_1600: return "DEVICE_1600";
        case PciDevice144D::DEVICE_A544: return "DEVICE_A544";
        case PciDevice144D::DEVICE_A800: return "DEVICE_A800";
        case PciDevice144D::DEVICE_A802: return "DEVICE_A802";
        case PciDevice144D::DEVICE_A804: return "DEVICE_A804";
        case PciDevice144D::DEVICE_A808: return "DEVICE_A808";
        case PciDevice144D::DEVICE_A809: return "DEVICE_A809";
        case PciDevice144D::DEVICE_A80A: return "DEVICE_A80A";
        case PciDevice144D::DEVICE_A820: return "DEVICE_A820";
        case PciDevice144D::DEVICE_A821: return "DEVICE_A821";
        case PciDevice144D::DEVICE_A822: return "DEVICE_A822";
        case PciDevice144D::DEVICE_A824: return "DEVICE_A824";
        case PciDevice144D::DEVICE_A825: return "DEVICE_A825";
        case PciDevice144D::DEVICE_A826: return "DEVICE_A826";
        case PciDevice144D::DEVICE_ECEC: return "DEVICE_ECEC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice144D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice144D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice144D::DEVICE_1600: return "Apple PCIe SSD";
        case PciDevice144D::DEVICE_A544: return "Exynos 8890 PCIe Root Complex";
        case PciDevice144D::DEVICE_A800: return "XP941 PCIe SSD";
        case PciDevice144D::DEVICE_A802: return "NVMe SSD Controller SM951/PM951";
        case PciDevice144D::DEVICE_A804: return "NVMe SSD Controller SM961/PM961/SM963";
        case PciDevice144D::DEVICE_A808: return "NVMe SSD Controller SM981/PM981/PM983";
        case PciDevice144D::DEVICE_A809: return "NVMe SSD Controller 980";
        case PciDevice144D::DEVICE_A80A: return "NVMe SSD Controller PM9A1/PM9A3/980PRO";
        case PciDevice144D::DEVICE_A820: return "NVMe SSD Controller 171X";
        case PciDevice144D::DEVICE_A821: return "NVMe SSD Controller 172X";
        case PciDevice144D::DEVICE_A822: return "NVMe SSD Controller 172Xa/172Xb";
        case PciDevice144D::DEVICE_A824: return "NVMe SSD Controller PM173X";
        case PciDevice144D::DEVICE_A825: return "NVMe SSD Controller PM173Xa";
        case PciDevice144D::DEVICE_A826: return "NVMe SSD Controller PM174X";
        case PciDevice144D::DEVICE_ECEC: return "Exynos 8895 PCIe Root Complex";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice144D device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice144D::DEVICE_1600: return "Unknown device";
        case PciDevice144D::DEVICE_A544: return "Unknown device";
        case PciDevice144D::DEVICE_A800: return "Unknown device";
        case PciDevice144D::DEVICE_A802: return enumToHumanString((PciSubDevice144DA802)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A804: return enumToHumanString((PciSubDevice144DA804)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A808: return enumToHumanString((PciSubDevice144DA808)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A809: return "Unknown device";
        case PciDevice144D::DEVICE_A80A: return enumToHumanString((PciSubDevice144DA80A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A820: return enumToHumanString((PciSubDevice144DA820)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A821: return enumToHumanString((PciSubDevice144DA821)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A822: return enumToHumanString((PciSubDevice144DA822)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A824: return enumToHumanString((PciSubDevice144DA824)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice144D::DEVICE_A825: return "Unknown device";
        case PciDevice144D::DEVICE_A826: return "Unknown device";
        case PciDevice144D::DEVICE_ECEC: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCIDEVICE144D_H
