// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1208_PCIDEVICE1208_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1208_PCIDEVICE1208_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1208: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4853 = 0x4853
};



inline const char8* enumToString(PciDevice1208 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1208::NONE:        return "NONE";
        case PciDevice1208::DEVICE_4853: return "DEVICE_4853";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1208 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1208 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1208::DEVICE_4853: return "HS-Link Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1208_PCIDEVICE1208_H
