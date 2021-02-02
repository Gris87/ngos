// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B3673C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B3673C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B3673C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140415 = 0x10140415,
    SUBDEVICE_10140487 = 0x10140487,
    SUBDEVICE_103C1782 = 0x103C1782,
    SUBDEVICE_15B30021 = 0x15B30021
};



inline const char8* enumToString(PciSubDevice15B3673C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B3673C::NONE:               return "NONE";
        case PciSubDevice15B3673C::SUBDEVICE_10140415: return "SUBDEVICE_10140415";
        case PciSubDevice15B3673C::SUBDEVICE_10140487: return "SUBDEVICE_10140487";
        case PciSubDevice15B3673C::SUBDEVICE_103C1782: return "SUBDEVICE_103C1782";
        case PciSubDevice15B3673C::SUBDEVICE_15B30021: return "SUBDEVICE_15B30021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B3673C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B3673C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B3673C::SUBDEVICE_10140415: return "PCIe2 2-port 4X InfiniBand QDR Adapter for Power";
        case PciSubDevice15B3673C::SUBDEVICE_10140487: return "GX++ 1-port 4X IB QDR Adapter for Power 795";
        case PciSubDevice15B3673C::SUBDEVICE_103C1782: return "4X QDR InfiniBand Mezzanine HCA for c-Class BladeSystem";
        case PciSubDevice15B3673C::SUBDEVICE_15B30021: return "HP InfiniBand 4X QDR CX-2 PCI-e G2 Dual Port HCA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B3673C_H
