// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627B0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_8086544E = 0x8086544E
};



inline const char8* enumToString(PciSubDevice808627B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B0::NONE:               return "NONE";
        case PciSubDevice808627B0::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice808627B0::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B0::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice808627B0::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B0_H
