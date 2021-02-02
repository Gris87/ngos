// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36746_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36746_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B36746: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1781 = 0x103C1781,
    SUBDEVICE_103C3349 = 0x103C3349
};



inline const char8* enumToString(PciSubDevice15B36746 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B36746::NONE:               return "NONE";
        case PciSubDevice15B36746::SUBDEVICE_103C1781: return "SUBDEVICE_103C1781";
        case PciSubDevice15B36746::SUBDEVICE_103C3349: return "SUBDEVICE_103C3349";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B36746 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B36746 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B36746::SUBDEVICE_103C1781: return "NC543i 1-port 4x QDR IB/Flex-10 10Gb Adapter";
        case PciSubDevice15B36746::SUBDEVICE_103C3349: return "NC543i 2-port 4xQDR IB/10Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B36746_H
