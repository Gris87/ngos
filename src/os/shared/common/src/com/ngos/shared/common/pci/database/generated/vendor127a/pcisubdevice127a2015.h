// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2015_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2015_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A2015: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF1063 = 0x10CF1063,
    SUBDEVICE_10CF1064 = 0x10CF1064,
    SUBDEVICE_14682015 = 0x14682015
};



inline const char8* enumToString(PciSubDevice127A2015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2015::NONE:               return "NONE";
        case PciSubDevice127A2015::SUBDEVICE_10CF1063: return "SUBDEVICE_10CF1063";
        case PciSubDevice127A2015::SUBDEVICE_10CF1064: return "SUBDEVICE_10CF1064";
        case PciSubDevice127A2015::SUBDEVICE_14682015: return "SUBDEVICE_14682015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A2015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A2015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2015::SUBDEVICE_10CF1063: return "Fujitsu";
        case PciSubDevice127A2015::SUBDEVICE_10CF1064: return "Fujitsu";
        case PciSubDevice127A2015::SUBDEVICE_14682015: return "Fujitsu";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2015_H
