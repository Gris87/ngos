// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5053_PCIDEVICE5053_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5053_PCIDEVICE5053_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5053: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2010 = 0x2010
};



inline const char8* enumToString(PciDevice5053 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5053::NONE:        return "NONE";
        case PciDevice5053::DEVICE_2010: return "DEVICE_2010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5053 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice5053 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5053::DEVICE_2010: return "Daytona Audio Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5053_PCIDEVICE5053_H
