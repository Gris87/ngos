// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCIDEVICE1148_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCIDEVICE1148_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcisubdevice11484000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcisubdevice11484300.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcisubdevice11484320.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcisubdevice11489000.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1148/pcisubdevice11489e00.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1148: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4000 = 0x4000,
    DEVICE_4200 = 0x4200,
    DEVICE_4300 = 0x4300,
    DEVICE_4320 = 0x4320,
    DEVICE_4400 = 0x4400,
    DEVICE_4500 = 0x4500,
    DEVICE_9000 = 0x9000,
    DEVICE_9843 = 0x9843,
    DEVICE_9E00 = 0x9E00,
    DEVICE_9E01 = 0x9E01
};



inline const char8* enumToString(PciDevice1148 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1148::NONE:        return "NONE";
        case PciDevice1148::DEVICE_4000: return "DEVICE_4000";
        case PciDevice1148::DEVICE_4200: return "DEVICE_4200";
        case PciDevice1148::DEVICE_4300: return "DEVICE_4300";
        case PciDevice1148::DEVICE_4320: return "DEVICE_4320";
        case PciDevice1148::DEVICE_4400: return "DEVICE_4400";
        case PciDevice1148::DEVICE_4500: return "DEVICE_4500";
        case PciDevice1148::DEVICE_9000: return "DEVICE_9000";
        case PciDevice1148::DEVICE_9843: return "DEVICE_9843";
        case PciDevice1148::DEVICE_9E00: return "DEVICE_9E00";
        case PciDevice1148::DEVICE_9E01: return "DEVICE_9E01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1148 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1148 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1148::DEVICE_4000: return "FDDI Adapter";
        case PciDevice1148::DEVICE_4200: return "Token Ring adapter";
        case PciDevice1148::DEVICE_4300: return "SK-9872 Gigabit Ethernet Server Adapter (SK-NET GE-ZX dual link)";
        case PciDevice1148::DEVICE_4320: return "SK-98xx V2.0 Gigabit Ethernet Adapter [Marvell 88E8001]";
        case PciDevice1148::DEVICE_4400: return "SK-9Dxx Gigabit Ethernet Adapter";
        case PciDevice1148::DEVICE_4500: return "SK-9Mxx Gigabit Ethernet Adapter";
        case PciDevice1148::DEVICE_9000: return "SK-9Sxx Gigabit Ethernet Server Adapter PCI-X [Marvell 88E8022]";
        case PciDevice1148::DEVICE_9843: return "[Fujitsu] Gigabit Ethernet";
        case PciDevice1148::DEVICE_9E00: return "SK-9E21D 10/100/1000Base-T Adapter, Copper RJ-45";
        case PciDevice1148::DEVICE_9E01: return "SK-9E21M 10/100/1000Base-T Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1148 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1148::DEVICE_4000: return enumToHumanString((PciSubDevice11484000)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1148::DEVICE_4200: return "Unknown device";
        case PciDevice1148::DEVICE_4300: return enumToHumanString((PciSubDevice11484300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1148::DEVICE_4320: return enumToHumanString((PciSubDevice11484320)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1148::DEVICE_4400: return "Unknown device";
        case PciDevice1148::DEVICE_4500: return "Unknown device";
        case PciDevice1148::DEVICE_9000: return enumToHumanString((PciSubDevice11489000)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1148::DEVICE_9843: return "Unknown device";
        case PciDevice1148::DEVICE_9E00: return enumToHumanString((PciSubDevice11489E00)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1148::DEVICE_9E01: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCIDEVICE1148_H
