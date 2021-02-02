// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCIDEVICE1242_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCIDEVICE1242_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1242/pcisubdevice12421560.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1242: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1560 = 0x1560,
    DEVICE_4643 = 0x4643,
    DEVICE_6562 = 0x6562,
    DEVICE_656A = 0x656A
};



inline const char8* enumToString(PciDevice1242 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1242::NONE:        return "NONE";
        case PciDevice1242::DEVICE_1560: return "DEVICE_1560";
        case PciDevice1242::DEVICE_4643: return "DEVICE_4643";
        case PciDevice1242::DEVICE_6562: return "DEVICE_6562";
        case PciDevice1242::DEVICE_656A: return "DEVICE_656A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1242 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1242 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1242::DEVICE_1560: return "JNIC-1560 PCI-X Fibre Channel Controller";
        case PciDevice1242::DEVICE_4643: return "FCI-1063 Fibre Channel Adapter";
        case PciDevice1242::DEVICE_6562: return "FCX2-6562 Dual Channel PCI-X Fibre Channel Adapter";
        case PciDevice1242::DEVICE_656A: return "FCX-6562 PCI-X Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1242 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1242::DEVICE_1560: return enumToHumanString((PciSubDevice12421560)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1242::DEVICE_4643: return "Unknown device";
        case PciDevice1242::DEVICE_6562: return "Unknown device";
        case PciDevice1242::DEVICE_656A: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1242_PCIDEVICE1242_H
