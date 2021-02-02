// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086105F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C704F = 0x103C704F,
    SUBDEVICE_8086005A = 0x8086005A,
    SUBDEVICE_8086115F = 0x8086115F,
    SUBDEVICE_8086125F = 0x8086125F,
    SUBDEVICE_8086135F = 0x8086135F
};



inline const char8* enumToString(PciSubDevice8086105F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086105F::NONE:               return "NONE";
        case PciSubDevice8086105F::SUBDEVICE_103C704F: return "SUBDEVICE_103C704F";
        case PciSubDevice8086105F::SUBDEVICE_8086005A: return "SUBDEVICE_8086005A";
        case PciSubDevice8086105F::SUBDEVICE_8086115F: return "SUBDEVICE_8086115F";
        case PciSubDevice8086105F::SUBDEVICE_8086125F: return "SUBDEVICE_8086125F";
        case PciSubDevice8086105F::SUBDEVICE_8086135F: return "SUBDEVICE_8086135F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086105F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086105F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086105F::SUBDEVICE_103C704F: return "Dual Port 1000Base-SX (PCIe) [AD338A]";
        case PciSubDevice8086105F::SUBDEVICE_8086005A: return "PRO/1000 PF Dual Port Server Adapter";
        case PciSubDevice8086105F::SUBDEVICE_8086115F: return "PRO/1000 PF Dual Port Server Adapter";
        case PciSubDevice8086105F::SUBDEVICE_8086125F: return "PRO/1000 PF Dual Port Server Adapter";
        case PciSubDevice8086105F::SUBDEVICE_8086135F: return "PRO/1000 PF Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105F_H
