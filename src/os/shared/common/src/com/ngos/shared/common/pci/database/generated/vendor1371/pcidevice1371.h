// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCIDEVICE1371_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCIDEVICE1371_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1371/pcisubdevice1371434e.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1371: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_434E = 0x434E
};



inline const char8* enumToString(PciDevice1371 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1371::NONE:        return "NONE";
        case PciDevice1371::DEVICE_434E: return "DEVICE_434E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1371 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1371 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1371::DEVICE_434E: return "GigaCard Network Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1371 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1371::DEVICE_434E: return enumToHumanString((PciSubDevice1371434E)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1371_PCIDEVICE1371_H
