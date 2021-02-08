// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCIDEVICE101E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCIDEVICE101E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101e/pcisubdevice101e1960.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101e/pcisubdevice101e9063.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice101E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0009 = 0x0009,
    DEVICE_1960 = 0x1960,
    DEVICE_9010 = 0x9010,
    DEVICE_9030 = 0x9030,
    DEVICE_9031 = 0x9031,
    DEVICE_9032 = 0x9032,
    DEVICE_9033 = 0x9033,
    DEVICE_9040 = 0x9040,
    DEVICE_9060 = 0x9060,
    DEVICE_9063 = 0x9063
};



inline const char8* enumToString(PciDevice101E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101E::NONE:        return "NONE";
        case PciDevice101E::DEVICE_0009: return "DEVICE_0009";
        case PciDevice101E::DEVICE_1960: return "DEVICE_1960";
        case PciDevice101E::DEVICE_9010: return "DEVICE_9010";
        case PciDevice101E::DEVICE_9030: return "DEVICE_9030";
        case PciDevice101E::DEVICE_9031: return "DEVICE_9031";
        case PciDevice101E::DEVICE_9032: return "DEVICE_9032";
        case PciDevice101E::DEVICE_9033: return "DEVICE_9033";
        case PciDevice101E::DEVICE_9040: return "DEVICE_9040";
        case PciDevice101E::DEVICE_9060: return "DEVICE_9060";
        case PciDevice101E::DEVICE_9063: return "DEVICE_9063";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice101E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice101E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101E::DEVICE_0009: return "MegaRAID 428 Ultra RAID Controller (rev 03)";
        case PciDevice101E::DEVICE_1960: return "MegaRAID";
        case PciDevice101E::DEVICE_9010: return "MegaRAID 428 Ultra RAID Controller";
        case PciDevice101E::DEVICE_9030: return "EIDE Controller";
        case PciDevice101E::DEVICE_9031: return "EIDE Controller";
        case PciDevice101E::DEVICE_9032: return "EIDE & SCSI Controller";
        case PciDevice101E::DEVICE_9033: return "SCSI Controller";
        case PciDevice101E::DEVICE_9040: return "Multimedia card";
        case PciDevice101E::DEVICE_9060: return "MegaRAID 434 Ultra GT RAID Controller";
        case PciDevice101E::DEVICE_9063: return "MegaRAC";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice101E device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101E::DEVICE_0009: return "Unknown device";
        case PciDevice101E::DEVICE_1960: return enumToHumanString((PciSubDevice101E1960)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice101E::DEVICE_9010: return "Unknown device";
        case PciDevice101E::DEVICE_9030: return "Unknown device";
        case PciDevice101E::DEVICE_9031: return "Unknown device";
        case PciDevice101E::DEVICE_9032: return "Unknown device";
        case PciDevice101E::DEVICE_9033: return "Unknown device";
        case PciDevice101E::DEVICE_9040: return "Unknown device";
        case PciDevice101E::DEVICE_9060: return "Unknown device";
        case PciDevice101E::DEVICE_9063: return enumToHumanString((PciSubDevice101E9063)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCIDEVICE101E_H
