// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1888_PCIDEVICE1888_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1888_PCIDEVICE1888_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1888: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0301 = 0x0301,
    DEVICE_0601 = 0x0601,
    DEVICE_0710 = 0x0710,
    DEVICE_0720 = 0x0720
};



inline const char8* enumToString(PciDevice1888 device1888) // TEST: NO
{
    // COMMON_LT((" | device1888 = %u", device1888)); // Commented to avoid bad looking logs



    switch (device1888)
    {
        case PciDevice1888::NONE:        return "NONE";
        case PciDevice1888::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1888::DEVICE_0601: return "DEVICE_0601";
        case PciDevice1888::DEVICE_0710: return "DEVICE_0710";
        case PciDevice1888::DEVICE_0720: return "DEVICE_0720";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1888 device1888) // TEST: NO
{
    // COMMON_LT((" | device1888 = %u", device1888)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1888, enumToString(device1888));

    return res;
}



inline const char8* enumToHumanString(PciDevice1888 device1888) // TEST: NO
{
    // COMMON_LT((" | device1888 = %u", device1888)); // Commented to avoid bad looking logs



    switch (device1888)
    {
        case PciDevice1888::DEVICE_0301: return "VMFX1 FPGA PMC module";
        case PciDevice1888::DEVICE_0601: return "VSM2 dual PMC carrier";
        case PciDevice1888::DEVICE_0710: return "VS14x series PowerPC PCI board";
        case PciDevice1888::DEVICE_0720: return "VS24x series PowerPC PCI board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1888_PCIDEVICE1888_H
