// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59080_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59080_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59080: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C10EB = 0x103C10EB,
    SUBDEVICE_103C10EC = 0x103C10EC,
    SUBDEVICE_10B51123 = 0x10B51123,
    SUBDEVICE_10B59080 = 0x10B59080,
    SUBDEVICE_12D90002 = 0x12D90002,
    SUBDEVICE_12DF4422 = 0x12DF4422,
    SUBDEVICE_13699601 = 0x13699601,
    SUBDEVICE_1369A102 = 0x1369A102,
    SUBDEVICE_1369A201 = 0x1369A201,
    SUBDEVICE_1369A301 = 0x1369A301,
    SUBDEVICE_1369A401 = 0x1369A401,
    SUBDEVICE_1369A402 = 0x1369A402,
    SUBDEVICE_1369A901 = 0x1369A901,
    SUBDEVICE_1369AA01 = 0x1369AA01,
    SUBDEVICE_1517000B = 0x1517000B
};



inline const char8* enumToString(PciSubDevice10B59080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59080::NONE:               return "NONE";
        case PciSubDevice10B59080::SUBDEVICE_103C10EB: return "SUBDEVICE_103C10EB";
        case PciSubDevice10B59080::SUBDEVICE_103C10EC: return "SUBDEVICE_103C10EC";
        case PciSubDevice10B59080::SUBDEVICE_10B51123: return "SUBDEVICE_10B51123";
        case PciSubDevice10B59080::SUBDEVICE_10B59080: return "SUBDEVICE_10B59080";
        case PciSubDevice10B59080::SUBDEVICE_12D90002: return "SUBDEVICE_12D90002";
        case PciSubDevice10B59080::SUBDEVICE_12DF4422: return "SUBDEVICE_12DF4422";
        case PciSubDevice10B59080::SUBDEVICE_13699601: return "SUBDEVICE_13699601";
        case PciSubDevice10B59080::SUBDEVICE_1369A102: return "SUBDEVICE_1369A102";
        case PciSubDevice10B59080::SUBDEVICE_1369A201: return "SUBDEVICE_1369A201";
        case PciSubDevice10B59080::SUBDEVICE_1369A301: return "SUBDEVICE_1369A301";
        case PciSubDevice10B59080::SUBDEVICE_1369A401: return "SUBDEVICE_1369A401";
        case PciSubDevice10B59080::SUBDEVICE_1369A402: return "SUBDEVICE_1369A402";
        case PciSubDevice10B59080::SUBDEVICE_1369A901: return "SUBDEVICE_1369A901";
        case PciSubDevice10B59080::SUBDEVICE_1369AA01: return "SUBDEVICE_1369AA01";
        case PciSubDevice10B59080::SUBDEVICE_1517000B: return "SUBDEVICE_1517000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59080::SUBDEVICE_103C10EB: return "(Agilent) E2777B 83K Series Optical Communication Interface";
        case PciSubDevice10B59080::SUBDEVICE_103C10EC: return "(Agilent) E6978-66442 PCI CIC";
        case PciSubDevice10B59080::SUBDEVICE_10B51123: return "Sectra KK631 encryption board";
        case PciSubDevice10B59080::SUBDEVICE_10B59080: return "9080 [real subsystem ID not set]";
        case PciSubDevice10B59080::SUBDEVICE_12D90002: return "PCI Prosody Card";
        case PciSubDevice10B59080::SUBDEVICE_12DF4422: return "4422PCI [\"Do-All\" Telemetry Data Acquisition System]";
        case PciSubDevice10B59080::SUBDEVICE_13699601: return "PCX822np";
        case PciSubDevice10B59080::SUBDEVICE_1369A102: return "PCX822v2";
        case PciSubDevice10B59080::SUBDEVICE_1369A201: return "PCX442";
        case PciSubDevice10B59080::SUBDEVICE_1369A301: return "LCM440v2";
        case PciSubDevice10B59080::SUBDEVICE_1369A401: return "VX822";
        case PciSubDevice10B59080::SUBDEVICE_1369A402: return "VX822v2";
        case PciSubDevice10B59080::SUBDEVICE_1369A901: return "LCM420";
        case PciSubDevice10B59080::SUBDEVICE_1369AA01: return "VX820v2";
        case PciSubDevice10B59080::SUBDEVICE_1517000B: return "ECSG-1R3ADC-PMC Clock synthesizer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59080_H
