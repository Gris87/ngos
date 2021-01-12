// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53754_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53754_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E53754: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E56122 = 0x19E56122,
    SUBDEVICE_19E56123 = 0x19E56123,
    SUBDEVICE_19E56124 = 0x19E56124,
    SUBDEVICE_19E56141 = 0x19E56141,
    SUBDEVICE_19E56142 = 0x19E56142,
    SUBDEVICE_19E56212 = 0x19E56212,
    SUBDEVICE_19E56213 = 0x19E56213,
    SUBDEVICE_19E56214 = 0x19E56214,
    SUBDEVICE_19E56215 = 0x19E56215
};



inline const char8* enumToString(PciSubDevice19E53754 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E53754::NONE:               return "NONE";
        case PciSubDevice19E53754::SUBDEVICE_19E56122: return "SUBDEVICE_19E56122";
        case PciSubDevice19E53754::SUBDEVICE_19E56123: return "SUBDEVICE_19E56123";
        case PciSubDevice19E53754::SUBDEVICE_19E56124: return "SUBDEVICE_19E56124";
        case PciSubDevice19E53754::SUBDEVICE_19E56141: return "SUBDEVICE_19E56141";
        case PciSubDevice19E53754::SUBDEVICE_19E56142: return "SUBDEVICE_19E56142";
        case PciSubDevice19E53754::SUBDEVICE_19E56212: return "SUBDEVICE_19E56212";
        case PciSubDevice19E53754::SUBDEVICE_19E56213: return "SUBDEVICE_19E56213";
        case PciSubDevice19E53754::SUBDEVICE_19E56214: return "SUBDEVICE_19E56214";
        case PciSubDevice19E53754::SUBDEVICE_19E56215: return "SUBDEVICE_19E56215";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E53754 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E53754 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E53754::SUBDEVICE_19E56122: return "NVMe SSD ES3600P V6 1600GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56123: return "NVMe SSD ES3600P V6 3200GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56124: return "NVMe SSD ES3600P V6 6400GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56141: return "NVMe SSD ES3800P V6 800GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56142: return "NVMe SSD ES3800P V6 1600GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56212: return "NVMe SSD ES3500P V6 1920GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56213: return "NVMe SSD ES3500P V6 3840GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56214: return "NVMe SSD ES3500P V6 7680GB 2.5\" U.2";
        case PciSubDevice19E53754::SUBDEVICE_19E56215: return "NVMe SSD ES3500P V6 15360GB 2.5\" U.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53754_H
