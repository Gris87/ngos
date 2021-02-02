// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR173B_PCIDEVICE173B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR173B_PCIDEVICE173B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor173b/pcisubdevice173b03ea.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice173B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_03E8 = 0x03E8,
    DEVICE_03E9 = 0x03E9,
    DEVICE_03EA = 0x03EA,
    DEVICE_03EB = 0x03EB
};



inline const char8* enumToString(PciDevice173B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice173B::NONE:        return "NONE";
        case PciDevice173B::DEVICE_03E8: return "DEVICE_03E8";
        case PciDevice173B::DEVICE_03E9: return "DEVICE_03E9";
        case PciDevice173B::DEVICE_03EA: return "DEVICE_03EA";
        case PciDevice173B::DEVICE_03EB: return "DEVICE_03EB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice173B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice173B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice173B::DEVICE_03E8: return "AC1000 Gigabit Ethernet";
        case PciDevice173B::DEVICE_03E9: return "AC1001 Gigabit Ethernet";
        case PciDevice173B::DEVICE_03EA: return "AC9100 Gigabit Ethernet";
        case PciDevice173B::DEVICE_03EB: return "AC1003 Gigabit Ethernet";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice173B device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice173B::DEVICE_03E8: return "Unknown device";
        case PciDevice173B::DEVICE_03E9: return "Unknown device";
        case PciDevice173B::DEVICE_03EA: return enumToHumanString((PciSubDevice173B03EA)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice173B::DEVICE_03EB: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR173B_PCIDEVICE173B_H
