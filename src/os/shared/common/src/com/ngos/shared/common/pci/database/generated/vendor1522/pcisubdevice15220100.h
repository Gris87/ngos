// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15220100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15220100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15220100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15220200 = 0x15220200,
    SUBDEVICE_15220300 = 0x15220300,
    SUBDEVICE_15220400 = 0x15220400,
    SUBDEVICE_15220500 = 0x15220500,
    SUBDEVICE_15220600 = 0x15220600,
    SUBDEVICE_15220700 = 0x15220700,
    SUBDEVICE_15220800 = 0x15220800,
    SUBDEVICE_15220C00 = 0x15220C00,
    SUBDEVICE_15220D00 = 0x15220D00,
    SUBDEVICE_15221D00 = 0x15221D00,
    SUBDEVICE_15222000 = 0x15222000,
    SUBDEVICE_15222100 = 0x15222100,
    SUBDEVICE_15222200 = 0x15222200,
    SUBDEVICE_15222300 = 0x15222300,
    SUBDEVICE_15222400 = 0x15222400,
    SUBDEVICE_15222500 = 0x15222500,
    SUBDEVICE_15222600 = 0x15222600,
    SUBDEVICE_15222700 = 0x15222700,
    SUBDEVICE_15223000 = 0x15223000,
    SUBDEVICE_15223100 = 0x15223100,
    SUBDEVICE_15223200 = 0x15223200,
    SUBDEVICE_15223300 = 0x15223300,
    SUBDEVICE_15223400 = 0x15223400,
    SUBDEVICE_15223500 = 0x15223500,
    SUBDEVICE_15223C00 = 0x15223C00,
    SUBDEVICE_15223D00 = 0x15223D00
};



inline const char8* enumToString(PciSubDevice15220100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15220100::NONE:               return "NONE";
        case PciSubDevice15220100::SUBDEVICE_15220200: return "SUBDEVICE_15220200";
        case PciSubDevice15220100::SUBDEVICE_15220300: return "SUBDEVICE_15220300";
        case PciSubDevice15220100::SUBDEVICE_15220400: return "SUBDEVICE_15220400";
        case PciSubDevice15220100::SUBDEVICE_15220500: return "SUBDEVICE_15220500";
        case PciSubDevice15220100::SUBDEVICE_15220600: return "SUBDEVICE_15220600";
        case PciSubDevice15220100::SUBDEVICE_15220700: return "SUBDEVICE_15220700";
        case PciSubDevice15220100::SUBDEVICE_15220800: return "SUBDEVICE_15220800";
        case PciSubDevice15220100::SUBDEVICE_15220C00: return "SUBDEVICE_15220C00";
        case PciSubDevice15220100::SUBDEVICE_15220D00: return "SUBDEVICE_15220D00";
        case PciSubDevice15220100::SUBDEVICE_15221D00: return "SUBDEVICE_15221D00";
        case PciSubDevice15220100::SUBDEVICE_15222000: return "SUBDEVICE_15222000";
        case PciSubDevice15220100::SUBDEVICE_15222100: return "SUBDEVICE_15222100";
        case PciSubDevice15220100::SUBDEVICE_15222200: return "SUBDEVICE_15222200";
        case PciSubDevice15220100::SUBDEVICE_15222300: return "SUBDEVICE_15222300";
        case PciSubDevice15220100::SUBDEVICE_15222400: return "SUBDEVICE_15222400";
        case PciSubDevice15220100::SUBDEVICE_15222500: return "SUBDEVICE_15222500";
        case PciSubDevice15220100::SUBDEVICE_15222600: return "SUBDEVICE_15222600";
        case PciSubDevice15220100::SUBDEVICE_15222700: return "SUBDEVICE_15222700";
        case PciSubDevice15220100::SUBDEVICE_15223000: return "SUBDEVICE_15223000";
        case PciSubDevice15220100::SUBDEVICE_15223100: return "SUBDEVICE_15223100";
        case PciSubDevice15220100::SUBDEVICE_15223200: return "SUBDEVICE_15223200";
        case PciSubDevice15220100::SUBDEVICE_15223300: return "SUBDEVICE_15223300";
        case PciSubDevice15220100::SUBDEVICE_15223400: return "SUBDEVICE_15223400";
        case PciSubDevice15220100::SUBDEVICE_15223500: return "SUBDEVICE_15223500";
        case PciSubDevice15220100::SUBDEVICE_15223C00: return "SUBDEVICE_15223C00";
        case PciSubDevice15220100::SUBDEVICE_15223D00: return "SUBDEVICE_15223D00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15220100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15220100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15220100::SUBDEVICE_15220200: return "RockForceDUO 2 Port V.92/V.44 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220300: return "RockForceQUATRO 4 Port V.92/V.44 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220400: return "RockForceDUO+ 2 Port V.92/V.44 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220500: return "RockForceQUATRO+ 4 Port V.92/V.44 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220600: return "RockForce+ 2 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220700: return "RockForce+ 4 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220800: return "RockForceOCTO+ 8 Port V.92/V.44 Data/Fax/Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220C00: return "RockForceDUO+ 2 Port V.92/V.44 Data, V.34 Super-G3 Fax, Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15220D00: return "RockForceQUATRO+ 4 Port V.92/V.44 Data, V.34 Super-G3 Fax, Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15221D00: return "RockForceOCTO+ 8 Port V.92/V.44 Data, V.34 Super-G3 Fax, Voice Modem";
        case PciSubDevice15220100::SUBDEVICE_15222000: return "RockForceD1 1 Port V.90 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15222100: return "RockForceF1 1 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15222200: return "RockForceD2 2 Port V.90 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15222300: return "RockForceF2 2 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15222400: return "RockForceD4 4 Port V.90 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15222500: return "RockForceF4 4 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15222600: return "RockForceD8 8 Port V.90 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15222700: return "RockForceF8 8 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15223000: return "IQ Express D1 - 1 Port V.92 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15223100: return "IQ Express F1 - 1 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15223200: return "IQ Express D2 - 2 Port V.92 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15223300: return "IQ Express F2 - 2 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15223400: return "IQ Express D4 - 4 Port V.92 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15223500: return "IQ Express F4 - 4 Port V.34 Super-G3 Fax Modem";
        case PciSubDevice15220100::SUBDEVICE_15223C00: return "IQ Express D8 - 8 Port V.92 Data Modem";
        case PciSubDevice15220100::SUBDEVICE_15223D00: return "IQ Express F8 - 8 Port V.34 Super-G3 Fax Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15220100_H
