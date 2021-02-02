// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146C_PCIDEVICE146C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146C_PCIDEVICE146C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice146C: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1430 = 0x1430
};



inline const char8* enumToString(PciDevice146C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice146C::NONE:        return "NONE";
        case PciDevice146C::DEVICE_1430: return "DEVICE_1430";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice146C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice146C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice146C::DEVICE_1430: return "FE-1430TX Fast Ethernet PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146C_PCIDEVICE146C_H
