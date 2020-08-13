// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15B7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2001 = 0x2001,
    DEVICE_5001 = 0x5001,
    DEVICE_5002 = 0x5002,
    DEVICE_5003 = 0x5003
};



inline const char8* enumToString(PciDevice15B7 device15B7) // TEST: NO
{
    // COMMON_LT((" | device15B7 = %u", device15B7)); // Commented to avoid bad looking logs



    switch (device15B7)
    {
        case PciDevice15B7::NONE:        return "NONE";
        case PciDevice15B7::DEVICE_2001: return "DEVICE_2001";
        case PciDevice15B7::DEVICE_5001: return "DEVICE_5001";
        case PciDevice15B7::DEVICE_5002: return "DEVICE_5002";
        case PciDevice15B7::DEVICE_5003: return "DEVICE_5003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15B7 device15B7) // TEST: NO
{
    // COMMON_LT((" | device15B7 = %u", device15B7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15B7, enumToString(device15B7));

    return res;
}



inline const char8* enumToHumanString(PciDevice15B7 device15B7) // TEST: NO
{
    // COMMON_LT((" | device15B7 = %u", device15B7)); // Commented to avoid bad looking logs



    switch (device15B7)
    {
        case PciDevice15B7::DEVICE_2001: return "Skyhawk Series NVME SSD";
        case PciDevice15B7::DEVICE_5001: return "WD Black NVMe SSD";
        case PciDevice15B7::DEVICE_5002: return "WD Black 2018/PC SN720 NVMe SSD";
        case PciDevice15B7::DEVICE_5003: return "WD Black 2018/PC SN520 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B7_PCIDEVICE15B7_H
