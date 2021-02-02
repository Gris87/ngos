// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCIDEVICE167B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCIDEVICE167B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor167b/pcisubdevice167b2102.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice167B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2102 = 0x2102,
    DEVICE_2116 = 0x2116
};



inline const char8* enumToString(PciDevice167B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice167B::NONE:        return "NONE";
        case PciDevice167B::DEVICE_2102: return "DEVICE_2102";
        case PciDevice167B::DEVICE_2116: return "DEVICE_2116";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice167B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice167B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice167B::DEVICE_2102: return "ZyDAS ZD1202";
        case PciDevice167B::DEVICE_2116: return "ZD1212B Wireless Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice167B device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice167B::DEVICE_2102: return enumToHumanString((PciSubDevice167B2102)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice167B::DEVICE_2116: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167B_PCIDEVICE167B_H
