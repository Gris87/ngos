// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C0030: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C8013 = 0x117C8013,
    SUBDEVICE_117C8014 = 0x117C8014,
    SUBDEVICE_117C8027 = 0x117C8027,
    SUBDEVICE_117C802F = 0x117C802F
};



inline const char8* enumToString(PciSubDevice117C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0030::NONE:               return "NONE";
        case PciSubDevice117C0030::SUBDEVICE_117C8013: return "SUBDEVICE_117C8013";
        case PciSubDevice117C0030::SUBDEVICE_117C8014: return "SUBDEVICE_117C8014";
        case PciSubDevice117C0030::SUBDEVICE_117C8027: return "SUBDEVICE_117C8027";
        case PciSubDevice117C0030::SUBDEVICE_117C802F: return "SUBDEVICE_117C802F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0030::SUBDEVICE_117C8013: return "ExpressPCI UL4D";
        case PciSubDevice117C0030::SUBDEVICE_117C8014: return "ExpressPCI UL4S";
        case PciSubDevice117C0030::SUBDEVICE_117C8027: return "ExpressPCI UL5D";
        case PciSubDevice117C0030::SUBDEVICE_117C802F: return "ExpressPCI UL5D Low Profile";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0030_H
