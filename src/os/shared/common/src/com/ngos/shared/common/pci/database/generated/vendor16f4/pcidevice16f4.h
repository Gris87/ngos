// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16F4: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8000 = 0x8000
};



inline const char8* enumToString(PciDevice16F4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16F4::NONE:        return "NONE";
        case PciDevice16F4::DEVICE_8000: return "DEVICE_8000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16F4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16F4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16F4::DEVICE_8000: return "VW2010";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H
