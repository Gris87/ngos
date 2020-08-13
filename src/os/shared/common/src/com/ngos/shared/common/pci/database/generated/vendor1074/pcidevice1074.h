// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1074_PCIDEVICE1074_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1074_PCIDEVICE1074_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1074: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4E78 = 0x4E78
};



inline const char8* enumToString(PciDevice1074 device1074) // TEST: NO
{
    // COMMON_LT((" | device1074 = %u", device1074)); // Commented to avoid bad looking logs



    switch (device1074)
    {
        case PciDevice1074::NONE:        return "NONE";
        case PciDevice1074::DEVICE_4E78: return "DEVICE_4E78";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1074 device1074) // TEST: NO
{
    // COMMON_LT((" | device1074 = %u", device1074)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1074, enumToString(device1074));

    return res;
}



inline const char8* enumToHumanString(PciDevice1074 device1074) // TEST: NO
{
    // COMMON_LT((" | device1074 = %u", device1074)); // Commented to avoid bad looking logs



    switch (device1074)
    {
        case PciDevice1074::DEVICE_4E78: return "82c500/1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1074_PCIDEVICE1074_H
