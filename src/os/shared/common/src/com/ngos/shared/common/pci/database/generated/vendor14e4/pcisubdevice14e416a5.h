// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416A5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F5C = 0x10281F5C,
    SUBDEVICE_10281F5D = 0x10281F5D,
    SUBDEVICE_10281F67 = 0x10281F67,
    SUBDEVICE_10281F68 = 0x10281F68
};



inline const char8* enumToString(PciSubDevice14E416A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A5::NONE:               return "NONE";
        case PciSubDevice14E416A5::SUBDEVICE_10281F5C: return "SUBDEVICE_10281F5C";
        case PciSubDevice14E416A5::SUBDEVICE_10281F5D: return "SUBDEVICE_10281F5D";
        case PciSubDevice14E416A5::SUBDEVICE_10281F67: return "SUBDEVICE_10281F67";
        case PciSubDevice14E416A5::SUBDEVICE_10281F68: return "SUBDEVICE_10281F68";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416A5::SUBDEVICE_10281F5C: return "NetXtreme II BCM57800 10-Gigabit Ethernet Multi Function";
        case PciSubDevice14E416A5::SUBDEVICE_10281F5D: return "NetXtreme II BCM57800 10-Gigabit Ethernet Multi Function";
        case PciSubDevice14E416A5::SUBDEVICE_10281F67: return "NetXtreme II BCM57800 1-Gigabit Ethernet Multi Function";
        case PciSubDevice14E416A5::SUBDEVICE_10281F68: return "NetXtreme II BCM57800 1-Gigabit Ethernet Multi Function";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416A5_H
