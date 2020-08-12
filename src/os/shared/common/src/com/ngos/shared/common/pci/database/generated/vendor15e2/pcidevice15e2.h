// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E2_PCIDEVICE15E2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E2_PCIDEVICE15E2_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15E2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0500 = 0x0500
};



inline const char8* enumToString(PciDevice15E2 device15E2) // TEST: NO
{
    // COMMON_LT((" | device15E2 = %u", device15E2)); // Commented to avoid bad looking logs



    switch (device15E2)
    {
        case PciDevice15E2::NONE:        return "NONE";
        case PciDevice15E2::DEVICE_0500: return "DEVICE_0500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15E2 device15E2) // TEST: NO
{
    // COMMON_LT((" | device15E2 = %u", device15E2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15E2, enumToString(device15E2));

    return res;
}



inline const char8* enumToHumanString(PciDevice15E2 device15E2) // TEST: NO
{
    // COMMON_LT((" | device15E2 = %u", device15E2)); // Commented to avoid bad looking logs



    switch (device15E2)
    {
        case PciDevice15E2::DEVICE_0500: return "PhoneJack-PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E2_PCIDEVICE15E2_H
