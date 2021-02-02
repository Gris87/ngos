// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15811_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15811_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C15811: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2A34 = 0x103C2A34,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_103C2A9E = 0x103C2A9E,
    SUBDEVICE_10438294 = 0x10438294,
    SUBDEVICE_11BD000E = 0x11BD000E,
    SUBDEVICE_8086524C = 0x8086524C,
    SUBDEVICE_90050033 = 0x90050033,
    SUBDEVICE_DEAD0800 = 0xDEAD0800
};



inline const char8* enumToString(PciSubDevice11C15811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C15811::NONE:               return "NONE";
        case PciSubDevice11C15811::SUBDEVICE_103C2A34: return "SUBDEVICE_103C2A34";
        case PciSubDevice11C15811::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice11C15811::SUBDEVICE_103C2A9E: return "SUBDEVICE_103C2A9E";
        case PciSubDevice11C15811::SUBDEVICE_10438294: return "SUBDEVICE_10438294";
        case PciSubDevice11C15811::SUBDEVICE_11BD000E: return "SUBDEVICE_11BD000E";
        case PciSubDevice11C15811::SUBDEVICE_8086524C: return "SUBDEVICE_8086524C";
        case PciSubDevice11C15811::SUBDEVICE_90050033: return "SUBDEVICE_90050033";
        case PciSubDevice11C15811::SUBDEVICE_DEAD0800: return "SUBDEVICE_DEAD0800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C15811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C15811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C15811::SUBDEVICE_103C2A34: return "Pavilion a1677c";
        case PciSubDevice11C15811::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice11C15811::SUBDEVICE_103C2A9E: return "Pavilion p6310f";
        case PciSubDevice11C15811::SUBDEVICE_10438294: return "LSI FW322/323 IEEE 1394a FireWire Controller";
        case PciSubDevice11C15811::SUBDEVICE_11BD000E: return "LSI FW323";
        case PciSubDevice11C15811::SUBDEVICE_8086524C: return "D865PERL mainboard";
        case PciSubDevice11C15811::SUBDEVICE_90050033: return "Adaptec AFW-2100 (HP) 2102900-R";
        case PciSubDevice11C15811::SUBDEVICE_DEAD0800: return "FireWire Host Bus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C15811_H
