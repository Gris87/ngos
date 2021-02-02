// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12be/pcisubdevice12be3042.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12BE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3041 = 0x3041,
    DEVICE_3042 = 0x3042
};



inline const char8* enumToString(PciDevice12BE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12BE::NONE:        return "NONE";
        case PciDevice12BE::DEVICE_3041: return "DEVICE_3041";
        case PciDevice12BE::DEVICE_3042: return "DEVICE_3042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12BE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12BE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12BE::DEVICE_3041: return "AN3041Q CO-MEM";
        case PciDevice12BE::DEVICE_3042: return "AN3042Q CO-MEM Lite";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12BE device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12BE::DEVICE_3041: return "Unknown device";
        case PciDevice12BE::DEVICE_3042: return enumToHumanString((PciSubDevice12BE3042)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H
