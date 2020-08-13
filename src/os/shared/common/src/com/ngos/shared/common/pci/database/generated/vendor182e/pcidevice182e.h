// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182E_PCIDEVICE182E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182E_PCIDEVICE182E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice182E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDevice182E device182E) // TEST: NO
{
    // COMMON_LT((" | device182E = %u", device182E)); // Commented to avoid bad looking logs



    switch (device182E)
    {
        case PciDevice182E::NONE:        return "NONE";
        case PciDevice182E::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice182E device182E) // TEST: NO
{
    // COMMON_LT((" | device182E = %u", device182E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device182E, enumToString(device182E));

    return res;
}



inline const char8* enumToHumanString(PciDevice182E device182E) // TEST: NO
{
    // COMMON_LT((" | device182E = %u", device182E)); // Commented to avoid bad looking logs



    switch (device182E)
    {
        case PciDevice182E::DEVICE_0008: return "XLR516 Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182E_PCIDEVICE182E_H
