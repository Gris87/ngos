// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1543_PCIDEVICE1543_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1543_PCIDEVICE1543_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1543: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3052 = 0x3052,
    DEVICE_4C22 = 0x4C22
};



inline const char8* enumToString(PciDevice1543 device1543) // TEST: NO
{
    // COMMON_LT((" | device1543 = %u", device1543)); // Commented to avoid bad looking logs



    switch (device1543)
    {
        case PciDevice1543::NONE:        return "NONE";
        case PciDevice1543::DEVICE_3052: return "DEVICE_3052";
        case PciDevice1543::DEVICE_4C22: return "DEVICE_4C22";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1543 device1543) // TEST: NO
{
    // COMMON_LT((" | device1543 = %u", device1543)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1543, enumToString(device1543));

    return res;
}



inline const char8* enumToHumanString(PciDevice1543 device1543) // TEST: NO
{
    // COMMON_LT((" | device1543 = %u", device1543)); // Commented to avoid bad looking logs



    switch (device1543)
    {
        case PciDevice1543::DEVICE_3052: return "Intel 537 [Winmodem]";
        case PciDevice1543::DEVICE_4C22: return "Si3036 MC'97 DAA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1543_PCIDEVICE1543_H
