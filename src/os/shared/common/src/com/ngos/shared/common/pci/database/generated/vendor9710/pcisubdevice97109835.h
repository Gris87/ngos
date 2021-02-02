// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109835_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109835_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice97109835: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000002 = 0x10000002,
    SUBDEVICE_10000012 = 0x10000012
};



inline const char8* enumToString(PciSubDevice97109835 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109835::NONE:               return "NONE";
        case PciSubDevice97109835::SUBDEVICE_10000002: return "SUBDEVICE_10000002";
        case PciSubDevice97109835::SUBDEVICE_10000012: return "SUBDEVICE_10000012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice97109835 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice97109835 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice97109835::SUBDEVICE_10000002: return "2S (16C550 UART)";
        case PciSubDevice97109835::SUBDEVICE_10000012: return "1P2S";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9710_PCISUBDEVICE97109835_H
