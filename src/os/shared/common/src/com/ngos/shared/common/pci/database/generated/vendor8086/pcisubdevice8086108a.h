// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086108A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086108A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086108A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086108A = 0x8086108A,
    SUBDEVICE_8086118A = 0x8086118A
};



inline const char8* enumToString(PciSubDevice8086108A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086108A::NONE:               return "NONE";
        case PciSubDevice8086108A::SUBDEVICE_8086108A: return "SUBDEVICE_8086108A";
        case PciSubDevice8086108A::SUBDEVICE_8086118A: return "SUBDEVICE_8086118A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086108A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086108A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086108A::SUBDEVICE_8086108A: return "PRO/1000 P Dual Port Server Adapter";
        case PciSubDevice8086108A::SUBDEVICE_8086118A: return "PRO/1000 P Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086108A_H
