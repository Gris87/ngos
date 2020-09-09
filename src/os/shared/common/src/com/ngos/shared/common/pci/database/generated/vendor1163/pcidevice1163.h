// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1163_PCIDEVICE1163_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1163_PCIDEVICE1163_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1163/pcisubdevice11632000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1163: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_2000 = 0x2000
};



inline const char8* enumToString(PciDevice1163 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1163::NONE:        return "NONE";
        case PciDevice1163::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1163::DEVICE_2000: return "DEVICE_2000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1163 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1163 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1163::DEVICE_0001: return "Verite 1000";
        case PciDevice1163::DEVICE_2000: return "Verite V2000/V2100/V2200";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1163 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1163::DEVICE_0001: return "Unknown device";
        case PciDevice1163::DEVICE_2000: return enumToHumanString((PciSubDevice11632000)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1163_PCIDEVICE1163_H
