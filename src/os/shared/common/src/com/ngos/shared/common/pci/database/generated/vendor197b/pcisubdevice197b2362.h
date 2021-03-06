// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2362_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2362_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice197B2362: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438460 = 0x10438460
};



inline const char8* enumToString(PciSubDevice197B2362 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2362::NONE:               return "NONE";
        case PciSubDevice197B2362::SUBDEVICE_10438460: return "SUBDEVICE_10438460";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice197B2362 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice197B2362 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2362::SUBDEVICE_10438460: return "P8P67 Deluxe Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2362_H
