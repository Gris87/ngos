// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8C_PCIDEVICE1A8C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8C_PCIDEVICE1A8C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A8C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100
};



inline const char8* enumToString(PciDevice1A8C device1A8C) // TEST: NO
{
    // COMMON_LT((" | device1A8C = %u", device1A8C)); // Commented to avoid bad looking logs



    switch (device1A8C)
    {
        case PciDevice1A8C::NONE:        return "NONE";
        case PciDevice1A8C::DEVICE_1100: return "DEVICE_1100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A8C device1A8C) // TEST: NO
{
    // COMMON_LT((" | device1A8C = %u", device1A8C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A8C, enumToString(device1A8C));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A8C device1A8C) // TEST: NO
{
    // COMMON_LT((" | device1A8C = %u", device1A8C)); // Commented to avoid bad looking logs



    switch (device1A8C)
    {
        case PciDevice1A8C::DEVICE_1100: return "E8001-66443 PCI Express CIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8C_PCIDEVICE1A8C_H
