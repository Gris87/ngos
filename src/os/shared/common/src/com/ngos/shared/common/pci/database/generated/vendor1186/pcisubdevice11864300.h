// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11864300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11864300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11864300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11864300 = 0x11864300,
    SUBDEVICE_11864B10 = 0x11864B10
};



inline const char8* enumToString(PciSubDevice11864300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11864300::NONE:               return "NONE";
        case PciSubDevice11864300::SUBDEVICE_11864300: return "SUBDEVICE_11864300";
        case PciSubDevice11864300::SUBDEVICE_11864B10: return "SUBDEVICE_11864B10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11864300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11864300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11864300::SUBDEVICE_11864300: return "DGE-528T PCI Gigabit Ethernet Adapter";
        case PciSubDevice11864300::SUBDEVICE_11864B10: return "DGE-560T PCI Express (x1) Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11864300_H
