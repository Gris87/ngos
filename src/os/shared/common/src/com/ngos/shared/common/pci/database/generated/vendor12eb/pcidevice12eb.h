// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12eb/pcisubdevice12eb0001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12eb/pcisubdevice12eb0002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12eb/pcisubdevice12eb0003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12eb/pcisubdevice12eb8803.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12EB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_8803 = 0x8803
};



inline const char8* enumToString(PciDevice12EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12EB::NONE:        return "NONE";
        case PciDevice12EB::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12EB::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12EB::DEVICE_0003: return "DEVICE_0003";
        case PciDevice12EB::DEVICE_8803: return "DEVICE_8803";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12EB::DEVICE_0001: return "Vortex 1";
        case PciDevice12EB::DEVICE_0002: return "Vortex 2";
        case PciDevice12EB::DEVICE_0003: return "AU8810 Vortex Digital Audio Processor";
        case PciDevice12EB::DEVICE_8803: return "Vortex 56k Software Modem";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12EB device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12EB::DEVICE_0001: return enumToHumanString((PciSubDevice12EB0001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12EB::DEVICE_0002: return enumToHumanString((PciSubDevice12EB0002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12EB::DEVICE_0003: return enumToHumanString((PciSubDevice12EB0003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice12EB::DEVICE_8803: return enumToHumanString((PciSubDevice12EB8803)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCIDEVICE12EB_H
