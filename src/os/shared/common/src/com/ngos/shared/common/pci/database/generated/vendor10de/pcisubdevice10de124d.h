// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE124D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE124D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE124D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280491 = 0x10280491,
    SUBDEVICE_10280570 = 0x10280570,
    SUBDEVICE_10280571 = 0x10280571,
    SUBDEVICE_1462108D = 0x1462108D,
    SUBDEVICE_146210CC = 0x146210CC
};



inline const char8* enumToString(PciSubDevice10DE124D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE124D::NONE:               return "NONE";
        case PciSubDevice10DE124D::SUBDEVICE_10280491: return "SUBDEVICE_10280491";
        case PciSubDevice10DE124D::SUBDEVICE_10280570: return "SUBDEVICE_10280570";
        case PciSubDevice10DE124D::SUBDEVICE_10280571: return "SUBDEVICE_10280571";
        case PciSubDevice10DE124D::SUBDEVICE_1462108D: return "SUBDEVICE_1462108D";
        case PciSubDevice10DE124D::SUBDEVICE_146210CC: return "SUBDEVICE_146210CC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE124D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE124D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE124D::SUBDEVICE_10280491: return "GeForce GT 555M";
        case PciSubDevice10DE124D::SUBDEVICE_10280570: return "GeForce GT 555M";
        case PciSubDevice10DE124D::SUBDEVICE_10280571: return "GeForce GT 555M";
        case PciSubDevice10DE124D::SUBDEVICE_1462108D: return "GeForce GT 555M";
        case PciSubDevice10DE124D::SUBDEVICE_146210CC: return "GeForce GT 635M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE124D_H
