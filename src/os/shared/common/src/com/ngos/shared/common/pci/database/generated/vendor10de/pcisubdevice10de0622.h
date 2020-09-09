// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0622_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0622_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0622: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107D2AC1 = 0x107D2AC1,
    SUBDEVICE_14583481 = 0x14583481
};



inline const char8* enumToString(PciSubDevice10DE0622 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0622::NONE:               return "NONE";
        case PciSubDevice10DE0622::SUBDEVICE_107D2AC1: return "SUBDEVICE_107D2AC1";
        case PciSubDevice10DE0622::SUBDEVICE_14583481: return "SUBDEVICE_14583481";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0622 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0622 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0622::SUBDEVICE_107D2AC1: return "WinFast PX9600GT 1024MB";
        case PciSubDevice10DE0622::SUBDEVICE_14583481: return "GV-NX96T512HP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0622_H
