// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5c/pcisubdevice1c5c243b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5c/pcisubdevice1c5c2839.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5c/pcisubdevice1c5c2849.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C5C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1283 = 0x1283,
    DEVICE_1284 = 0x1284,
    DEVICE_1285 = 0x1285,
    DEVICE_1327 = 0x1327,
    DEVICE_1339 = 0x1339,
    DEVICE_1504 = 0x1504,
    DEVICE_1527 = 0x1527,
    DEVICE_174A = 0x174A,
    DEVICE_243B = 0x243B,
    DEVICE_2839 = 0x2839,
    DEVICE_2849 = 0x2849
};



inline const char8* enumToString(PciDevice1C5C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5C::NONE:        return "NONE";
        case PciDevice1C5C::DEVICE_1283: return "DEVICE_1283";
        case PciDevice1C5C::DEVICE_1284: return "DEVICE_1284";
        case PciDevice1C5C::DEVICE_1285: return "DEVICE_1285";
        case PciDevice1C5C::DEVICE_1327: return "DEVICE_1327";
        case PciDevice1C5C::DEVICE_1339: return "DEVICE_1339";
        case PciDevice1C5C::DEVICE_1504: return "DEVICE_1504";
        case PciDevice1C5C::DEVICE_1527: return "DEVICE_1527";
        case PciDevice1C5C::DEVICE_174A: return "DEVICE_174A";
        case PciDevice1C5C::DEVICE_243B: return "DEVICE_243B";
        case PciDevice1C5C::DEVICE_2839: return "DEVICE_2839";
        case PciDevice1C5C::DEVICE_2849: return "DEVICE_2849";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C5C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C5C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5C::DEVICE_1283: return "PC300 NVMe Solid State Drive 256GB";
        case PciDevice1C5C::DEVICE_1284: return "PC300 NVMe Solid State Drive 512GB";
        case PciDevice1C5C::DEVICE_1285: return "PC300 NVMe Solid State Drive 1TB";
        case PciDevice1C5C::DEVICE_1327: return "BC501 NVMe Solid State Drive";
        case PciDevice1C5C::DEVICE_1339: return "BC511";
        case PciDevice1C5C::DEVICE_1504: return "SC300 512GB M.2 2280 SATA Solid State Drive";
        case PciDevice1C5C::DEVICE_1527: return "PC401 NVMe Solid State Drive 256GB";
        case PciDevice1C5C::DEVICE_174A: return "Gold P31 SSD";
        case PciDevice1C5C::DEVICE_243B: return "PE6110 NVMe Solid State Drive";
        case PciDevice1C5C::DEVICE_2839: return "PE8000 Series NVMe Solid State Drive";
        case PciDevice1C5C::DEVICE_2849: return "PE81x0 U.2/3 NVMe Solid State Drive";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1C5C device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5C::DEVICE_1283: return "Unknown device";
        case PciDevice1C5C::DEVICE_1284: return "Unknown device";
        case PciDevice1C5C::DEVICE_1285: return "Unknown device";
        case PciDevice1C5C::DEVICE_1327: return "Unknown device";
        case PciDevice1C5C::DEVICE_1339: return "Unknown device";
        case PciDevice1C5C::DEVICE_1504: return "Unknown device";
        case PciDevice1C5C::DEVICE_1527: return "Unknown device";
        case PciDevice1C5C::DEVICE_174A: return "Unknown device";
        case PciDevice1C5C::DEVICE_243B: return enumToHumanString((PciSubDevice1C5C243B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1C5C::DEVICE_2839: return enumToHumanString((PciSubDevice1C5C2839)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1C5C::DEVICE_2849: return enumToHumanString((PciSubDevice1C5C2849)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H
