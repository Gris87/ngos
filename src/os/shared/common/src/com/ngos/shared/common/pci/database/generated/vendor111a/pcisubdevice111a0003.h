// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice111A0003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_111A0000 = 0x111A0000
};



inline const char8* enumToString(PciSubDevice111A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0003::NONE:               return "NONE";
        case PciSubDevice111A0003::SUBDEVICE_111A0000: return "SUBDEVICE_111A0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice111A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice111A0003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0003::SUBDEVICE_111A0000: return "ENI-25p Miniport ATM Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0003_H
