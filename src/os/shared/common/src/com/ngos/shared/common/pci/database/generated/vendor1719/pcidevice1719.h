// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1719_PCIDEVICE1719_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1719_PCIDEVICE1719_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1719: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000
};



inline const char8* enumToString(PciDevice1719 device1719) // TEST: NO
{
    // COMMON_LT((" | device1719 = %u", device1719)); // Commented to avoid bad looking logs



    switch (device1719)
    {
        case PciDevice1719::NONE:        return "NONE";
        case PciDevice1719::DEVICE_1000: return "DEVICE_1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1719 device1719) // TEST: NO
{
    // COMMON_LT((" | device1719 = %u", device1719)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1719, enumToString(device1719));

    return res;
}



inline const char8* enumToHumanString(PciDevice1719 device1719) // TEST: NO
{
    // COMMON_LT((" | device1719 = %u", device1719)); // Commented to avoid bad looking logs



    switch (device1719)
    {
        case PciDevice1719::DEVICE_1000: return "NPA Access Network Processor Family";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1719_PCIDEVICE1719_H
