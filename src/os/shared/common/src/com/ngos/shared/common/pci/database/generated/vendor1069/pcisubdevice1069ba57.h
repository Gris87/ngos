// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA57_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA57_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1069BA57: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10690072 = 0x10690072
};



inline const char8* enumToString(PciSubDevice1069BA57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069BA57::NONE:               return "NONE";
        case PciSubDevice1069BA57::SUBDEVICE_10690072: return "SUBDEVICE_10690072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1069BA57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1069BA57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069BA57::SUBDEVICE_10690072: return "eXtremeRAID 5000 support Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069BA57_H
