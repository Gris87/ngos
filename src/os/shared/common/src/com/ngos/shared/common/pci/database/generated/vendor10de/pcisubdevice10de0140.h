// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0140_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0140_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0140: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14583125 = 0x14583125,
    SUBDEVICE_14583126 = 0x14583126,
    SUBDEVICE_14628939 = 0x14628939
};



inline const char8* enumToString(PciSubDevice10DE0140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0140::NONE:               return "NONE";
        case PciSubDevice10DE0140::SUBDEVICE_14583125: return "SUBDEVICE_14583125";
        case PciSubDevice10DE0140::SUBDEVICE_14583126: return "SUBDEVICE_14583126";
        case PciSubDevice10DE0140::SUBDEVICE_14628939: return "SUBDEVICE_14628939";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0140::SUBDEVICE_14583125: return "GV-NX66T128D";
        case PciSubDevice10DE0140::SUBDEVICE_14583126: return "GV-NX66T256DE";
        case PciSubDevice10DE0140::SUBDEVICE_14628939: return "MS-8983";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0140_H
