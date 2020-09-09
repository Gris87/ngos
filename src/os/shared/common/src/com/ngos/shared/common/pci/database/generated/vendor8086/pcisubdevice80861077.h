// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861077_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861077_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861077: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_80860077 = 0x80860077,
    SUBDEVICE_80861077 = 0x80861077
};



inline const char8* enumToString(PciSubDevice80861077 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861077::NONE:               return "NONE";
        case PciSubDevice80861077::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice80861077::SUBDEVICE_80860077: return "SUBDEVICE_80860077";
        case PciSubDevice80861077::SUBDEVICE_80861077: return "SUBDEVICE_80861077";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861077 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861077 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861077::SUBDEVICE_11790001: return "PRO/1000 MT Mobile Connection";
        case PciSubDevice80861077::SUBDEVICE_80860077: return "PRO/1000 MT Mobile Connection";
        case PciSubDevice80861077::SUBDEVICE_80861077: return "PRO/1000 MT Mobile Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861077_H
