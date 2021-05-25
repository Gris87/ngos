// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D97_PCIDEVICE1D97_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D97_PCIDEVICE1D97_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D97: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2263 = 0x2263
};



inline const char8* enumToString(PciDevice1D97 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D97::NONE:        return "NONE";
        case PciDevice1D97::DEVICE_2263: return "DEVICE_2263";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D97 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D97 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D97::DEVICE_2263: return "SM2263EN/SM2263XT-based OEM SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D97_PCIDEVICE1D97_H
