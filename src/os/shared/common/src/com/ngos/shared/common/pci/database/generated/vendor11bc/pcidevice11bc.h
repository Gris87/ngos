// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BC_PCIDEVICE11BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BC_PCIDEVICE11BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11BC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice11BC device11BC) // TEST: NO
{
    // COMMON_LT((" | device11BC = %u", device11BC)); // Commented to avoid bad looking logs



    switch (device11BC)
    {
        case PciDevice11BC::NONE:        return "NONE";
        case PciDevice11BC::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11BC device11BC) // TEST: NO
{
    // COMMON_LT((" | device11BC = %u", device11BC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11BC, enumToString(device11BC));

    return res;
}



inline const char8* enumToHumanString(PciDevice11BC device11BC) // TEST: NO
{
    // COMMON_LT((" | device11BC = %u", device11BC)); // Commented to avoid bad looking logs



    switch (device11BC)
    {
        case PciDevice11BC::DEVICE_0001: return "NP-PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11BC_PCIDEVICE11BC_H