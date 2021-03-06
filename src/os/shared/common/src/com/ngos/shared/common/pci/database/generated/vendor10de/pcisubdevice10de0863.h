// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0863_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0863_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0863: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B00AA = 0x106B00AA
};



inline const char8* enumToString(PciSubDevice10DE0863 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0863::NONE:               return "NONE";
        case PciSubDevice10DE0863::SUBDEVICE_106B00AA: return "SUBDEVICE_106B00AA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0863 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0863 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0863::SUBDEVICE_106B00AA: return "MacBook5, 1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0863_H
