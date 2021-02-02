// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029553_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029553_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029553: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025015E = 0x1025015E,
    SUBDEVICE_1025017D = 0x1025017D,
    SUBDEVICE_10250205 = 0x10250205,
    SUBDEVICE_10250206 = 0x10250206,
    SUBDEVICE_10250237 = 0x10250237,
    SUBDEVICE_102802BE = 0x102802BE,
    SUBDEVICE_102802E8 = 0x102802E8,
    SUBDEVICE_103C143C = 0x103C143C,
    SUBDEVICE_103C1446 = 0x103C1446,
    SUBDEVICE_103C3624 = 0x103C3624,
    SUBDEVICE_103C3628 = 0x103C3628,
    SUBDEVICE_103C3636 = 0x103C3636,
    SUBDEVICE_10431B32 = 0x10431B32,
    SUBDEVICE_10431B42 = 0x10431B42,
    SUBDEVICE_104D9056 = 0x104D9056,
    SUBDEVICE_1179FF82 = 0x1179FF82,
    SUBDEVICE_144DC07F = 0x144DC07F,
    SUBDEVICE_144DC571 = 0x144DC571,
    SUBDEVICE_14621006 = 0x14621006,
    SUBDEVICE_17AA2129 = 0x17AA2129,
    SUBDEVICE_17AA215B = 0x17AA215B,
    SUBDEVICE_17AA21BB = 0x17AA21BB
};



inline const char8* enumToString(PciSubDevice10029553 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029553::NONE:               return "NONE";
        case PciSubDevice10029553::SUBDEVICE_1025015E: return "SUBDEVICE_1025015E";
        case PciSubDevice10029553::SUBDEVICE_1025017D: return "SUBDEVICE_1025017D";
        case PciSubDevice10029553::SUBDEVICE_10250205: return "SUBDEVICE_10250205";
        case PciSubDevice10029553::SUBDEVICE_10250206: return "SUBDEVICE_10250206";
        case PciSubDevice10029553::SUBDEVICE_10250237: return "SUBDEVICE_10250237";
        case PciSubDevice10029553::SUBDEVICE_102802BE: return "SUBDEVICE_102802BE";
        case PciSubDevice10029553::SUBDEVICE_102802E8: return "SUBDEVICE_102802E8";
        case PciSubDevice10029553::SUBDEVICE_103C143C: return "SUBDEVICE_103C143C";
        case PciSubDevice10029553::SUBDEVICE_103C1446: return "SUBDEVICE_103C1446";
        case PciSubDevice10029553::SUBDEVICE_103C3624: return "SUBDEVICE_103C3624";
        case PciSubDevice10029553::SUBDEVICE_103C3628: return "SUBDEVICE_103C3628";
        case PciSubDevice10029553::SUBDEVICE_103C3636: return "SUBDEVICE_103C3636";
        case PciSubDevice10029553::SUBDEVICE_10431B32: return "SUBDEVICE_10431B32";
        case PciSubDevice10029553::SUBDEVICE_10431B42: return "SUBDEVICE_10431B42";
        case PciSubDevice10029553::SUBDEVICE_104D9056: return "SUBDEVICE_104D9056";
        case PciSubDevice10029553::SUBDEVICE_1179FF82: return "SUBDEVICE_1179FF82";
        case PciSubDevice10029553::SUBDEVICE_144DC07F: return "SUBDEVICE_144DC07F";
        case PciSubDevice10029553::SUBDEVICE_144DC571: return "SUBDEVICE_144DC571";
        case PciSubDevice10029553::SUBDEVICE_14621006: return "SUBDEVICE_14621006";
        case PciSubDevice10029553::SUBDEVICE_17AA2129: return "SUBDEVICE_17AA2129";
        case PciSubDevice10029553::SUBDEVICE_17AA215B: return "SUBDEVICE_17AA215B";
        case PciSubDevice10029553::SUBDEVICE_17AA21BB: return "SUBDEVICE_17AA21BB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029553 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029553 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029553::SUBDEVICE_1025015E: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_1025017D: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_10250205: return "Mobility Radeon HD 4570 / 545v";
        case PciSubDevice10029553::SUBDEVICE_10250206: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_10250237: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_102802BE: return "Mobility Radeon HD 4570 / 545v";
        case PciSubDevice10029553::SUBDEVICE_102802E8: return "Mobility Radeon HD 4530";
        case PciSubDevice10029553::SUBDEVICE_103C143C: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_103C1446: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_103C3624: return "Mobility Radeon HD 4530";
        case PciSubDevice10029553::SUBDEVICE_103C3628: return "Mobility Radeon HD 4530";
        case PciSubDevice10029553::SUBDEVICE_103C3636: return "Mobility Radeon HD 4530";
        case PciSubDevice10029553::SUBDEVICE_10431B32: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_10431B42: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_104D9056: return "Mobility Radeon HD 4570";
        case PciSubDevice10029553::SUBDEVICE_1179FF82: return "Satellite L505-13T GPU (Mobility Radeon HD 5145)";
        case PciSubDevice10029553::SUBDEVICE_144DC07F: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_144DC571: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_14621006: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_17AA2129: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_17AA215B: return "Mobility Radeon HD 545v";
        case PciSubDevice10029553::SUBDEVICE_17AA21BB: return "Mobility Radeon HD 545v";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029553_H
