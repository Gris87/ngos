// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCISUBDEVICE124B0040_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCISUBDEVICE124B0040_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice124B0040: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_124B9080 = 0x124B9080
};



inline const char8* enumToString(PciSubDevice124B0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice124B0040::NONE:               return "NONE";
        case PciSubDevice124B0040::SUBDEVICE_124B9080: return "SUBDEVICE_124B9080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice124B0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice124B0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice124B0040::SUBDEVICE_124B9080: return "PCI9080 Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCISUBDEVICE124B0040_H
