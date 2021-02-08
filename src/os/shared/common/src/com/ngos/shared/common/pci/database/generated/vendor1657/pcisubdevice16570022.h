// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570022_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570022_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice16570022: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16570022 = 0x16570022,
    SUBDEVICE_16570023 = 0x16570023,
    SUBDEVICE_16570024 = 0x16570024
};



inline const char8* enumToString(PciSubDevice16570022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570022::NONE:               return "NONE";
        case PciSubDevice16570022::SUBDEVICE_16570022: return "SUBDEVICE_16570022";
        case PciSubDevice16570022::SUBDEVICE_16570023: return "SUBDEVICE_16570023";
        case PciSubDevice16570022::SUBDEVICE_16570024: return "SUBDEVICE_16570024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice16570022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice16570022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice16570022::SUBDEVICE_16570022: return "10Gbps CNA - FCOE";
        case PciSubDevice16570022::SUBDEVICE_16570023: return "10Gbps CNA - LL";
        case PciSubDevice16570022::SUBDEVICE_16570024: return "16Gbps FC HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1657_PCISUBDEVICE16570022_H
