// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020004: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020040 = 0x11020040,
    SUBDEVICE_11020041 = 0x11020041,
    SUBDEVICE_11020042 = 0x11020042,
    SUBDEVICE_11020043 = 0x11020043,
    SUBDEVICE_11020051 = 0x11020051,
    SUBDEVICE_11020052 = 0x11020052,
    SUBDEVICE_11020053 = 0x11020053,
    SUBDEVICE_11020054 = 0x11020054,
    SUBDEVICE_11020055 = 0x11020055,
    SUBDEVICE_11020056 = 0x11020056,
    SUBDEVICE_11020057 = 0x11020057,
    SUBDEVICE_11020058 = 0x11020058,
    SUBDEVICE_11020059 = 0x11020059,
    SUBDEVICE_1102005A = 0x1102005A,
    SUBDEVICE_1102005B = 0x1102005B,
    SUBDEVICE_1102005C = 0x1102005C,
    SUBDEVICE_11021002 = 0x11021002,
    SUBDEVICE_11021003 = 0x11021003,
    SUBDEVICE_11021004 = 0x11021004,
    SUBDEVICE_11021005 = 0x11021005,
    SUBDEVICE_11021006 = 0x11021006,
    SUBDEVICE_11021007 = 0x11021007,
    SUBDEVICE_11021008 = 0x11021008,
    SUBDEVICE_11021009 = 0x11021009,
    SUBDEVICE_1102100A = 0x1102100A,
    SUBDEVICE_11022001 = 0x11022001,
    SUBDEVICE_11022002 = 0x11022002,
    SUBDEVICE_11022003 = 0x11022003,
    SUBDEVICE_11022004 = 0x11022004,
    SUBDEVICE_11022005 = 0x11022005,
    SUBDEVICE_11022006 = 0x11022006,
    SUBDEVICE_11022007 = 0x11022007,
    SUBDEVICE_11024001 = 0x11024001,
    SUBDEVICE_11024002 = 0x11024002,
    SUBDEVICE_11024003 = 0x11024003
};



