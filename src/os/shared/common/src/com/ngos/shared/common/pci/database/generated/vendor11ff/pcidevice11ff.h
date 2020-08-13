// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FF_PCIDEVICE11FF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FF_PCIDEVICE11FF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11FF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice11FF device11FF) // TEST: NO
{
    // COMMON_LT((" | device11FF = %u", device11FF)); // Commented to avoid bad looking logs



    switch (device11FF)
    {
        case PciDevice11FF::NONE:        return "NONE";
        case PciDevice11FF::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11FF device11FF) // TEST: NO
{
    // COMMON_LT((" | device11FF = %u", device11FF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11FF, enumToString(device11FF));

    return res;
}



inline const char8* enumToHumanString(PciDevice11FF device11FF) // TEST: NO
{
    // COMMON_LT((" | device11FF = %u", device11FF)); // Commented to avoid bad looking logs



    switch (device11FF)
    {
        case PciDevice11FF::DEVICE_0003: return "AG-5";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11FF_PCIDEVICE11FF_H
