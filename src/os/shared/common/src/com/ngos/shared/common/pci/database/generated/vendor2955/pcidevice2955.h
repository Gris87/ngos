// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2955_PCIDEVICE2955_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2955_PCIDEVICE2955_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2955: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6E61 = 0x6E61
};



inline const char8* enumToString(PciDevice2955 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2955::NONE:        return "NONE";
        case PciDevice2955::DEVICE_6E61: return "DEVICE_6E61";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2955 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice2955 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice2955::DEVICE_6E61: return "OHCI USB 1.1 controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2955_PCIDEVICE2955_H
