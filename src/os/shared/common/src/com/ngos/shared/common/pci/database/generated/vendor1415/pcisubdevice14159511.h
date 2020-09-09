// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159511_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159511_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14159511: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12C40211 = 0x12C40211,
    SUBDEVICE_15ED2000 = 0x15ED2000,
    SUBDEVICE_15ED2001 = 0x15ED2001
};



inline const char8* enumToString(PciSubDevice14159511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14159511::NONE:               return "NONE";
        case PciSubDevice14159511::SUBDEVICE_12C40211: return "SUBDEVICE_12C40211";
        case PciSubDevice14159511::SUBDEVICE_15ED2000: return "SUBDEVICE_15ED2000";
        case PciSubDevice14159511::SUBDEVICE_15ED2001: return "SUBDEVICE_15ED2001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14159511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14159511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14159511::SUBDEVICE_12C40211: return "Titan/104-Plus (8 port, p5-8)";
        case PciSubDevice14159511::SUBDEVICE_15ED2000: return "MCCR Serial p4-7 of 8";
        case PciSubDevice14159511::SUBDEVICE_15ED2001: return "MCCR Serial p4-15 of 16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCISUBDEVICE14159511_H
