// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1003_PCIDEVICE1003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1003_PCIDEVICE1003_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1003: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0201 = 0x0201
};



inline const char8* enumToString(PciDevice1003 device1003) // TEST: NO
{
    // COMMON_LT((" | device1003 = %u", device1003)); // Commented to avoid bad looking logs



    switch (device1003)
    {
        case PciDevice1003::NONE:        return "NONE";
        case PciDevice1003::DEVICE_0201: return "DEVICE_0201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1003 device1003) // TEST: NO
{
    // COMMON_LT((" | device1003 = %u", device1003)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1003, enumToString(device1003));

    return res;
}



inline const char8* enumToHumanString(PciDevice1003 device1003) // TEST: NO
{
    // COMMON_LT((" | device1003 = %u", device1003)); // Commented to avoid bad looking logs



    switch (device1003)
    {
        case PciDevice1003::DEVICE_0201: return "US201";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1003_PCIDEVICE1003_H
