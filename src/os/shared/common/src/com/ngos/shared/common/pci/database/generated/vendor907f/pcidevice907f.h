// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR907F_PCIDEVICE907F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR907F_PCIDEVICE907F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice907F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2015 = 0x2015
};



inline const char8* enumToString(PciDevice907F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice907F::NONE:        return "NONE";
        case PciDevice907F::DEVICE_2015: return "DEVICE_2015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice907F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice907F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice907F::DEVICE_2015: return "IDE-2015PL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR907F_PCIDEVICE907F_H
