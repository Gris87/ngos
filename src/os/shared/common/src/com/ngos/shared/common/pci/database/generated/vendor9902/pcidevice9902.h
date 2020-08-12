// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9902_PCIDEVICE9902_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9902_PCIDEVICE9902_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9902: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice9902 device9902) // TEST: NO
{
    // COMMON_LT((" | device9902 = %u", device9902)); // Commented to avoid bad looking logs



    switch (device9902)
    {
        case PciDevice9902::NONE:        return "NONE";
        case PciDevice9902::DEVICE_0001: return "DEVICE_0001";
        case PciDevice9902::DEVICE_0002: return "DEVICE_0002";
        case PciDevice9902::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9902 device9902) // TEST: NO
{
    // COMMON_LT((" | device9902 = %u", device9902)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9902, enumToString(device9902));

    return res;
}



inline const char8* enumToHumanString(PciDevice9902 device9902) // TEST: NO
{
    // COMMON_LT((" | device9902 = %u", device9902)); // Commented to avoid bad looking logs



    switch (device9902)
    {
        case PciDevice9902::DEVICE_0001: return "SG2010 PCI over Starfabric Bridge";
        case PciDevice9902::DEVICE_0002: return "SG2010 PCI to Starfabric Gateway";
        case PciDevice9902::DEVICE_0003: return "SG1010 Starfabric Switch and PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9902_PCIDEVICE9902_H
