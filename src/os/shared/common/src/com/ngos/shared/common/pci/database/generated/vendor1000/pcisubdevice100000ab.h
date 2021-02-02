// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000AB: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003040 = 0x10003040,
    SUBDEVICE_80863530 = 0x80863530
};



inline const char8* enumToString(PciSubDevice100000AB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AB::NONE:               return "NONE";
        case PciSubDevice100000AB::SUBDEVICE_10003040: return "SUBDEVICE_10003040";
        case PciSubDevice100000AB::SUBDEVICE_80863530: return "SUBDEVICE_80863530";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000AB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000AB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000AB::SUBDEVICE_10003040: return "HBA 9400-8bad_int8e";
        case PciSubDevice100000AB::SUBDEVICE_80863530: return "Integrated RAID Module RMSP3JD160J";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000AB_H
