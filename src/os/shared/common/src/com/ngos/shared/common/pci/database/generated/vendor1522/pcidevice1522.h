// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1522/pcisubdevice15220100.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1522/pcisubdevice15224000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1522: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_4000 = 0x4000
};



inline const char8* enumToString(PciDevice1522 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1522::NONE:        return "NONE";
        case PciDevice1522::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1522::DEVICE_4000: return "DEVICE_4000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1522 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1522 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1522::DEVICE_0100: return "PCI <-> IOBus Bridge";
        case PciDevice1522::DEVICE_4000: return "PCI Express UART";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1522 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1522::DEVICE_0100: return enumToHumanString((PciSubDevice15220100)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1522::DEVICE_4000: return enumToHumanString((PciSubDevice15224000)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCIDEVICE1522_H
