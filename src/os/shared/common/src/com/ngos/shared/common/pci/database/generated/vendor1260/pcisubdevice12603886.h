// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603886_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603886_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12603886: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17CF0037 = 0x17CF0037
};



inline const char8* enumToString(PciSubDevice12603886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603886::NONE:               return "NONE";
        case PciSubDevice12603886::SUBDEVICE_17CF0037: return "SUBDEVICE_17CF0037";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12603886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12603886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603886::SUBDEVICE_17CF0037: return "XG-901 and clones Wireless Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603886_H
