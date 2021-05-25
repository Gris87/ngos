// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41751_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41751_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41751: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14E45045 = 0x14E45045,
    SUBDEVICE_14E45250 = 0x14E45250,
    SUBDEVICE_14E4D142 = 0x14E4D142
};



inline const char8* enumToString(PciSubDevice14E41751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41751::NONE:               return "NONE";
        case PciSubDevice14E41751::SUBDEVICE_14E45045: return "SUBDEVICE_14E45045";
        case PciSubDevice14E41751::SUBDEVICE_14E45250: return "SUBDEVICE_14E45250";
        case PciSubDevice14E41751::SUBDEVICE_14E4D142: return "SUBDEVICE_14E4D142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41751 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41751::SUBDEVICE_14E45045: return "NetXtreme-E BCM57504 4x25G OCP3.0";
        case PciSubDevice14E41751::SUBDEVICE_14E45250: return "NetXtreme-E BCM57504 4x25G KR Mezz";
        case PciSubDevice14E41751::SUBDEVICE_14E4D142: return "NetXtreme-E P425D BCM57504 4x25G SFP28 PCIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41751_H
