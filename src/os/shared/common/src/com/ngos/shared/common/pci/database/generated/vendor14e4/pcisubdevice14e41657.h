// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41657_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41657_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41657: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140420 = 0x10140420,
    SUBDEVICE_103C169D = 0x103C169D,
    SUBDEVICE_103C22BE = 0x103C22BE,
    SUBDEVICE_103C3383 = 0x103C3383,
    SUBDEVICE_14E41904 = 0x14E41904
};



inline const char8* enumToString(PciSubDevice14E41657 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41657::NONE:               return "NONE";
        case PciSubDevice14E41657::SUBDEVICE_10140420: return "SUBDEVICE_10140420";
        case PciSubDevice14E41657::SUBDEVICE_103C169D: return "SUBDEVICE_103C169D";
        case PciSubDevice14E41657::SUBDEVICE_103C22BE: return "SUBDEVICE_103C22BE";
        case PciSubDevice14E41657::SUBDEVICE_103C3383: return "SUBDEVICE_103C3383";
        case PciSubDevice14E41657::SUBDEVICE_14E41904: return "SUBDEVICE_14E41904";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41657 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41657 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41657::SUBDEVICE_10140420: return "FC 5260/5899 4-port 1 GbE Adapter for Power";
        case PciSubDevice14E41657::SUBDEVICE_103C169D: return "Ethernet 1Gb 4-port 331FLR Adapter";
        case PciSubDevice14E41657::SUBDEVICE_103C22BE: return "Ethernet 1Gb 4-port 331i Adapter";
        case PciSubDevice14E41657::SUBDEVICE_103C3383: return "Ethernet 1Gb 4-port 331T Adapter";
        case PciSubDevice14E41657::SUBDEVICE_14E41904: return "4-port 1Gb Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41657_H
