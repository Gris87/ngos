// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12EB0003: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8049 = 0x104D8049,
    SUBDEVICE_104D8077 = 0x104D8077,
    SUBDEVICE_109F1000 = 0x109F1000,
    SUBDEVICE_12EB0003 = 0x12EB0003,
    SUBDEVICE_14626780 = 0x14626780,
    SUBDEVICE_14A42073 = 0x14A42073,
    SUBDEVICE_14A42091 = 0x14A42091,
    SUBDEVICE_14A42104 = 0x14A42104,
    SUBDEVICE_14A42106 = 0x14A42106
};



inline const char8* enumToString(PciSubDevice12EB0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0003::NONE:               return "NONE";
        case PciSubDevice12EB0003::SUBDEVICE_104D8049: return "SUBDEVICE_104D8049";
        case PciSubDevice12EB0003::SUBDEVICE_104D8077: return "SUBDEVICE_104D8077";
        case PciSubDevice12EB0003::SUBDEVICE_109F1000: return "SUBDEVICE_109F1000";
        case PciSubDevice12EB0003::SUBDEVICE_12EB0003: return "SUBDEVICE_12EB0003";
        case PciSubDevice12EB0003::SUBDEVICE_14626780: return "SUBDEVICE_14626780";
        case PciSubDevice12EB0003::SUBDEVICE_14A42073: return "SUBDEVICE_14A42073";
        case PciSubDevice12EB0003::SUBDEVICE_14A42091: return "SUBDEVICE_14A42091";
        case PciSubDevice12EB0003::SUBDEVICE_14A42104: return "SUBDEVICE_14A42104";
        case PciSubDevice12EB0003::SUBDEVICE_14A42106: return "SUBDEVICE_14A42106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12EB0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12EB0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0003::SUBDEVICE_104D8049: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_104D8077: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_109F1000: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_12EB0003: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_14626780: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_14A42073: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_14A42091: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_14A42104: return "Abad_uint8810 Vortex Digital Audio Processor";
        case PciSubDevice12EB0003::SUBDEVICE_14A42106: return "Abad_uint8810 Vortex Digital Audio Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0003_H
