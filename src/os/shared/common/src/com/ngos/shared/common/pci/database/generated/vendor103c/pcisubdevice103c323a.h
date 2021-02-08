// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C323A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3241 = 0x103C3241,
    SUBDEVICE_103C3243 = 0x103C3243,
    SUBDEVICE_103C3245 = 0x103C3245,
    SUBDEVICE_103C3247 = 0x103C3247,
    SUBDEVICE_103C3249 = 0x103C3249,
    SUBDEVICE_103C324A = 0x103C324A,
    SUBDEVICE_103C324B = 0x103C324B
};



inline const char8* enumToString(PciSubDevice103C323A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323A::NONE:               return "NONE";
        case PciSubDevice103C323A::SUBDEVICE_103C3241: return "SUBDEVICE_103C3241";
        case PciSubDevice103C323A::SUBDEVICE_103C3243: return "SUBDEVICE_103C3243";
        case PciSubDevice103C323A::SUBDEVICE_103C3245: return "SUBDEVICE_103C3245";
        case PciSubDevice103C323A::SUBDEVICE_103C3247: return "SUBDEVICE_103C3247";
        case PciSubDevice103C323A::SUBDEVICE_103C3249: return "SUBDEVICE_103C3249";
        case PciSubDevice103C323A::SUBDEVICE_103C324A: return "SUBDEVICE_103C324A";
        case PciSubDevice103C323A::SUBDEVICE_103C324B: return "SUBDEVICE_103C324B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C323A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C323A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C323A::SUBDEVICE_103C3241: return "Smart Array P212";
        case PciSubDevice103C323A::SUBDEVICE_103C3243: return "Smart Array P410";
        case PciSubDevice103C323A::SUBDEVICE_103C3245: return "Smart Array P410i";
        case PciSubDevice103C323A::SUBDEVICE_103C3247: return "Smart Array P411";
        case PciSubDevice103C323A::SUBDEVICE_103C3249: return "Smart Array P812";
        case PciSubDevice103C323A::SUBDEVICE_103C324A: return "Smart Array 712m (Mezzanine RAID controller)";
        case PciSubDevice103C323A::SUBDEVICE_103C324B: return "Smart Array P711m (Mezzanine RAID controller)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C323A_H
