// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR018A_PCIDEVICE018A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR018A_PCIDEVICE018A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice018A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0106 = 0x0106
};



inline const char8* enumToString(PciDevice018A device018A) // TEST: NO
{
    // COMMON_LT((" | device018A = %u", device018A)); // Commented to avoid bad looking logs



    switch (device018A)
    {
        case PciDevice018A::NONE:        return "NONE";
        case PciDevice018A::DEVICE_0106: return "DEVICE_0106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice018A device018A) // TEST: NO
{
    // COMMON_LT((" | device018A = %u", device018A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device018A, enumToString(device018A));

    return res;
}



inline const char8* enumToHumanString(PciDevice018A device018A) // TEST: NO
{
    // COMMON_LT((" | device018A = %u", device018A)); // Commented to avoid bad looking logs



    switch (device018A)
    {
        case PciDevice018A::DEVICE_0106: return "FPC-0106TX misprogrammed [RTL81xx]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR018A_PCIDEVICE018A_H
