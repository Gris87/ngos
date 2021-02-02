// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12b9/pcisubdevice12b91006.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12b9/pcisubdevice12b91007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12b9/pcisubdevice12b91008.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12B9: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008
};



inline const char8* enumToString(PciDevice12B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12B9::NONE:        return "NONE";
        case PciDevice12B9::DEVICE_1006: return "DEVICE_1006";
        case PciDevice12B9::DEVICE_1007: return "DEVICE_1007";
        case PciDevice12B9::DEVICE_1008: return "DEVICE_1008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12B9::DEVICE_1006: return "WinModem";
        case PciDevice12B9::DEVICE_1007: return "USR 56k Internal WinModem";
        case PciDevice12B9::DEVICE_1008: return "56K FaxModem Model 5610";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12B9 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12B9::DEVICE_1006: return enumToHumanString((PciSubDevice12B91006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12B9::DEVICE_1007: return enumToHumanString((PciSubDevice12B91007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12B9::DEVICE_1008: return enumToHumanString((PciSubDevice12B91008)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCIDEVICE12B9_H
