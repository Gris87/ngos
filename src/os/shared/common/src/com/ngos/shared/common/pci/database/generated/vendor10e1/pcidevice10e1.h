// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10e1/pcisubdevice10e10391.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E1: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0391 = 0x0391,
    DEVICE_690C = 0x690C,
    DEVICE_DC29 = 0xDC29
};



inline const char8* enumToString(PciDevice10E1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E1::NONE:        return "NONE";
        case PciDevice10E1::DEVICE_0391: return "DEVICE_0391";
        case PciDevice10E1::DEVICE_690C: return "DEVICE_690C";
        case PciDevice10E1::DEVICE_DC29: return "DEVICE_DC29";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E1::DEVICE_0391: return "TRM-S1040";
        case PciDevice10E1::DEVICE_690C: return "DC-690c";
        case PciDevice10E1::DEVICE_DC29: return "DC-290";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10E1 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E1::DEVICE_0391: return enumToHumanString((PciSubDevice10E10391)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10E1::DEVICE_690C: return "Unknown device";
        case PciDevice10E1::DEVICE_DC29: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E1_PCIDEVICE10E1_H
