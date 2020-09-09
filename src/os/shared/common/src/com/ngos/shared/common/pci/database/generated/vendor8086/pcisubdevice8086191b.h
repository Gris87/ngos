// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086191B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806E4 = 0x102806E4,
    SUBDEVICE_103C825B = 0x103C825B
};



inline const char8* enumToString(PciSubDevice8086191B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086191B::NONE:               return "NONE";
        case PciSubDevice8086191B::SUBDEVICE_102806E4: return "SUBDEVICE_102806E4";
        case PciSubDevice8086191B::SUBDEVICE_103C825B: return "SUBDEVICE_103C825B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086191B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086191B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086191B::SUBDEVICE_102806E4: return "XPS 15 9550";
        case PciSubDevice8086191B::SUBDEVICE_103C825B: return "OMEN-17-w001nv";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191B_H
