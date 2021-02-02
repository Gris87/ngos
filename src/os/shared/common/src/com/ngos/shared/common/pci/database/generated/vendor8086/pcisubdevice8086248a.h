// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086248A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086248A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086248A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110030 = 0x0E110030,
    SUBDEVICE_10140220 = 0x10140220,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_80861958 = 0x80861958,
    SUBDEVICE_80864541 = 0x80864541
};



inline const char8* enumToString(PciSubDevice8086248A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086248A::NONE:               return "NONE";
        case PciSubDevice8086248A::SUBDEVICE_0E110030: return "SUBDEVICE_0E110030";
        case PciSubDevice8086248A::SUBDEVICE_10140220: return "SUBDEVICE_10140220";
        case PciSubDevice8086248A::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice8086248A::SUBDEVICE_80861958: return "SUBDEVICE_80861958";
        case PciSubDevice8086248A::SUBDEVICE_80864541: return "SUBDEVICE_80864541";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086248A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086248A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086248A::SUBDEVICE_0E110030: return "Evo N600c";
        case PciSubDevice8086248A::SUBDEVICE_10140220: return "ThinkPad A/T/X Series";
        case PciSubDevice8086248A::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice8086248A::SUBDEVICE_80861958: return "vpr Matrix 170B4";
        case PciSubDevice8086248A::SUBDEVICE_80864541: return "Latitude C640";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086248A_H
