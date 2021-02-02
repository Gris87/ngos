// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50123_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50123_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50123: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E53022 = 0x19E53022,
    SUBDEVICE_19E53023 = 0x19E53023,
    SUBDEVICE_19E53024 = 0x19E53024,
    SUBDEVICE_19E53025 = 0x19E53025,
    SUBDEVICE_19E53026 = 0x19E53026,
    SUBDEVICE_19E53033 = 0x19E53033,
    SUBDEVICE_19E53034 = 0x19E53034,
    SUBDEVICE_19E53036 = 0x19E53036
};



inline const char8* enumToString(PciSubDevice19E50123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50123::NONE:               return "NONE";
        case PciSubDevice19E50123::SUBDEVICE_19E53022: return "SUBDEVICE_19E53022";
        case PciSubDevice19E50123::SUBDEVICE_19E53023: return "SUBDEVICE_19E53023";
        case PciSubDevice19E50123::SUBDEVICE_19E53024: return "SUBDEVICE_19E53024";
        case PciSubDevice19E50123::SUBDEVICE_19E53025: return "SUBDEVICE_19E53025";
        case PciSubDevice19E50123::SUBDEVICE_19E53026: return "SUBDEVICE_19E53026";
        case PciSubDevice19E50123::SUBDEVICE_19E53033: return "SUBDEVICE_19E53033";
        case PciSubDevice19E50123::SUBDEVICE_19E53034: return "SUBDEVICE_19E53034";
        case PciSubDevice19E50123::SUBDEVICE_19E53036: return "SUBDEVICE_19E53036";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50123 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50123::SUBDEVICE_19E53022: return "NVMe SSD ES3600P V3 800GB 2.5\" U.2";
        case PciSubDevice19E50123::SUBDEVICE_19E53023: return "NVMe SSD ES3600P V3 1200GB 2.5\" U.2";
        case PciSubDevice19E50123::SUBDEVICE_19E53024: return "NVMe SSD ES3600P V3 1600GB 2.5\" U.2";
        case PciSubDevice19E50123::SUBDEVICE_19E53025: return "NVMe SSD ES3600P V3 2000GB 2.5\" U.2";
        case PciSubDevice19E50123::SUBDEVICE_19E53026: return "NVMe SSD ES3600P V3 3200GB 2.5\" U.2";
        case PciSubDevice19E50123::SUBDEVICE_19E53033: return "NVMe SSD ES3600C V3 1200GB HHHL AIC";
        case PciSubDevice19E50123::SUBDEVICE_19E53034: return "NVMe SSD ES3600C V3 1600GB HHHL AIC";
        case PciSubDevice19E50123::SUBDEVICE_19E53036: return "NVMe SSD ES3600C V3 3200GB HHHL AIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50123_H
