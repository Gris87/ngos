// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16ae/pcisubdevice16ae1141.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16AE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_000A = 0x000A,
    DEVICE_1141 = 0x1141,
    DEVICE_1841 = 0x1841
};



inline const char8* enumToString(PciDevice16AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16AE::NONE:        return "NONE";
        case PciDevice16AE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice16AE::DEVICE_000A: return "DEVICE_000A";
        case PciDevice16AE::DEVICE_1141: return "DEVICE_1141";
        case PciDevice16AE::DEVICE_1841: return "DEVICE_1841";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16AE::DEVICE_0001: return "SafeXcel 1140";
        case PciDevice16AE::DEVICE_000A: return "SafeXcel 1841";
        case PciDevice16AE::DEVICE_1141: return "SafeXcel 1141";
        case PciDevice16AE::DEVICE_1841: return "SafeXcel 1842";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice16AE device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16AE::DEVICE_0001: return "Unknown device";
        case PciDevice16AE::DEVICE_000A: return "Unknown device";
        case PciDevice16AE::DEVICE_1141: return enumToHumanString((PciSubDevice16AE1141)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice16AE::DEVICE_1841: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H
