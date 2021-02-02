// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18801_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18801_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18801: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00702801 = 0x00702801,
    SUBDEVICE_185BE000 = 0x185BE000,
    SUBDEVICE_56542388 = 0x56542388,
    SUBDEVICE_70635500 = 0x70635500
};



inline const char8* enumToString(PciSubDevice14F18801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18801::NONE:               return "NONE";
        case PciSubDevice14F18801::SUBDEVICE_00702801: return "SUBDEVICE_00702801";
        case PciSubDevice14F18801::SUBDEVICE_185BE000: return "SUBDEVICE_185BE000";
        case PciSubDevice14F18801::SUBDEVICE_56542388: return "SUBDEVICE_56542388";
        case PciSubDevice14F18801::SUBDEVICE_70635500: return "SUBDEVICE_70635500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18801::SUBDEVICE_00702801: return "Hauppauge WinTV 28xxx (Roslyn) models";
        case PciSubDevice14F18801::SUBDEVICE_185BE000: return "VideoMate X500";
        case PciSubDevice14F18801::SUBDEVICE_56542388: return "GoTView PCI Hybrid Audio AVStream Device";
        case PciSubDevice14F18801::SUBDEVICE_70635500: return "pcHDTV HD-5500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18801_H
