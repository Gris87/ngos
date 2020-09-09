// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624CC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_17341055 = 0x17341055
};



inline const char8* enumToString(PciSubDevice808624CC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CC::NONE:               return "NONE";
        case PciSubDevice808624CC::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice808624CC::SUBDEVICE_17341055: return "SUBDEVICE_17341055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624CC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624CC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CC::SUBDEVICE_144DC00C: return "P30 notebook";
        case PciSubDevice808624CC::SUBDEVICE_17341055: return "Amilo M1420";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CC_H
