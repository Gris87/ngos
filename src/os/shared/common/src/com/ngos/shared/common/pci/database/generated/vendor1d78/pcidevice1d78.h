// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCIDEVICE1D78_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCIDEVICE1D78_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1d78/pcisubdevice1d781512.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D78: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1512 = 0x1512
};



inline const char8* enumToString(PciDevice1D78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D78::NONE:        return "NONE";
        case PciDevice1D78::DEVICE_1512: return "DEVICE_1512";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D78::DEVICE_1512: return "TAI NVMe Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1D78 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D78::DEVICE_1512: return enumToHumanString((PciSubDevice1D781512)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCIDEVICE1D78_H
