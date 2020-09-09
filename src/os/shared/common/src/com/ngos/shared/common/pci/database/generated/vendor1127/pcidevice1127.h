// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCIDEVICE1127_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCIDEVICE1127_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1127/pcisubdevice11270400.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1127: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200,
    DEVICE_0210 = 0x0210,
    DEVICE_0250 = 0x0250,
    DEVICE_0300 = 0x0300,
    DEVICE_0310 = 0x0310,
    DEVICE_0400 = 0x0400
};



inline const char8* enumToString(PciDevice1127 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1127::NONE:        return "NONE";
        case PciDevice1127::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1127::DEVICE_0210: return "DEVICE_0210";
        case PciDevice1127::DEVICE_0250: return "DEVICE_0250";
        case PciDevice1127::DEVICE_0300: return "DEVICE_0300";
        case PciDevice1127::DEVICE_0310: return "DEVICE_0310";
        case PciDevice1127::DEVICE_0400: return "DEVICE_0400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1127 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1127 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1127::DEVICE_0200: return "ForeRunner PCA-200 ATM";
        case PciDevice1127::DEVICE_0210: return "PCA-200PC";
        case PciDevice1127::DEVICE_0250: return "ATM";
        case PciDevice1127::DEVICE_0300: return "ForeRunner PCA-200EPC ATM";
        case PciDevice1127::DEVICE_0310: return "ATM";
        case PciDevice1127::DEVICE_0400: return "ForeRunnerHE ATM Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1127 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1127::DEVICE_0200: return "Unknown device";
        case PciDevice1127::DEVICE_0210: return "Unknown device";
        case PciDevice1127::DEVICE_0250: return "Unknown device";
        case PciDevice1127::DEVICE_0300: return "Unknown device";
        case PciDevice1127::DEVICE_0310: return "Unknown device";
        case PciDevice1127::DEVICE_0400: return enumToHumanString((PciSubDevice11270400)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1127_PCIDEVICE1127_H
