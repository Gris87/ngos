// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416AA: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3102 = 0x103C3102,
    SUBDEVICE_103C310C = 0x103C310C
};



inline const char8* enumToString(PciSubDevice14E416AA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AA::NONE:               return "NONE";
        case PciSubDevice14E416AA::SUBDEVICE_103C3102: return "SUBDEVICE_103C3102";
        case PciSubDevice14E416AA::SUBDEVICE_103C310C: return "SUBDEVICE_103C310C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416AA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416AA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AA::SUBDEVICE_103C3102: return "NC370F MultifuNCtion Gigabit Server Adapter";
        case PciSubDevice14E416AA::SUBDEVICE_103C310C: return "NC370i Multifunction Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AA_H
