// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2363_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2363_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice197B2363: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104381E4 = 0x104381E4,
    SUBDEVICE_1458B000 = 0x1458B000,
    SUBDEVICE_18492363 = 0x18492363
};



inline const char8* enumToString(PciSubDevice197B2363 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2363::NONE:               return "NONE";
        case PciSubDevice197B2363::SUBDEVICE_104381E4: return "SUBDEVICE_104381E4";
        case PciSubDevice197B2363::SUBDEVICE_1458B000: return "SUBDEVICE_1458B000";
        case PciSubDevice197B2363::SUBDEVICE_18492363: return "SUBDEVICE_18492363";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice197B2363 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice197B2363 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice197B2363::SUBDEVICE_104381E4: return "P5B [JMB363]";
        case PciSubDevice197B2363::SUBDEVICE_1458B000: return "Motherboard";
        case PciSubDevice197B2363::SUBDEVICE_18492363: return "Motherboard (one of many)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR197B_PCISUBDEVICE197B2363_H
