// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCIDEVICE1E57_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCIDEVICE1E57_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E57: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1E57 device1E57) // TEST: NO
{
    // COMMON_LT((" | device1E57 = %u", device1E57)); // Commented to avoid bad looking logs



    switch (device1E57)
    {
        case PciDevice1E57::NONE:        return "NONE";
        case PciDevice1E57::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E57 device1E57) // TEST: NO
{
    // COMMON_LT((" | device1E57 = %u", device1E57)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E57, enumToString(device1E57));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E57 device1E57) // TEST: NO
{
    // COMMON_LT((" | device1E57 = %u", device1E57)); // Commented to avoid bad looking logs



    switch (device1E57)
    {
        case PciDevice1E57::DEVICE_0100: return "The device has already been deleted.";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E57_PCIDEVICE1E57_H
