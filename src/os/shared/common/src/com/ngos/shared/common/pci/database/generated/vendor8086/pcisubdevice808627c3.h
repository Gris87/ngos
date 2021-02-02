// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627C3: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_8086544E = 0x8086544E
};



inline const char8* enumToString(PciSubDevice808627C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C3::NONE:               return "NONE";
        case PciSubDevice808627C3::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627C3::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C3::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627C3::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C3_H
