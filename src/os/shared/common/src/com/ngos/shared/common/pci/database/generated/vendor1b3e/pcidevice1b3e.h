// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b3e/pcisubdevice1b3e1fa8.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B3E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1FA8 = 0x1FA8
};



inline const char8* enumToString(PciDevice1B3E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B3E::NONE:        return "NONE";
        case PciDevice1B3E::DEVICE_1FA8: return "DEVICE_1FA8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B3E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B3E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B3E::DEVICE_1FA8: return "BYNET BIC2SE/X";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1B3E device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B3E::DEVICE_1FA8: return enumToHumanString((PciSubDevice1B3E1FA8)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H
