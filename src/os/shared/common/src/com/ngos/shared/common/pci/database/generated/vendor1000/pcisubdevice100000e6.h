// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000E6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10004050 = 0x10004050,
    SUBDEVICE_10004060 = 0x10004060,
    SUBDEVICE_10004070 = 0x10004070,
    SUBDEVICE_10004080 = 0x10004080,
    SUBDEVICE_1028200B = 0x1028200B,
    SUBDEVICE_1028200C = 0x1028200C,
    SUBDEVICE_1028200D = 0x1028200D,
    SUBDEVICE_1028200E = 0x1028200E,
    SUBDEVICE_10282170 = 0x10282170,
    SUBDEVICE_10282175 = 0x10282175,
    SUBDEVICE_10282197 = 0x10282197,
    SUBDEVICE_1D490205 = 0x1D490205,
    SUBDEVICE_1D490206 = 0x1D490206,
    SUBDEVICE_1D490207 = 0x1D490207,
    SUBDEVICE_1D490208 = 0x1D490208,
    SUBDEVICE_1D490209 = 0x1D490209,
    SUBDEVICE_80864050 = 0x80864050,
    SUBDEVICE_80864070 = 0x80864070
};



inline const char8* enumToString(PciSubDevice100000E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000E6::NONE:               return "NONE";
        case PciSubDevice100000E6::SUBDEVICE_10004050: return "SUBDEVICE_10004050";
        case PciSubDevice100000E6::SUBDEVICE_10004060: return "SUBDEVICE_10004060";
        case PciSubDevice100000E6::SUBDEVICE_10004070: return "SUBDEVICE_10004070";
        case PciSubDevice100000E6::SUBDEVICE_10004080: return "SUBDEVICE_10004080";
        case PciSubDevice100000E6::SUBDEVICE_1028200B: return "SUBDEVICE_1028200B";
        case PciSubDevice100000E6::SUBDEVICE_1028200C: return "SUBDEVICE_1028200C";
        case PciSubDevice100000E6::SUBDEVICE_1028200D: return "SUBDEVICE_1028200D";
        case PciSubDevice100000E6::SUBDEVICE_1028200E: return "SUBDEVICE_1028200E";
        case PciSubDevice100000E6::SUBDEVICE_10282170: return "SUBDEVICE_10282170";
        case PciSubDevice100000E6::SUBDEVICE_10282175: return "SUBDEVICE_10282175";
        case PciSubDevice100000E6::SUBDEVICE_10282197: return "SUBDEVICE_10282197";
        case PciSubDevice100000E6::SUBDEVICE_1D490205: return "SUBDEVICE_1D490205";
        case PciSubDevice100000E6::SUBDEVICE_1D490206: return "SUBDEVICE_1D490206";
        case PciSubDevice100000E6::SUBDEVICE_1D490207: return "SUBDEVICE_1D490207";
        case PciSubDevice100000E6::SUBDEVICE_1D490208: return "SUBDEVICE_1D490208";
        case PciSubDevice100000E6::SUBDEVICE_1D490209: return "SUBDEVICE_1D490209";
        case PciSubDevice100000E6::SUBDEVICE_80864050: return "SUBDEVICE_80864050";
        case PciSubDevice100000E6::SUBDEVICE_80864070: return "SUBDEVICE_80864070";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000E6::SUBDEVICE_10004050: return "9500-16i Tri-Mode HBA";
        case PciSubDevice100000E6::SUBDEVICE_10004060: return "9500-8i Tri-Mode HBA";
        case PciSubDevice100000E6::SUBDEVICE_10004070: return "9500-16e Tri-Mode HBA";
        case PciSubDevice100000E6::SUBDEVICE_10004080: return "9500-8e Tri-Mode HBA";
        case PciSubDevice100000E6::SUBDEVICE_1028200B: return "HBA355i Adapter";
        case PciSubDevice100000E6::SUBDEVICE_1028200C: return "HBA355i Front";
        case PciSubDevice100000E6::SUBDEVICE_1028200D: return "HBA355e Adapter";
        case PciSubDevice100000E6::SUBDEVICE_1028200E: return "HBA350i MX";
        case PciSubDevice100000E6::SUBDEVICE_10282170: return "HBA350i MM";
        case PciSubDevice100000E6::SUBDEVICE_10282175: return "HBA350i Adapter";
        case PciSubDevice100000E6::SUBDEVICE_10282197: return "HBA350i MM LP";
        case PciSubDevice100000E6::SUBDEVICE_1D490205: return "ThinkSystem 440-16i SAS/SATA PCIe Gen4 12Gb Internal HBA";
        case PciSubDevice100000E6::SUBDEVICE_1D490206: return "ThinkSystem 440-16e SAS/SATA PCIe Gen4 12Gb HBA";
        case PciSubDevice100000E6::SUBDEVICE_1D490207: return "ThinkSystem 440-8i SAS/SATA PCIe Gen4 12Gb HBA";
        case PciSubDevice100000E6::SUBDEVICE_1D490208: return "ThinkSystem 440-16i SAS/SATA PCIe Gen4 12Gb HBA";
        case PciSubDevice100000E6::SUBDEVICE_1D490209: return "ThinkSystem 440-8e SAS/SATA PCIe Gen4 12Gb HBA";
        case PciSubDevice100000E6::SUBDEVICE_80864050: return "Storage Controller RS3P4QF160J";
        case PciSubDevice100000E6::SUBDEVICE_80864070: return "Storage Controller RS3P4GF016J";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000E6_H
