// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCIDEVICE1F2F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCIDEVICE1F2F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f2f/pcisubdevice1f2f1513.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1F2F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1513 = 0x1513
};



inline const char8* enumToString(PciDevice1F2F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F2F::NONE:        return "NONE";
        case PciDevice1F2F::DEVICE_1513: return "DEVICE_1513";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1F2F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1F2F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F2F::DEVICE_1513: return "DERA MENG NVMe Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1F2F device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F2F::DEVICE_1513: return enumToHumanString((PciSubDevice1F2F1513)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F2F_PCIDEVICE1F2F_H
