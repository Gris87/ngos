// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR112F_PCIDEVICE112F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR112F_PCIDEVICE112F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice112F: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0004 = 0x0004,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDevice112F device112F) // TEST: NO
{
    // COMMON_LT((" | device112F = %u", device112F)); // Commented to avoid bad looking logs



    switch (device112F)
    {
        case PciDevice112F::DEVICE_0000: return "DEVICE_0000";
        case PciDevice112F::DEVICE_0001: return "DEVICE_0001";
        case PciDevice112F::DEVICE_0004: return "DEVICE_0004";
        case PciDevice112F::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice112F device112F) // TEST: NO
{
    // COMMON_LT((" | device112F = %u", device112F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device112F, enumToString(device112F));

    return res;
}



inline const char8* enumToHumanString(PciDevice112F device112F) // TEST: NO
{
    // COMMON_LT((" | device112F = %u", device112F)); // Commented to avoid bad looking logs



    switch (device112F)
    {
        case PciDevice112F::DEVICE_0000: return "MVC IC-PCI";
        case PciDevice112F::DEVICE_0001: return "MVC IM-PCI Video frame grabber/processor";
        case PciDevice112F::DEVICE_0004: return "PCDig Digital Image Capture";
        case PciDevice112F::DEVICE_0008: return "PC-CamLink PCI framegrabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR112F_PCIDEVICE112F_H
