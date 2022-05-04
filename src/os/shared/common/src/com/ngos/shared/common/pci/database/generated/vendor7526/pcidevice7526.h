// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7526_PCIDEVICE7526_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7526_PCIDEVICE7526_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice7526: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0082 = 0x0082,
    DEVICE_0083 = 0x0083
};



inline const char8* enumToString(PciDevice7526 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7526::NONE:        return "NONE";
        case PciDevice7526::DEVICE_0082: return "DEVICE_0082";
        case PciDevice7526::DEVICE_0083: return "DEVICE_0083";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice7526 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice7526 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7526::DEVICE_0082: return "HQ SSD 1TB";
        case PciDevice7526::DEVICE_0083: return "HQ SSD 2TB M.2 NVMe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7526_PCIDEVICE7526_H
