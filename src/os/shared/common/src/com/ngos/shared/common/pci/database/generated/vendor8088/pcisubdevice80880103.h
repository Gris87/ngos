// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880103_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80880103: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80880401 = 0x80880401,
    SUBDEVICE_80880440 = 0x80880440,
    SUBDEVICE_80884103 = 0x80884103,
    SUBDEVICE_80888103 = 0x80888103,
    SUBDEVICE_8088C103 = 0x8088C103
};



inline const char8* enumToString(PciSubDevice80880103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880103::NONE:               return "NONE";
        case PciSubDevice80880103::SUBDEVICE_80880401: return "SUBDEVICE_80880401";
        case PciSubDevice80880103::SUBDEVICE_80880440: return "SUBDEVICE_80880440";
        case PciSubDevice80880103::SUBDEVICE_80884103: return "SUBDEVICE_80884103";
        case PciSubDevice80880103::SUBDEVICE_80888103: return "SUBDEVICE_80888103";
        case PciSubDevice80880103::SUBDEVICE_8088C103: return "SUBDEVICE_8088C103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80880103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80880103 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880103::SUBDEVICE_80880401: return "Qual-Port Ethernet Network Adaptor SF400T";
        case PciSubDevice80880103::SUBDEVICE_80880440: return "Qual-Port Ethernet Network Adaptor SF400-OCP";
        case PciSubDevice80880103::SUBDEVICE_80884103: return "Quad-Port Ethernet Network Adaptor SF400T (WOL)";
        case PciSubDevice80880103::SUBDEVICE_80888103: return "Quad-Port Ethernet Network Adaptor SF400T (NCSI)";
        case PciSubDevice80880103::SUBDEVICE_8088C103: return "Quad-Port Ethernet Network Adaptor SF400T (WOL, NCSI)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880103_H
