// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002719B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002719B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002719B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CC3D12 = 0x13CC3D12,
    SUBDEVICE_13CC3D14 = 0x13CC3D14
};



inline const char8* enumToString(PciSubDevice1002719B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002719B::NONE:               return "NONE";
        case PciSubDevice1002719B::SUBDEVICE_13CC3D12: return "SUBDEVICE_13CC3D12";
        case PciSubDevice1002719B::SUBDEVICE_13CC3D14: return "SUBDEVICE_13CC3D14";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002719B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002719B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002719B::SUBDEVICE_13CC3D12: return "MXRT-1150";
        case PciSubDevice1002719B::SUBDEVICE_13CC3D14: return "MXRT-2150";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002719B_H
