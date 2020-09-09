// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11484000: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B03B = 0x0E11B03B,
    SUBDEVICE_0E11B03C = 0x0E11B03C,
    SUBDEVICE_0E11B03D = 0x0E11B03D,
    SUBDEVICE_0E11B03E = 0x0E11B03E,
    SUBDEVICE_0E11B03F = 0x0E11B03F,
    SUBDEVICE_11485521 = 0x11485521,
    SUBDEVICE_11485522 = 0x11485522,
    SUBDEVICE_11485541 = 0x11485541,
    SUBDEVICE_11485543 = 0x11485543,
    SUBDEVICE_11485544 = 0x11485544,
    SUBDEVICE_11485821 = 0x11485821,
    SUBDEVICE_11485822 = 0x11485822,
    SUBDEVICE_11485841 = 0x11485841,
    SUBDEVICE_11485843 = 0x11485843,
    SUBDEVICE_11485844 = 0x11485844
};



inline const char8* enumToString(PciSubDevice11484000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484000::NONE:               return "NONE";
        case PciSubDevice11484000::SUBDEVICE_0E11B03B: return "SUBDEVICE_0E11B03B";
        case PciSubDevice11484000::SUBDEVICE_0E11B03C: return "SUBDEVICE_0E11B03C";
        case PciSubDevice11484000::SUBDEVICE_0E11B03D: return "SUBDEVICE_0E11B03D";
        case PciSubDevice11484000::SUBDEVICE_0E11B03E: return "SUBDEVICE_0E11B03E";
        case PciSubDevice11484000::SUBDEVICE_0E11B03F: return "SUBDEVICE_0E11B03F";
        case PciSubDevice11484000::SUBDEVICE_11485521: return "SUBDEVICE_11485521";
        case PciSubDevice11484000::SUBDEVICE_11485522: return "SUBDEVICE_11485522";
        case PciSubDevice11484000::SUBDEVICE_11485541: return "SUBDEVICE_11485541";
        case PciSubDevice11484000::SUBDEVICE_11485543: return "SUBDEVICE_11485543";
        case PciSubDevice11484000::SUBDEVICE_11485544: return "SUBDEVICE_11485544";
        case PciSubDevice11484000::SUBDEVICE_11485821: return "SUBDEVICE_11485821";
        case PciSubDevice11484000::SUBDEVICE_11485822: return "SUBDEVICE_11485822";
        case PciSubDevice11484000::SUBDEVICE_11485841: return "SUBDEVICE_11485841";
        case PciSubDevice11484000::SUBDEVICE_11485843: return "SUBDEVICE_11485843";
        case PciSubDevice11484000::SUBDEVICE_11485844: return "SUBDEVICE_11485844";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11484000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11484000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484000::SUBDEVICE_0E11B03B: return "Netelligent 100 FDDI DAS Fibre SC";
        case PciSubDevice11484000::SUBDEVICE_0E11B03C: return "Netelligent 100 FDDI SAS Fibre SC";
        case PciSubDevice11484000::SUBDEVICE_0E11B03D: return "Netelligent 100 FDDI DAS UTP";
        case PciSubDevice11484000::SUBDEVICE_0E11B03E: return "Netelligent 100 FDDI SAS UTP";
        case PciSubDevice11484000::SUBDEVICE_0E11B03F: return "Netelligent 100 FDDI SAS Fibre MIC";
        case PciSubDevice11484000::SUBDEVICE_11485521: return "FDDI SK-5521 (SK-NET FDDI-UP)";
        case PciSubDevice11484000::SUBDEVICE_11485522: return "FDDI SK-5522 (SK-NET FDDI-UP DAS)";
        case PciSubDevice11484000::SUBDEVICE_11485541: return "FDDI SK-5541 (SK-NET FDDI-FP)";
        case PciSubDevice11484000::SUBDEVICE_11485543: return "FDDI SK-5543 (SK-NET FDDI-LP)";
        case PciSubDevice11484000::SUBDEVICE_11485544: return "FDDI SK-5544 (SK-NET FDDI-LP DAS)";
        case PciSubDevice11484000::SUBDEVICE_11485821: return "FDDI SK-5821 (SK-NET FDDI-UP64)";
        case PciSubDevice11484000::SUBDEVICE_11485822: return "FDDI SK-5822 (SK-NET FDDI-UP64 DAS)";
        case PciSubDevice11484000::SUBDEVICE_11485841: return "FDDI SK-5841 (SK-NET FDDI-FP64)";
        case PciSubDevice11484000::SUBDEVICE_11485843: return "FDDI SK-5843 (SK-NET FDDI-LP64)";
        case PciSubDevice11484000::SUBDEVICE_11485844: return "FDDI SK-5844 (SK-NET FDDI-LP64 DAS)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484000_H
