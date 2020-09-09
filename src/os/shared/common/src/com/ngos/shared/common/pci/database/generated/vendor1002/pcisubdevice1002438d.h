// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002438D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002438D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002438D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C280A = 0x103C280A,
    SUBDEVICE_1179FF50 = 0x1179FF50,
    SUBDEVICE_14627368 = 0x14627368,
    SUBDEVICE_17F25000 = 0x17F25000
};



inline const char8* enumToString(PciSubDevice1002438D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002438D::NONE:               return "NONE";
        case PciSubDevice1002438D::SUBDEVICE_103C280A: return "SUBDEVICE_103C280A";
        case PciSubDevice1002438D::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";
        case PciSubDevice1002438D::SUBDEVICE_14627368: return "SUBDEVICE_14627368";
        case PciSubDevice1002438D::SUBDEVICE_17F25000: return "SUBDEVICE_17F25000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002438D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002438D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002438D::SUBDEVICE_103C280A: return "DC5750 Microtower";
        case PciSubDevice1002438D::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";
        case PciSubDevice1002438D::SUBDEVICE_14627368: return "K9AG Neo2";
        case PciSubDevice1002438D::SUBDEVICE_17F25000: return "KI690-AM2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002438D_H
