// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A2013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_1179FF00 = 0x1179FF00
};



inline const char8* enumToString(PciSubDevice127A2013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2013::NONE:               return "NONE";
        case PciSubDevice127A2013::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice127A2013::SUBDEVICE_1179FF00: return "SUBDEVICE_1179FF00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A2013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A2013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2013::SUBDEVICE_11790001: return "Modem";
        case PciSubDevice127A2013::SUBDEVICE_1179FF00: return "Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2013_H
