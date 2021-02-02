// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11815_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11815_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11815: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110022 = 0x0E110022,
    SUBDEVICE_0E110042 = 0x0E110042
};



inline const char8* enumToString(PciSubDevice14F11815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11815::NONE:               return "NONE";
        case PciSubDevice14F11815::SUBDEVICE_0E110022: return "SUBDEVICE_0E110022";
        case PciSubDevice14F11815::SUBDEVICE_0E110042: return "SUBDEVICE_0E110042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11815 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11815::SUBDEVICE_0E110022: return "Grizzly";
        case PciSubDevice14F11815::SUBDEVICE_0E110042: return "Yogi";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11815_H
