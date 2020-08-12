// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16AE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_000A = 0x000A,
    DEVICE_1141 = 0x1141,
    DEVICE_1841 = 0x1841
};



inline const char8* enumToString(PciDevice16AE device16AE) // TEST: NO
{
    // COMMON_LT((" | device16AE = %u", device16AE)); // Commented to avoid bad looking logs



    switch (device16AE)
    {
        case PciDevice16AE::NONE:        return "NONE";
        case PciDevice16AE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice16AE::DEVICE_000A: return "DEVICE_000A";
        case PciDevice16AE::DEVICE_1141: return "DEVICE_1141";
        case PciDevice16AE::DEVICE_1841: return "DEVICE_1841";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16AE device16AE) // TEST: NO
{
    // COMMON_LT((" | device16AE = %u", device16AE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16AE, enumToString(device16AE));

    return res;
}



inline const char8* enumToHumanString(PciDevice16AE device16AE) // TEST: NO
{
    // COMMON_LT((" | device16AE = %u", device16AE)); // Commented to avoid bad looking logs



    switch (device16AE)
    {
        case PciDevice16AE::DEVICE_0001: return "SafeXcel 1140";
        case PciDevice16AE::DEVICE_000A: return "SafeXcel 1841";
        case PciDevice16AE::DEVICE_1141: return "SafeXcel 1141";
        case PciDevice16AE::DEVICE_1841: return "SafeXcel 1842";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16AE_PCIDEVICE16AE_H
