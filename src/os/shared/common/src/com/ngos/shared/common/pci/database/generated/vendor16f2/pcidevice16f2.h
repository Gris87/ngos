// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor16f2/pcisubdevice16f20200.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16F2: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice16F2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16F2::NONE:        return "NONE";
        case PciDevice16F2::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16F2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16F2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16F2::DEVICE_0200: return "I/O board";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice16F2 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16F2::DEVICE_0200: return enumToHumanString((PciSubDevice16F20200)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H
