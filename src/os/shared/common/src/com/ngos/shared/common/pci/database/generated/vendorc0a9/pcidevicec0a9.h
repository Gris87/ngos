// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORC0A9_PCIDEVICEC0A9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORC0A9_PCIDEVICEC0A9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceC0A9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2263 = 0x2263,
    DEVICE_540A = 0x540A
};



inline const char8* enumToString(PciDeviceC0A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceC0A9::NONE:        return "NONE";
        case PciDeviceC0A9::DEVICE_2263: return "DEVICE_2263";
        case PciDeviceC0A9::DEVICE_540A: return "DEVICE_540A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceC0A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceC0A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceC0A9::DEVICE_2263: return "P1 NVMe PCIe SSD";
        case PciDeviceC0A9::DEVICE_540A: return "P2 NVMe PCIe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORC0A9_PCIDEVICEC0A9_H
