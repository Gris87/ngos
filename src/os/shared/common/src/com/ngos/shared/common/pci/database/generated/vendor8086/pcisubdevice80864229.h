// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864229_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864229_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864229: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861100 = 0x80861100,
    SUBDEVICE_80861101 = 0x80861101
};



inline const char8* enumToString(PciSubDevice80864229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864229::NONE:               return "NONE";
        case PciSubDevice80864229::SUBDEVICE_80861100: return "SUBDEVICE_80861100";
        case PciSubDevice80864229::SUBDEVICE_80861101: return "SUBDEVICE_80861101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864229::SUBDEVICE_80861100: return "Vaio VGN-SZ79SN_C";
        case PciSubDevice80864229::SUBDEVICE_80861101: return "PRO/Wireless 4965 AG or AGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864229_H
