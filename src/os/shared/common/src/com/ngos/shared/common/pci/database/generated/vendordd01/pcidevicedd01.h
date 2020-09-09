// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCIDEVICEDD01_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCIDEVICEDD01_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendordd01/pcisubdevicedd010003.h>
#include <com/ngos/shared/common/pci/database/generated/vendordd01/pcisubdevicedd010007.h>
#include <com/ngos/shared/common/pci/database/generated/vendordd01/pcisubdevicedd010011.h>
#include <com/ngos/shared/common/pci/database/generated/vendordd01/pcisubdevicedd010201.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceDD01: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0011 = 0x0011,
    DEVICE_0201 = 0x0201
};



inline const char8* enumToString(PciDeviceDD01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDD01::NONE:        return "NONE";
        case PciDeviceDD01::DEVICE_0003: return "DEVICE_0003";
        case PciDeviceDD01::DEVICE_0006: return "DEVICE_0006";
        case PciDeviceDD01::DEVICE_0007: return "DEVICE_0007";
        case PciDeviceDD01::DEVICE_0011: return "DEVICE_0011";
        case PciDeviceDD01::DEVICE_0201: return "DEVICE_0201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceDD01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceDD01 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDD01::DEVICE_0003: return "Octopus DVB Adapter";
        case PciDeviceDD01::DEVICE_0006: return "Cine V7";
        case PciDeviceDD01::DEVICE_0007: return "Max";
        case PciDeviceDD01::DEVICE_0011: return "Octopus CI DVB Adapter";
        case PciDeviceDD01::DEVICE_0201: return "Resi DVB-C Modulator";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDeviceDD01 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDD01::DEVICE_0003: return enumToHumanString((PciSubDeviceDD010003)(subsystemVendorID << 16 | subDeviceId));
        case PciDeviceDD01::DEVICE_0006: return "Unknown device";
        case PciDeviceDD01::DEVICE_0007: return enumToHumanString((PciSubDeviceDD010007)(subsystemVendorID << 16 | subDeviceId));
        case PciDeviceDD01::DEVICE_0011: return enumToHumanString((PciSubDeviceDD010011)(subsystemVendorID << 16 | subDeviceId));
        case PciDeviceDD01::DEVICE_0201: return enumToHumanString((PciSubDeviceDD010201)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCIDEVICEDD01_H
