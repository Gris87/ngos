// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice16570014: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16570014 = 0x16570014,
    SUBDEVICE_16570015 = 0x16570015
};



inline const char8* enumToString(PciSubDevice16570014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570014::NONE:               return "NONE";
        case PciSubDevice16570014::SUBDEVICE_16570014: return "SUBDEVICE_16570014";
        case PciSubDevice16570014::SUBDEVICE_16570015: return "SUBDEVICE_16570015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice16570014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice16570014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570014::SUBDEVICE_16570014: return "1010/1020/1007/1741 10Gbps CNA - FCOE";
        case PciSubDevice16570014::SUBDEVICE_16570015: return "1010/1020/1007/1741 10Gbps CNA - LL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570014_H
