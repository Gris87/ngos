// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0324_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0324_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0324: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_10718160 = 0x10718160
};



inline const char8* enumToString(PciSubDevice10DE0324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0324::NONE:               return "NONE";
        case PciSubDevice10DE0324::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice10DE0324::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice10DE0324::SUBDEVICE_10718160: return "SUBDEVICE_10718160";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0324::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice10DE0324::SUBDEVICE_103C006A: return "Pavilion ZD7000 laptop";
        case PciSubDevice10DE0324::SUBDEVICE_10718160: return "MIM2000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0324_H
