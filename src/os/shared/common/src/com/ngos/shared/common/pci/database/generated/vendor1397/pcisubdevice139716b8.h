// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139716B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139716B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice139716B8: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_139716B8 = 0x139716B8,
    SUBDEVICE_1397B521 = 0x1397B521,
    SUBDEVICE_1397B522 = 0x1397B522,
    SUBDEVICE_1397B552 = 0x1397B552,
    SUBDEVICE_1397B55B = 0x1397B55B,
    SUBDEVICE_1397B562 = 0x1397B562,
    SUBDEVICE_1397B56B = 0x1397B56B,
    SUBDEVICE_1397B622 = 0x1397B622,
    SUBDEVICE_1397E998 = 0x1397E998
};



inline const char8* enumToString(PciSubDevice139716B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139716B8::NONE:               return "NONE";
        case PciSubDevice139716B8::SUBDEVICE_139716B8: return "SUBDEVICE_139716B8";
        case PciSubDevice139716B8::SUBDEVICE_1397B521: return "SUBDEVICE_1397B521";
        case PciSubDevice139716B8::SUBDEVICE_1397B522: return "SUBDEVICE_1397B522";
        case PciSubDevice139716B8::SUBDEVICE_1397B552: return "SUBDEVICE_1397B552";
        case PciSubDevice139716B8::SUBDEVICE_1397B55B: return "SUBDEVICE_1397B55B";
        case PciSubDevice139716B8::SUBDEVICE_1397B562: return "SUBDEVICE_1397B562";
        case PciSubDevice139716B8::SUBDEVICE_1397B56B: return "SUBDEVICE_1397B56B";
        case PciSubDevice139716B8::SUBDEVICE_1397B622: return "SUBDEVICE_1397B622";
        case PciSubDevice139716B8::SUBDEVICE_1397E998: return "SUBDEVICE_1397E998";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice139716B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice139716B8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139716B8::SUBDEVICE_139716B8: return "HFC-8S [Cologne Chip HFC-8S Eval. Board]";
        case PciSubDevice139716B8::SUBDEVICE_1397B521: return "HFC-8S [IOB4ST Recording]";
        case PciSubDevice139716B8::SUBDEVICE_1397B522: return "HFC-8S [IOB8ST]";
        case PciSubDevice139716B8::SUBDEVICE_1397B552: return "HFC-8S [Junghanns.NET octoBRI]";
        case PciSubDevice139716B8::SUBDEVICE_1397B55B: return "HFC-8S [Junghanns.NET octoBRI]";
        case PciSubDevice139716B8::SUBDEVICE_1397B562: return "HFC-8S [BeroNet BN8S0]";
        case PciSubDevice139716B8::SUBDEVICE_1397B56B: return "HFC-8S [BeroNet BN8S0+]";
        case PciSubDevice139716B8::SUBDEVICE_1397B622: return "HFC-8S";
        case PciSubDevice139716B8::SUBDEVICE_1397E998: return "HFC-8S [OpenVox B800P]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139716B8_H
