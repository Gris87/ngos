// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94026_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94026_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC94026: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C521000 = 0x4C521000
};



inline const char8* enumToString(PciSubDevice1FC94026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94026::NONE:               return "NONE";
        case PciSubDevice1FC94026::SUBDEVICE_4C521000: return "SUBDEVICE_4C521000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC94026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC94026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94026::SUBDEVICE_4C521000: return "LREC6860AF 10 Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94026_H
