// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861039_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861039_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861039: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_114A0582 = 0x114A0582
};



inline const char8* enumToString(PciSubDevice80861039 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861039::NONE:               return "NONE";
        case PciSubDevice80861039::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice80861039::SUBDEVICE_114A0582: return "SUBDEVICE_114A0582";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861039 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861039 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861039::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice80861039::SUBDEVICE_114A0582: return "PC8 onboard ethernet ETH1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861039_H
