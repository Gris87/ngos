// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C5C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1283 = 0x1283,
    DEVICE_1284 = 0x1284,
    DEVICE_1285 = 0x1285,
    DEVICE_1327 = 0x1327,
    DEVICE_1504 = 0x1504
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
        case PciDevice1C5C::DEVICE_1504: return "DEVICE_1504";

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
        case PciDevice1C5C::DEVICE_1327: return "BC501 NVMe Solid State Drive 512GB";
        case PciDevice1C5C::DEVICE_1504: return "SC300 512GB M.2 2280 SATA Solid State Drive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5C_PCIDEVICE1C5C_H
