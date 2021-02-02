// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCIDEVICE1283_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCIDEVICE1283_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1283/pcisubdevice12838211.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1283/pcisubdevice12838212.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1283/pcisubdevice12838213.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1283/pcisubdevice12838892.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1283: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_673A = 0x673A,
    DEVICE_8152 = 0x8152,
    DEVICE_8211 = 0x8211,
    DEVICE_8212 = 0x8212,
    DEVICE_8213 = 0x8213,
    DEVICE_8330 = 0x8330,
    DEVICE_8872 = 0x8872,
    DEVICE_8888 = 0x8888,
    DEVICE_8889 = 0x8889,
    DEVICE_8892 = 0x8892,
    DEVICE_8893 = 0x8893,
    DEVICE_E886 = 0xE886
};



inline const char8* enumToString(PciDevice1283 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1283::NONE:        return "NONE";
        case PciDevice1283::DEVICE_673A: return "DEVICE_673A";
        case PciDevice1283::DEVICE_8152: return "DEVICE_8152";
        case PciDevice1283::DEVICE_8211: return "DEVICE_8211";
        case PciDevice1283::DEVICE_8212: return "DEVICE_8212";
        case PciDevice1283::DEVICE_8213: return "DEVICE_8213";
        case PciDevice1283::DEVICE_8330: return "DEVICE_8330";
        case PciDevice1283::DEVICE_8872: return "DEVICE_8872";
        case PciDevice1283::DEVICE_8888: return "DEVICE_8888";
        case PciDevice1283::DEVICE_8889: return "DEVICE_8889";
        case PciDevice1283::DEVICE_8892: return "DEVICE_8892";
        case PciDevice1283::DEVICE_8893: return "DEVICE_8893";
        case PciDevice1283::DEVICE_E886: return "DEVICE_E886";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1283 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1283 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1283::DEVICE_673A: return "IT8330G";
        case PciDevice1283::DEVICE_8152: return "IT8152F/G Advanced RISC-to-PCI Companion Chip";
        case PciDevice1283::DEVICE_8211: return "ITE 8211F Single Channel UDMA 133";
        case PciDevice1283::DEVICE_8212: return "IT8212 Dual channel ATA RAID controller";
        case PciDevice1283::DEVICE_8213: return "IT8213 IDE Controller";
        case PciDevice1283::DEVICE_8330: return "IT8330G";
        case PciDevice1283::DEVICE_8872: return "IT887xF PCI to ISA I/O chip with SMB, GPIO, Serial or Parallel Port";
        case PciDevice1283::DEVICE_8888: return "IT8888F/G PCI to ISA Bridge with SMB [Golden Gate]";
        case PciDevice1283::DEVICE_8889: return "IT8889F PCI to ISA Bridge";
        case PciDevice1283::DEVICE_8892: return "IT8892E PCIe to PCI Bridge";
        case PciDevice1283::DEVICE_8893: return "IT8893E PCIe to PCI Bridge";
        case PciDevice1283::DEVICE_E886: return "IT8330G";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1283 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1283::DEVICE_673A: return "Unknown device";
        case PciDevice1283::DEVICE_8152: return "Unknown device";
        case PciDevice1283::DEVICE_8211: return enumToHumanString((PciSubDevice12838211)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1283::DEVICE_8212: return enumToHumanString((PciSubDevice12838212)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1283::DEVICE_8213: return enumToHumanString((PciSubDevice12838213)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1283::DEVICE_8330: return "Unknown device";
        case PciDevice1283::DEVICE_8872: return "Unknown device";
        case PciDevice1283::DEVICE_8888: return "Unknown device";
        case PciDevice1283::DEVICE_8889: return "Unknown device";
        case PciDevice1283::DEVICE_8892: return enumToHumanString((PciSubDevice12838892)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1283::DEVICE_8893: return "Unknown device";
        case PciDevice1283::DEVICE_E886: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCIDEVICE1283_H
