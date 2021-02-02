// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCIDEVICE1317_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCIDEVICE1317_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1317/pcisubdevice13170985.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1317/pcisubdevice13171985.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1317/pcisubdevice13178201.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1317: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0981 = 0x0981,
    DEVICE_0985 = 0x0985,
    DEVICE_1985 = 0x1985,
    DEVICE_2850 = 0x2850,
    DEVICE_5120 = 0x5120,
    DEVICE_8201 = 0x8201,
    DEVICE_8211 = 0x8211,
    DEVICE_9511 = 0x9511
};



inline const char8* enumToString(PciDevice1317 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1317::NONE:        return "NONE";
        case PciDevice1317::DEVICE_0981: return "DEVICE_0981";
        case PciDevice1317::DEVICE_0985: return "DEVICE_0985";
        case PciDevice1317::DEVICE_1985: return "DEVICE_1985";
        case PciDevice1317::DEVICE_2850: return "DEVICE_2850";
        case PciDevice1317::DEVICE_5120: return "DEVICE_5120";
        case PciDevice1317::DEVICE_8201: return "DEVICE_8201";
        case PciDevice1317::DEVICE_8211: return "DEVICE_8211";
        case PciDevice1317::DEVICE_9511: return "DEVICE_9511";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1317 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1317 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1317::DEVICE_0981: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice1317::DEVICE_0985: return "NC100 Network Everywhere Fast Ethernet 10/100";
        case PciDevice1317::DEVICE_1985: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice1317::DEVICE_2850: return "HSP MicroModem 56";
        case PciDevice1317::DEVICE_5120: return "ADM5120 OpenGate System-on-Chip";
        case PciDevice1317::DEVICE_8201: return "ADM8211 802.11b Wireless Interface";
        case PciDevice1317::DEVICE_8211: return "ADM8211 802.11b Wireless Interface";
        case PciDevice1317::DEVICE_9511: return "21x4x DEC-Tulip compatible 10/100 Ethernet";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1317 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1317::DEVICE_0981: return "Unknown device";
        case PciDevice1317::DEVICE_0985: return enumToHumanString((PciSubDevice13170985)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1317::DEVICE_1985: return enumToHumanString((PciSubDevice13171985)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1317::DEVICE_2850: return "Unknown device";
        case PciDevice1317::DEVICE_5120: return "Unknown device";
        case PciDevice1317::DEVICE_8201: return enumToHumanString((PciSubDevice13178201)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1317::DEVICE_8211: return "Unknown device";
        case PciDevice1317::DEVICE_9511: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1317_PCIDEVICE1317_H
