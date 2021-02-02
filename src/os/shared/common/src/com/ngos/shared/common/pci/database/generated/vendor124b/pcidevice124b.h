// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor124b/pcisubdevice124b0040.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice124B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0040 = 0x0040
};



inline const char8* enumToString(PciDevice124B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice124B::NONE:        return "NONE";
        case PciDevice124B::DEVICE_0040: return "DEVICE_0040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice124B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice124B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice124B::DEVICE_0040: return "PCI-40A or cPCI-200 Quad IndustryPack carrier";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice124B device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice124B::DEVICE_0040: return enumToHumanString((PciSubDevice124B0040)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H
