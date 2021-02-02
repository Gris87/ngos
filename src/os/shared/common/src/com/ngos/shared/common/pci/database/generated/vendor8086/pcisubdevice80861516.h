// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861516_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861516_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861516: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_808612B1 = 0x808612B1,
    SUBDEVICE_808612B2 = 0x808612B2
};



inline const char8* enumToString(PciSubDevice80861516 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861516::NONE:               return "NONE";
        case PciSubDevice80861516::SUBDEVICE_808612B1: return "SUBDEVICE_808612B1";
        case PciSubDevice80861516::SUBDEVICE_808612B2: return "SUBDEVICE_808612B2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861516 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861516 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861516::SUBDEVICE_808612B1: return "Ethernet Server Adapter I340-T2";
        case PciSubDevice80861516::SUBDEVICE_808612B2: return "Ethernet Server Adapter I340-T2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861516_H
