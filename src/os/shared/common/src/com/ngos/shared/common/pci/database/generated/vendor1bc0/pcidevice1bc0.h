// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BC0_PCIDEVICE1BC0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BC0_PCIDEVICE1BC0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BC0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1160 = 0x1160,
    DEVICE_1321 = 0x1321,
    DEVICE_1322 = 0x1322,
    DEVICE_2262 = 0x2262,
    DEVICE_5208 = 0x5208,
    DEVICE_5216 = 0x5216,
    DEVICE_5236 = 0x5236
};



inline const char8* enumToString(PciDevice1BC0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BC0::NONE:        return "NONE";
        case PciDevice1BC0::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1BC0::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1BC0::DEVICE_1160: return "DEVICE_1160";
        case PciDevice1BC0::DEVICE_1321: return "DEVICE_1321";
        case PciDevice1BC0::DEVICE_1322: return "DEVICE_1322";
        case PciDevice1BC0::DEVICE_2262: return "DEVICE_2262";
        case PciDevice1BC0::DEVICE_5208: return "DEVICE_5208";
        case PciDevice1BC0::DEVICE_5216: return "DEVICE_5216";
        case PciDevice1BC0::DEVICE_5236: return "DEVICE_5236";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BC0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BC0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BC0::DEVICE_1001: return "PCIe 3TG6-P Controller";
        case PciDevice1BC0::DEVICE_1002: return "PCIe 3TE6 Controller";
        case PciDevice1BC0::DEVICE_1160: return "PCIe 3TE2 Controller";
        case PciDevice1BC0::DEVICE_1321: return "PCIe 4TG-P Controller";
        case PciDevice1BC0::DEVICE_1322: return "PCIe 4TE Controller";
        case PciDevice1BC0::DEVICE_2262: return "PCIe 3TG3-P Controller";
        case PciDevice1BC0::DEVICE_5208: return "PCIe 3TE7 Controller";
        case PciDevice1BC0::DEVICE_5216: return "PCIe 3TE8 Controller";
        case PciDevice1BC0::DEVICE_5236: return "PCIe 4TG2-P Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BC0_PCIDEVICE1BC0_H
