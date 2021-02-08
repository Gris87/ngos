// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E110046_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E110046_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0E110046: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E114091 = 0x0E114091,
    SUBDEVICE_0E11409A = 0x0E11409A,
    SUBDEVICE_0E11409B = 0x0E11409B,
    SUBDEVICE_0E11409C = 0x0E11409C,
    SUBDEVICE_0E11409D = 0x0E11409D
};



inline const char8* enumToString(PciSubDevice0E110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E110046::NONE:               return "NONE";
        case PciSubDevice0E110046::SUBDEVICE_0E114091: return "SUBDEVICE_0E114091";
        case PciSubDevice0E110046::SUBDEVICE_0E11409A: return "SUBDEVICE_0E11409A";
        case PciSubDevice0E110046::SUBDEVICE_0E11409B: return "SUBDEVICE_0E11409B";
        case PciSubDevice0E110046::SUBDEVICE_0E11409C: return "SUBDEVICE_0E11409C";
        case PciSubDevice0E110046::SUBDEVICE_0E11409D: return "SUBDEVICE_0E11409D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0E110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0E110046 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E110046::SUBDEVICE_0E114091: return "Smart Array 6i";
        case PciSubDevice0E110046::SUBDEVICE_0E11409A: return "Smart Array 641";
        case PciSubDevice0E110046::SUBDEVICE_0E11409B: return "Smart Array 642";
        case PciSubDevice0E110046::SUBDEVICE_0E11409C: return "Smart Array 6400";
        case PciSubDevice0E110046::SUBDEVICE_0E11409D: return "Smart Array 6400 EM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E110046_H
