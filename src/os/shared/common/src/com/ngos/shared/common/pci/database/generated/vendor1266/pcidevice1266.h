// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1266/pcisubdevice12661910.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1266: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1910 = 0x1910
};



inline const char8* enumToString(PciDevice1266 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1266::NONE:        return "NONE";
        case PciDevice1266::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1266::DEVICE_1910: return "DEVICE_1910";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1266 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1266 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1266::DEVICE_0001: return "NE10/100 Adapter (bad_int82557B)";
        case PciDevice1266::DEVICE_1910: return "NE2000Plus (RT8029) Ethernet Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1266 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1266::DEVICE_0001: return "Unknown device";
        case PciDevice1266::DEVICE_1910: return enumToHumanString((PciSubDevice12661910)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1266_PCIDEVICE1266_H
