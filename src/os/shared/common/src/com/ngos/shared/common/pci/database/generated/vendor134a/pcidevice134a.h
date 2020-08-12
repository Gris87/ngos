// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134A_PCIDEVICE134A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134A_PCIDEVICE134A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice134A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice134A device134A) // TEST: NO
{
    // COMMON_LT((" | device134A = %u", device134A)); // Commented to avoid bad looking logs



    switch (device134A)
    {
        case PciDevice134A::NONE:        return "NONE";
        case PciDevice134A::DEVICE_0001: return "DEVICE_0001";
        case PciDevice134A::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice134A device134A) // TEST: NO
{
    // COMMON_LT((" | device134A = %u", device134A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device134A, enumToString(device134A));

    return res;
}



inline const char8* enumToHumanString(PciDevice134A device134A) // TEST: NO
{
    // COMMON_LT((" | device134A = %u", device134A)); // Commented to avoid bad looking logs



    switch (device134A)
    {
        case PciDevice134A::DEVICE_0001: return "Domex 536";
        case PciDevice134A::DEVICE_0002: return "Domex DMX3194UP SCSI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR134A_PCIDEVICE134A_H
