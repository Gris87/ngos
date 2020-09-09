// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50200: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D139 = 0x19E5D139,
    SUBDEVICE_19E5D13D = 0x19E5D13D,
    SUBDEVICE_19E5D147 = 0x19E5D147
};



inline const char8* enumToString(PciSubDevice19E50200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50200::NONE:               return "NONE";
        case PciSubDevice19E50200::SUBDEVICE_19E5D139: return "SUBDEVICE_19E5D139";
        case PciSubDevice19E50200::SUBDEVICE_19E5D13D: return "SUBDEVICE_19E5D13D";
        case PciSubDevice19E50200::SUBDEVICE_19E5D147: return "SUBDEVICE_19E5D147";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50200::SUBDEVICE_19E5D139: return "Hi1822 SP572 (2*100GE)";
        case PciSubDevice19E50200::SUBDEVICE_19E5D13D: return "Hi1822 SC371 (2*100GE)";
        case PciSubDevice19E50200::SUBDEVICE_19E5D147: return "Hi1822 SP573 (2*100GE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50200_H
