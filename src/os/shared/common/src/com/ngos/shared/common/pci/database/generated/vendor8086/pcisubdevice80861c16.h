// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C16_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C16_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861C16: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804AA = 0x102804AA,
    SUBDEVICE_17AA21CF = 0x17AA21CF
};



inline const char8* enumToString(PciSubDevice80861C16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C16::NONE:               return "NONE";
        case PciSubDevice80861C16::SUBDEVICE_102804AA: return "SUBDEVICE_102804AA";
        case PciSubDevice80861C16::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861C16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861C16 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C16::SUBDEVICE_102804AA: return "XPS 8300";
        case PciSubDevice80861C16::SUBDEVICE_17AA21CF: return "ThinkPad T520";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C16_H
