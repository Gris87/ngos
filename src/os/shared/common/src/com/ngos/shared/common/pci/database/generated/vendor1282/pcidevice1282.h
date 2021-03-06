// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1282_PCIDEVICE1282_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1282_PCIDEVICE1282_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1282/pcisubdevice12829102.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1282: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6585 = 0x6585,
    DEVICE_9009 = 0x9009,
    DEVICE_9100 = 0x9100,
    DEVICE_9102 = 0x9102,
    DEVICE_9132 = 0x9132
};



inline const char8* enumToString(PciDevice1282 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1282::NONE:        return "NONE";
        case PciDevice1282::DEVICE_6585: return "DEVICE_6585";
        case PciDevice1282::DEVICE_9009: return "DEVICE_9009";
        case PciDevice1282::DEVICE_9100: return "DEVICE_9100";
        case PciDevice1282::DEVICE_9102: return "DEVICE_9102";
        case PciDevice1282::DEVICE_9132: return "DEVICE_9132";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1282 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1282 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1282::DEVICE_6585: return "DM562P V90 Modem";
        case PciDevice1282::DEVICE_9009: return "DM9009 Ethernet Controller";
        case PciDevice1282::DEVICE_9100: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice1282::DEVICE_9102: return "DM9102 Fast Ethernet Controller";
        case PciDevice1282::DEVICE_9132: return "Ethernet 100/10 MBit";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1282 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1282::DEVICE_6585: return "Unknown device";
        case PciDevice1282::DEVICE_9009: return "Unknown device";
        case PciDevice1282::DEVICE_9100: return "Unknown device";
        case PciDevice1282::DEVICE_9102: return enumToHumanString((PciSubDevice12829102)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1282::DEVICE_9132: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1282_PCIDEVICE1282_H
