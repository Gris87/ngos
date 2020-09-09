// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D000A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D000A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice3D3D000A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_3D3D0121 = 0x3D3D0121
};



inline const char8* enumToString(PciSubDevice3D3D000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D000A::NONE:               return "NONE";
        case PciSubDevice3D3D000A::SUBDEVICE_3D3D0121: return "SUBDEVICE_3D3D0121";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice3D3D000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice3D3D000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D000A::SUBDEVICE_3D3D0121: return "Oxygen VX1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D000A_H
