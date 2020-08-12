// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4348_PCIDEVICE4348_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4348_PCIDEVICE4348_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4348: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2273 = 0x2273,
    DEVICE_3253 = 0x3253,
    DEVICE_3453 = 0x3453,
    DEVICE_5053 = 0x5053,
    DEVICE_7053 = 0x7053,
    DEVICE_7073 = 0x7073,
    DEVICE_7173 = 0x7173
};



inline const char8* enumToString(PciDevice4348 device4348) // TEST: NO
{
    // COMMON_LT((" | device4348 = %u", device4348)); // Commented to avoid bad looking logs



    switch (device4348)
    {
        case PciDevice4348::NONE:        return "NONE";
        case PciDevice4348::DEVICE_2273: return "DEVICE_2273";
        case PciDevice4348::DEVICE_3253: return "DEVICE_3253";
        case PciDevice4348::DEVICE_3453: return "DEVICE_3453";
        case PciDevice4348::DEVICE_5053: return "DEVICE_5053";
        case PciDevice4348::DEVICE_7053: return "DEVICE_7053";
        case PciDevice4348::DEVICE_7073: return "DEVICE_7073";
        case PciDevice4348::DEVICE_7173: return "DEVICE_7173";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4348 device4348) // TEST: NO
{
    // COMMON_LT((" | device4348 = %u", device4348)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4348, enumToString(device4348));

    return res;
}



inline const char8* enumToHumanString(PciDevice4348 device4348) // TEST: NO
{
    // COMMON_LT((" | device4348 = %u", device4348)); // Commented to avoid bad looking logs



    switch (device4348)
    {
        case PciDevice4348::DEVICE_2273: return "CH351 PCI Dual Serial Port Controller";
        case PciDevice4348::DEVICE_3253: return "CH352 PCI Dual Serial Port Controller";
        case PciDevice4348::DEVICE_3453: return "CH353 PCI Quad Serial Port Controller";
        case PciDevice4348::DEVICE_5053: return "CH352 PCI Serial and Parallel Port Controller";
        case PciDevice4348::DEVICE_7053: return "CH353 PCI Dual Serial and Parallel Ports Controller";
        case PciDevice4348::DEVICE_7073: return "CH356 PCI Quad Serial and Parallel Ports Controller";
        case PciDevice4348::DEVICE_7173: return "CH355 PCI Quad Serial Port Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4348_PCIDEVICE4348_H
