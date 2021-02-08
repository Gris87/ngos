// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE03F0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020E = 0x1028020E,
    SUBDEVICE_10438415 = 0x10438415,
    SUBDEVICE_18490888 = 0x18490888
};



inline const char8* enumToString(PciSubDevice10DE03F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE03F0::NONE:               return "NONE";
        case PciSubDevice10DE03F0::SUBDEVICE_1028020E: return "SUBDEVICE_1028020E";
        case PciSubDevice10DE03F0::SUBDEVICE_10438415: return "SUBDEVICE_10438415";
        case PciSubDevice10DE03F0::SUBDEVICE_18490888: return "SUBDEVICE_18490888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE03F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE03F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE03F0::SUBDEVICE_1028020E: return "Inspiron 531";
        case PciSubDevice10DE03F0::SUBDEVICE_10438415: return "M4N68T series motherboard";
        case PciSubDevice10DE03F0::SUBDEVICE_18490888: return "939NF6G-VSTA Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE03F0_H
