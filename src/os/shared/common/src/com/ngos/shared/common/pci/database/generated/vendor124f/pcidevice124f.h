// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124F_PCIDEVICE124F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124F_PCIDEVICE124F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice124F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0041 = 0x0041
};



inline const char8* enumToString(PciDevice124F device124F) // TEST: NO
{
    // COMMON_LT((" | device124F = %u", device124F)); // Commented to avoid bad looking logs



    switch (device124F)
    {
        case PciDevice124F::NONE:        return "NONE";
        case PciDevice124F::DEVICE_0041: return "DEVICE_0041";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice124F device124F) // TEST: NO
{
    // COMMON_LT((" | device124F = %u", device124F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device124F, enumToString(device124F));

    return res;
}



inline const char8* enumToHumanString(PciDevice124F device124F) // TEST: NO
{
    // COMMON_LT((" | device124F = %u", device124F)); // Commented to avoid bad looking logs



    switch (device124F)
    {
        case PciDevice124F::DEVICE_0041: return "IFT-2000 Series RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124F_PCIDEVICE124F_H
