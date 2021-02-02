// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860166_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860166_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860166: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431517 = 0x10431517,
    SUBDEVICE_10432103 = 0x10432103,
    SUBDEVICE_10CF16C1 = 0x10CF16C1
};



inline const char8* enumToString(PciSubDevice80860166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860166::NONE:               return "NONE";
        case PciSubDevice80860166::SUBDEVICE_10431517: return "SUBDEVICE_10431517";
        case PciSubDevice80860166::SUBDEVICE_10432103: return "SUBDEVICE_10432103";
        case PciSubDevice80860166::SUBDEVICE_10CF16C1: return "SUBDEVICE_10CF16C1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860166::SUBDEVICE_10431517: return "Zenbook Prime UX31A";
        case PciSubDevice80860166::SUBDEVICE_10432103: return "N56VZ";
        case PciSubDevice80860166::SUBDEVICE_10CF16C1: return "LIFEBOOK E752";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860166_H
