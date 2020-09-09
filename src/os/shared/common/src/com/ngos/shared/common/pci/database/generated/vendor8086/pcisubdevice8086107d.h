// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086107D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861082 = 0x80861082,
    SUBDEVICE_80861084 = 0x80861084,
    SUBDEVICE_80861092 = 0x80861092
};



inline const char8* enumToString(PciSubDevice8086107D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107D::NONE:               return "NONE";
        case PciSubDevice8086107D::SUBDEVICE_80861082: return "SUBDEVICE_80861082";
        case PciSubDevice8086107D::SUBDEVICE_80861084: return "SUBDEVICE_80861084";
        case PciSubDevice8086107D::SUBDEVICE_80861092: return "SUBDEVICE_80861092";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086107D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086107D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107D::SUBDEVICE_80861082: return "PRO/1000 PT Server Adapter";
        case PciSubDevice8086107D::SUBDEVICE_80861084: return "PRO/1000 PT Server Adapter";
        case PciSubDevice8086107D::SUBDEVICE_80861092: return "PRO/1000 PT Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107D_H
