// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860897_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860897_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860897: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865015 = 0x80865015,
    SUBDEVICE_80865017 = 0x80865017
};



inline const char8* enumToString(PciSubDevice80860897 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860897::NONE:               return "NONE";
        case PciSubDevice80860897::SUBDEVICE_80865015: return "SUBDEVICE_80865015";
        case PciSubDevice80860897::SUBDEVICE_80865017: return "SUBDEVICE_80865017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860897 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860897 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860897::SUBDEVICE_80865015: return "Centrino Wireless-N 130 BGN";
        case PciSubDevice80860897::SUBDEVICE_80865017: return "Centrino Wireless-N 130 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860897_H
