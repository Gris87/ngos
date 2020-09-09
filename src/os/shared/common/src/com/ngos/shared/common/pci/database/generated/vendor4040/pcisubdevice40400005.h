// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice40400005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C170E = 0x103C170E
};



inline const char8* enumToString(PciSubDevice40400005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40400005::NONE:               return "NONE";
        case PciSubDevice40400005::SUBDEVICE_103C170E: return "SUBDEVICE_103C170E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice40400005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice40400005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40400005::SUBDEVICE_103C170E: return "NC512m Dual Port 10GbE Multifunction BL-C Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400005_H
