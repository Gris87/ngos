// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862826_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862826_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862826: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D490100 = 0x1D490100,
    SUBDEVICE_1D490101 = 0x1D490101,
    SUBDEVICE_1D490102 = 0x1D490102,
    SUBDEVICE_1D490103 = 0x1D490103,
    SUBDEVICE_1D490104 = 0x1D490104,
    SUBDEVICE_1D490105 = 0x1D490105
};



inline const char8* enumToString(PciSubDevice80862826 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862826::NONE:               return "NONE";
        case PciSubDevice80862826::SUBDEVICE_1D490100: return "SUBDEVICE_1D490100";
        case PciSubDevice80862826::SUBDEVICE_1D490101: return "SUBDEVICE_1D490101";
        case PciSubDevice80862826::SUBDEVICE_1D490102: return "SUBDEVICE_1D490102";
        case PciSubDevice80862826::SUBDEVICE_1D490103: return "SUBDEVICE_1D490103";
        case PciSubDevice80862826::SUBDEVICE_1D490104: return "SUBDEVICE_1D490104";
        case PciSubDevice80862826::SUBDEVICE_1D490105: return "SUBDEVICE_1D490105";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862826 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862826 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862826::SUBDEVICE_1D490100: return "Intel RSTe SATA Software RAID";
        case PciSubDevice80862826::SUBDEVICE_1D490101: return "Intel RSTe SATA Software RAID";
        case PciSubDevice80862826::SUBDEVICE_1D490102: return "Intel RSTe SATA Software RAID";
        case PciSubDevice80862826::SUBDEVICE_1D490103: return "Intel RSTe SATA Software RAID";
        case PciSubDevice80862826::SUBDEVICE_1D490104: return "Intel RSTe SATA Software RAID";
        case PciSubDevice80862826::SUBDEVICE_1D490105: return "Intel RSTe SATA Software RAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862826_H
