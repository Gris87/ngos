// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2361_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2361_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice197B2361: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14627235 = 0x14627235
};



inline const char8* enumToString(PciSubDevice197B2361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2361::NONE:               return "NONE";
        case PciSubDevice197B2361::SUBDEVICE_14627235: return "SUBDEVICE_14627235";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice197B2361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice197B2361 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2361::SUBDEVICE_14627235: return "P965 Neo MS-7235 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2361_H
