// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861587_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861587_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861587: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C0000 = 0x103C0000,
    SUBDEVICE_103C22FE = 0x103C22FE
};



inline const char8* enumToString(PciSubDevice80861587 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861587::NONE:               return "NONE";
        case PciSubDevice80861587::SUBDEVICE_103C0000: return "SUBDEVICE_103C0000";
        case PciSubDevice80861587::SUBDEVICE_103C22FE: return "SUBDEVICE_103C22FE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861587 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861587 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861587::SUBDEVICE_103C0000: return "Ethernet 10/20Gb 2-port 660FLB Adapter";
        case PciSubDevice80861587::SUBDEVICE_103C22FE: return "Ethernet 10/20Gb 2-port 660FLB Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861587_H
