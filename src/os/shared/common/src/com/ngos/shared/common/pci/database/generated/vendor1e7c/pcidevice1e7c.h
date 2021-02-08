// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E7C_PCIDEVICE1E7C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E7C_PCIDEVICE1E7C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E7C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_BCA1 = 0xBCA1
};



inline const char8* enumToString(PciDevice1E7C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E7C::NONE:        return "NONE";
        case PciDevice1E7C::DEVICE_BCA1: return "DEVICE_BCA1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E7C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E7C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E7C::DEVICE_BCA1: return "AKD1000 Neural Network Coprocessor [Akida]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E7C_PCIDEVICE1E7C_H
