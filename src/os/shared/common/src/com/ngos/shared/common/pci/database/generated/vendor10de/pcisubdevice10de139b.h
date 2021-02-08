// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE139B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806E4 = 0x102806E4,
    SUBDEVICE_103C2B4C = 0x103C2B4C
};



inline const char8* enumToString(PciSubDevice10DE139B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE139B::NONE:               return "NONE";
        case PciSubDevice10DE139B::SUBDEVICE_102806E4: return "SUBDEVICE_102806E4";
        case PciSubDevice10DE139B::SUBDEVICE_103C2B4C: return "SUBDEVICE_103C2B4C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE139B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE139B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE139B::SUBDEVICE_102806E4: return "XPS 15 9550";
        case PciSubDevice10DE139B::SUBDEVICE_103C2B4C: return "GeForce GTX 960A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139B_H
