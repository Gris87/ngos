// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4165D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028865D = 0x1028865D,
    SUBDEVICE_14E4165D = 0x14E4165D
};



inline const char8* enumToString(PciSubDevice14E4165D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165D::NONE:               return "NONE";
        case PciSubDevice14E4165D::SUBDEVICE_1028865D: return "SUBDEVICE_1028865D";
        case PciSubDevice14E4165D::SUBDEVICE_14E4165D: return "SUBDEVICE_14E4165D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4165D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4165D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165D::SUBDEVICE_1028865D: return "Latitude D400";
        case PciSubDevice14E4165D::SUBDEVICE_14E4165D: return "Dell Latitude D600";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165D_H
