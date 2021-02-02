// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11456_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11456_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11456: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_122D4035 = 0x122D4035,
    SUBDEVICE_122D4302 = 0x122D4302
};



inline const char8* enumToString(PciSubDevice14F11456 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11456::NONE:               return "NONE";
        case PciSubDevice14F11456::SUBDEVICE_122D4035: return "SUBDEVICE_122D4035";
        case PciSubDevice14F11456::SUBDEVICE_122D4302: return "SUBDEVICE_122D4302";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11456 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11456 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11456::SUBDEVICE_122D4035: return "Dell Europa - MDP3900V-W";
        case PciSubDevice14F11456::SUBDEVICE_122D4302: return "Dell MP3930V-W(C) MiniPCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11456_H
