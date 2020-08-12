// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR169C_PCIDEVICE169C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR169C_PCIDEVICE169C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice169C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0044 = 0x0044
};



inline const char8* enumToString(PciDevice169C device169C) // TEST: NO
{
    // COMMON_LT((" | device169C = %u", device169C)); // Commented to avoid bad looking logs



    switch (device169C)
    {
        case PciDevice169C::NONE:        return "NONE";
        case PciDevice169C::DEVICE_0044: return "DEVICE_0044";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice169C device169C) // TEST: NO
{
    // COMMON_LT((" | device169C = %u", device169C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device169C, enumToString(device169C));

    return res;
}



inline const char8* enumToHumanString(PciDevice169C device169C) // TEST: NO
{
    // COMMON_LT((" | device169C = %u", device169C)); // Commented to avoid bad looking logs



    switch (device169C)
    {
        case PciDevice169C::DEVICE_0044: return "Revolution Storage Processing Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR169C_PCIDEVICE169C_H
