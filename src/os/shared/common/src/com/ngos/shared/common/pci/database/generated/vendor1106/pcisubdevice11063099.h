// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063099_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063099_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063099: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10191841 = 0x10191841,
    SUBDEVICE_10438064 = 0x10438064,
    SUBDEVICE_1043807F = 0x1043807F,
    SUBDEVICE_18493099 = 0x18493099
};



inline const char8* enumToString(PciSubDevice11063099 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063099::NONE:               return "NONE";
        case PciSubDevice11063099::SUBDEVICE_10191841: return "SUBDEVICE_10191841";
        case PciSubDevice11063099::SUBDEVICE_10438064: return "SUBDEVICE_10438064";
        case PciSubDevice11063099::SUBDEVICE_1043807F: return "SUBDEVICE_1043807F";
        case PciSubDevice11063099::SUBDEVICE_18493099: return "SUBDEVICE_18493099";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063099 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063099 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063099::SUBDEVICE_10191841: return "M811 (VT8367/VT8235/VT6103) [KT333] motherboard";
        case PciSubDevice11063099::SUBDEVICE_10438064: return "A7V266-E Mainboard";
        case PciSubDevice11063099::SUBDEVICE_1043807F: return "A7V333 Mainboard";
        case PciSubDevice11063099::SUBDEVICE_18493099: return "K7VT2 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063099_H
