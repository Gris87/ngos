// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4916_PCIDEVICE4916_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4916_PCIDEVICE4916_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4916: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1960 = 0x1960
};



inline const char8* enumToString(PciDevice4916 device4916) // TEST: NO
{
    // COMMON_LT((" | device4916 = %u", device4916)); // Commented to avoid bad looking logs



    switch (device4916)
    {
        case PciDevice4916::NONE:        return "NONE";
        case PciDevice4916::DEVICE_1960: return "DEVICE_1960";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4916 device4916) // TEST: NO
{
    // COMMON_LT((" | device4916 = %u", device4916)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4916, enumToString(device4916));

    return res;
}



inline const char8* enumToHumanString(PciDevice4916 device4916) // TEST: NO
{
    // COMMON_LT((" | device4916 = %u", device4916)); // Commented to avoid bad looking logs



    switch (device4916)
    {
        case PciDevice4916::DEVICE_1960: return "RedCreek PCI adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4916_PCIDEVICE4916_H
