// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610BC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140368 = 0x10140368,
    SUBDEVICE_103C704B = 0x103C704B,
    SUBDEVICE_108E11BC = 0x108E11BC,
    SUBDEVICE_808610BC = 0x808610BC,
    SUBDEVICE_808611BC = 0x808611BC
};



inline const char8* enumToString(PciSubDevice808610BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610BC::NONE:               return "NONE";
        case PciSubDevice808610BC::SUBDEVICE_10140368: return "SUBDEVICE_10140368";
        case PciSubDevice808610BC::SUBDEVICE_103C704B: return "SUBDEVICE_103C704B";
        case PciSubDevice808610BC::SUBDEVICE_108E11BC: return "SUBDEVICE_108E11BC";
        case PciSubDevice808610BC::SUBDEVICE_808610BC: return "SUBDEVICE_808610BC";
        case PciSubDevice808610BC::SUBDEVICE_808611BC: return "SUBDEVICE_808611BC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610BC::SUBDEVICE_10140368: return "4-Port 10/100/1000 Base-TX PCI Express Adapter for POWER";
        case PciSubDevice808610BC::SUBDEVICE_103C704B: return "NC364T PCI Express Quad Port Gigabit Server Adapter";
        case PciSubDevice808610BC::SUBDEVICE_108E11BC: return "Quad Port Adapter";
        case PciSubDevice808610BC::SUBDEVICE_808610BC: return "PRO/1000 PT Quad Port LP Server Adapter";
        case PciSubDevice808610BC::SUBDEVICE_808611BC: return "PRO/1000 PT Quad Port LP Server Adapter (Kirkwood Low Profile)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610BC_H
