// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4167D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140577 = 0x10140577,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0940 = 0x103C0940,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_17AA2081 = 0x17AA2081
};



inline const char8* enumToString(PciSubDevice14E4167D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4167D::NONE:               return "NONE";
        case PciSubDevice14E4167D::SUBDEVICE_10140577: return "SUBDEVICE_10140577";
        case PciSubDevice14E4167D::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice14E4167D::SUBDEVICE_103C0940: return "SUBDEVICE_103C0940";
        case PciSubDevice14E4167D::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice14E4167D::SUBDEVICE_17AA2081: return "SUBDEVICE_17AA2081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4167D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4167D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4167D::SUBDEVICE_10140577: return "ThinkPad X41 / Z60t";
        case PciSubDevice14E4167D::SUBDEVICE_103C0934: return "nx8220";
        case PciSubDevice14E4167D::SUBDEVICE_103C0940: return "Compaq nw8240 Mobile Workstation";
        case PciSubDevice14E4167D::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice14E4167D::SUBDEVICE_17AA2081: return "ThinkPad R60e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167D_H
