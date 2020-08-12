// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7E_PCIDEVICE1C7E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7E_PCIDEVICE1C7E_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C7E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice1C7E device1C7E) // TEST: NO
{
    // COMMON_LT((" | device1C7E = %u", device1C7E)); // Commented to avoid bad looking logs



    switch (device1C7E)
    {
        case PciDevice1C7E::NONE:        return "NONE";
        case PciDevice1C7E::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C7E device1C7E) // TEST: NO
{
    // COMMON_LT((" | device1C7E = %u", device1C7E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C7E, enumToString(device1C7E));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C7E device1C7E) // TEST: NO
{
    // COMMON_LT((" | device1C7E = %u", device1C7E)); // Commented to avoid bad looking logs



    switch (device1C7E)
    {
        case PciDevice1C7E::DEVICE_0200: return "zFAS Debug Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C7E_PCIDEVICE1C7E_H
