// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880107_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880107_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80880107: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80880402 = 0x80880402,
    SUBDEVICE_80884402 = 0x80884402,
    SUBDEVICE_80888402 = 0x80888402,
    SUBDEVICE_8088C402 = 0x8088C402
};



inline const char8* enumToString(PciSubDevice80880107 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880107::NONE:               return "NONE";
        case PciSubDevice80880107::SUBDEVICE_80880402: return "SUBDEVICE_80880402";
        case PciSubDevice80880107::SUBDEVICE_80884402: return "SUBDEVICE_80884402";
        case PciSubDevice80880107::SUBDEVICE_80888402: return "SUBDEVICE_80888402";
        case PciSubDevice80880107::SUBDEVICE_8088C402: return "SUBDEVICE_8088C402";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80880107 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80880107 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880107::SUBDEVICE_80880402: return "Qual-Port Ethernet Network Adaptor SF400HT";
        case PciSubDevice80880107::SUBDEVICE_80884402: return "Quad-Port Ethernet Network Adaptor SF400HT (WOL)";
        case PciSubDevice80880107::SUBDEVICE_80888402: return "Quad-Port Ethernet Network Adaptor SF400HT (NCSI)";
        case PciSubDevice80880107::SUBDEVICE_8088C402: return "Quad-Port Ethernet Network Adaptor SF400HT (WOL, NCSI)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880107_H
