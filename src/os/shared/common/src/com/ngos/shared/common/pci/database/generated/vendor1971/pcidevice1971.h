// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1971_PCIDEVICE1971_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1971_PCIDEVICE1971_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1971/pcisubdevice19711011.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1971: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1011 = 0x1011
};



inline const char8* enumToString(PciDevice1971 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1971::NONE:        return "NONE";
        case PciDevice1971::DEVICE_1011: return "DEVICE_1011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1971 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1971 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1971::DEVICE_1011: return "Physics Processing Unit [PhysX]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1971 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1971::DEVICE_1011: return enumToHumanString((PciSubDevice19711011)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1971_PCIDEVICE1971_H
