// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500CF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500CF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice900500CF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800CE = 0x102800CE,
    SUBDEVICE_102800D1 = 0x102800D1,
    SUBDEVICE_102800D9 = 0x102800D9,
    SUBDEVICE_10F12462 = 0x10F12462,
    SUBDEVICE_15D99005 = 0x15D99005,
    SUBDEVICE_80863411 = 0x80863411
};



inline const char8* enumToString(PciSubDevice900500CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice900500CF::NONE:               return "NONE";
        case PciSubDevice900500CF::SUBDEVICE_102800CE: return "SUBDEVICE_102800CE";
        case PciSubDevice900500CF::SUBDEVICE_102800D1: return "SUBDEVICE_102800D1";
        case PciSubDevice900500CF::SUBDEVICE_102800D9: return "SUBDEVICE_102800D9";
        case PciSubDevice900500CF::SUBDEVICE_10F12462: return "SUBDEVICE_10F12462";
        case PciSubDevice900500CF::SUBDEVICE_15D99005: return "SUBDEVICE_15D99005";
        case PciSubDevice900500CF::SUBDEVICE_80863411: return "SUBDEVICE_80863411";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice900500CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice900500CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice900500CF::SUBDEVICE_102800CE: return "PowerEdge 1400";
        case PciSubDevice900500CF::SUBDEVICE_102800D1: return "PowerEdge 2550";
        case PciSubDevice900500CF::SUBDEVICE_102800D9: return "PowerEdge 2500";
        case PciSubDevice900500CF::SUBDEVICE_10F12462: return "Thunder K7 S2462";
        case PciSubDevice900500CF::SUBDEVICE_15D99005: return "Onboard SCSI Host Adapter";
        case PciSubDevice900500CF::SUBDEVICE_80863411: return "SDS2 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE900500CF_H
