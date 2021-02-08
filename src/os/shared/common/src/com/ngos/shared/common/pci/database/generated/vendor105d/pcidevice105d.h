// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCIDEVICE105D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCIDEVICE105D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105d/pcisubdevice105d2339.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105d/pcisubdevice105d493d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105d/pcisubdevice105d5348.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice105D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2309 = 0x2309,
    DEVICE_2339 = 0x2339,
    DEVICE_493D = 0x493D,
    DEVICE_5348 = 0x5348
};



inline const char8* enumToString(PciDevice105D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105D::NONE:        return "NONE";
        case PciDevice105D::DEVICE_2309: return "DEVICE_2309";
        case PciDevice105D::DEVICE_2339: return "DEVICE_2339";
        case PciDevice105D::DEVICE_493D: return "DEVICE_493D";
        case PciDevice105D::DEVICE_5348: return "DEVICE_5348";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice105D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice105D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105D::DEVICE_2309: return "Imagine 128";
        case PciDevice105D::DEVICE_2339: return "Imagine 128-II";
        case PciDevice105D::DEVICE_493D: return "Imagine 128 T2R [Ticket to Ride]";
        case PciDevice105D::DEVICE_5348: return "Revolution 4";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice105D device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105D::DEVICE_2309: return "Unknown device";
        case PciDevice105D::DEVICE_2339: return enumToHumanString((PciSubDevice105D2339)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105D::DEVICE_493D: return enumToHumanString((PciSubDevice105D493D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105D::DEVICE_5348: return enumToHumanString((PciSubDevice105D5348)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105D_PCIDEVICE105D_H
