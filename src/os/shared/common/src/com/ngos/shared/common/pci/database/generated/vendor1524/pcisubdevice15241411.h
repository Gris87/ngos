// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241411_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241411_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15241411: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C006A = 0x103C006A
};



inline const char8* enumToString(PciSubDevice15241411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15241411::NONE:               return "NONE";
        case PciSubDevice15241411::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15241411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15241411 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15241411::SUBDEVICE_103C006A: return "NX9500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1524_PCISUBDEVICE15241411_H
