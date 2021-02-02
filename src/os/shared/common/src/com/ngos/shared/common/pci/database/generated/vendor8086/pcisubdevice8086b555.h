// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086B555_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086B555_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086B555: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12C75005 = 0x12C75005,
    SUBDEVICE_12C75006 = 0x12C75006,
    SUBDEVICE_12D9000A = 0x12D9000A,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051,
    SUBDEVICE_E4BF1000 = 0xE4BF1000
};



inline const char8* enumToString(PciSubDevice8086B555 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086B555::NONE:               return "NONE";
        case PciSubDevice8086B555::SUBDEVICE_12C75005: return "SUBDEVICE_12C75005";
        case PciSubDevice8086B555::SUBDEVICE_12C75006: return "SUBDEVICE_12C75006";
        case PciSubDevice8086B555::SUBDEVICE_12D9000A: return "SUBDEVICE_12D9000A";
        case PciSubDevice8086B555::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice8086B555::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";
        case PciSubDevice8086B555::SUBDEVICE_E4BF1000: return "SUBDEVICE_E4BF1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086B555 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086B555 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086B555::SUBDEVICE_12C75005: return "SS7HD PCI Adaptor Card";
        case PciSubDevice8086B555::SUBDEVICE_12C75006: return "SS7HDC cPCI Adaptor Card";
        case PciSubDevice8086B555::SUBDEVICE_12D9000A: return "PCI VoIP Gateway";
        case PciSubDevice8086B555::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice8086B555::SUBDEVICE_4C531051: return "CE7 mainboard";
        case PciSubDevice8086B555::SUBDEVICE_E4BF1000: return "CC8-1-BLUES";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086B555_H
