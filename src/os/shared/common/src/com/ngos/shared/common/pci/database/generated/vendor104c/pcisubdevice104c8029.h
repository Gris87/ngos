// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8029: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280163 = 0x10280163,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_10718160 = 0x10718160
};



inline const char8* enumToString(PciSubDevice104C8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8029::NONE:               return "NONE";
        case PciSubDevice104C8029::SUBDEVICE_10280163: return "SUBDEVICE_10280163";
        case PciSubDevice104C8029::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice104C8029::SUBDEVICE_10718160: return "SUBDEVICE_10718160";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8029::SUBDEVICE_10280163: return "Latitude D505";
        case PciSubDevice104C8029::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice104C8029::SUBDEVICE_10718160: return "MIM2900";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8029_H
