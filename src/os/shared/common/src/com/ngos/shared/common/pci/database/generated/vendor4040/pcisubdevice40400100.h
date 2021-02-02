// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice40400100: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C171B = 0x103C171B,
    SUBDEVICE_103C1740 = 0x103C1740,
    SUBDEVICE_103C3251 = 0x103C3251,
    SUBDEVICE_103C705A = 0x103C705A,
    SUBDEVICE_103C705B = 0x103C705B,
    SUBDEVICE_152D896B = 0x152D896B,
    SUBDEVICE_40400124 = 0x40400124,
    SUBDEVICE_40400126 = 0x40400126
};



inline const char8* enumToString(PciSubDevice40400100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40400100::NONE:               return "NONE";
        case PciSubDevice40400100::SUBDEVICE_103C171B: return "SUBDEVICE_103C171B";
        case PciSubDevice40400100::SUBDEVICE_103C1740: return "SUBDEVICE_103C1740";
        case PciSubDevice40400100::SUBDEVICE_103C3251: return "SUBDEVICE_103C3251";
        case PciSubDevice40400100::SUBDEVICE_103C705A: return "SUBDEVICE_103C705A";
        case PciSubDevice40400100::SUBDEVICE_103C705B: return "SUBDEVICE_103C705B";
        case PciSubDevice40400100::SUBDEVICE_152D896B: return "SUBDEVICE_152D896B";
        case PciSubDevice40400100::SUBDEVICE_40400124: return "SUBDEVICE_40400124";
        case PciSubDevice40400100::SUBDEVICE_40400126: return "SUBDEVICE_40400126";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice40400100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice40400100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice40400100::SUBDEVICE_103C171B: return "NC522m Dual Port 10GbE Multifunction BL-c Adapter";
        case PciSubDevice40400100::SUBDEVICE_103C1740: return "NC375T PCI Express Quad Port Gigabit Server Adapter";
        case PciSubDevice40400100::SUBDEVICE_103C3251: return "NC375i 1G w/NC524SFP 10G Module";
        case PciSubDevice40400100::SUBDEVICE_103C705A: return "NC375i Integrated Quad Port Multifunction Gigabit Server Adapter";
        case PciSubDevice40400100::SUBDEVICE_103C705B: return "NC522SFP Dual Port 10GbE Server Adapter";
        case PciSubDevice40400100::SUBDEVICE_152D896B: return "TG20 Dual Port 10GbE Server/Storage Adapter";
        case PciSubDevice40400100::SUBDEVICE_40400124: return "NX3031 Quad Port Gigabit Server Adapter";
        case PciSubDevice40400100::SUBDEVICE_40400126: return "Dual Port SFP+ 10GbE Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCISUBDEVICE40400100_H
