// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BD_PCIDEVICE10BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BD_PCIDEVICE10BD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10BD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0E34 = 0x0E34
};



inline const char8* enumToString(PciDevice10BD device10BD) // TEST: NO
{
    // COMMON_LT((" | device10BD = %u", device10BD)); // Commented to avoid bad looking logs



    switch (device10BD)
    {
        case PciDevice10BD::NONE:        return "NONE";
        case PciDevice10BD::DEVICE_0E34: return "DEVICE_0E34";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10BD device10BD) // TEST: NO
{
    // COMMON_LT((" | device10BD = %u", device10BD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10BD, enumToString(device10BD));

    return res;
}



inline const char8* enumToHumanString(PciDevice10BD device10BD) // TEST: NO
{
    // COMMON_LT((" | device10BD = %u", device10BD)); // Commented to avoid bad looking logs



    switch (device10BD)
    {
        case PciDevice10BD::DEVICE_0E34: return "NE-34";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BD_PCIDEVICE10BD_H
