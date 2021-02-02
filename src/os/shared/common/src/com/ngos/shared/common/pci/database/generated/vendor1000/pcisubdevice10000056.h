// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000056_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000056_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000056: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101403BB = 0x101403BB,
    SUBDEVICE_808634DC = 0x808634DC
};



inline const char8* enumToString(PciSubDevice10000056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000056::NONE:               return "NONE";
        case PciSubDevice10000056::SUBDEVICE_101403BB: return "SUBDEVICE_101403BB";
        case PciSubDevice10000056::SUBDEVICE_808634DC: return "SUBDEVICE_808634DC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000056::SUBDEVICE_101403BB: return "ServeRAID BR10il SAS/SATA Controller v2";
        case PciSubDevice10000056::SUBDEVICE_808634DC: return "AXX4SASMOD RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000056_H
