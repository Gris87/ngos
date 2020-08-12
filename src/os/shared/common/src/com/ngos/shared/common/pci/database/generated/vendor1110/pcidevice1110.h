// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1110_PCIDEVICE1110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1110_PCIDEVICE1110_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1110: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6037 = 0x6037,
    DEVICE_6073 = 0x6073
};



inline const char8* enumToString(PciDevice1110 device1110) // TEST: NO
{
    // COMMON_LT((" | device1110 = %u", device1110)); // Commented to avoid bad looking logs



    switch (device1110)
    {
        case PciDevice1110::NONE:        return "NONE";
        case PciDevice1110::DEVICE_6037: return "DEVICE_6037";
        case PciDevice1110::DEVICE_6073: return "DEVICE_6073";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1110 device1110) // TEST: NO
{
    // COMMON_LT((" | device1110 = %u", device1110)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1110, enumToString(device1110));

    return res;
}



inline const char8* enumToHumanString(PciDevice1110 device1110) // TEST: NO
{
    // COMMON_LT((" | device1110 = %u", device1110)); // Commented to avoid bad looking logs



    switch (device1110)
    {
        case PciDevice1110::DEVICE_6037: return "Firepower Powerized SMP I/O ASIC";
        case PciDevice1110::DEVICE_6073: return "Firepower Powerized SMP I/O ASIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1110_PCIDEVICE1110_H
