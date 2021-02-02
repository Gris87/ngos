// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869C31_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869C31_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80869C31: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA2214 = 0x17AA2214,
    SUBDEVICE_80867270 = 0x80867270
};



inline const char8* enumToString(PciSubDevice80869C31 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869C31::NONE:               return "NONE";
        case PciSubDevice80869C31::SUBDEVICE_17AA2214: return "SUBDEVICE_17AA2214";
        case PciSubDevice80869C31::SUBDEVICE_80867270: return "SUBDEVICE_80867270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80869C31 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80869C31 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869C31::SUBDEVICE_17AA2214: return "ThinkPad X240";
        case PciSubDevice80869C31::SUBDEVICE_80867270: return "Apple MacBookAir6, 2 / MacBookPro11, 1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869C31_H
