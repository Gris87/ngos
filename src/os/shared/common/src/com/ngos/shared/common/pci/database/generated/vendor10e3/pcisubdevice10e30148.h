// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCISUBDEVICE10E30148_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCISUBDEVICE10E30148_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10E30148: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17751100 = 0x17751100
};



inline const char8* enumToString(PciSubDevice10E30148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10E30148::NONE:               return "NONE";
        case PciSubDevice10E30148::SUBDEVICE_17751100: return "SUBDEVICE_17751100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10E30148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10E30148 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10E30148::SUBDEVICE_17751100: return "VR11 Single Board Computer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E3_PCISUBDEVICE10E30148_H
