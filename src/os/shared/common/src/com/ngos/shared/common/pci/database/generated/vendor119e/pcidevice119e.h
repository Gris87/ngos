// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119E_PCIDEVICE119E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119E_PCIDEVICE119E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice119E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice119E device119E) // TEST: NO
{
    // COMMON_LT((" | device119E = %u", device119E)); // Commented to avoid bad looking logs



    switch (device119E)
    {
        case PciDevice119E::NONE:        return "NONE";
        case PciDevice119E::DEVICE_0001: return "DEVICE_0001";
        case PciDevice119E::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice119E device119E) // TEST: NO
{
    // COMMON_LT((" | device119E = %u", device119E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device119E, enumToString(device119E));

    return res;
}



inline const char8* enumToHumanString(PciDevice119E device119E) // TEST: NO
{
    // COMMON_LT((" | device119E = %u", device119E)); // Commented to avoid bad looking logs



    switch (device119E)
    {
        case PciDevice119E::DEVICE_0001: return "FireStream 155";
        case PciDevice119E::DEVICE_0003: return "FireStream 50";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119E_PCIDEVICE119E_H
