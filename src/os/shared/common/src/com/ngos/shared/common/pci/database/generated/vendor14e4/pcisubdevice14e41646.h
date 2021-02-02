// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41646_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41646_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41646: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100BB = 0x0E1100BB,
    SUBDEVICE_10280126 = 0x10280126,
    SUBDEVICE_14E48009 = 0x14E48009
};



inline const char8* enumToString(PciSubDevice14E41646 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41646::NONE:               return "NONE";
        case PciSubDevice14E41646::SUBDEVICE_0E1100BB: return "SUBDEVICE_0E1100BB";
        case PciSubDevice14E41646::SUBDEVICE_10280126: return "SUBDEVICE_10280126";
        case PciSubDevice14E41646::SUBDEVICE_14E48009: return "SUBDEVICE_14E48009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41646 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41646 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41646::SUBDEVICE_0E1100BB: return "NC7760 1000BaseTX";
        case PciSubDevice14E41646::SUBDEVICE_10280126: return "Broadcom BCM5702 1000BaseTX";
        case PciSubDevice14E41646::SUBDEVICE_14E48009: return "BCM5702 1000BaseTX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41646_H
