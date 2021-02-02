// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE006A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE006A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE006A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438095 = 0x10438095,
    SUBDEVICE_A0A00304 = 0xA0A00304
};



inline const char8* enumToString(PciSubDevice10DE006A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE006A::NONE:               return "NONE";
        case PciSubDevice10DE006A::SUBDEVICE_10438095: return "SUBDEVICE_10438095";
        case PciSubDevice10DE006A::SUBDEVICE_A0A00304: return "SUBDEVICE_A0A00304";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE006A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE006A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE006A::SUBDEVICE_10438095: return "nForce2 AC97 Audio Controller (MCP)";
        case PciSubDevice10DE006A::SUBDEVICE_A0A00304: return "UK79G-1394 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE006A_H
