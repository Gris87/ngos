// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002683D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020030 = 0x10020030,
    SUBDEVICE_10190030 = 0x10190030,
    SUBDEVICE_103C6890 = 0x103C6890,
    SUBDEVICE_10438760 = 0x10438760,
    SUBDEVICE_14622710 = 0x14622710,
    SUBDEVICE_174B8304 = 0x174B8304
};



inline const char8* enumToString(PciSubDevice1002683D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002683D::NONE:               return "NONE";
        case PciSubDevice1002683D::SUBDEVICE_10020030: return "SUBDEVICE_10020030";
        case PciSubDevice1002683D::SUBDEVICE_10190030: return "SUBDEVICE_10190030";
        case PciSubDevice1002683D::SUBDEVICE_103C6890: return "SUBDEVICE_103C6890";
        case PciSubDevice1002683D::SUBDEVICE_10438760: return "SUBDEVICE_10438760";
        case PciSubDevice1002683D::SUBDEVICE_14622710: return "SUBDEVICE_14622710";
        case PciSubDevice1002683D::SUBDEVICE_174B8304: return "SUBDEVICE_174B8304";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002683D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002683D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002683D::SUBDEVICE_10020030: return "Radeon HD 8760 OEM";
        case PciSubDevice1002683D::SUBDEVICE_10190030: return "Radeon HD 8760 OEM";
        case PciSubDevice1002683D::SUBDEVICE_103C6890: return "Radeon HD 8760 OEM";
        case PciSubDevice1002683D::SUBDEVICE_10438760: return "Radeon HD 8760 OEM";
        case PciSubDevice1002683D::SUBDEVICE_14622710: return "R7770-PMD1GD5";
        case PciSubDevice1002683D::SUBDEVICE_174B8304: return "Radeon HD 8760 OEM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683D_H
