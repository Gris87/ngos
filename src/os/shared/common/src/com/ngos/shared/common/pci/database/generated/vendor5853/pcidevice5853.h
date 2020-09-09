// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5853_PCIDEVICE5853_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5853_PCIDEVICE5853_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5853: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_C000 = 0xC000,
    DEVICE_C110 = 0xC110,
    DEVICE_C147 = 0xC147,
    DEVICE_C200 = 0xC200
};



inline const char8* enumToString(PciDevice5853 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5853::NONE:        return "NONE";
        case PciDevice5853::DEVICE_0001: return "DEVICE_0001";
        case PciDevice5853::DEVICE_C000: return "DEVICE_C000";
        case PciDevice5853::DEVICE_C110: return "DEVICE_C110";
        case PciDevice5853::DEVICE_C147: return "DEVICE_C147";
        case PciDevice5853::DEVICE_C200: return "DEVICE_C200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5853 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice5853 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5853::DEVICE_0001: return "Xen Platform Device";
        case PciDevice5853::DEVICE_C000: return "Citrix XenServer PCI Device for Windows Update";
        case PciDevice5853::DEVICE_C110: return "Virtualized HID";
        case PciDevice5853::DEVICE_C147: return "Virtualized Graphics Device";
        case PciDevice5853::DEVICE_C200: return "XCP-ng Project PCI Device for Windows Update";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5853_PCIDEVICE5853_H
