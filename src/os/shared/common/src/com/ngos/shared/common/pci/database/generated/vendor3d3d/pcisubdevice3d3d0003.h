// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice3D3D0003: u32 // Ignore CppEnumVerifier
{
    SUBDEVICE_00000000 = 0x00000000
};



inline const char8* enumToString(PciSubDevice3D3D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0003::SUBDEVICE_00000000: return "SUBDEVICE_00000000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice3D3D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice3D3D0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0003::SUBDEVICE_00000000: return "GLoria XL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0003_H
