// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0272_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0272_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0272: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A34 = 0x103C2A34,
    SUBDEVICE_105B0CAD = 0x105B0CAD
};



inline const char8* enumToString(PciSubDevice10DE0272 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0272::NONE:               return "NONE";
        case PciSubDevice10DE0272::SUBDEVICE_103C2A34: return "SUBDEVICE_103C2A34";
        case PciSubDevice10DE0272::SUBDEVICE_105B0CAD: return "SUBDEVICE_105B0CAD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0272 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0272 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0272::SUBDEVICE_103C2A34: return "Pavilion a1677c";
        case PciSubDevice10DE0272::SUBDEVICE_105B0CAD: return "Winfast 6100K8MB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0272_H
