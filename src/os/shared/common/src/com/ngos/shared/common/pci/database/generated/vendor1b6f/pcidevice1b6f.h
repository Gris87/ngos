// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b6f/pcisubdevice1b6f7023.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b6f/pcisubdevice1b6f7052.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B6F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7023 = 0x7023,
    DEVICE_7052 = 0x7052
};



inline const char8* enumToString(PciDevice1B6F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B6F::NONE:        return "NONE";
        case PciDevice1B6F::DEVICE_7023: return "DEVICE_7023";
        case PciDevice1B6F::DEVICE_7052: return "DEVICE_7052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B6F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B6F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B6F::DEVICE_7023: return "EJ168 USB 3.0 Host Controller";
        case PciDevice1B6F::DEVICE_7052: return "EJ188/EJ198 USB 3.0 Host Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1B6F device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B6F::DEVICE_7023: return enumToHumanString((PciSubDevice1B6F7023)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B6F::DEVICE_7052: return enumToHumanString((PciSubDevice1B6F7052)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H
