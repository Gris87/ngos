// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50210_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50210_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50210: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5DF2E = 0x19E5DF2E
};



inline const char8* enumToString(PciSubDevice19E50210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50210::NONE:               return "NONE";
        case PciSubDevice19E50210::SUBDEVICE_19E5DF2E: return "SUBDEVICE_19E5DF2E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50210 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50210::SUBDEVICE_19E5DF2E: return "Hi1822 MZ532 MEZZ (4*25GE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50210_H
