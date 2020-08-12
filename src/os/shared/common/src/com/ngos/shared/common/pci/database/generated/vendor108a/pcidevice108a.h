// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108A_PCIDEVICE108A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108A_PCIDEVICE108A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice108A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0010 = 0x0010,
    DEVICE_0040 = 0x0040,
    DEVICE_3000 = 0x3000
};



inline const char8* enumToString(PciDevice108A device108A) // TEST: NO
{
    // COMMON_LT((" | device108A = %u", device108A)); // Commented to avoid bad looking logs



    switch (device108A)
    {
        case PciDevice108A::NONE:        return "NONE";
        case PciDevice108A::DEVICE_0001: return "DEVICE_0001";
        case PciDevice108A::DEVICE_0010: return "DEVICE_0010";
        case PciDevice108A::DEVICE_0040: return "DEVICE_0040";
        case PciDevice108A::DEVICE_3000: return "DEVICE_3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice108A device108A) // TEST: NO
{
    // COMMON_LT((" | device108A = %u", device108A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device108A, enumToString(device108A));

    return res;
}



inline const char8* enumToHumanString(PciDevice108A device108A) // TEST: NO
{
    // COMMON_LT((" | device108A = %u", device108A)); // Commented to avoid bad looking logs



    switch (device108A)
    {
        case PciDevice108A::DEVICE_0001: return "VME Bridge Model 617";
        case PciDevice108A::DEVICE_0010: return "VME Bridge Model 618";
        case PciDevice108A::DEVICE_0040: return "dataBLIZZARD";
        case PciDevice108A::DEVICE_3000: return "VME Bridge Model 2706";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108A_PCIDEVICE108A_H
