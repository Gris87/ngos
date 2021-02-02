// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCIDEVICE1A78_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCIDEVICE1A78_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1a78/pcisubdevice1a780031.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A78: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0031 = 0x0031,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0042 = 0x0042,
    DEVICE_0050 = 0x0050
};



inline const char8* enumToString(PciDevice1A78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A78::NONE:        return "NONE";
        case PciDevice1A78::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1A78::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1A78::DEVICE_0041: return "DEVICE_0041";
        case PciDevice1A78::DEVICE_0042: return "DEVICE_0042";
        case PciDevice1A78::DEVICE_0050: return "DEVICE_0050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A78 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A78::DEVICE_0031: return "FlashMAX Drive";
        case PciDevice1A78::DEVICE_0040: return "FlashMAX II";
        case PciDevice1A78::DEVICE_0041: return "FlashMAX II";
        case PciDevice1A78::DEVICE_0042: return "FlashMAX II";
        case PciDevice1A78::DEVICE_0050: return "FlashMAX III";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1A78 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A78::DEVICE_0031: return enumToHumanString((PciSubDevice1A780031)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1A78::DEVICE_0040: return "Unknown device";
        case PciDevice1A78::DEVICE_0041: return "Unknown device";
        case PciDevice1A78::DEVICE_0042: return "Unknown device";
        case PciDevice1A78::DEVICE_0050: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A78_PCIDEVICE1A78_H
