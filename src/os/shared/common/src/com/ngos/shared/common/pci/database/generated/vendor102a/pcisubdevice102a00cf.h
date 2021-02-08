// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00CF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00CF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102A00CF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280106 = 0x10280106,
    SUBDEVICE_10280121 = 0x10280121
};



inline const char8* enumToString(PciSubDevice102A00CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A00CF::NONE:               return "NONE";
        case PciSubDevice102A00CF::SUBDEVICE_10280106: return "SUBDEVICE_10280106";
        case PciSubDevice102A00CF::SUBDEVICE_10280121: return "SUBDEVICE_10280121";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102A00CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102A00CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A00CF::SUBDEVICE_10280106: return "PowerEdge 4600";
        case PciSubDevice102A00CF::SUBDEVICE_10280121: return "PowerEdge 2650";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A00CF_H
