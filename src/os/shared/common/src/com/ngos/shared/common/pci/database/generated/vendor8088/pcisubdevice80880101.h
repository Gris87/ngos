// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80880101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80880201 = 0x80880201,
    SUBDEVICE_80884201 = 0x80884201,
    SUBDEVICE_80888201 = 0x80888201,
    SUBDEVICE_8088C201 = 0x8088C201
};



inline const char8* enumToString(PciSubDevice80880101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880101::NONE:               return "NONE";
        case PciSubDevice80880101::SUBDEVICE_80880201: return "SUBDEVICE_80880201";
        case PciSubDevice80880101::SUBDEVICE_80884201: return "SUBDEVICE_80884201";
        case PciSubDevice80880101::SUBDEVICE_80888201: return "SUBDEVICE_80888201";
        case PciSubDevice80880101::SUBDEVICE_8088C201: return "SUBDEVICE_8088C201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80880101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80880101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80880101::SUBDEVICE_80880201: return "Dual-Port Ethernet Network Adaptor SF200T";
        case PciSubDevice80880101::SUBDEVICE_80884201: return "Dual-Port Ethernet Network Adaptor SF200T (WOL)";
        case PciSubDevice80880101::SUBDEVICE_80888201: return "Dual-Port Ethernet Network Adaptor SF200T (NCSI)";
        case PciSubDevice80880101::SUBDEVICE_8088C201: return "Dual-Port Ethernet Network Adaptor SF200T (WOL, NCSI)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8088_PCISUBDEVICE80880101_H
