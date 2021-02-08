// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCIDEVICE1137_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCIDEVICE1137_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370040.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370042.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370043.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370044.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370045.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice11370046.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice1137007a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1137/pcisubdevice113700cf.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1137: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0023 = 0x0023,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0043 = 0x0043,
    DEVICE_0044 = 0x0044,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_004E = 0x004E,
    DEVICE_0071 = 0x0071,
    DEVICE_007A = 0x007A,
    DEVICE_00CF = 0x00CF,
    DEVICE_023E = 0x023E
};



inline const char8* enumToString(PciDevice1137 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1137::NONE:        return "NONE";
        case PciDevice1137::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1137::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1137::DEVICE_0041: return "DEVICE_0041";
        case PciDevice1137::DEVICE_0042: return "DEVICE_0042";
        case PciDevice1137::DEVICE_0043: return "DEVICE_0043";
        case PciDevice1137::DEVICE_0044: return "DEVICE_0044";
        case PciDevice1137::DEVICE_0045: return "DEVICE_0045";
        case PciDevice1137::DEVICE_0046: return "DEVICE_0046";
        case PciDevice1137::DEVICE_004E: return "DEVICE_004E";
        case PciDevice1137::DEVICE_0071: return "DEVICE_0071";
        case PciDevice1137::DEVICE_007A: return "DEVICE_007A";
        case PciDevice1137::DEVICE_00CF: return "DEVICE_00CF";
        case PciDevice1137::DEVICE_023E: return "DEVICE_023E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1137 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1137 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1137::DEVICE_0023: return "VIC 81 PCIe Upstream Port";
        case PciDevice1137::DEVICE_0040: return "VIC PCIe Upstream Port";
        case PciDevice1137::DEVICE_0041: return "VIC PCIe Downstream Port";
        case PciDevice1137::DEVICE_0042: return "VIC Management Controller";
        case PciDevice1137::DEVICE_0043: return "VIC Ethernet NIC";
        case PciDevice1137::DEVICE_0044: return "VIC Ethernet NIC Dynamic";
        case PciDevice1137::DEVICE_0045: return "VIC FCoE HBA";
        case PciDevice1137::DEVICE_0046: return "VIC SCSI Controller";
        case PciDevice1137::DEVICE_004E: return "VIC 82 PCIe Upstream Port";
        case PciDevice1137::DEVICE_0071: return "VIC SR-IOV VF";
        case PciDevice1137::DEVICE_007A: return "VIC 1300 PCIe Upstream Port";
        case PciDevice1137::DEVICE_00CF: return "VIC Userspace NIC";
        case PciDevice1137::DEVICE_023E: return "1GigE I350 LOM";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1137 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1137::DEVICE_0023: return "Unknown device";
        case PciDevice1137::DEVICE_0040: return enumToHumanString((PciSubDevice11370040)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_0041: return "Unknown device";
        case PciDevice1137::DEVICE_0042: return enumToHumanString((PciSubDevice11370042)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_0043: return enumToHumanString((PciSubDevice11370043)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_0044: return enumToHumanString((PciSubDevice11370044)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_0045: return enumToHumanString((PciSubDevice11370045)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_0046: return enumToHumanString((PciSubDevice11370046)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_004E: return "Unknown device";
        case PciDevice1137::DEVICE_0071: return "Unknown device";
        case PciDevice1137::DEVICE_007A: return enumToHumanString((PciSubDevice1137007A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_00CF: return enumToHumanString((PciSubDevice113700CF)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1137::DEVICE_023E: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCIDEVICE1137_H
