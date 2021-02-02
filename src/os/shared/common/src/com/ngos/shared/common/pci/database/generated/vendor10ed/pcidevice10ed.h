// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10ED_PCIDEVICE10ED_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10ED_PCIDEVICE10ED_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10ED: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7310 = 0x7310
};



inline const char8* enumToString(PciDevice10ED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10ED::NONE:        return "NONE";
        case PciDevice10ED::DEVICE_7310: return "DEVICE_7310";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10ED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10ED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10ED::DEVICE_7310: return "V7310";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10ED_PCIDEVICE10ED_H
