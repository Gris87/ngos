// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12ae/pcisubdevice12ae0001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12ae/pcisubdevice12ae0002.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12AE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_00FA = 0x00FA
};



inline const char8* enumToString(PciDevice12AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12AE::NONE:        return "NONE";
        case PciDevice12AE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12AE::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12AE::DEVICE_00FA: return "DEVICE_00FA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12AE::DEVICE_0001: return "AceNIC Gigabit Ethernet";
        case PciDevice12AE::DEVICE_0002: return "AceNIC Gigabit Ethernet (Copper)";
        case PciDevice12AE::DEVICE_00FA: return "Farallon PN9100-T Gigabit Ethernet";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12AE device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12AE::DEVICE_0001: return enumToHumanString((PciSubDevice12AE0001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12AE::DEVICE_0002: return enumToHumanString((PciSubDevice12AE0002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12AE::DEVICE_00FA: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCIDEVICE12AE_H
