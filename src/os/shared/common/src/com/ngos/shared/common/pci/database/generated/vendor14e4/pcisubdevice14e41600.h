// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41600: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801C1 = 0x102801C1,
    SUBDEVICE_102801C2 = 0x102801C2,
    SUBDEVICE_103C3015 = 0x103C3015,
    SUBDEVICE_107B5048 = 0x107B5048,
    SUBDEVICE_12592705 = 0x12592705
};



inline const char8* enumToString(PciSubDevice14E41600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41600::NONE:               return "NONE";
        case PciSubDevice14E41600::SUBDEVICE_102801C1: return "SUBDEVICE_102801C1";
        case PciSubDevice14E41600::SUBDEVICE_102801C2: return "SUBDEVICE_102801C2";
        case PciSubDevice14E41600::SUBDEVICE_103C3015: return "SUBDEVICE_103C3015";
        case PciSubDevice14E41600::SUBDEVICE_107B5048: return "SUBDEVICE_107B5048";
        case PciSubDevice14E41600::SUBDEVICE_12592705: return "SUBDEVICE_12592705";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41600::SUBDEVICE_102801C1: return "Precision 490";
        case PciSubDevice14E41600::SUBDEVICE_102801C2: return "Latitude D620";
        case PciSubDevice14E41600::SUBDEVICE_103C3015: return "PCIe LAN on Motherboard";
        case PciSubDevice14E41600::SUBDEVICE_107B5048: return "E4500 Onboard";
        case PciSubDevice14E41600::SUBDEVICE_12592705: return "AT-2711FX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41600_H
