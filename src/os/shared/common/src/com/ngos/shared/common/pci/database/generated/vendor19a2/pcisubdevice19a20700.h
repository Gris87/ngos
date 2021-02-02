// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20700_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20700_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19A20700: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1747 = 0x103C1747,
    SUBDEVICE_103C1749 = 0x103C1749,
    SUBDEVICE_103C174A = 0x103C174A,
    SUBDEVICE_103C174B = 0x103C174B,
    SUBDEVICE_103C3314 = 0x103C3314
};



inline const char8* enumToString(PciSubDevice19A20700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20700::NONE:               return "NONE";
        case PciSubDevice19A20700::SUBDEVICE_103C1747: return "SUBDEVICE_103C1747";
        case PciSubDevice19A20700::SUBDEVICE_103C1749: return "SUBDEVICE_103C1749";
        case PciSubDevice19A20700::SUBDEVICE_103C174A: return "SUBDEVICE_103C174A";
        case PciSubDevice19A20700::SUBDEVICE_103C174B: return "SUBDEVICE_103C174B";
        case PciSubDevice19A20700::SUBDEVICE_103C3314: return "SUBDEVICE_103C3314";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19A20700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19A20700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19A20700::SUBDEVICE_103C1747: return "NC550SFP DualPort 10GbE Server Adapter";
        case PciSubDevice19A20700::SUBDEVICE_103C1749: return "NC550SFP Dual Port Server Adapter";
        case PciSubDevice19A20700::SUBDEVICE_103C174A: return "NC551m Dual Port FlexFabric 10Gb Adapter";
        case PciSubDevice19A20700::SUBDEVICE_103C174B: return "StorageWorks NC550 DualPort Converged Network Adapter";
        case PciSubDevice19A20700::SUBDEVICE_103C3314: return "NC551i Dual Port FlexFabric 10Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19A2_PCISUBDEVICE19A20700_H
