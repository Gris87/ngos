// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862925_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862925_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862925: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_173410E0 = 0x173410E0,
    SUBDEVICE_80862925 = 0x80862925
};



inline const char8* enumToString(PciSubDevice80862925 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862925::NONE:               return "NONE";
        case PciSubDevice80862925::SUBDEVICE_173410E0: return "SUBDEVICE_173410E0";
        case PciSubDevice80862925::SUBDEVICE_80862925: return "SUBDEVICE_80862925";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862925 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862925 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862925::SUBDEVICE_173410E0: return "System Board D2542";
        case PciSubDevice80862925::SUBDEVICE_80862925: return "System Board D2542";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862925_H
