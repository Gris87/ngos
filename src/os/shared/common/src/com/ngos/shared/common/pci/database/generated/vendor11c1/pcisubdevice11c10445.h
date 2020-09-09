// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10445_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10445_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10445: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80862203 = 0x80862203,
    SUBDEVICE_80862204 = 0x80862204
};



inline const char8* enumToString(PciSubDevice11C10445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10445::NONE:               return "NONE";
        case PciSubDevice11C10445::SUBDEVICE_80862203: return "SUBDEVICE_80862203";
        case PciSubDevice11C10445::SUBDEVICE_80862204: return "SUBDEVICE_80862204";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10445::SUBDEVICE_80862203: return "PRO/100+ MiniPCI (probably an Ambit U98.003.C.00 combo card)";
        case PciSubDevice11C10445::SUBDEVICE_80862204: return "PRO/100+ MiniPCI on Armada E500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10445_H
