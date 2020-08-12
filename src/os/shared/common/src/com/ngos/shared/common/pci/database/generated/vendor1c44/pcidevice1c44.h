// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C44_PCIDEVICE1C44_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C44_PCIDEVICE1C44_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C44: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8000 = 0x8000
};



inline const char8* enumToString(PciDevice1C44 device1C44) // TEST: NO
{
    // COMMON_LT((" | device1C44 = %u", device1C44)); // Commented to avoid bad looking logs



    switch (device1C44)
    {
        case PciDevice1C44::NONE:        return "NONE";
        case PciDevice1C44::DEVICE_8000: return "DEVICE_8000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C44 device1C44) // TEST: NO
{
    // COMMON_LT((" | device1C44 = %u", device1C44)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C44, enumToString(device1C44));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C44 device1C44) // TEST: NO
{
    // COMMON_LT((" | device1C44 = %u", device1C44)); // Commented to avoid bad looking logs



    switch (device1C44)
    {
        case PciDevice1C44::DEVICE_8000: return "8000 Storage IO Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C44_PCIDEVICE1C44_H
