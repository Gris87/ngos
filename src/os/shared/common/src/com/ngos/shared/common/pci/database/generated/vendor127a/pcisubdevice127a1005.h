// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1005: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1005127A = 0x1005127A,
    SUBDEVICE_10338029 = 0x10338029,
    SUBDEVICE_10338054 = 0x10338054,
    SUBDEVICE_10CF103C = 0x10CF103C,
    SUBDEVICE_10CF1055 = 0x10CF1055,
    SUBDEVICE_10CF1056 = 0x10CF1056,
    SUBDEVICE_122D4003 = 0x122D4003,
    SUBDEVICE_122D4006 = 0x122D4006,
    SUBDEVICE_122D4008 = 0x122D4008,
    SUBDEVICE_122D4009 = 0x122D4009,
    SUBDEVICE_122D4010 = 0x122D4010,
    SUBDEVICE_122D4011 = 0x122D4011,
    SUBDEVICE_122D4013 = 0x122D4013,
    SUBDEVICE_122D4015 = 0x122D4015,
    SUBDEVICE_122D4016 = 0x122D4016,
    SUBDEVICE_122D4019 = 0x122D4019,
    SUBDEVICE_13DF1005 = 0x13DF1005,
    SUBDEVICE_13E00187 = 0x13E00187,
    SUBDEVICE_13E001A7 = 0x13E001A7,
    SUBDEVICE_13E001B7 = 0x13E001B7,
    SUBDEVICE_13E001D7 = 0x13E001D7,
    SUBDEVICE_14361005 = 0x14361005,
    SUBDEVICE_14361105 = 0x14361105,
    SUBDEVICE_14371105 = 0x14371105
};



inline const char8* enumToString(PciSubDevice127A1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1005::NONE:               return "NONE";
        case PciSubDevice127A1005::SUBDEVICE_1005127A: return "SUBDEVICE_1005127A";
        case PciSubDevice127A1005::SUBDEVICE_10338029: return "SUBDEVICE_10338029";
        case PciSubDevice127A1005::SUBDEVICE_10338054: return "SUBDEVICE_10338054";
        case PciSubDevice127A1005::SUBDEVICE_10CF103C: return "SUBDEVICE_10CF103C";
        case PciSubDevice127A1005::SUBDEVICE_10CF1055: return "SUBDEVICE_10CF1055";
        case PciSubDevice127A1005::SUBDEVICE_10CF1056: return "SUBDEVICE_10CF1056";
        case PciSubDevice127A1005::SUBDEVICE_122D4003: return "SUBDEVICE_122D4003";
        case PciSubDevice127A1005::SUBDEVICE_122D4006: return "SUBDEVICE_122D4006";
        case PciSubDevice127A1005::SUBDEVICE_122D4008: return "SUBDEVICE_122D4008";
        case PciSubDevice127A1005::SUBDEVICE_122D4009: return "SUBDEVICE_122D4009";
        case PciSubDevice127A1005::SUBDEVICE_122D4010: return "SUBDEVICE_122D4010";
        case PciSubDevice127A1005::SUBDEVICE_122D4011: return "SUBDEVICE_122D4011";
        case PciSubDevice127A1005::SUBDEVICE_122D4013: return "SUBDEVICE_122D4013";
        case PciSubDevice127A1005::SUBDEVICE_122D4015: return "SUBDEVICE_122D4015";
        case PciSubDevice127A1005::SUBDEVICE_122D4016: return "SUBDEVICE_122D4016";
        case PciSubDevice127A1005::SUBDEVICE_122D4019: return "SUBDEVICE_122D4019";
        case PciSubDevice127A1005::SUBDEVICE_13DF1005: return "SUBDEVICE_13DF1005";
        case PciSubDevice127A1005::SUBDEVICE_13E00187: return "SUBDEVICE_13E00187";
        case PciSubDevice127A1005::SUBDEVICE_13E001A7: return "SUBDEVICE_13E001A7";
        case PciSubDevice127A1005::SUBDEVICE_13E001B7: return "SUBDEVICE_13E001B7";
        case PciSubDevice127A1005::SUBDEVICE_13E001D7: return "SUBDEVICE_13E001D7";
        case PciSubDevice127A1005::SUBDEVICE_14361005: return "SUBDEVICE_14361005";
        case PciSubDevice127A1005::SUBDEVICE_14361105: return "SUBDEVICE_14361105";
        case PciSubDevice127A1005::SUBDEVICE_14371105: return "SUBDEVICE_14371105";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1005::SUBDEVICE_1005127A: return "AOpen FM56-P";
        case PciSubDevice127A1005::SUBDEVICE_10338029: return "229-DFSV";
        case PciSubDevice127A1005::SUBDEVICE_10338054: return "Modem";
        case PciSubDevice127A1005::SUBDEVICE_10CF103C: return "Fujitsu";
        case PciSubDevice127A1005::SUBDEVICE_10CF1055: return "Fujitsu 229-DFSV";
        case PciSubDevice127A1005::SUBDEVICE_10CF1056: return "Fujitsu 229-DFSV";
        case PciSubDevice127A1005::SUBDEVICE_122D4003: return "MDP3858SP-U";
        case PciSubDevice127A1005::SUBDEVICE_122D4006: return "Packard Bell MDP3858V-E";
        case PciSubDevice127A1005::SUBDEVICE_122D4008: return "MDP3858SP-A/SP-NZ";
        case PciSubDevice127A1005::SUBDEVICE_122D4009: return "MDP3858SP-E";
        case PciSubDevice127A1005::SUBDEVICE_122D4010: return "MDP3858V-U";
        case PciSubDevice127A1005::SUBDEVICE_122D4011: return "MDP3858SP-SA";
        case PciSubDevice127A1005::SUBDEVICE_122D4013: return "MDP3858V-A/V-NZ";
        case PciSubDevice127A1005::SUBDEVICE_122D4015: return "MDP3858SP-W";
        case PciSubDevice127A1005::SUBDEVICE_122D4016: return "MDP3858V-W";
        case PciSubDevice127A1005::SUBDEVICE_122D4019: return "MDP3858V-SA";
        case PciSubDevice127A1005::SUBDEVICE_13DF1005: return "PCI56RVP Modem";
        case PciSubDevice127A1005::SUBDEVICE_13E00187: return "IBM";
        case PciSubDevice127A1005::SUBDEVICE_13E001A7: return "IBM";
        case PciSubDevice127A1005::SUBDEVICE_13E001B7: return "IBM DF-1156IV+/R3 Spain V.90 Modem";
        case PciSubDevice127A1005::SUBDEVICE_13E001D7: return "IBM DF-1156IV+/R3 WW V.90 Modem";
        case PciSubDevice127A1005::SUBDEVICE_14361005: return "IBM";
        case PciSubDevice127A1005::SUBDEVICE_14361105: return "IBM";
        case PciSubDevice127A1005::SUBDEVICE_14371105: return "IBM 5614PS3G V.90 Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1005_H
