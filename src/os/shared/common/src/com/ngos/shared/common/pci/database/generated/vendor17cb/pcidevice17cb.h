// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17CB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0400 = 0x0400,
    DEVICE_0401 = 0x0401
};



inline const char8* enumToString(PciDevice17CB device17CB) // TEST: NO
{
    // COMMON_LT((" | device17CB = %u", device17CB)); // Commented to avoid bad looking logs



    switch (device17CB)
    {
        case PciDevice17CB::NONE:        return "NONE";
        case PciDevice17CB::DEVICE_0001: return "DEVICE_0001";
        case PciDevice17CB::DEVICE_0002: return "DEVICE_0002";
        case PciDevice17CB::DEVICE_0400: return "DEVICE_0400";
        case PciDevice17CB::DEVICE_0401: return "DEVICE_0401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17CB device17CB) // TEST: NO
{
    // COMMON_LT((" | device17CB = %u", device17CB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17CB, enumToString(device17CB));

    return res;
}



inline const char8* enumToHumanString(PciDevice17CB device17CB) // TEST: NO
{
    // COMMON_LT((" | device17CB = %u", device17CB)); // Commented to avoid bad looking logs



    switch (device17CB)
    {
        case PciDevice17CB::DEVICE_0001: return "AGN100 802.11 a/b/g True MIMO Wireless Card";
        case PciDevice17CB::DEVICE_0002: return "AGN300 802.11 a/b/g True MIMO Wireless Card";
        case PciDevice17CB::DEVICE_0400: return "Datacenter Technologies QDF2432 PCI Express Root Port";
        case PciDevice17CB::DEVICE_0401: return "Datacenter Technologies QDF2400 PCI Express Root Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CB_PCIDEVICE17CB_H
