// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860327_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860327_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860327: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3208 = 0x103C3208,
    SUBDEVICE_17751100 = 0x17751100
};



inline const char8* enumToString(PciSubDevice80860327 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860327::NONE:               return "NONE";
        case PciSubDevice80860327::SUBDEVICE_103C3208: return "SUBDEVICE_103C3208";
        case PciSubDevice80860327::SUBDEVICE_17751100: return "SUBDEVICE_17751100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860327 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860327 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860327::SUBDEVICE_103C3208: return "ProLiant DL140 G2";
        case PciSubDevice80860327::SUBDEVICE_17751100: return "CR11/VR11 Single Board Computer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860327_H
