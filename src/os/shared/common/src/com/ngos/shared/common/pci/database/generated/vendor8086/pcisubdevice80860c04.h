// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860C04_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860C04_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860C04: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1909 = 0x103C1909,
    SUBDEVICE_17AA220E = 0x17AA220E
};



inline const char8* enumToString(PciSubDevice80860C04 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860C04::NONE:               return "NONE";
        case PciSubDevice80860C04::SUBDEVICE_103C1909: return "SUBDEVICE_103C1909";
        case PciSubDevice80860C04::SUBDEVICE_17AA220E: return "SUBDEVICE_17AA220E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860C04 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860C04 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860C04::SUBDEVICE_103C1909: return "ZBook 15";
        case PciSubDevice80860C04::SUBDEVICE_17AA220E: return "ThinkPad T440p";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860C04_H
