// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B9_PCIDEVICE11B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B9_PCIDEVICE11B9_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11B9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C0ED = 0xC0ED
};



inline const char8* enumToString(PciDevice11B9 device11B9) // TEST: NO
{
    // COMMON_LT((" | device11B9 = %u", device11B9)); // Commented to avoid bad looking logs



    switch (device11B9)
    {
        case PciDevice11B9::NONE:        return "NONE";
        case PciDevice11B9::DEVICE_C0ED: return "DEVICE_C0ED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11B9 device11B9) // TEST: NO
{
    // COMMON_LT((" | device11B9 = %u", device11B9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11B9, enumToString(device11B9));

    return res;
}



inline const char8* enumToHumanString(PciDevice11B9 device11B9) // TEST: NO
{
    // COMMON_LT((" | device11B9 = %u", device11B9)); // Commented to avoid bad looking logs



    switch (device11B9)
    {
        case PciDevice11B9::DEVICE_C0ED: return "SSA Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B9_PCIDEVICE11B9_H
