// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCISUBDEVICE12D91078_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCISUBDEVICE12D91078_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12D91078: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12D9000D = 0x12D9000D,
    SUBDEVICE_12D9000E = 0x12D9000E
};



inline const char8* enumToString(PciSubDevice12D91078 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D91078::NONE:               return "NONE";
        case PciSubDevice12D91078::SUBDEVICE_12D9000D: return "SUBDEVICE_12D9000D";
        case PciSubDevice12D91078::SUBDEVICE_12D9000E: return "SUBDEVICE_12D9000E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12D91078 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12D91078 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D91078::SUBDEVICE_12D9000D: return "Prosody X PCI";
        case PciSubDevice12D91078::SUBDEVICE_12D9000E: return "Prosody X cPCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCISUBDEVICE12D91078_H
