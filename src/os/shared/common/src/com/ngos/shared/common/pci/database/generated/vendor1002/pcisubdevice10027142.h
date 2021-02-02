// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027142_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027142_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027142: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020322 = 0x10020322,
    SUBDEVICE_10430142 = 0x10430142
};



inline const char8* enumToString(PciSubDevice10027142 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027142::NONE:               return "NONE";
        case PciSubDevice10027142::SUBDEVICE_10020322: return "SUBDEVICE_10020322";
        case PciSubDevice10027142::SUBDEVICE_10430142: return "SUBDEVICE_10430142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027142 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027142 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027142::SUBDEVICE_10020322: return "All-in-Wonder 2006 PCI-E Edition";
        case PciSubDevice10027142::SUBDEVICE_10430142: return "EAX1300PRO/TD/256M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027142_H
