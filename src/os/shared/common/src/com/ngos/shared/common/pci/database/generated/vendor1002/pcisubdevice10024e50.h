// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E50_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E50_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024E50: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_14620311 = 0x14620311,
    SUBDEVICE_17341055 = 0x17341055
};



inline const char8* enumToString(PciSubDevice10024E50 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E50::NONE:               return "NONE";
        case PciSubDevice10024E50::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice10024E50::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice10024E50::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice10024E50::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice10024E50::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice10024E50::SUBDEVICE_14620311: return "SUBDEVICE_14620311";
        case PciSubDevice10024E50::SUBDEVICE_17341055: return "SUBDEVICE_17341055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024E50 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024E50 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E50::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice10024E50::SUBDEVICE_10250064: return "Extensa 3000 series laptop: ATI RV360/M11 [Mobility Radeon 9700]";
        case PciSubDevice10024E50::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice10024E50::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice10024E50::SUBDEVICE_144DC00C: return "P35 notebook";
        case PciSubDevice10024E50::SUBDEVICE_14620311: return "MSI M510A";
        case PciSubDevice10024E50::SUBDEVICE_17341055: return "Amilo M1420W";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E50_H
