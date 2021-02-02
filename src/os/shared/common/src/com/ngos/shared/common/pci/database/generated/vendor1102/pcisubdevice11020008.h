// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020008: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11020008 = 0x11020008,
    SUBDEVICE_11021001 = 0x11021001,
    SUBDEVICE_11021021 = 0x11021021,
    SUBDEVICE_11021022 = 0x11021022,
    SUBDEVICE_11021023 = 0x11021023,
    SUBDEVICE_11021024 = 0x11021024,
    SUBDEVICE_11021101 = 0x11021101,
    SUBDEVICE_11022001 = 0x11022001,
    SUBDEVICE_11022021 = 0x11022021,
    SUBDEVICE_11024002 = 0x11024002,
    SUBDEVICE_11024003 = 0x11024003,
    SUBDEVICE_11024004 = 0x11024004,
    SUBDEVICE_11024005 = 0x11024005,
    SUBDEVICE_11024007 = 0x11024007,
    SUBDEVICE_11024201 = 0x11024201
};



inline const char8* enumToString(PciSubDevice11020008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020008::NONE:               return "NONE";
        case PciSubDevice11020008::SUBDEVICE_11020008: return "SUBDEVICE_11020008";
        case PciSubDevice11020008::SUBDEVICE_11021001: return "SUBDEVICE_11021001";
        case PciSubDevice11020008::SUBDEVICE_11021021: return "SUBDEVICE_11021021";
        case PciSubDevice11020008::SUBDEVICE_11021022: return "SUBDEVICE_11021022";
        case PciSubDevice11020008::SUBDEVICE_11021023: return "SUBDEVICE_11021023";
        case PciSubDevice11020008::SUBDEVICE_11021024: return "SUBDEVICE_11021024";
        case PciSubDevice11020008::SUBDEVICE_11021101: return "SUBDEVICE_11021101";
        case PciSubDevice11020008::SUBDEVICE_11022001: return "SUBDEVICE_11022001";
        case PciSubDevice11020008::SUBDEVICE_11022021: return "SUBDEVICE_11022021";
        case PciSubDevice11020008::SUBDEVICE_11024002: return "SUBDEVICE_11024002";
        case PciSubDevice11020008::SUBDEVICE_11024003: return "SUBDEVICE_11024003";
        case PciSubDevice11020008::SUBDEVICE_11024004: return "SUBDEVICE_11024004";
        case PciSubDevice11020008::SUBDEVICE_11024005: return "SUBDEVICE_11024005";
        case PciSubDevice11020008::SUBDEVICE_11024007: return "SUBDEVICE_11024007";
        case PciSubDevice11020008::SUBDEVICE_11024201: return "SUBDEVICE_11024201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020008::SUBDEVICE_11020008: return "EMU0404 Digital Audio System";
        case PciSubDevice11020008::SUBDEVICE_11021001: return "SB0400 Audigy 2 Value";
        case PciSubDevice11020008::SUBDEVICE_11021021: return "SB0610 Audigy 4 Value";
        case PciSubDevice11020008::SUBDEVICE_11021022: return "SBxxx Audigy 2/4 Value";
        case PciSubDevice11020008::SUBDEVICE_11021023: return "SB0612 Audigy 2 LS";
        case PciSubDevice11020008::SUBDEVICE_11021024: return "SB1550 Audigy 5/Rx";
        case PciSubDevice11020008::SUBDEVICE_11021101: return "SBxxxx Audigy 2 SA";
        case PciSubDevice11020008::SUBDEVICE_11022001: return "SB0530 Audigy 2 ZS Notebook";
        case PciSubDevice11020008::SUBDEVICE_11022021: return "SBxxxx Audigy 4 Notebook";
        case PciSubDevice11020008::SUBDEVICE_11024002: return "E-MU 0404";
        case PciSubDevice11020008::SUBDEVICE_11024003: return "E-MU 1010";
        case PciSubDevice11020008::SUBDEVICE_11024004: return "EMU1010 Digital Audio System [MAEM8960]";
        case PciSubDevice11020008::SUBDEVICE_11024005: return "E-MU 0404 [MAEM8984]";
        case PciSubDevice11020008::SUBDEVICE_11024007: return "E-MU 1010 [MAEM8982]";
        case PciSubDevice11020008::SUBDEVICE_11024201: return "E-MU 0202 [MAEM8950]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020008_H
