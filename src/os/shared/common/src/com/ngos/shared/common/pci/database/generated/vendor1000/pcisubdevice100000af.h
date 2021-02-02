// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000AF: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003010 = 0x10003010,
    SUBDEVICE_10003030 = 0x10003030,
    SUBDEVICE_1D490200 = 0x1D490200,
    SUBDEVICE_1D490202 = 0x1D490202,
    SUBDEVICE_1D490204 = 0x1D490204
};



inline const char8* enumToString(PciSubDevice100000AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AF::NONE:               return "NONE";
        case PciSubDevice100000AF::SUBDEVICE_10003010: return "SUBDEVICE_10003010";
        case PciSubDevice100000AF::SUBDEVICE_10003030: return "SUBDEVICE_10003030";
        case PciSubDevice100000AF::SUBDEVICE_1D490200: return "SUBDEVICE_1D490200";
        case PciSubDevice100000AF::SUBDEVICE_1D490202: return "SUBDEVICE_1D490202";
        case PciSubDevice100000AF::SUBDEVICE_1D490204: return "SUBDEVICE_1D490204";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AF::SUBDEVICE_10003010: return "HBA 9400-8i";
        case PciSubDevice100000AF::SUBDEVICE_10003030: return "HBA 9400-8e";
        case PciSubDevice100000AF::SUBDEVICE_1D490200: return "ThinkSystem 430-8i SAS/SATA 12Gb HBA";
        case PciSubDevice100000AF::SUBDEVICE_1D490202: return "ThinkSystem 430-8e SAS/SATA 12Gb HBA";
        case PciSubDevice100000AF::SUBDEVICE_1D490204: return "ThinkSystem 430-8i SAS/SATA 12Gb Dense HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AF_H
