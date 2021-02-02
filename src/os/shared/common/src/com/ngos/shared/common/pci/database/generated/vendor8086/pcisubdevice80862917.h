// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862917_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862917_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862917: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA20F5 = 0x17AA20F5,
    SUBDEVICE_E4BFCC4D = 0xE4BFCC4D
};



inline const char8* enumToString(PciSubDevice80862917 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862917::NONE:               return "NONE";
        case PciSubDevice80862917::SUBDEVICE_17AA20F5: return "SUBDEVICE_17AA20F5";
        case PciSubDevice80862917::SUBDEVICE_E4BFCC4D: return "SUBDEVICE_E4BFCC4D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862917 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862917 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862917::SUBDEVICE_17AA20F5: return "ThinkPad T400";
        case PciSubDevice80862917::SUBDEVICE_E4BFCC4D: return "CCM-BOOGIE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862917_H
