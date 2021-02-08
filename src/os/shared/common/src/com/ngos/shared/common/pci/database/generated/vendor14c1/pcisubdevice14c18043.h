// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C18043_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C18043_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14C18043: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1240 = 0x103C1240
};



inline const char8* enumToString(PciSubDevice14C18043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14C18043::NONE:               return "NONE";
        case PciSubDevice14C18043::SUBDEVICE_103C1240: return "SUBDEVICE_103C1240";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14C18043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14C18043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14C18043::SUBDEVICE_103C1240: return "Myrinet M2L-PCi64/2-3.0 LANai 7.4 (HP OEM)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCISUBDEVICE14C18043_H
