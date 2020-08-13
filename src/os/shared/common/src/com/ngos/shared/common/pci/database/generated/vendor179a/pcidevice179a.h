// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179A_PCIDEVICE179A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179A_PCIDEVICE179A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice179A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice179A device179A) // TEST: NO
{
    // COMMON_LT((" | device179A = %u", device179A)); // Commented to avoid bad looking logs



    switch (device179A)
    {
        case PciDevice179A::NONE:        return "NONE";
        case PciDevice179A::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice179A device179A) // TEST: NO
{
    // COMMON_LT((" | device179A = %u", device179A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device179A, enumToString(device179A));

    return res;
}



inline const char8* enumToHumanString(PciDevice179A device179A) // TEST: NO
{
    // COMMON_LT((" | device179A = %u", device179A)); // Commented to avoid bad looking logs



    switch (device179A)
    {
        case PciDevice179A::DEVICE_0001: return "Quantis PCI 16Mbps";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179A_PCIDEVICE179A_H
