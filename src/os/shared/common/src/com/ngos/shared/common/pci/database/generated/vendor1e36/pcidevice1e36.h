// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E36: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1E36 device1E36) // TEST: NO
{
    // COMMON_LT((" | device1E36 = %u", device1E36)); // Commented to avoid bad looking logs



    switch (device1E36)
    {
        case PciDevice1E36::NONE:        return "NONE";
        case PciDevice1E36::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E36 device1E36) // TEST: NO
{
    // COMMON_LT((" | device1E36 = %u", device1E36)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E36, enumToString(device1E36));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E36 device1E36) // TEST: NO
{
    // COMMON_LT((" | device1E36 = %u", device1E36)); // Commented to avoid bad looking logs



    switch (device1E36)
    {
        case PciDevice1E36::DEVICE_0001: return "T10 [CloudBlazer]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H