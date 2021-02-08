// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199F_PCIDEVICE199F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199F_PCIDEVICE199F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice199F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8501 = 0x8501,
    DEVICE_8521 = 0x8521
};



inline const char8* enumToString(PciDevice199F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice199F::NONE:        return "NONE";
        case PciDevice199F::DEVICE_8501: return "DEVICE_8501";
        case PciDevice199F::DEVICE_8521: return "DEVICE_8521";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice199F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice199F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice199F::DEVICE_8501: return "Au85X1 PCI REV1.1";
        case PciDevice199F::DEVICE_8521: return "Au8521 TV card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR199F_PCIDEVICE199F_H
