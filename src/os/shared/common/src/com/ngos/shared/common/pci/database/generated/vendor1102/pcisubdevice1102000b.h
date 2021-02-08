// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE1102000B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE1102000B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1102000B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020041 = 0x11020041,
    SUBDEVICE_11020062 = 0x11020062
};



inline const char8* enumToString(PciSubDevice1102000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1102000B::NONE:               return "NONE";
        case PciSubDevice1102000B::SUBDEVICE_11020041: return "SUBDEVICE_11020041";
        case PciSubDevice1102000B::SUBDEVICE_11020062: return "SUBDEVICE_11020062";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1102000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1102000B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1102000B::SUBDEVICE_11020041: return "SB0880 [SoundBlaster X-Fi Titanium PCI-e]";
        case PciSubDevice1102000B::SUBDEVICE_11020062: return "SB1270 [SoundBlaster X-Fi Titanium HD]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE1102000B_H
