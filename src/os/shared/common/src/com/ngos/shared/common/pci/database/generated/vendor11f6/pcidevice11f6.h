// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCIDEVICE11F6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCIDEVICE11F6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f6/pcisubdevice11f62011.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f6/pcisubdevice11f62201.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11F6: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0112 = 0x0112,
    DEVICE_0113 = 0x0113,
    DEVICE_1401 = 0x1401,
    DEVICE_2011 = 0x2011,
    DEVICE_2201 = 0x2201,
    DEVICE_9881 = 0x9881
};



inline const char8* enumToString(PciDevice11F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F6::NONE:        return "NONE";
        case PciDevice11F6::DEVICE_0112: return "DEVICE_0112";
        case PciDevice11F6::DEVICE_0113: return "DEVICE_0113";
        case PciDevice11F6::DEVICE_1401: return "DEVICE_1401";
        case PciDevice11F6::DEVICE_2011: return "DEVICE_2011";
        case PciDevice11F6::DEVICE_2201: return "DEVICE_2201";
        case PciDevice11F6::DEVICE_9881: return "DEVICE_9881";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F6::DEVICE_0112: return "ENet100VG4";
        case PciDevice11F6::DEVICE_0113: return "FreedomLine 100";
        case PciDevice11F6::DEVICE_1401: return "ReadyLink 2000";
        case PciDevice11F6::DEVICE_2011: return "RL100-ATX 10/100";
        case PciDevice11F6::DEVICE_2201: return "ReadyLink 100TX (Winbond W89C840)";
        case PciDevice11F6::DEVICE_9881: return "RL100TX Fast Ethernet";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11F6 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F6::DEVICE_0112: return "Unknown device";
        case PciDevice11F6::DEVICE_0113: return "Unknown device";
        case PciDevice11F6::DEVICE_1401: return "Unknown device";
        case PciDevice11F6::DEVICE_2011: return enumToHumanString((PciSubDevice11F62011)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11F6::DEVICE_2201: return enumToHumanString((PciSubDevice11F62201)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11F6::DEVICE_9881: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCIDEVICE11F6_H
