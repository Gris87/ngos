// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861016_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861016_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861016: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014052C = 0x1014052C,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_80861016 = 0x80861016
};



inline const char8* enumToString(PciSubDevice80861016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861016::NONE:               return "NONE";
        case PciSubDevice80861016::SUBDEVICE_1014052C: return "SUBDEVICE_1014052C";
        case PciSubDevice80861016::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice80861016::SUBDEVICE_80861016: return "SUBDEVICE_80861016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861016::SUBDEVICE_1014052C: return "PRO/1000 MT Mobile Connection";
        case PciSubDevice80861016::SUBDEVICE_11790001: return "PRO/1000 MT Mobile Connection";
        case PciSubDevice80861016::SUBDEVICE_80861016: return "PRO/1000 MT Mobile Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861016_H
