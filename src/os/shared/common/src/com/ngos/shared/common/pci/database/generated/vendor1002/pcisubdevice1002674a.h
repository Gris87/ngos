// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002674A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002674A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002674A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CC3D22 = 0x13CC3D22,
    SUBDEVICE_15C30106 = 0x15C30106
};



inline const char8* enumToString(PciSubDevice1002674A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002674A::NONE:               return "NONE";
        case PciSubDevice1002674A::SUBDEVICE_13CC3D22: return "SUBDEVICE_13CC3D22";
        case PciSubDevice1002674A::SUBDEVICE_15C30106: return "SUBDEVICE_15C30106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002674A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002674A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002674A::SUBDEVICE_13CC3D22: return "MXRT-2500";
        case PciSubDevice1002674A::SUBDEVICE_15C30106: return "MED-X3900";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002674A_H
