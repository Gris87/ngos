// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor18c3/pcisubdevice18c30720.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18C3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0720 = 0x0720
};



inline const char8* enumToString(PciDevice18C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18C3::NONE:        return "NONE";
        case PciDevice18C3::DEVICE_0720: return "DEVICE_0720";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18C3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18C3::DEVICE_0720: return "nGene PCI-Express Multimedia Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice18C3 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18C3::DEVICE_0720: return enumToHumanString((PciSubDevice18C30720)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18C3_PCIDEVICE18C3_H
