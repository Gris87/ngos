// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086282A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086282A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086282A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_E4BF50C1 = 0xE4BF50C1
};



inline const char8* enumToString(PciSubDevice8086282A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086282A::NONE:               return "NONE";
        case PciSubDevice8086282A::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice8086282A::SUBDEVICE_E4BF50C1: return "SUBDEVICE_E4BF50C1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086282A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086282A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086282A::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice8086282A::SUBDEVICE_E4BF50C1: return "PC1-GROOVE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086282A_H
