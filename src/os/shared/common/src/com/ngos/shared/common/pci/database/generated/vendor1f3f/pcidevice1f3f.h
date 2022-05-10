// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCIDEVICE1F3F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCIDEVICE1F3F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f2100.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f2200.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9004.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9020.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9030.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9031.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1f3f/pcisubdevice1f3f9032.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1F3F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2100 = 0x2100,
    DEVICE_2200 = 0x2200,
    DEVICE_9001 = 0x9001,
    DEVICE_9002 = 0x9002,
    DEVICE_9003 = 0x9003,
    DEVICE_9004 = 0x9004,
    DEVICE_9008 = 0x9008,
    DEVICE_9009 = 0x9009,
    DEVICE_9010 = 0x9010,
    DEVICE_9020 = 0x9020,
    DEVICE_9030 = 0x9030,
    DEVICE_9031 = 0x9031,
    DEVICE_9032 = 0x9032
};



inline const char8* enumToString(PciDevice1F3F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F3F::NONE:        return "NONE";
        case PciDevice1F3F::DEVICE_2100: return "DEVICE_2100";
        case PciDevice1F3F::DEVICE_2200: return "DEVICE_2200";
        case PciDevice1F3F::DEVICE_9001: return "DEVICE_9001";
        case PciDevice1F3F::DEVICE_9002: return "DEVICE_9002";
        case PciDevice1F3F::DEVICE_9003: return "DEVICE_9003";
        case PciDevice1F3F::DEVICE_9004: return "DEVICE_9004";
        case PciDevice1F3F::DEVICE_9008: return "DEVICE_9008";
        case PciDevice1F3F::DEVICE_9009: return "DEVICE_9009";
        case PciDevice1F3F::DEVICE_9010: return "DEVICE_9010";
        case PciDevice1F3F::DEVICE_9020: return "DEVICE_9020";
        case PciDevice1F3F::DEVICE_9030: return "DEVICE_9030";
        case PciDevice1F3F::DEVICE_9031: return "DEVICE_9031";
        case PciDevice1F3F::DEVICE_9032: return "DEVICE_9032";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1F3F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1F3F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F3F::DEVICE_2100: return "3SRAID SAS/SATA HBA";
        case PciDevice1F3F::DEVICE_2200: return "3SRAID RAID controller";
        case PciDevice1F3F::DEVICE_9001: return "Ethernet VF";
        case PciDevice1F3F::DEVICE_9002: return "Ethernet VF Hyper-V";
        case PciDevice1F3F::DEVICE_9003: return "Ethernet SDI VF";
        case PciDevice1F3F::DEVICE_9004: return "Ethernet SDI VF Hyper-V";
        case PciDevice1F3F::DEVICE_9008: return "3SFC VF";
        case PciDevice1F3F::DEVICE_9009: return "3SFC VF Hyper-V";
        case PciDevice1F3F::DEVICE_9010: return "3SFC FC Controller";
        case PciDevice1F3F::DEVICE_9020: return "Ethernet Network Adapter";
        case PciDevice1F3F::DEVICE_9030: return "IPU";
        case PciDevice1F3F::DEVICE_9031: return "SDI5.0";
        case PciDevice1F3F::DEVICE_9032: return "SDI5.1";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1F3F device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1F3F::DEVICE_2100: return enumToHumanString((PciSubDevice1F3F2100)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_2200: return enumToHumanString((PciSubDevice1F3F2200)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9001: return enumToHumanString((PciSubDevice1F3F9001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9002: return enumToHumanString((PciSubDevice1F3F9002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9003: return enumToHumanString((PciSubDevice1F3F9003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9004: return enumToHumanString((PciSubDevice1F3F9004)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9008: return enumToHumanString((PciSubDevice1F3F9008)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9009: return enumToHumanString((PciSubDevice1F3F9009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9010: return enumToHumanString((PciSubDevice1F3F9010)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9020: return enumToHumanString((PciSubDevice1F3F9020)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9030: return enumToHumanString((PciSubDevice1F3F9030)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9031: return enumToHumanString((PciSubDevice1F3F9031)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1F3F::DEVICE_9032: return enumToHumanString((PciSubDevice1F3F9032)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCIDEVICE1F3F_H
