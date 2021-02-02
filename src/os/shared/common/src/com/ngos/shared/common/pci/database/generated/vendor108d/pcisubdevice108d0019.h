// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice108D0019: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108D0016 = 0x108D0016,
    SUBDEVICE_108D0017 = 0x108D0017
};



inline const char8* enumToString(PciSubDevice108D0019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108D0019::NONE:               return "NONE";
        case PciSubDevice108D0019::SUBDEVICE_108D0016: return "SUBDEVICE_108D0016";
        case PciSubDevice108D0019::SUBDEVICE_108D0017: return "SUBDEVICE_108D0017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice108D0019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice108D0019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice108D0019::SUBDEVICE_108D0016: return "OC-2327 Rapidfire 10/100 Ethernet Adapter";
        case PciSubDevice108D0019::SUBDEVICE_108D0017: return "OC-2250 GoCard 10/100 Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCISUBDEVICE108D0019_H
