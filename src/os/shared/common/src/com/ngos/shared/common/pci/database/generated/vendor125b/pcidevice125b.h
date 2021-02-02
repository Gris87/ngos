// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125b/pcisubdevice125b1400.h>
#include <com/ngos/shared/common/pci/database/generated/vendor125b/pcisubdevice125b9100.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice125B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1400 = 0x1400,
    DEVICE_9100 = 0x9100
};



inline const char8* enumToString(PciDevice125B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125B::NONE:        return "NONE";
        case PciDevice125B::DEVICE_1400: return "DEVICE_1400";
        case PciDevice125B::DEVICE_9100: return "DEVICE_9100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice125B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice125B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125B::DEVICE_1400: return "AX88141 Fast Ethernet Controller";
        case PciDevice125B::DEVICE_9100: return "AX99100 PCIe to Multi I/O Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice125B device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125B::DEVICE_1400: return enumToHumanString((PciSubDevice125B1400)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice125B::DEVICE_9100: return enumToHumanString((PciSubDevice125B9100)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCIDEVICE125B_H
