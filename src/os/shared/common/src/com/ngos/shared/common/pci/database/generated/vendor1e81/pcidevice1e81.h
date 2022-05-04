// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCIDEVICE1E81_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCIDEVICE1E81_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e81/pcisubdevice1e811203.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E81: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1203 = 0x1203
};



inline const char8* enumToString(PciDevice1E81 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E81::NONE:        return "NONE";
        case PciDevice1E81::DEVICE_1203: return "DEVICE_1203";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E81 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E81 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E81::DEVICE_1203: return "NVMe SSD Controller UHXXXa series";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1E81 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E81::DEVICE_1203: return enumToHumanString((PciSubDevice1E811203)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCIDEVICE1E81_H
