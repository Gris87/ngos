// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C1_PCIDEVICE13C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C1_PCIDEVICE13C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13c1/pcisubdevice13c11001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13C1: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1010 = 0x1010
};



inline const char8* enumToString(PciDevice13C1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C1::NONE:        return "NONE";
        case PciDevice13C1::DEVICE_1000: return "DEVICE_1000";
        case PciDevice13C1::DEVICE_1001: return "DEVICE_1001";
        case PciDevice13C1::DEVICE_1002: return "DEVICE_1002";
        case PciDevice13C1::DEVICE_1003: return "DEVICE_1003";
        case PciDevice13C1::DEVICE_1004: return "DEVICE_1004";
        case PciDevice13C1::DEVICE_1005: return "DEVICE_1005";
        case PciDevice13C1::DEVICE_1010: return "DEVICE_1010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13C1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13C1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C1::DEVICE_1000: return "5xxx/6xxx-series PATA-RAID";
        case PciDevice13C1::DEVICE_1001: return "7xxx/8xxx-series PATA/SATA-RAID";
        case PciDevice13C1::DEVICE_1002: return "9xxx-series SATA-RAID";
        case PciDevice13C1::DEVICE_1003: return "9550SX SATA-II RAID PCI-X";
        case PciDevice13C1::DEVICE_1004: return "9650SE SATA-II RAID PCIe";
        case PciDevice13C1::DEVICE_1005: return "9690SA SAS/SATA-II RAID PCIe";
        case PciDevice13C1::DEVICE_1010: return "9750 SAS2/SATA-II RAID PCIe";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice13C1 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C1::DEVICE_1000: return "Unknown device";
        case PciDevice13C1::DEVICE_1001: return enumToHumanString((PciSubDevice13C11001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13C1::DEVICE_1002: return "Unknown device";
        case PciDevice13C1::DEVICE_1003: return "Unknown device";
        case PciDevice13C1::DEVICE_1004: return "Unknown device";
        case PciDevice13C1::DEVICE_1005: return "Unknown device";
        case PciDevice13C1::DEVICE_1010: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C1_PCIDEVICE13C1_H
