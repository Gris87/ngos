// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416C6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416C6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416C6: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B71100 = 0x10B71100,
    SUBDEVICE_14E4000C = 0x14E4000C,
    SUBDEVICE_14E48009 = 0x14E48009
};



inline const char8* enumToString(PciSubDevice14E416C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416C6::NONE:               return "NONE";
        case PciSubDevice14E416C6::SUBDEVICE_10B71100: return "SUBDEVICE_10B71100";
        case PciSubDevice14E416C6::SUBDEVICE_14E4000C: return "SUBDEVICE_14E4000C";
        case PciSubDevice14E416C6::SUBDEVICE_14E48009: return "SUBDEVICE_14E48009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416C6::SUBDEVICE_10B71100: return "3C1000B-T 10/100/1000 PCI";
        case PciSubDevice14E416C6::SUBDEVICE_14E4000C: return "BCM5702 1000Base-T";
        case PciSubDevice14E416C6::SUBDEVICE_14E48009: return "BCM5702 1000Base-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416C6_H
