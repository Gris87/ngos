// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020007 = 0x11020007,
    SUBDEVICE_11021001 = 0x11021001,
    SUBDEVICE_11021002 = 0x11021002,
    SUBDEVICE_11021006 = 0x11021006,
    SUBDEVICE_1102100A = 0x1102100A,
    SUBDEVICE_11021012 = 0x11021012,
    SUBDEVICE_11021013 = 0x11021013,
    SUBDEVICE_14621009 = 0x14621009
};



inline const char8* enumToString(PciSubDevice11020007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020007::NONE:               return "NONE";
        case PciSubDevice11020007::SUBDEVICE_11020007: return "SUBDEVICE_11020007";
        case PciSubDevice11020007::SUBDEVICE_11021001: return "SUBDEVICE_11021001";
        case PciSubDevice11020007::SUBDEVICE_11021002: return "SUBDEVICE_11021002";
        case PciSubDevice11020007::SUBDEVICE_11021006: return "SUBDEVICE_11021006";
        case PciSubDevice11020007::SUBDEVICE_1102100A: return "SUBDEVICE_1102100A";
        case PciSubDevice11020007::SUBDEVICE_11021012: return "SUBDEVICE_11021012";
        case PciSubDevice11020007::SUBDEVICE_11021013: return "SUBDEVICE_11021013";
        case PciSubDevice11020007::SUBDEVICE_14621009: return "SUBDEVICE_14621009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020007::SUBDEVICE_11020007: return "SBLive! 24bit";
        case PciSubDevice11020007::SUBDEVICE_11021001: return "SB0310 Audigy LS";
        case PciSubDevice11020007::SUBDEVICE_11021002: return "SB0312 Audigy LS";
        case PciSubDevice11020007::SUBDEVICE_11021006: return "SB0410 SBLive! 24-bit";
        case PciSubDevice11020007::SUBDEVICE_1102100A: return "SB0570 [SB Audigy SE]";
        case PciSubDevice11020007::SUBDEVICE_11021012: return "SB0790 X-Fi XA";
        case PciSubDevice11020007::SUBDEVICE_11021013: return "Soundblaster X-Fi Xtreme Audio";
        case PciSubDevice11020007::SUBDEVICE_14621009: return "K8N Diamond";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020007_H
