// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90045647_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90045647_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90045647: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90047710 = 0x90047710,
    SUBDEVICE_90047711 = 0x90047711
};



inline const char8* enumToString(PciSubDevice90045647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90045647::NONE:               return "NONE";
        case PciSubDevice90045647::SUBDEVICE_90047710: return "SUBDEVICE_90047710";
        case PciSubDevice90045647::SUBDEVICE_90047711: return "SUBDEVICE_90047711";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90045647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90045647 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90045647::SUBDEVICE_90047710: return "ANA-7711F TCP Offload Engine - Optical";
        case PciSubDevice90045647::SUBDEVICE_90047711: return "ANA-7711LP TCP Offload Engine - Copper";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90045647_H
