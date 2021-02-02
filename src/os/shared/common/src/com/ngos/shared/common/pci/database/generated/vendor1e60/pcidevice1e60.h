// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E60_PCIDEVICE1E60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E60_PCIDEVICE1E60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E60: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2864 = 0x2864
};



inline const char8* enumToString(PciDevice1E60 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E60::NONE:        return "NONE";
        case PciDevice1E60::DEVICE_2864: return "DEVICE_2864";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E60 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E60 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E60::DEVICE_2864: return "Hailo-8 AI Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E60_PCIDEVICE1E60_H
