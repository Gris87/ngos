// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR137A_PCIDEVICE137A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR137A_PCIDEVICE137A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice137A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice137A device137A) // TEST: NO
{
    // COMMON_LT((" | device137A = %u", device137A)); // Commented to avoid bad looking logs



    switch (device137A)
    {
        case PciDevice137A::NONE:        return "NONE";
        case PciDevice137A::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice137A device137A) // TEST: NO
{
    // COMMON_LT((" | device137A = %u", device137A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device137A, enumToString(device137A));

    return res;
}



inline const char8* enumToHumanString(PciDevice137A device137A) // TEST: NO
{
    // COMMON_LT((" | device137A = %u", device137A)); // Commented to avoid bad looking logs



    switch (device137A)
    {
        case PciDevice137A::DEVICE_0001: return "PCI-324 Audiowire Interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR137A_PCIDEVICE137A_H
