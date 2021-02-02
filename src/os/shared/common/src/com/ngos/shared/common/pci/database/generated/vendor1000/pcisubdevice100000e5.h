// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000E5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028200B = 0x1028200B,
    SUBDEVICE_1028200C = 0x1028200C,
    SUBDEVICE_1028200D = 0x1028200D,
    SUBDEVICE_1028200E = 0x1028200E,
    SUBDEVICE_1D490205 = 0x1D490205,
    SUBDEVICE_1D490206 = 0x1D490206
};



inline const char8* enumToString(PciSubDevice100000E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000E5::NONE:               return "NONE";
        case PciSubDevice100000E5::SUBDEVICE_1028200B: return "SUBDEVICE_1028200B";
        case PciSubDevice100000E5::SUBDEVICE_1028200C: return "SUBDEVICE_1028200C";
        case PciSubDevice100000E5::SUBDEVICE_1028200D: return "SUBDEVICE_1028200D";
        case PciSubDevice100000E5::SUBDEVICE_1028200E: return "SUBDEVICE_1028200E";
        case PciSubDevice100000E5::SUBDEVICE_1D490205: return "SUBDEVICE_1D490205";
        case PciSubDevice100000E5::SUBDEVICE_1D490206: return "SUBDEVICE_1D490206";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000E5::SUBDEVICE_1028200B: return "HBA355i Adapter";
        case PciSubDevice100000E5::SUBDEVICE_1028200C: return "HBA355i Front";
        case PciSubDevice100000E5::SUBDEVICE_1028200D: return "HBA355e Adapter";
        case PciSubDevice100000E5::SUBDEVICE_1028200E: return "HBA350i MX";
        case PciSubDevice100000E5::SUBDEVICE_1D490205: return "ThinkSystem 440-16i SAS/SATA PCIe Gen4 12Gb Internal HBA";
        case PciSubDevice100000E5::SUBDEVICE_1D490206: return "ThinkSystem 440-16e SAS/SATA PCIe Gen4 12Gb HBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E5_H
