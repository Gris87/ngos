// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060364_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060364_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060364: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104381CE = 0x104381CE
};



inline const char8* enumToString(PciSubDevice11060364 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060364::NONE:               return "NONE";
        case PciSubDevice11060364::SUBDEVICE_104381CE: return "SUBDEVICE_104381CE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060364 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060364 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060364::SUBDEVICE_104381CE: return "P5VD2-VM mothervoard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060364_H
