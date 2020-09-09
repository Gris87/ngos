// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867194_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867194_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867194: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10330000 = 0x10330000,
    SUBDEVICE_4C5310A0 = 0x4C5310A0
};



inline const char8* enumToString(PciSubDevice80867194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867194::NONE:               return "NONE";
        case PciSubDevice80867194::SUBDEVICE_10330000: return "SUBDEVICE_10330000";
        case PciSubDevice80867194::SUBDEVICE_4C5310A0: return "SUBDEVICE_4C5310A0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867194 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867194::SUBDEVICE_10330000: return "Versa Note Vxi";
        case PciSubDevice80867194::SUBDEVICE_4C5310A0: return "CA3/CR3 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867194_H
