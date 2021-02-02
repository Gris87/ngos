// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014003E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014003E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1014003E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014003E = 0x1014003E,
    SUBDEVICE_101400CD = 0x101400CD,
    SUBDEVICE_101400CE = 0x101400CE,
    SUBDEVICE_101400CF = 0x101400CF,
    SUBDEVICE_101400E4 = 0x101400E4,
    SUBDEVICE_101400E5 = 0x101400E5,
    SUBDEVICE_1014016D = 0x1014016D
};



inline const char8* enumToString(PciSubDevice1014003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014003E::NONE:               return "NONE";
        case PciSubDevice1014003E::SUBDEVICE_1014003E: return "SUBDEVICE_1014003E";
        case PciSubDevice1014003E::SUBDEVICE_101400CD: return "SUBDEVICE_101400CD";
        case PciSubDevice1014003E::SUBDEVICE_101400CE: return "SUBDEVICE_101400CE";
        case PciSubDevice1014003E::SUBDEVICE_101400CF: return "SUBDEVICE_101400CF";
        case PciSubDevice1014003E::SUBDEVICE_101400E4: return "SUBDEVICE_101400E4";
        case PciSubDevice1014003E::SUBDEVICE_101400E5: return "SUBDEVICE_101400E5";
        case PciSubDevice1014003E::SUBDEVICE_1014016D: return "SUBDEVICE_1014016D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1014003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1014003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014003E::SUBDEVICE_1014003E: return "Token-Ring Adapter";
        case PciSubDevice1014003E::SUBDEVICE_101400CD: return "Token-Ring Adapter + Wake-On-LAN";
        case PciSubDevice1014003E::SUBDEVICE_101400CE: return "16/4 Token-Ring Adapter 2";
        case PciSubDevice1014003E::SUBDEVICE_101400CF: return "16/4 Token-Ring Adapter Special";
        case PciSubDevice1014003E::SUBDEVICE_101400E4: return "High-Speed 100/16/4 Token-Ring Adapter";
        case PciSubDevice1014003E::SUBDEVICE_101400E5: return "16/4 Token-Ring Adapter 2 + Wake-On-LAN";
        case PciSubDevice1014003E::SUBDEVICE_1014016D: return "iSeries 2744 Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014003E_H
