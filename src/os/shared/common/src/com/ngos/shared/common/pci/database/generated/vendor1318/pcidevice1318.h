// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1318_PCIDEVICE1318_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1318_PCIDEVICE1318_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1318: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0911 = 0x0911
};



inline const char8* enumToString(PciDevice1318 device1318) // TEST: NO
{
    // COMMON_LT((" | device1318 = %u", device1318)); // Commented to avoid bad looking logs



    switch (device1318)
    {
        case PciDevice1318::NONE:        return "NONE";
        case PciDevice1318::DEVICE_0911: return "DEVICE_0911";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1318 device1318) // TEST: NO
{
    // COMMON_LT((" | device1318 = %u", device1318)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1318, enumToString(device1318));

    return res;
}



inline const char8* enumToHumanString(PciDevice1318 device1318) // TEST: NO
{
    // COMMON_LT((" | device1318 = %u", device1318)); // Commented to avoid bad looking logs



    switch (device1318)
    {
        case PciDevice1318::DEVICE_0911: return "GNIC-II PCI Gigabit Ethernet [Hamachi]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1318_PCIDEVICE1318_H
