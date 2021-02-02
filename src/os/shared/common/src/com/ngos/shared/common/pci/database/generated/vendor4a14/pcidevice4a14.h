// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCIDEVICE4A14_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCIDEVICE4A14_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4a14/pcisubdevice4a145000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4A14: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5000 = 0x5000
};



inline const char8* enumToString(PciDevice4A14 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4A14::NONE:        return "NONE";
        case PciDevice4A14::DEVICE_5000: return "DEVICE_5000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4A14 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4A14 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4A14::DEVICE_5000: return "NV5000SC";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice4A14 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4A14::DEVICE_5000: return enumToHumanString((PciSubDevice4A145000)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4A14_PCIDEVICE4A14_H
