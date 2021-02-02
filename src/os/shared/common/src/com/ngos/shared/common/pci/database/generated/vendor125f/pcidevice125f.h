// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125F_PCIDEVICE125F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125F_PCIDEVICE125F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice125F: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2071 = 0x2071,
    DEVICE_2084 = 0x2084,
    DEVICE_2091 = 0x2091
};



inline const char8* enumToString(PciDevice125F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125F::NONE:        return "NONE";
        case PciDevice125F::DEVICE_2071: return "DEVICE_2071";
        case PciDevice125F::DEVICE_2084: return "DEVICE_2084";
        case PciDevice125F::DEVICE_2091: return "DEVICE_2091";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice125F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice125F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125F::DEVICE_2071: return "CC PMC/232";
        case PciDevice125F::DEVICE_2084: return "CC PMC/23P";
        case PciDevice125F::DEVICE_2091: return "CC PMC/422";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125F_PCIDEVICE125F_H
