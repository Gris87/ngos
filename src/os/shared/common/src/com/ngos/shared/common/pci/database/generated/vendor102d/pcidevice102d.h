// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102D_PCIDEVICE102D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102D_PCIDEVICE102D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice102D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_50DC = 0x50DC
};



inline const char8* enumToString(PciDevice102D device102D) // TEST: NO
{
    // COMMON_LT((" | device102D = %u", device102D)); // Commented to avoid bad looking logs



    switch (device102D)
    {
        case PciDevice102D::NONE:        return "NONE";
        case PciDevice102D::DEVICE_50DC: return "DEVICE_50DC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice102D device102D) // TEST: NO
{
    // COMMON_LT((" | device102D = %u", device102D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device102D, enumToString(device102D));

    return res;
}



inline const char8* enumToHumanString(PciDevice102D device102D) // TEST: NO
{
    // COMMON_LT((" | device102D = %u", device102D)); // Commented to avoid bad looking logs



    switch (device102D)
    {
        case PciDevice102D::DEVICE_50DC: return "3328 Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102D_PCIDEVICE102D_H
