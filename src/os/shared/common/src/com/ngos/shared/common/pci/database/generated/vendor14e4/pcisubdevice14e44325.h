// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44325_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44325_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44325: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14140003 = 0x14140003,
    SUBDEVICE_14140004 = 0x14140004
};



inline const char8* enumToString(PciSubDevice14E44325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44325::NONE:               return "NONE";
        case PciSubDevice14E44325::SUBDEVICE_14140003: return "SUBDEVICE_14140003";
        case PciSubDevice14E44325::SUBDEVICE_14140004: return "SUBDEVICE_14140004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44325::SUBDEVICE_14140003: return "Wireless Notebook Adapter MN-720";
        case PciSubDevice14E44325::SUBDEVICE_14140004: return "Wireless PCI Adapter MN-730";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44325_H
