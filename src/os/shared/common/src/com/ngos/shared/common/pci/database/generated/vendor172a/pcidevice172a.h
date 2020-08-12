// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR172A_PCIDEVICE172A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR172A_PCIDEVICE172A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice172A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_13C8 = 0x13C8
};



inline const char8* enumToString(PciDevice172A device172A) // TEST: NO
{
    // COMMON_LT((" | device172A = %u", device172A)); // Commented to avoid bad looking logs



    switch (device172A)
    {
        case PciDevice172A::NONE:        return "NONE";
        case PciDevice172A::DEVICE_13C8: return "DEVICE_13C8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice172A device172A) // TEST: NO
{
    // COMMON_LT((" | device172A = %u", device172A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device172A, enumToString(device172A));

    return res;
}



inline const char8* enumToHumanString(PciDevice172A device172A) // TEST: NO
{
    // COMMON_LT((" | device172A = %u", device172A)); // Commented to avoid bad looking logs



    switch (device172A)
    {
        case PciDevice172A::DEVICE_13C8: return "AEP SureWare Runner 1000V3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR172A_PCIDEVICE172A_H
