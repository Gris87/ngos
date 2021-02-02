// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90058011: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100AC = 0x0E1100AC,
    SUBDEVICE_90050041 = 0x90050041
};



inline const char8* enumToString(PciSubDevice90058011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90058011::NONE:               return "NONE";
        case PciSubDevice90058011::SUBDEVICE_0E1100AC: return "SUBDEVICE_0E1100AC";
        case PciSubDevice90058011::SUBDEVICE_90050041: return "SUBDEVICE_90050041";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90058011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90058011 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90058011::SUBDEVICE_0E1100AC: return "ASC-39320D bad_uint320";
        case PciSubDevice90058011::SUBDEVICE_90050041: return "ASC-39320D bad_uint320";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058011_H
