// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1D_PCIDEVICE1D1D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1D_PCIDEVICE1D1D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D1D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1F1F = 0x1F1F,
    DEVICE_2807 = 0x2807
};



inline const char8* enumToString(PciDevice1D1D device1D1D) // TEST: NO
{
    // COMMON_LT((" | device1D1D = %u", device1D1D)); // Commented to avoid bad looking logs



    switch (device1D1D)
    {
        case PciDevice1D1D::NONE:        return "NONE";
        case PciDevice1D1D::DEVICE_1F1F: return "DEVICE_1F1F";
        case PciDevice1D1D::DEVICE_2807: return "DEVICE_2807";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D1D device1D1D) // TEST: NO
{
    // COMMON_LT((" | device1D1D = %u", device1D1D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D1D, enumToString(device1D1D));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D1D device1D1D) // TEST: NO
{
    // COMMON_LT((" | device1D1D = %u", device1D1D)); // Commented to avoid bad looking logs



    switch (device1D1D)
    {
        case PciDevice1D1D::DEVICE_1F1F: return "QEMU NVM Express LightNVM Controller";
        case PciDevice1D1D::DEVICE_2807: return "8800 series NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1D_PCIDEVICE1D1D_H
