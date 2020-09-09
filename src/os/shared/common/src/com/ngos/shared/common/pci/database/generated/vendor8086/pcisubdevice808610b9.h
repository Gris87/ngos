// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610B9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C704A = 0x103C704A,
    SUBDEVICE_80861083 = 0x80861083,
    SUBDEVICE_80861093 = 0x80861093
};



inline const char8* enumToString(PciSubDevice808610B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610B9::NONE:               return "NONE";
        case PciSubDevice808610B9::SUBDEVICE_103C704A: return "SUBDEVICE_103C704A";
        case PciSubDevice808610B9::SUBDEVICE_80861083: return "SUBDEVICE_80861083";
        case PciSubDevice808610B9::SUBDEVICE_80861093: return "SUBDEVICE_80861093";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610B9::SUBDEVICE_103C704A: return "110T PCIe Gigabit Server Adapter";
        case PciSubDevice808610B9::SUBDEVICE_80861083: return "PRO/1000 PT Desktop Adapter";
        case PciSubDevice808610B9::SUBDEVICE_80861093: return "PRO/1000 PT Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B9_H
