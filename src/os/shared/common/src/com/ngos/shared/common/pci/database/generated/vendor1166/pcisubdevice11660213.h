// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660213_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660213_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11660213: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10284134 = 0x10284134,
    SUBDEVICE_1028C134 = 0x1028C134,
    SUBDEVICE_17341012 = 0x17341012
};



inline const char8* enumToString(PciSubDevice11660213 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660213::NONE:               return "NONE";
        case PciSubDevice11660213::SUBDEVICE_10284134: return "SUBDEVICE_10284134";
        case PciSubDevice11660213::SUBDEVICE_1028C134: return "SUBDEVICE_1028C134";
        case PciSubDevice11660213::SUBDEVICE_17341012: return "SUBDEVICE_17341012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11660213 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11660213 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660213::SUBDEVICE_10284134: return "PowerEdge 600SC";
        case PciSubDevice11660213::SUBDEVICE_1028C134: return "Poweredge SC600";
        case PciSubDevice11660213::SUBDEVICE_17341012: return "PRIMERGY RX/TX series onboard IDE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660213_H
