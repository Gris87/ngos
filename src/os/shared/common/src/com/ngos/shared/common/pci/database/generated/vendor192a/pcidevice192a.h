// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR192A_PCIDEVICE192A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR192A_PCIDEVICE192A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice192A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDevice192A device192A) // TEST: NO
{
    // COMMON_LT((" | device192A = %u", device192A)); // Commented to avoid bad looking logs



    switch (device192A)
    {
        case PciDevice192A::NONE:        return "NONE";
        case PciDevice192A::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice192A device192A) // TEST: NO
{
    // COMMON_LT((" | device192A = %u", device192A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device192A, enumToString(device192A));

    return res;
}



inline const char8* enumToHumanString(PciDevice192A device192A) // TEST: NO
{
    // COMMON_LT((" | device192A = %u", device192A)); // Commented to avoid bad looking logs



    switch (device192A)
    {
        case PciDevice192A::DEVICE_0008: return "RAMPART";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR192A_PCIDEVICE192A_H
