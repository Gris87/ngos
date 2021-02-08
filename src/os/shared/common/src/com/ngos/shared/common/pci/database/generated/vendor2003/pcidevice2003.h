// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2003_PCIDEVICE2003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2003_PCIDEVICE2003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2003: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8800 = 0x8800
};



inline const char8* enumToString(PciDevice2003 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2003::NONE:        return "NONE";
        case PciDevice2003::DEVICE_8800: return "DEVICE_8800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2003 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice2003 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2003::DEVICE_8800: return "LM-I56N";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2003_PCIDEVICE2003_H
