// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AC1_PCIDEVICE1AC1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AC1_PCIDEVICE1AC1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AC1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_089A = 0x089A
};



inline const char8* enumToString(PciDevice1AC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AC1::NONE:        return "NONE";
        case PciDevice1AC1::DEVICE_089A: return "DEVICE_089A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AC1::DEVICE_089A: return "Coral Edge TPU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AC1_PCIDEVICE1AC1_H
