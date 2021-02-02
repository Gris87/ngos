// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861031: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140209 = 0x10140209,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_104D813C = 0x104D813C,
    SUBDEVICE_107B5350 = 0x107B5350,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_144DC000 = 0x144DC000,
    SUBDEVICE_144DC001 = 0x144DC001,
    SUBDEVICE_144DC003 = 0x144DC003,
    SUBDEVICE_144DC006 = 0x144DC006
};



inline const char8* enumToString(PciSubDevice80861031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861031::NONE:               return "NONE";
        case PciSubDevice80861031::SUBDEVICE_10140209: return "SUBDEVICE_10140209";
        case PciSubDevice80861031::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice80861031::SUBDEVICE_104D813C: return "SUBDEVICE_104D813C";
        case PciSubDevice80861031::SUBDEVICE_107B5350: return "SUBDEVICE_107B5350";
        case PciSubDevice80861031::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice80861031::SUBDEVICE_144DC000: return "SUBDEVICE_144DC000";
        case PciSubDevice80861031::SUBDEVICE_144DC001: return "SUBDEVICE_144DC001";
        case PciSubDevice80861031::SUBDEVICE_144DC003: return "SUBDEVICE_144DC003";
        case PciSubDevice80861031::SUBDEVICE_144DC006: return "SUBDEVICE_144DC006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861031::SUBDEVICE_10140209: return "ThinkPad A/T/X Series";
        case PciSubDevice80861031::SUBDEVICE_104D80E7: return "Vaio PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice80861031::SUBDEVICE_104D813C: return "Vaio PCG-GRV616G";
        case PciSubDevice80861031::SUBDEVICE_107B5350: return "EtherExpress PRO/100 VE";
        case PciSubDevice80861031::SUBDEVICE_11790001: return "EtherExpress PRO/100 VE";
        case PciSubDevice80861031::SUBDEVICE_144DC000: return "EtherExpress PRO/100 VE";
        case PciSubDevice80861031::SUBDEVICE_144DC001: return "EtherExpress PRO/100 VE";
        case PciSubDevice80861031::SUBDEVICE_144DC003: return "EtherExpress PRO/100 VE";
        case PciSubDevice80861031::SUBDEVICE_144DC006: return "vpr Matrix 170B4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861031_H
