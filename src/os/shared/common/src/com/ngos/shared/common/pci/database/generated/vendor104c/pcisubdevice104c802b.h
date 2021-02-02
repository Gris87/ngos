// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C802B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280139 = 0x10280139,
    SUBDEVICE_1028014E = 0x1028014E
};



inline const char8* enumToString(PciSubDevice104C802B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C802B::NONE:               return "NONE";
        case PciSubDevice104C802B::SUBDEVICE_10280139: return "SUBDEVICE_10280139";
        case PciSubDevice104C802B::SUBDEVICE_1028014E: return "SUBDEVICE_1028014E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C802B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C802B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C802B::SUBDEVICE_10280139: return "Latitude D400";
        case PciSubDevice104C802B::SUBDEVICE_1028014E: return "PCI7410, 7510, 7610 OHCI-Lynx Controller (Latitude D800)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802B_H
