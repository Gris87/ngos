// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCIDEVICE1657_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCIDEVICE1657_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1657/pcisubdevice16570013.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1657/pcisubdevice16570014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1657/pcisubdevice16570017.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1657/pcisubdevice16570022.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1657: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0017 = 0x0017,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0646 = 0x0646
};



inline const char8* enumToString(PciDevice1657 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1657::NONE:        return "NONE";
        case PciDevice1657::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1657::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1657::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1657::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1657::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1657::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1657::DEVICE_0646: return "DEVICE_0646";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1657 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1657 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1657::DEVICE_0013: return "425/825/42B/82B 4Gbps/8Gbps PCIe dual port FC HBA";
        case PciDevice1657::DEVICE_0014: return "1010/1020/1007/1741 10Gbps CNA";
        case PciDevice1657::DEVICE_0017: return "415/815/41B/81B 4Gbps/8Gbps PCIe single port FC HBA";
        case PciDevice1657::DEVICE_0021: return "804 8Gbps FC HBA for HP Bladesystem c-class";
        case PciDevice1657::DEVICE_0022: return "BR-1860 Fabric Adapter";
        case PciDevice1657::DEVICE_0023: return "1867/1869 16Gbps FC HBA";
        case PciDevice1657::DEVICE_0646: return "400 4Gbps PCIe FC HBA";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1657 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1657::DEVICE_0013: return enumToHumanString((PciSubDevice16570013)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1657::DEVICE_0014: return enumToHumanString((PciSubDevice16570014)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1657::DEVICE_0017: return enumToHumanString((PciSubDevice16570017)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1657::DEVICE_0021: return "Unknown device";
        case PciDevice1657::DEVICE_0022: return enumToHumanString((PciSubDevice16570022)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1657::DEVICE_0023: return "Unknown device";
        case PciDevice1657::DEVICE_0646: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCIDEVICE1657_H
