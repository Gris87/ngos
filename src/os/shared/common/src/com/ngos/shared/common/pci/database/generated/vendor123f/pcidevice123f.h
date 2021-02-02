// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor123f/pcisubdevice123f8120.h>
#include <com/ngos/shared/common/pci/database/generated/vendor123f/pcisubdevice123f8888.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice123F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00E4 = 0x00E4,
    DEVICE_8120 = 0x8120,
    DEVICE_8888 = 0x8888
};



inline const char8* enumToString(PciDevice123F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice123F::NONE:        return "NONE";
        case PciDevice123F::DEVICE_00E4: return "DEVICE_00E4";
        case PciDevice123F::DEVICE_8120: return "DEVICE_8120";
        case PciDevice123F::DEVICE_8888: return "DEVICE_8888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice123F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice123F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice123F::DEVICE_00E4: return "MPEG";
        case PciDevice123F::DEVICE_8120: return "DVxplore Codec";
        case PciDevice123F::DEVICE_8888: return "Cinemaster C 3.0 DVD Decoder";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice123F device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice123F::DEVICE_00E4: return "Unknown device";
        case PciDevice123F::DEVICE_8120: return enumToHumanString((PciSubDevice123F8120)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice123F::DEVICE_8888: return enumToHumanString((PciSubDevice123F8888)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H
