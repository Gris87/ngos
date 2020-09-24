// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30201.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30202.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30203.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30204.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30205.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1df3/pcisubdevice1df30206.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DF3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0201 = 0x0201,
    DEVICE_0202 = 0x0202,
    DEVICE_0203 = 0x0203,
    DEVICE_0204 = 0x0204,
    DEVICE_0205 = 0x0205,
    DEVICE_0206 = 0x0206
};



inline const char8* enumToString(PciDevice1DF3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DF3::NONE:        return "NONE";
        case PciDevice1DF3::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1DF3::DEVICE_0202: return "DEVICE_0202";
        case PciDevice1DF3::DEVICE_0203: return "DEVICE_0203";
        case PciDevice1DF3::DEVICE_0204: return "DEVICE_0204";
        case PciDevice1DF3::DEVICE_0205: return "DEVICE_0205";
        case PciDevice1DF3::DEVICE_0206: return "DEVICE_0206";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DF3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DF3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DF3::DEVICE_0201: return "ACE-NIC40 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0202: return "ACE-NIC50 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0203: return "ACE-NIC100 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0204: return "ACE-NIC-NID Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0205: return "ACE-NIC250 Programmable Network Accelerator";
        case PciDevice1DF3::DEVICE_0206: return "ACE-NIC200 Programmable Network Accelerator";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1DF3 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DF3::DEVICE_0201: return enumToHumanString((PciSubDevice1DF30201)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1DF3::DEVICE_0202: return enumToHumanString((PciSubDevice1DF30202)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1DF3::DEVICE_0203: return enumToHumanString((PciSubDevice1DF30203)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1DF3::DEVICE_0204: return enumToHumanString((PciSubDevice1DF30204)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1DF3::DEVICE_0205: return enumToHumanString((PciSubDevice1DF30205)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1DF3::DEVICE_0206: return enumToHumanString((PciSubDevice1DF30206)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DF3_PCIDEVICE1DF3_H
