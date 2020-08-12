// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9D32_PCIDEVICE9D32_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9D32_PCIDEVICE9D32_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9D32: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_1001 = 0x1001,
    DEVICE_1201 = 0x1201,
    DEVICE_1202 = 0x1202,
    DEVICE_1203 = 0x1203,
    DEVICE_1204 = 0x1204
};



inline const char8* enumToString(PciDevice9D32 device9D32) // TEST: NO
{
    // COMMON_LT((" | device9D32 = %u", device9D32)); // Commented to avoid bad looking logs



    switch (device9D32)
    {
        case PciDevice9D32::DEVICE_0000: return "DEVICE_0000";
        case PciDevice9D32::DEVICE_1001: return "DEVICE_1001";
        case PciDevice9D32::DEVICE_1201: return "DEVICE_1201";
        case PciDevice9D32::DEVICE_1202: return "DEVICE_1202";
        case PciDevice9D32::DEVICE_1203: return "DEVICE_1203";
        case PciDevice9D32::DEVICE_1204: return "DEVICE_1204";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9D32 device9D32) // TEST: NO
{
    // COMMON_LT((" | device9D32 = %u", device9D32)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9D32, enumToString(device9D32));

    return res;
}



inline const char8* enumToHumanString(PciDevice9D32 device9D32) // TEST: NO
{
    // COMMON_LT((" | device9D32 = %u", device9D32)); // Commented to avoid bad looking logs



    switch (device9D32)
    {
        case PciDevice9D32::DEVICE_0000: return "STAR1000 PCIe NVMe SSD Controller";
        case PciDevice9D32::DEVICE_1001: return "STAR1000P PCIe NVMe SSD Controller";
        case PciDevice9D32::DEVICE_1201: return "STAR1200C NVMe SSD";
        case PciDevice9D32::DEVICE_1202: return "STAR1200I NVMe SSD";
        case PciDevice9D32::DEVICE_1203: return "STAR1200L NVMe SSD";
        case PciDevice9D32::DEVICE_1204: return "STAR1200E NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9D32_PCIDEVICE9D32_H
