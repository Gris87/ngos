// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1048_PCIDEVICE1048_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1048_PCIDEVICE1048_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1048/pcisubdevice10488901.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1048: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0C60 = 0x0C60,
    DEVICE_0D22 = 0x0D22,
    DEVICE_1000 = 0x1000,
    DEVICE_3000 = 0x3000,
    DEVICE_8901 = 0x8901
};



inline const char8* enumToString(PciDevice1048 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1048::NONE:        return "NONE";
        case PciDevice1048::DEVICE_0C60: return "DEVICE_0C60";
        case PciDevice1048::DEVICE_0D22: return "DEVICE_0D22";
        case PciDevice1048::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1048::DEVICE_3000: return "DEVICE_3000";
        case PciDevice1048::DEVICE_8901: return "DEVICE_8901";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1048 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1048 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1048::DEVICE_0C60: return "Gladiac MX";
        case PciDevice1048::DEVICE_0D22: return "Quadro4 900XGL [ELSA GLoria4 900XGL]";
        case PciDevice1048::DEVICE_1000: return "QuickStep 1000";
        case PciDevice1048::DEVICE_3000: return "QuickStep 3000";
        case PciDevice1048::DEVICE_8901: return "Gloria XL";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1048 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1048::DEVICE_0C60: return "Unknown device";
        case PciDevice1048::DEVICE_0D22: return "Unknown device";
        case PciDevice1048::DEVICE_1000: return "Unknown device";
        case PciDevice1048::DEVICE_3000: return "Unknown device";
        case PciDevice1048::DEVICE_8901: return enumToHumanString((PciSubDevice10488901)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1048_PCIDEVICE1048_H
