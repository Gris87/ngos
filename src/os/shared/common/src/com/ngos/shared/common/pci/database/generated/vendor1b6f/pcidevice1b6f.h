// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B6F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7023 = 0x7023,
    DEVICE_7052 = 0x7052
};



inline const char8* enumToString(PciDevice1B6F device1B6F) // TEST: NO
{
    // COMMON_LT((" | device1B6F = %u", device1B6F)); // Commented to avoid bad looking logs



    switch (device1B6F)
    {
        case PciDevice1B6F::NONE:        return "NONE";
        case PciDevice1B6F::DEVICE_7023: return "DEVICE_7023";
        case PciDevice1B6F::DEVICE_7052: return "DEVICE_7052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B6F device1B6F) // TEST: NO
{
    // COMMON_LT((" | device1B6F = %u", device1B6F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B6F, enumToString(device1B6F));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B6F device1B6F) // TEST: NO
{
    // COMMON_LT((" | device1B6F = %u", device1B6F)); // Commented to avoid bad looking logs



    switch (device1B6F)
    {
        case PciDevice1B6F::DEVICE_7023: return "EJ168 USB 3.0 Host Controller";
        case PciDevice1B6F::DEVICE_7052: return "EJ188/EJ198 USB 3.0 Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B6F_PCIDEVICE1B6F_H
