// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127E_PCIDEVICE127E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127E_PCIDEVICE127E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice127E: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010
};



inline const char8* enumToString(PciDevice127E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice127E::NONE:        return "NONE";
        case PciDevice127E::DEVICE_0010: return "DEVICE_0010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice127E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice127E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice127E::DEVICE_0010: return "Videum 1000 Plus";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127E_PCIDEVICE127E_H
