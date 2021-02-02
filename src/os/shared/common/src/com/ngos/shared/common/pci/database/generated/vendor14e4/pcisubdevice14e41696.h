// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41696_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41696_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41696: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C12BC = 0x103C12BC,
    SUBDEVICE_14E4000D = 0x14E4000D
};



inline const char8* enumToString(PciSubDevice14E41696 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41696::NONE:               return "NONE";
        case PciSubDevice14E41696::SUBDEVICE_103C12BC: return "SUBDEVICE_103C12BC";
        case PciSubDevice14E41696::SUBDEVICE_14E4000D: return "SUBDEVICE_14E4000D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41696 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41696 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41696::SUBDEVICE_103C12BC: return "d530 CMT (DG746A)";
        case PciSubDevice14E41696::SUBDEVICE_14E4000D: return "NetXtreme BCM5782 1000Base-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41696_H
