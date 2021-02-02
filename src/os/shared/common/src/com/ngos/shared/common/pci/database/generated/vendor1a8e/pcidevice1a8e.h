// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8E_PCIDEVICE1A8E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8E_PCIDEVICE1A8E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A8E: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2090 = 0x2090
};



inline const char8* enumToString(PciDevice1A8E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A8E::NONE:        return "NONE";
        case PciDevice1A8E::DEVICE_2090: return "DEVICE_2090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A8E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A8E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A8E::DEVICE_2090: return "Model 2090 PCI Express";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A8E_PCIDEVICE1A8E_H
