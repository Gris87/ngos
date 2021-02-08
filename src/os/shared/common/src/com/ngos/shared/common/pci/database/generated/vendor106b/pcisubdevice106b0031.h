// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCISUBDEVICE106B0031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCISUBDEVICE106B0031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice106B0031: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B5811 = 0x106B5811
};



inline const char8* enumToString(PciSubDevice106B0031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice106B0031::NONE:               return "NONE";
        case PciSubDevice106B0031::SUBDEVICE_106B5811: return "SUBDEVICE_106B5811";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice106B0031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice106B0031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice106B0031::SUBDEVICE_106B5811: return "iBook G4 2004";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR106B_PCISUBDEVICE106B0031_H
