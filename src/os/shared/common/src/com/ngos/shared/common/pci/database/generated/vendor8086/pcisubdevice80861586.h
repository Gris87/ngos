// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861586_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861586_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861586: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E0000 = 0x108E0000,
    SUBDEVICE_108E4857 = 0x108E4857
};



inline const char8* enumToString(PciSubDevice80861586 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861586::NONE:               return "NONE";
        case PciSubDevice80861586::SUBDEVICE_108E0000: return "SUBDEVICE_108E0000";
        case PciSubDevice80861586::SUBDEVICE_108E4857: return "SUBDEVICE_108E4857";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861586 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861586 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861586::SUBDEVICE_108E0000: return "Ethernet Controller X710 for 10GBASE-T";
        case PciSubDevice80861586::SUBDEVICE_108E4857: return "Ethernet Controller X710 for 10GBASE-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861586_H
