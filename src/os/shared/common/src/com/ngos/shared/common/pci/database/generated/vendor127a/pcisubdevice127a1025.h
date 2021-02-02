// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1025_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1025_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1025: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF106A = 0x10CF106A,
    SUBDEVICE_122D4021 = 0x122D4021,
    SUBDEVICE_122D4022 = 0x122D4022,
    SUBDEVICE_122D4024 = 0x122D4024,
    SUBDEVICE_122D4025 = 0x122D4025
};



inline const char8* enumToString(PciSubDevice127A1025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1025::NONE:               return "NONE";
        case PciSubDevice127A1025::SUBDEVICE_10CF106A: return "SUBDEVICE_10CF106A";
        case PciSubDevice127A1025::SUBDEVICE_122D4021: return "SUBDEVICE_122D4021";
        case PciSubDevice127A1025::SUBDEVICE_122D4022: return "SUBDEVICE_122D4022";
        case PciSubDevice127A1025::SUBDEVICE_122D4024: return "SUBDEVICE_122D4024";
        case PciSubDevice127A1025::SUBDEVICE_122D4025: return "SUBDEVICE_122D4025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1025::SUBDEVICE_10CF106A: return "Fujitsu 235-DFSV";
        case PciSubDevice127A1025::SUBDEVICE_122D4021: return "Packard Bell MDP3858V-WE";
        case PciSubDevice127A1025::SUBDEVICE_122D4022: return "MDP3858SP-WE";
        case PciSubDevice127A1025::SUBDEVICE_122D4024: return "MDP3858V-UE";
        case PciSubDevice127A1025::SUBDEVICE_122D4025: return "MDP3858SP-UE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1025_H
