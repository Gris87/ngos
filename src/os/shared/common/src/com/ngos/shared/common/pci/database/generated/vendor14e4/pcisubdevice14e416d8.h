// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416D8: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FEB = 0x10281FEB,
    SUBDEVICE_14E44163 = 0x14E44163,
    SUBDEVICE_14E44166 = 0x14E44166,
    SUBDEVICE_1590020C = 0x1590020C,
    SUBDEVICE_15900212 = 0x15900212
};



inline const char8* enumToString(PciSubDevice14E416D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D8::NONE:               return "NONE";
        case PciSubDevice14E416D8::SUBDEVICE_10281FEB: return "SUBDEVICE_10281FEB";
        case PciSubDevice14E416D8::SUBDEVICE_14E44163: return "SUBDEVICE_14E44163";
        case PciSubDevice14E416D8::SUBDEVICE_14E44166: return "SUBDEVICE_14E44166";
        case PciSubDevice14E416D8::SUBDEVICE_1590020C: return "SUBDEVICE_1590020C";
        case PciSubDevice14E416D8::SUBDEVICE_15900212: return "SUBDEVICE_15900212";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416D8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D8::SUBDEVICE_10281FEB: return "NetXtreme-E 10Gb SFP+ Adapter";
        case PciSubDevice14E416D8::SUBDEVICE_14E44163: return "NetXtreme-E Dual-port 10GBASE-T Ethernet OCP 2.0 Adapter (BCM957416M4163C)";
        case PciSubDevice14E416D8::SUBDEVICE_14E44166: return "NetXtreme-E Dual-port 10GBASE-T Ethernet OCP 3.0 Adapter (BCM957416N4160C)";
        case PciSubDevice14E416D8::SUBDEVICE_1590020C: return "Ethernet 10Gb 2-port 535T Adapter";
        case PciSubDevice14E416D8::SUBDEVICE_15900212: return "Ethernet 10Gb 2-port 535FLR-T Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D8_H
