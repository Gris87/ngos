// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A1004: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10481500 = 0x10481500,
    SUBDEVICE_10CF1059 = 0x10CF1059
};



inline const char8* enumToString(PciSubDevice127A1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1004::NONE:               return "NONE";
        case PciSubDevice127A1004::SUBDEVICE_10481500: return "SUBDEVICE_10481500";
        case PciSubDevice127A1004::SUBDEVICE_10CF1059: return "SUBDEVICE_10CF1059";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A1004::SUBDEVICE_10481500: return "MicroLink 56k Modem";
        case PciSubDevice127A1004::SUBDEVICE_10CF1059: return "Fujitsu 229-DFRT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A1004_H
