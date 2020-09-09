// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086107C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861376 = 0x80861376,
    SUBDEVICE_80861476 = 0x80861476
};



inline const char8* enumToString(PciSubDevice8086107C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107C::NONE:               return "NONE";
        case PciSubDevice8086107C::SUBDEVICE_80861376: return "SUBDEVICE_80861376";
        case PciSubDevice8086107C::SUBDEVICE_80861476: return "SUBDEVICE_80861476";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086107C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086107C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107C::SUBDEVICE_80861376: return "PRO/1000 GT Desktop Adapter";
        case PciSubDevice8086107C::SUBDEVICE_80861476: return "PRO/1000 GT Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107C_H
