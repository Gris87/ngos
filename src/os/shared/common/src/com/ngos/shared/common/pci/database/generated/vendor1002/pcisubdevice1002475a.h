// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002475A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002475A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002475A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020084 = 0x10020084,
    SUBDEVICE_10020087 = 0x10020087,
    SUBDEVICE_1002475A = 0x1002475A
};



inline const char8* enumToString(PciSubDevice1002475A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002475A::NONE:               return "NONE";
        case PciSubDevice1002475A::SUBDEVICE_10020084: return "SUBDEVICE_10020084";
        case PciSubDevice1002475A::SUBDEVICE_10020087: return "SUBDEVICE_10020087";
        case PciSubDevice1002475A::SUBDEVICE_1002475A: return "SUBDEVICE_1002475A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002475A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002475A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002475A::SUBDEVICE_10020084: return "Rage 3D Pro AGP 2x XPERT 98";
        case PciSubDevice1002475A::SUBDEVICE_10020087: return "Rage 3D IIC";
        case PciSubDevice1002475A::SUBDEVICE_1002475A: return "Rage IIC AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002475A_H
