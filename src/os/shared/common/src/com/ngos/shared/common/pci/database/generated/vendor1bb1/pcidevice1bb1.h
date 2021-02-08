// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bb1/pcisubdevice1bb1005d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1bb1/pcisubdevice1bb10100.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BB1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_005D = 0x005D,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1BB1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BB1::NONE:        return "NONE";
        case PciDevice1BB1::DEVICE_005D: return "DEVICE_005D";
        case PciDevice1BB1::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BB1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BB1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BB1::DEVICE_005D: return "Nytro PCIe Flash Storage";
        case PciDevice1BB1::DEVICE_0100: return "Nytro Flash Storage";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1BB1 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BB1::DEVICE_005D: return enumToHumanString((PciSubDevice1BB1005D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1BB1::DEVICE_0100: return enumToHumanString((PciSubDevice1BB10100)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCIDEVICE1BB1_H
