// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCIDEVICE1E3B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCIDEVICE1E3B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e3b/pcisubdevice1e3b1098.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E3B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1098 = 0x1098
};



inline const char8* enumToString(PciDevice1E3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E3B::NONE:        return "NONE";
        case PciDevice1E3B::DEVICE_1098: return "DEVICE_1098";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E3B::DEVICE_1098: return "Haishen NVMe SSD";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1E3B device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E3B::DEVICE_1098: return enumToHumanString((PciSubDevice1E3B1098)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E3B_PCIDEVICE1E3B_H
