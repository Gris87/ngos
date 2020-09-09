// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240A03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240A03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240A03: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19248011 = 0x19248011,
    SUBDEVICE_19248012 = 0x19248012,
    SUBDEVICE_19248013 = 0x19248013,
    SUBDEVICE_19248014 = 0x19248014,
    SUBDEVICE_19248016 = 0x19248016,
    SUBDEVICE_19248017 = 0x19248017,
    SUBDEVICE_19248018 = 0x19248018,
    SUBDEVICE_19248019 = 0x19248019,
    SUBDEVICE_1924801A = 0x1924801A,
    SUBDEVICE_1924801B = 0x1924801B,
    SUBDEVICE_1924801C = 0x1924801C,
    SUBDEVICE_19248021 = 0x19248021
};



inline const char8* enumToString(PciSubDevice19240A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240A03::NONE:               return "NONE";
        case PciSubDevice19240A03::SUBDEVICE_19248011: return "SUBDEVICE_19248011";
        case PciSubDevice19240A03::SUBDEVICE_19248012: return "SUBDEVICE_19248012";
        case PciSubDevice19240A03::SUBDEVICE_19248013: return "SUBDEVICE_19248013";
        case PciSubDevice19240A03::SUBDEVICE_19248014: return "SUBDEVICE_19248014";
        case PciSubDevice19240A03::SUBDEVICE_19248016: return "SUBDEVICE_19248016";
        case PciSubDevice19240A03::SUBDEVICE_19248017: return "SUBDEVICE_19248017";
        case PciSubDevice19240A03::SUBDEVICE_19248018: return "SUBDEVICE_19248018";
        case PciSubDevice19240A03::SUBDEVICE_19248019: return "SUBDEVICE_19248019";
        case PciSubDevice19240A03::SUBDEVICE_1924801A: return "SUBDEVICE_1924801A";
        case PciSubDevice19240A03::SUBDEVICE_1924801B: return "SUBDEVICE_1924801B";
        case PciSubDevice19240A03::SUBDEVICE_1924801C: return "SUBDEVICE_1924801C";
        case PciSubDevice19240A03::SUBDEVICE_19248021: return "SUBDEVICE_19248021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240A03::SUBDEVICE_19248011: return "SFN8022-R1 8000 Series 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248012: return "SFN8522-R1 8000 Series 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248013: return "SFN8042-R1 8000 Series 10/40G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248014: return "SFN8542-R1 8000 Series 10/40G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248016: return "SFN8022-R2 8000 Series 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248017: return "SFN8522-R2 8000 Series 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248018: return "SFN8042-R2 8000 Series 10/40G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248019: return "SFN8542-R2 8000 Series 10/40G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_1924801A: return "SFN8722-R1 8000 Series OCP 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_1924801B: return "SFN8522-R3 8000 Series 10G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_1924801C: return "SFN8042-R3 8000 Series 10/40G Adapter";
        case PciSubDevice19240A03::SUBDEVICE_19248021: return "SFN8041-R1 8000 Series 10/40G Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240A03_H
