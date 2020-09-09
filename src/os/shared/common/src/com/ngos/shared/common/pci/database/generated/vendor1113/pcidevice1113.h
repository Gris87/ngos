// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCIDEVICE1113_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCIDEVICE1113_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1113/pcisubdevice11131211.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1113/pcisubdevice11131216.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1113/pcisubdevice11139211.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1113: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1211 = 0x1211,
    DEVICE_1216 = 0x1216,
    DEVICE_1217 = 0x1217,
    DEVICE_5105 = 0x5105,
    DEVICE_9211 = 0x9211,
    DEVICE_9511 = 0x9511,
    DEVICE_D301 = 0xD301,
    DEVICE_EC02 = 0xEC02,
    DEVICE_EE23 = 0xEE23
};



inline const char8* enumToString(PciDevice1113 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1113::NONE:        return "NONE";
        case PciDevice1113::DEVICE_1211: return "DEVICE_1211";
        case PciDevice1113::DEVICE_1216: return "DEVICE_1216";
        case PciDevice1113::DEVICE_1217: return "DEVICE_1217";
        case PciDevice1113::DEVICE_5105: return "DEVICE_5105";
        case PciDevice1113::DEVICE_9211: return "DEVICE_9211";
        case PciDevice1113::DEVICE_9511: return "DEVICE_9511";
        case PciDevice1113::DEVICE_D301: return "DEVICE_D301";
        case PciDevice1113::DEVICE_EC02: return "DEVICE_EC02";
        case PciDevice1113::DEVICE_EE23: return "DEVICE_EE23";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1113 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1113 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1113::DEVICE_1211: return "SMC2-1211TX";
        case PciDevice1113::DEVICE_1216: return "EN-1216 Ethernet Adapter";
        case PciDevice1113::DEVICE_1217: return "EN-1217 Ethernet Adapter";
        case PciDevice1113::DEVICE_5105: return "10Mbps Network card";
        case PciDevice1113::DEVICE_9211: return "EN-1207D Fast Ethernet Adapter";
        case PciDevice1113::DEVICE_9511: return "21x4x DEC-Tulip compatible Fast Ethernet";
        case PciDevice1113::DEVICE_D301: return "CPWNA100 (Philips wireless PCMCIA)";
        case PciDevice1113::DEVICE_EC02: return "SMC 1244TX v3";
        case PciDevice1113::DEVICE_EE23: return "SMCWPCIT-G 108Mbps Wireless PCI adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1113 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1113::DEVICE_1211: return enumToHumanString((PciSubDevice11131211)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1113::DEVICE_1216: return enumToHumanString((PciSubDevice11131216)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1113::DEVICE_1217: return "Unknown device";
        case PciDevice1113::DEVICE_5105: return "Unknown device";
        case PciDevice1113::DEVICE_9211: return enumToHumanString((PciSubDevice11139211)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1113::DEVICE_9511: return "Unknown device";
        case PciDevice1113::DEVICE_D301: return "Unknown device";
        case PciDevice1113::DEVICE_EC02: return "Unknown device";
        case PciDevice1113::DEVICE_EE23: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCIDEVICE1113_H
