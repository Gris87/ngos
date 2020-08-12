// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice123F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00E4 = 0x00E4,
    DEVICE_8120 = 0x8120,
    DEVICE_8888 = 0x8888
};



inline const char8* enumToString(PciDevice123F device123F) // TEST: NO
{
    // COMMON_LT((" | device123F = %u", device123F)); // Commented to avoid bad looking logs



    switch (device123F)
    {
        case PciDevice123F::NONE:        return "NONE";
        case PciDevice123F::DEVICE_00E4: return "DEVICE_00E4";
        case PciDevice123F::DEVICE_8120: return "DEVICE_8120";
        case PciDevice123F::DEVICE_8888: return "DEVICE_8888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice123F device123F) // TEST: NO
{
    // COMMON_LT((" | device123F = %u", device123F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device123F, enumToString(device123F));

    return res;
}



inline const char8* enumToHumanString(PciDevice123F device123F) // TEST: NO
{
    // COMMON_LT((" | device123F = %u", device123F)); // Commented to avoid bad looking logs



    switch (device123F)
    {
        case PciDevice123F::DEVICE_00E4: return "MPEG";
        case PciDevice123F::DEVICE_8120: return "DVxplore Codec";
        case PciDevice123F::DEVICE_8888: return "Cinemaster C 3.0 DVD Decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCIDEVICE123F_H
