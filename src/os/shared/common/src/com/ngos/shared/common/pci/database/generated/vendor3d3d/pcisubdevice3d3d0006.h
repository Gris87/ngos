// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice3D3D0006: bad_uint32 // Ignore CppEnumVerifier
{
    SUBDEVICE_00000000 = 0x00000000,
    SUBDEVICE_10480A42 = 0x10480A42
};



inline const char8* enumToString(PciSubDevice3D3D0006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0006::SUBDEVICE_00000000: return "SUBDEVICE_00000000";
        case PciSubDevice3D3D0006::SUBDEVICE_10480A42: return "SUBDEVICE_10480A42";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice3D3D0006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice3D3D0006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0006::SUBDEVICE_00000000: return "GLoria XL";
        case PciSubDevice3D3D0006::SUBDEVICE_10480A42: return "GLoria XXL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0006_H
