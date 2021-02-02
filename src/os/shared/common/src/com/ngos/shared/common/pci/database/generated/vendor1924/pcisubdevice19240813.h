// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240813_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240813_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240813: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19246100 = 0x19246100,
    SUBDEVICE_19246102 = 0x19246102,
    SUBDEVICE_19246103 = 0x19246103,
    SUBDEVICE_19246104 = 0x19246104,
    SUBDEVICE_19246902 = 0x19246902,
    SUBDEVICE_19246904 = 0x19246904,
    SUBDEVICE_19247104 = 0x19247104,
    SUBDEVICE_19247904 = 0x19247904
};



inline const char8* enumToString(PciSubDevice19240813 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240813::NONE:               return "NONE";
        case PciSubDevice19240813::SUBDEVICE_19246100: return "SUBDEVICE_19246100";
        case PciSubDevice19240813::SUBDEVICE_19246102: return "SUBDEVICE_19246102";
        case PciSubDevice19240813::SUBDEVICE_19246103: return "SUBDEVICE_19246103";
        case PciSubDevice19240813::SUBDEVICE_19246104: return "SUBDEVICE_19246104";
        case PciSubDevice19240813::SUBDEVICE_19246902: return "SUBDEVICE_19246902";
        case PciSubDevice19240813::SUBDEVICE_19246904: return "SUBDEVICE_19246904";
        case PciSubDevice19240813::SUBDEVICE_19247104: return "SUBDEVICE_19247104";
        case PciSubDevice19240813::SUBDEVICE_19247904: return "SUBDEVICE_19247904";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240813 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240813 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240813::SUBDEVICE_19246100: return "SFN5121T-R0 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19246102: return "SFN5121T-R2 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19246103: return "SFN5121T-R3 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19246104: return "SFN5121T-R4 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19246902: return "SFN5111T-R2 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19246904: return "SFN5111T-R4 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19247104: return "SFN5161T-R4 10GBASE-T Server Adapter";
        case PciSubDevice19240813::SUBDEVICE_19247904: return "SFN5151T-R4 10GBASE-T Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240813_H
