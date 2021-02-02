// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b4/pcisubdevice10b41b1d.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B4: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1B1D = 0x1B1D
};



inline const char8* enumToString(PciDevice10B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B4::NONE:        return "NONE";
        case PciDevice10B4::DEVICE_1B1D: return "DEVICE_1B1D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B4::DEVICE_1B1D: return "Velocity 128 3D";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10B4 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B4::DEVICE_1B1D: return enumToHumanString((PciSubDevice10B41B1D)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H
