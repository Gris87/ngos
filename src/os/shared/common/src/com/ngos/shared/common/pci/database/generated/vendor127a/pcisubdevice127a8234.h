// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A8234_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A8234_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A8234: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108D0022 = 0x108D0022,
    SUBDEVICE_108D0027 = 0x108D0027
};



inline const char8* enumToString(PciSubDevice127A8234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A8234::NONE:               return "NONE";
        case PciSubDevice127A8234::SUBDEVICE_108D0022: return "SUBDEVICE_108D0022";
        case PciSubDevice127A8234::SUBDEVICE_108D0027: return "SUBDEVICE_108D0027";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A8234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A8234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A8234::SUBDEVICE_108D0022: return "RapidFire 616X ATM155 Adapter";
        case PciSubDevice127A8234::SUBDEVICE_108D0027: return "RapidFire 616X ATM155 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A8234_H
