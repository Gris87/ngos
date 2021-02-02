// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027129_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027129_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027129: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020323 = 0x10020323,
    SUBDEVICE_10020D03 = 0x10020D03
};



inline const char8* enumToString(PciSubDevice10027129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027129::NONE:               return "NONE";
        case PciSubDevice10027129::SUBDEVICE_10020323: return "SUBDEVICE_10020323";
        case PciSubDevice10027129::SUBDEVICE_10020D03: return "SUBDEVICE_10020D03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027129::SUBDEVICE_10020323: return "All-In-Wonder X1800 XL (Secondary)";
        case PciSubDevice10027129::SUBDEVICE_10020D03: return "Radeon X1800 CrossFire Edition (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027129_H
