// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139708B4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139708B4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice139708B4: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_139708B4 = 0x139708B4,
    SUBDEVICE_1397B51A = 0x1397B51A,
    SUBDEVICE_1397B520 = 0x1397B520,
    SUBDEVICE_1397B540 = 0x1397B540,
    SUBDEVICE_1397B550 = 0x1397B550,
    SUBDEVICE_1397B556 = 0x1397B556,
    SUBDEVICE_1397B559 = 0x1397B559,
    SUBDEVICE_1397B560 = 0x1397B560,
    SUBDEVICE_1397B566 = 0x1397B566,
    SUBDEVICE_1397B567 = 0x1397B567,
    SUBDEVICE_1397B568 = 0x1397B568,
    SUBDEVICE_1397B569 = 0x1397B569,
    SUBDEVICE_1397B620 = 0x1397B620,
    SUBDEVICE_1397B752 = 0x1397B752,
    SUBDEVICE_1397B761 = 0x1397B761,
    SUBDEVICE_1397B762 = 0x1397B762,
    SUBDEVICE_1397E884 = 0x1397E884,
    SUBDEVICE_1397E888 = 0x1397E888
};



inline const char8* enumToString(PciSubDevice139708B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139708B4::NONE:               return "NONE";
        case PciSubDevice139708B4::SUBDEVICE_139708B4: return "SUBDEVICE_139708B4";
        case PciSubDevice139708B4::SUBDEVICE_1397B51A: return "SUBDEVICE_1397B51A";
        case PciSubDevice139708B4::SUBDEVICE_1397B520: return "SUBDEVICE_1397B520";
        case PciSubDevice139708B4::SUBDEVICE_1397B540: return "SUBDEVICE_1397B540";
        case PciSubDevice139708B4::SUBDEVICE_1397B550: return "SUBDEVICE_1397B550";
        case PciSubDevice139708B4::SUBDEVICE_1397B556: return "SUBDEVICE_1397B556";
        case PciSubDevice139708B4::SUBDEVICE_1397B559: return "SUBDEVICE_1397B559";
        case PciSubDevice139708B4::SUBDEVICE_1397B560: return "SUBDEVICE_1397B560";
        case PciSubDevice139708B4::SUBDEVICE_1397B566: return "SUBDEVICE_1397B566";
        case PciSubDevice139708B4::SUBDEVICE_1397B567: return "SUBDEVICE_1397B567";
        case PciSubDevice139708B4::SUBDEVICE_1397B568: return "SUBDEVICE_1397B568";
        case PciSubDevice139708B4::SUBDEVICE_1397B569: return "SUBDEVICE_1397B569";
        case PciSubDevice139708B4::SUBDEVICE_1397B620: return "SUBDEVICE_1397B620";
        case PciSubDevice139708B4::SUBDEVICE_1397B752: return "SUBDEVICE_1397B752";
        case PciSubDevice139708B4::SUBDEVICE_1397B761: return "SUBDEVICE_1397B761";
        case PciSubDevice139708B4::SUBDEVICE_1397B762: return "SUBDEVICE_1397B762";
        case PciSubDevice139708B4::SUBDEVICE_1397E884: return "SUBDEVICE_1397E884";
        case PciSubDevice139708B4::SUBDEVICE_1397E888: return "SUBDEVICE_1397E888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice139708B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice139708B4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice139708B4::SUBDEVICE_139708B4: return "HFC-4S [Cologne Chip HFC-4S Eval. Board]";
        case PciSubDevice139708B4::SUBDEVICE_1397B51A: return "HFC-4S [Allo.com BRI card]";
        case PciSubDevice139708B4::SUBDEVICE_1397B520: return "HFC-4S [IOB4ST]";
        case PciSubDevice139708B4::SUBDEVICE_1397B540: return "HFC-4S [Swyx SX2 QuadBri]";
        case PciSubDevice139708B4::SUBDEVICE_1397B550: return "HFC-4S [Junghanns.NET quadBRI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B556: return "HFC-4S [Junghanns.NET duoBRI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B559: return "HFC-4S [Junghanns.NET duoBRI miniPCI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B560: return "HFC-4S [BeroNet BN4S0]";
        case PciSubDevice139708B4::SUBDEVICE_1397B566: return "HFC-4S [BeroNet BN2S0]";
        case PciSubDevice139708B4::SUBDEVICE_1397B567: return "HFC-4S [BeroNet BN1S0 miniPCI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B568: return "HFC-4S [BeroNet BN4S0 miniPCI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B569: return "HFC-4S [BeroNet BN2S0 miniPCI]";
        case PciSubDevice139708B4::SUBDEVICE_1397B620: return "HFC-4S";
        case PciSubDevice139708B4::SUBDEVICE_1397B752: return "HFC-4S [Junghanns.NET quadBRI PCIe]";
        case PciSubDevice139708B4::SUBDEVICE_1397B761: return "HFC-4S [BeroNet BN2S0 PCIe]";
        case PciSubDevice139708B4::SUBDEVICE_1397B762: return "HFC-4S [BeroNet BN4S0 PCIe]";
        case PciSubDevice139708B4::SUBDEVICE_1397E884: return "HFC-4S [OpenVox B200P]";
        case PciSubDevice139708B4::SUBDEVICE_1397E888: return "HFC-4S [OpenVox B200P / B400P]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE139708B4_H
