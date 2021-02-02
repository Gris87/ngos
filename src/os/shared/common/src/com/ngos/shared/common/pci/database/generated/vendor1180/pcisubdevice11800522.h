// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800522_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800522_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800522: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101401CF = 0x101401CF,
    SUBDEVICE_10431967 = 0x10431967
};



inline const char8* enumToString(PciSubDevice11800522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800522::NONE:               return "NONE";
        case PciSubDevice11800522::SUBDEVICE_101401CF: return "SUBDEVICE_101401CF";
        case PciSubDevice11800522::SUBDEVICE_10431967: return "SUBDEVICE_10431967";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800522::SUBDEVICE_101401CF: return "ThinkPad A30p";
        case PciSubDevice11800522::SUBDEVICE_10431967: return "V6800V";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800522_H
