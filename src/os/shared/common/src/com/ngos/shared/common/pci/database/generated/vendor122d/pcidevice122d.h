// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122D_PCIDEVICE122D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122D_PCIDEVICE122D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice122D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1206 = 0x1206,
    DEVICE_1400 = 0x1400,
    DEVICE_50DC = 0x50DC,
    DEVICE_80DA = 0x80DA
};



inline const char8* enumToString(PciDevice122D device122D) // TEST: NO
{
    // COMMON_LT((" | device122D = %u", device122D)); // Commented to avoid bad looking logs



    switch (device122D)
    {
        case PciDevice122D::NONE:        return "NONE";
        case PciDevice122D::DEVICE_1206: return "DEVICE_1206";
        case PciDevice122D::DEVICE_1400: return "DEVICE_1400";
        case PciDevice122D::DEVICE_50DC: return "DEVICE_50DC";
        case PciDevice122D::DEVICE_80DA: return "DEVICE_80DA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice122D device122D) // TEST: NO
{
    // COMMON_LT((" | device122D = %u", device122D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device122D, enumToString(device122D));

    return res;
}



inline const char8* enumToHumanString(PciDevice122D device122D) // TEST: NO
{
    // COMMON_LT((" | device122D = %u", device122D)); // Commented to avoid bad looking logs



    switch (device122D)
    {
        case PciDevice122D::DEVICE_1206: return "368DSP";
        case PciDevice122D::DEVICE_1400: return "Trident PCI288-Q3DII (NX)";
        case PciDevice122D::DEVICE_50DC: return "3328 Audio";
        case PciDevice122D::DEVICE_80DA: return "3328 Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR122D_PCIDEVICE122D_H
