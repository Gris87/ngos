// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1966/pcisubdevice19661980.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1966: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1975 = 0x1975,
    DEVICE_1977 = 0x1977,
    DEVICE_1979 = 0x1979,
    DEVICE_1980 = 0x1980
};



inline const char8* enumToString(PciDevice1966 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1966::NONE:        return "NONE";
        case PciDevice1966::DEVICE_1975: return "DEVICE_1975";
        case PciDevice1966::DEVICE_1977: return "DEVICE_1977";
        case PciDevice1966::DEVICE_1979: return "DEVICE_1979";
        case PciDevice1966::DEVICE_1980: return "DEVICE_1980";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1966 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1966 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1966::DEVICE_1975: return "DVG64 family";
        case PciDevice1966::DEVICE_1977: return "DVG128 family";
        case PciDevice1966::DEVICE_1979: return "3DVG/UHD3";
        case PciDevice1966::DEVICE_1980: return "HDV2/UHD2";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1966 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1966::DEVICE_1975: return "Unknown device";
        case PciDevice1966::DEVICE_1977: return "Unknown device";
        case PciDevice1966::DEVICE_1979: return "Unknown device";
        case PciDevice1966::DEVICE_1980: return enumToHumanString((PciSubDevice19661980)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1966_PCIDEVICE1966_H
