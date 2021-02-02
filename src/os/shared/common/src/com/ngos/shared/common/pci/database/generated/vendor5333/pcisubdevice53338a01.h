// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A01_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A01_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338A01: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B032 = 0x0E11B032,
    SUBDEVICE_10B41617 = 0x10B41617,
    SUBDEVICE_10B41717 = 0x10B41717,
    SUBDEVICE_53338A01 = 0x53338A01
};



inline const char8* enumToString(PciSubDevice53338A01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A01::NONE:               return "NONE";
        case PciSubDevice53338A01::SUBDEVICE_0E11B032: return "SUBDEVICE_0E11B032";
        case PciSubDevice53338A01::SUBDEVICE_10B41617: return "SUBDEVICE_10B41617";
        case PciSubDevice53338A01::SUBDEVICE_10B41717: return "SUBDEVICE_10B41717";
        case PciSubDevice53338A01::SUBDEVICE_53338A01: return "SUBDEVICE_53338A01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338A01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338A01 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A01::SUBDEVICE_0E11B032: return "ViRGE/GX";
        case PciSubDevice53338A01::SUBDEVICE_10B41617: return "Nitro 3D";
        case PciSubDevice53338A01::SUBDEVICE_10B41717: return "Nitro 3D";
        case PciSubDevice53338A01::SUBDEVICE_53338A01: return "ViRGE/DX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A01_H
