// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102A00C5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800C5 = 0x102800C5
};



inline const char8* enumToString(PciSubDevice102A00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A00C5::NONE:               return "NONE";
        case PciSubDevice102A00C5::SUBDEVICE_102800C5: return "SUBDEVICE_102800C5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102A00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102A00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A00C5::SUBDEVICE_102800C5: return "PowerEdge 2550/2650/4600";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00C5_H
