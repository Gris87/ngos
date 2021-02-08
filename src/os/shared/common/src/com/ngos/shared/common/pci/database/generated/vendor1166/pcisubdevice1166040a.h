// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE1166040A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE1166040A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1166040A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280223 = 0x10280223
};



inline const char8* enumToString(PciSubDevice1166040A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1166040A::NONE:               return "NONE";
        case PciSubDevice1166040A::SUBDEVICE_10280223: return "SUBDEVICE_10280223";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1166040A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1166040A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1166040A::SUBDEVICE_10280223: return "PowerEdge R905 HT1100 ISA-LPC Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE1166040A_H
