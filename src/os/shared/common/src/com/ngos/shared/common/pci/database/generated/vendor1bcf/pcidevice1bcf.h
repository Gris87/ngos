// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BCF_PCIDEVICE1BCF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BCF_PCIDEVICE1BCF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BCF: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_001C = 0x001C
};



inline const char8* enumToString(PciDevice1BCF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BCF::NONE:        return "NONE";
        case PciDevice1BCF::DEVICE_001C: return "DEVICE_001C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BCF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BCF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BCF::DEVICE_001C: return "Vector Engine 1.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BCF_PCIDEVICE1BCF_H
