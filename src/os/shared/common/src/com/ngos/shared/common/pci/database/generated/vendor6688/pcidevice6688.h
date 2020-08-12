// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6688_PCIDEVICE6688_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6688_PCIDEVICE6688_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice6688: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1200 = 0x1200,
    DEVICE_1400 = 0x1400,
    DEVICE_1600 = 0x1600,
    DEVICE_1800 = 0x1800
};



inline const char8* enumToString(PciDevice6688 device6688) // TEST: NO
{
    // COMMON_LT((" | device6688 = %u", device6688)); // Commented to avoid bad looking logs



    switch (device6688)
    {
        case PciDevice6688::NONE:        return "NONE";
        case PciDevice6688::DEVICE_1200: return "DEVICE_1200";
        case PciDevice6688::DEVICE_1400: return "DEVICE_1400";
        case PciDevice6688::DEVICE_1600: return "DEVICE_1600";
        case PciDevice6688::DEVICE_1800: return "DEVICE_1800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice6688 device6688) // TEST: NO
{
    // COMMON_LT((" | device6688 = %u", device6688)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device6688, enumToString(device6688));

    return res;
}



inline const char8* enumToHumanString(PciDevice6688 device6688) // TEST: NO
{
    // COMMON_LT((" | device6688 = %u", device6688)); // Commented to avoid bad looking logs



    switch (device6688)
    {
        case PciDevice6688::DEVICE_1200: return "CooVox TDM Analog Module";
        case PciDevice6688::DEVICE_1400: return "CooVOX TDM GSM Module";
        case PciDevice6688::DEVICE_1600: return "CooVOX TDM E1/T1 Module";
        case PciDevice6688::DEVICE_1800: return "CooVOX TDM BRI Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6688_PCIDEVICE6688_H
