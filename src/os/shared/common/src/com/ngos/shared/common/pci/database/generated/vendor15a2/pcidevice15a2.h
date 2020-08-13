// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15A2_PCIDEVICE15A2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15A2_PCIDEVICE15A2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15A2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice15A2 device15A2) // TEST: NO
{
    // COMMON_LT((" | device15A2 = %u", device15A2)); // Commented to avoid bad looking logs



    switch (device15A2)
    {
        case PciDevice15A2::NONE:        return "NONE";
        case PciDevice15A2::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15A2 device15A2) // TEST: NO
{
    // COMMON_LT((" | device15A2 = %u", device15A2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15A2, enumToString(device15A2));

    return res;
}



inline const char8* enumToHumanString(PciDevice15A2 device15A2) // TEST: NO
{
    // COMMON_LT((" | device15A2 = %u", device15A2)); // Commented to avoid bad looking logs



    switch (device15A2)
    {
        case PciDevice15A2::DEVICE_0001: return "TA700 PCI Bus Analyzer/Exerciser";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15A2_PCIDEVICE15A2_H
