// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice16570017: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1741 = 0x103C1741,
    SUBDEVICE_103C1743 = 0x103C1743,
    SUBDEVICE_16570014 = 0x16570014
};



inline const char8* enumToString(PciSubDevice16570017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570017::NONE:               return "NONE";
        case PciSubDevice16570017::SUBDEVICE_103C1741: return "SUBDEVICE_103C1741";
        case PciSubDevice16570017::SUBDEVICE_103C1743: return "SUBDEVICE_103C1743";
        case PciSubDevice16570017::SUBDEVICE_16570014: return "SUBDEVICE_16570014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice16570017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice16570017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570017::SUBDEVICE_103C1741: return "41B 4Gbps single port FC HBA";
        case PciSubDevice16570017::SUBDEVICE_103C1743: return "81B 8Gbps single port FC HBA";
        case PciSubDevice16570017::SUBDEVICE_16570014: return "415/815 4Gbps/8Gbps single port PCIe FC HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570017_H
