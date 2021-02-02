// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCIDEVICEE159_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCIDEVICEE159_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendore159/pcisubdevicee1590001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceE159: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDeviceE159 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE159::NONE:        return "NONE";
        case PciDeviceE159::DEVICE_0001: return "DEVICE_0001";
        case PciDeviceE159::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceE159 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceE159 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE159::DEVICE_0001: return "Tiger3XX Modem/ISDN interface";
        case PciDeviceE159::DEVICE_0002: return "Tiger100APC ISDN chipset";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDeviceE159 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE159::DEVICE_0001: return enumToHumanString((PciSubDeviceE1590001)(subsystemVendorID << 16 | subDeviceId));
        case PciDeviceE159::DEVICE_0002: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE159_PCIDEVICEE159_H
