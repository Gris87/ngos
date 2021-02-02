// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice16570013: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1742 = 0x103C1742,
    SUBDEVICE_103C1744 = 0x103C1744,
    SUBDEVICE_16570014 = 0x16570014
};



inline const char8* enumToString(PciSubDevice16570013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570013::NONE:               return "NONE";
        case PciSubDevice16570013::SUBDEVICE_103C1742: return "SUBDEVICE_103C1742";
        case PciSubDevice16570013::SUBDEVICE_103C1744: return "SUBDEVICE_103C1744";
        case PciSubDevice16570013::SUBDEVICE_16570014: return "SUBDEVICE_16570014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice16570013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice16570013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570013::SUBDEVICE_103C1742: return "82B 8Gbps dual port FC HBA";
        case PciSubDevice16570013::SUBDEVICE_103C1744: return "42B 4Gbps dual port FC HBA";
        case PciSubDevice16570013::SUBDEVICE_16570014: return "425/825 4Gbps/8Gbps PCIe dual port FC HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570013_H
