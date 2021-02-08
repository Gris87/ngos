// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCIDEVICE11CB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCIDEVICE11CB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11cb/pcisubdevice11cb2000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11CB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2000 = 0x2000,
    DEVICE_4000 = 0x4000,
    DEVICE_8000 = 0x8000
};



inline const char8* enumToString(PciDevice11CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11CB::NONE:        return "NONE";
        case PciDevice11CB::DEVICE_2000: return "DEVICE_2000";
        case PciDevice11CB::DEVICE_4000: return "DEVICE_4000";
        case PciDevice11CB::DEVICE_8000: return "DEVICE_8000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11CB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11CB::DEVICE_2000: return "PCI_9050";
        case PciDevice11CB::DEVICE_4000: return "SUPI_1";
        case PciDevice11CB::DEVICE_8000: return "T225";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11CB device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11CB::DEVICE_2000: return enumToHumanString((PciSubDevice11CB2000)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11CB::DEVICE_4000: return "Unknown device";
        case PciDevice11CB::DEVICE_8000: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11CB_PCIDEVICE11CB_H
