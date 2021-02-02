// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861009: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140268 = 0x10140268,
    SUBDEVICE_80861109 = 0x80861109,
    SUBDEVICE_80862109 = 0x80862109
};



inline const char8* enumToString(PciSubDevice80861009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861009::NONE:               return "NONE";
        case PciSubDevice80861009::SUBDEVICE_10140268: return "SUBDEVICE_10140268";
        case PciSubDevice80861009::SUBDEVICE_80861109: return "SUBDEVICE_80861109";
        case PciSubDevice80861009::SUBDEVICE_80862109: return "SUBDEVICE_80862109";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861009::SUBDEVICE_10140268: return "iSeries Gigabit Ethernet Adapter";
        case PciSubDevice80861009::SUBDEVICE_80861109: return "PRO/1000 XF Server Adapter";
        case PciSubDevice80861009::SUBDEVICE_80862109: return "PRO/1000 XF Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861009_H
