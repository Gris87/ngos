// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4c53/pcisubdevice4c530000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4c53/pcisubdevice4c530001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4C53: bad_uint16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice4C53 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4C53::DEVICE_0000: return "DEVICE_0000";
        case PciDevice4C53::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4C53 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4C53 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4C53::DEVICE_0000: return "PLUSTEST device";
        case PciDevice4C53::DEVICE_0001: return "PLUSTEST-MM device";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice4C53 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4C53::DEVICE_0000: return enumToHumanString((PciSubDevice4C530000)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice4C53::DEVICE_0001: return enumToHumanString((PciSubDevice4C530001)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H
