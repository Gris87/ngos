// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153F_PCIDEVICE153F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153F_PCIDEVICE153F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice153F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice153F device153F) // TEST: NO
{
    // COMMON_LT((" | device153F = %u", device153F)); // Commented to avoid bad looking logs



    switch (device153F)
    {
        case PciDevice153F::NONE:        return "NONE";
        case PciDevice153F::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice153F device153F) // TEST: NO
{
    // COMMON_LT((" | device153F = %u", device153F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device153F, enumToString(device153F));

    return res;
}



inline const char8* enumToHumanString(PciDevice153F device153F) // TEST: NO
{
    // COMMON_LT((" | device153F = %u", device153F)); // Commented to avoid bad looking logs



    switch (device153F)
    {
        case PciDevice153F::DEVICE_0001: return "SOC-it 101 System Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR153F_PCIDEVICE153F_H