// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086107E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861084 = 0x80861084,
    SUBDEVICE_80861085 = 0x80861085,
    SUBDEVICE_80861094 = 0x80861094
};



inline const char8* enumToString(PciSubDevice8086107E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107E::NONE:               return "NONE";
        case PciSubDevice8086107E::SUBDEVICE_80861084: return "SUBDEVICE_80861084";
        case PciSubDevice8086107E::SUBDEVICE_80861085: return "SUBDEVICE_80861085";
        case PciSubDevice8086107E::SUBDEVICE_80861094: return "SUBDEVICE_80861094";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086107E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086107E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107E::SUBDEVICE_80861084: return "PRO/1000 PF Server Adapter";
        case PciSubDevice8086107E::SUBDEVICE_80861085: return "PRO/1000 PF Server Adapter";
        case PciSubDevice8086107E::SUBDEVICE_80861094: return "PRO/1000 PF Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107E_H
