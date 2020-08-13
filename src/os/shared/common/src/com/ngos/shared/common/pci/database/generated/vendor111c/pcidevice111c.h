// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111C_PCIDEVICE111C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111C_PCIDEVICE111C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice111C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice111C device111C) // TEST: NO
{
    // COMMON_LT((" | device111C = %u", device111C)); // Commented to avoid bad looking logs



    switch (device111C)
    {
        case PciDevice111C::NONE:        return "NONE";
        case PciDevice111C::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice111C device111C) // TEST: NO
{
    // COMMON_LT((" | device111C = %u", device111C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device111C, enumToString(device111C));

    return res;
}



inline const char8* enumToHumanString(PciDevice111C device111C) // TEST: NO
{
    // COMMON_LT((" | device111C = %u", device111C)); // Commented to avoid bad looking logs



    switch (device111C)
    {
        case PciDevice111C::DEVICE_0001: return "Powerbis Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111C_PCIDEVICE111C_H
