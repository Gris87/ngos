// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B3E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1FA8 = 0x1FA8
};



inline const char8* enumToString(PciDevice1B3E device1B3E) // TEST: NO
{
    // COMMON_LT((" | device1B3E = %u", device1B3E)); // Commented to avoid bad looking logs



    switch (device1B3E)
    {
        case PciDevice1B3E::NONE:        return "NONE";
        case PciDevice1B3E::DEVICE_1FA8: return "DEVICE_1FA8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B3E device1B3E) // TEST: NO
{
    // COMMON_LT((" | device1B3E = %u", device1B3E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B3E, enumToString(device1B3E));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B3E device1B3E) // TEST: NO
{
    // COMMON_LT((" | device1B3E = %u", device1B3E)); // Commented to avoid bad looking logs



    switch (device1B3E)
    {
        case PciDevice1B3E::DEVICE_1FA8: return "BYNET BIC2SE/X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCIDEVICE1B3E_H
