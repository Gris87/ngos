// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861013: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860013 = 0x80860013,
    SUBDEVICE_80861013 = 0x80861013,
    SUBDEVICE_80861113 = 0x80861113
};



inline const char8* enumToString(PciSubDevice80861013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861013::NONE:               return "NONE";
        case PciSubDevice80861013::SUBDEVICE_80860013: return "SUBDEVICE_80860013";
        case PciSubDevice80861013::SUBDEVICE_80861013: return "SUBDEVICE_80861013";
        case PciSubDevice80861013::SUBDEVICE_80861113: return "SUBDEVICE_80861113";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861013::SUBDEVICE_80860013: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861013::SUBDEVICE_80861013: return "PRO/1000 MT Network Connection";
        case PciSubDevice80861013::SUBDEVICE_80861113: return "PRO/1000 MT Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861013_H
