// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10430201 = 0x10430201,
    SUBDEVICE_10434008 = 0x10434008,
    SUBDEVICE_10434009 = 0x10434009,
    SUBDEVICE_10480C41 = 0x10480C41,
    SUBDEVICE_10480C43 = 0x10480C43,
    SUBDEVICE_10480C48 = 0x10480C48,
    SUBDEVICE_1102102D = 0x1102102D,
    SUBDEVICE_14AF5022 = 0x14AF5022
};



inline const char8* enumToString(PciSubDevice10DE0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0100::NONE:               return "NONE";
        case PciSubDevice10DE0100::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE0100::SUBDEVICE_10430201: return "SUBDEVICE_10430201";
        case PciSubDevice10DE0100::SUBDEVICE_10434008: return "SUBDEVICE_10434008";
        case PciSubDevice10DE0100::SUBDEVICE_10434009: return "SUBDEVICE_10434009";
        case PciSubDevice10DE0100::SUBDEVICE_10480C41: return "SUBDEVICE_10480C41";
        case PciSubDevice10DE0100::SUBDEVICE_10480C43: return "SUBDEVICE_10480C43";
        case PciSubDevice10DE0100::SUBDEVICE_10480C48: return "SUBDEVICE_10480C48";
        case PciSubDevice10DE0100::SUBDEVICE_1102102D: return "SUBDEVICE_1102102D";
        case PciSubDevice10DE0100::SUBDEVICE_14AF5022: return "SUBDEVICE_14AF5022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0100::SUBDEVICE_10430200: return "AGP-V6600 SGRAM";
        case PciSubDevice10DE0100::SUBDEVICE_10430201: return "AGP-V6600 SDRAM";
        case PciSubDevice10DE0100::SUBDEVICE_10434008: return "AGP-V6600 SGRAM";
        case PciSubDevice10DE0100::SUBDEVICE_10434009: return "AGP-V6600 SDRAM";
        case PciSubDevice10DE0100::SUBDEVICE_10480C41: return "Erazor X";
        case PciSubDevice10DE0100::SUBDEVICE_10480C43: return "ERAZOR X PCI";
        case PciSubDevice10DE0100::SUBDEVICE_10480C48: return "Synergy Force";
        case PciSubDevice10DE0100::SUBDEVICE_1102102D: return "CT6941 GeForce 256";
        case PciSubDevice10DE0100::SUBDEVICE_14AF5022: return "3D Prophet SE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0100_H
