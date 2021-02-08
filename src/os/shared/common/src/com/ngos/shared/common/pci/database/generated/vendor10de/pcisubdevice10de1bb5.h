// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BB5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BB5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1BB5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C842F = 0x103C842F
};



inline const char8* enumToString(PciSubDevice10DE1BB5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BB5::NONE:               return "NONE";
        case PciSubDevice10DE1BB5::SUBDEVICE_103C842F: return "SUBDEVICE_103C842F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1BB5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1BB5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BB5::SUBDEVICE_103C842F: return "P5200 [Zbook 17 G5 mobile workstation]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BB5_H
