// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11027005: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11021001 = 0x11021001,
    SUBDEVICE_11021002 = 0x11021002
};



inline const char8* enumToString(PciSubDevice11027005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11027005::NONE:               return "NONE";
        case PciSubDevice11027005::SUBDEVICE_11021001: return "SUBDEVICE_11021001";
        case PciSubDevice11027005::SUBDEVICE_11021002: return "SUBDEVICE_11021002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11027005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11027005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11027005::SUBDEVICE_11021001: return "SB0310 Audigy LS MIDI/Game port";
        case PciSubDevice11027005::SUBDEVICE_11021002: return "SB0312 Audigy LS MIDI/Game port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11027005_H
