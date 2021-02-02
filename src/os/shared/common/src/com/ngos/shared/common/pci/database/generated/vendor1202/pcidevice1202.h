// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1202/pcisubdevice12024300.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1202: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4300 = 0x4300
};



inline const char8* enumToString(PciDevice1202 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1202::NONE:        return "NONE";
        case PciDevice1202::DEVICE_4300: return "DEVICE_4300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1202 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1202 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1202::DEVICE_4300: return "Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1202 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1202::DEVICE_4300: return enumToHumanString((PciSubDevice12024300)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H
