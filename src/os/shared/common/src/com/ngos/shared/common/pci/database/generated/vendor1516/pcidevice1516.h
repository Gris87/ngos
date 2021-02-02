// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCIDEVICE1516_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCIDEVICE1516_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1516/pcisubdevice15160803.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1516: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0800 = 0x0800,
    DEVICE_0803 = 0x0803,
    DEVICE_0891 = 0x0891
};



inline const char8* enumToString(PciDevice1516 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1516::NONE:        return "NONE";
        case PciDevice1516::DEVICE_0800: return "DEVICE_0800";
        case PciDevice1516::DEVICE_0803: return "DEVICE_0803";
        case PciDevice1516::DEVICE_0891: return "DEVICE_0891";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1516 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1516 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1516::DEVICE_0800: return "MTD-8xx 100/10M Ethernet PCI Adapter";
        case PciDevice1516::DEVICE_0803: return "SURECOM EP-320X-S 100/10M Ethernet PCI Adapter";
        case PciDevice1516::DEVICE_0891: return "MTD-8xx 100/10M Ethernet PCI Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1516 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1516::DEVICE_0800: return "Unknown device";
        case PciDevice1516::DEVICE_0803: return enumToHumanString((PciSubDevice15160803)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1516::DEVICE_0891: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1516_PCIDEVICE1516_H
