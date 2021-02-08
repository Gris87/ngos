// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA56_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA56_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1069BA56: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10690030 = 0x10690030,
    SUBDEVICE_10690040 = 0x10690040
};



inline const char8* enumToString(PciSubDevice1069BA56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069BA56::NONE:               return "NONE";
        case PciSubDevice1069BA56::SUBDEVICE_10690030: return "SUBDEVICE_10690030";
        case PciSubDevice1069BA56::SUBDEVICE_10690040: return "SUBDEVICE_10690040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1069BA56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1069BA56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069BA56::SUBDEVICE_10690030: return "eXtremeRAID 3000 support Device";
        case PciSubDevice1069BA56::SUBDEVICE_10690040: return "eXtremeRAID 2000 support Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA56_H