inline const char8* enumToString(PciSubDevice11020004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020004::NONE:               return "NONE";
        case PciSubDevice11020004::SUBDEVICE_11020040: return "SUBDEVICE_11020040";
        case PciSubDevice11020004::SUBDEVICE_11020041: return "SUBDEVICE_11020041";
        case PciSubDevice11020004::SUBDEVICE_11020042: return "SUBDEVICE_11020042";
        case PciSubDevice11020004::SUBDEVICE_11020043: return "SUBDEVICE_11020043";
        case PciSubDevice11020004::SUBDEVICE_11020051: return "SUBDEVICE_11020051";
        case PciSubDevice11020004::SUBDEVICE_11020052: return "SUBDEVICE_11020052";
        case PciSubDevice11020004::SUBDEVICE_11020053: return "SUBDEVICE_11020053";
        case PciSubDevice11020004::SUBDEVICE_11020054: return "SUBDEVICE_11020054";
        case PciSubDevice11020004::SUBDEVICE_11020055: return "SUBDEVICE_11020055";
        case PciSubDevice11020004::SUBDEVICE_11020056: return "SUBDEVICE_11020056";
        case PciSubDevice11020004::SUBDEVICE_11020057: return "SUBDEVICE_11020057";
        case PciSubDevice11020004::SUBDEVICE_11020058: return "SUBDEVICE_11020058";
        case PciSubDevice11020004::SUBDEVICE_11020059: return "SUBDEVICE_11020059";
        case PciSubDevice11020004::SUBDEVICE_1102005A: return "SUBDEVICE_1102005A";
        case PciSubDevice11020004::SUBDEVICE_1102005B: return "SUBDEVICE_1102005B";
        case PciSubDevice11020004::SUBDEVICE_1102005C: return "SUBDEVICE_1102005C";
        case PciSubDevice11020004::SUBDEVICE_11021002: return "SUBDEVICE_11021002";
        case PciSubDevice11020004::SUBDEVICE_11021003: return "SUBDEVICE_11021003";
        case PciSubDevice11020004::SUBDEVICE_11021004: return "SUBDEVICE_11021004";
        case PciSubDevice11020004::SUBDEVICE_11021005: return "SUBDEVICE_11021005";
        case PciSubDevice11020004::SUBDEVICE_11021006: return "SUBDEVICE_11021006";
        case PciSubDevice11020004::SUBDEVICE_11021007: return "SUBDEVICE_11021007";
        case PciSubDevice11020004::SUBDEVICE_11021008: return "SUBDEVICE_11021008";
        case PciSubDevice11020004::SUBDEVICE_11021009: return "SUBDEVICE_11021009";
        case PciSubDevice11020004::SUBDEVICE_1102100A: return "SUBDEVICE_1102100A";
        case PciSubDevice11020004::SUBDEVICE_11022001: return "SUBDEVICE_11022001";
        case PciSubDevice11020004::SUBDEVICE_11022002: return "SUBDEVICE_11022002";
        case PciSubDevice11020004::SUBDEVICE_11022003: return "SUBDEVICE_11022003";
        case PciSubDevice11020004::SUBDEVICE_11022004: return "SUBDEVICE_11022004";
        case PciSubDevice11020004::SUBDEVICE_11022005: return "SUBDEVICE_11022005";
        case PciSubDevice11020004::SUBDEVICE_11022006: return "SUBDEVICE_11022006";
        case PciSubDevice11020004::SUBDEVICE_11022007: return "SUBDEVICE_11022007";
        case PciSubDevice11020004::SUBDEVICE_11024001: return "SUBDEVICE_11024001";
        case PciSubDevice11020004::SUBDEVICE_11024002: return "SUBDEVICE_11024002";
        case PciSubDevice11020004::SUBDEVICE_11024003: return "SUBDEVICE_11024003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020004::SUBDEVICE_11020040: return "SB0090 Audigy Player";
        case PciSubDevice11020004::SUBDEVICE_11020041: return "CT4820 SBLive!2";
        case PciSubDevice11020004::SUBDEVICE_11020042: return "CT0070 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11020043: return "CT0072 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11020051: return "SB0090 Audigy Player/Platinum (EX)";
        case PciSubDevice11020004::SUBDEVICE_11020052: return "SB0162 Audigy ES";
        case PciSubDevice11020004::SUBDEVICE_11020053: return "CT0090/SB0092 Audigy Player/OEM";
        case PciSubDevice11020004::SUBDEVICE_11020054: return "SB0161 Audigy ES";
        case PciSubDevice11020004::SUBDEVICE_11020055: return "SB0192 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11020056: return "SB0191 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11020057: return "SB0091 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11020058: return "SB0095 Audigy Player/OEM";
        case PciSubDevice11020004::SUBDEVICE_11020059: return "SB0230 Audigy";
        case PciSubDevice11020004::SUBDEVICE_1102005A: return "SB0231 Audigy";
        case PciSubDevice11020004::SUBDEVICE_1102005B: return "SB0232 Audigy";
        case PciSubDevice11020004::SUBDEVICE_1102005C: return "SB0238 Audigy";
        case PciSubDevice11020004::SUBDEVICE_11021002: return "SB0240 Audigy 2 Platinum 6.1";
        case PciSubDevice11020004::SUBDEVICE_11021003: return "SB0350 Audigy 2 / SB0243 Audigy 2 OEM";
        case PciSubDevice11020004::SUBDEVICE_11021004: return "SB0242 Audigy 2";
        case PciSubDevice11020004::SUBDEVICE_11021005: return "SB0280 Audigy 2 Platinum Ex";
        case PciSubDevice11020004::SUBDEVICE_11021006: return "SB0245 Audigy 2 OEM";
        case PciSubDevice11020004::SUBDEVICE_11021007: return "SB0240/SB0244 Audigy 2 Platinum";
        case PciSubDevice11020004::SUBDEVICE_11021008: return "SB0320 Audigy 2";
        case PciSubDevice11020004::SUBDEVICE_11021009: return "SB0249 Audigy 2 OEM";
        case PciSubDevice11020004::SUBDEVICE_1102100A: return "SB0246 Audigy 2";
        case PciSubDevice11020004::SUBDEVICE_11022001: return "SB0360 Audigy 2 ZS Platinum Pro";
        case PciSubDevice11020004::SUBDEVICE_11022002: return "SB0350 Audigy 2 ZS";
        case PciSubDevice11020004::SUBDEVICE_11022003: return "SB0352 Audigy 2 ZS";
        case PciSubDevice11020004::SUBDEVICE_11022004: return "SB0355 Audigy 2 ZS";
        case PciSubDevice11020004::SUBDEVICE_11022005: return "SB0359 Audigy 2 ZS";
        case PciSubDevice11020004::SUBDEVICE_11022006: return "SB035x Audigy 2 OEM";
        case PciSubDevice11020004::SUBDEVICE_11022007: return "SB0380 Audigy 4 Pro";
        case PciSubDevice11020004::SUBDEVICE_11024001: return "E-MU 1010 [MAEM8810]";
        case PciSubDevice11020004::SUBDEVICE_11024002: return "E-MU 0404";
        case PciSubDevice11020004::SUBDEVICE_11024003: return "E-MU 1010";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020004_H
