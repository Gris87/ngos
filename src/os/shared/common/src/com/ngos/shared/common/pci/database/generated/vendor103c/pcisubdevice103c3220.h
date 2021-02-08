// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3220_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3220_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C3220: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3225 = 0x103C3225
};



inline const char8* enumToString(PciSubDevice103C3220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3220::NONE:               return "NONE";
        case PciSubDevice103C3220::SUBDEVICE_103C3225: return "SUBDEVICE_103C3225";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C3220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C3220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3220::SUBDEVICE_103C3225: return "3 Gb/s SAS RAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3220_H
