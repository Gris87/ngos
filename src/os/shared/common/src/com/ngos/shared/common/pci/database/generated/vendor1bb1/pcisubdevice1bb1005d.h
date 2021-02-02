// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB1005D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB1005D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1BB1005D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1BB16501 = 0x1BB16501,
    SUBDEVICE_1BB16502 = 0x1BB16502,
    SUBDEVICE_1BB16503 = 0x1BB16503,
    SUBDEVICE_1BB16511 = 0x1BB16511,
    SUBDEVICE_1BB16512 = 0x1BB16512,
    SUBDEVICE_1BB16521 = 0x1BB16521,
    SUBDEVICE_1BB16522 = 0x1BB16522,
    SUBDEVICE_1BB16523 = 0x1BB16523
};



inline const char8* enumToString(PciSubDevice1BB1005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1BB1005D::NONE:               return "NONE";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16501: return "SUBDEVICE_1BB16501";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16502: return "SUBDEVICE_1BB16502";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16503: return "SUBDEVICE_1BB16503";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16511: return "SUBDEVICE_1BB16511";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16512: return "SUBDEVICE_1BB16512";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16521: return "SUBDEVICE_1BB16521";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16522: return "SUBDEVICE_1BB16522";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16523: return "SUBDEVICE_1BB16523";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1BB1005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1BB1005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16501: return "Nytro XP6500-8A1536 1.5TB";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16502: return "Nytro XP6500-8A2048";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16503: return "Nytro XP6500-8A4096";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16511: return "Nytro XH6550-2GB DRAM";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16512: return "Nytro XH6550-8GB DRAM";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16521: return "Nytro XP6500-8A1536 1.5TB";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16522: return "Nytro XP6500-8A2048";
        case PciSubDevice1BB1005D::SUBDEVICE_1BB16523: return "Nytro XP6500-8A4096";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB1005D_H
