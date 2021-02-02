// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC47_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC47_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC47: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280139 = 0x10280139,
    SUBDEVICE_1028013F = 0x1028013F,
    SUBDEVICE_1028014E = 0x1028014E
};



inline const char8* enumToString(PciSubDevice104CAC47 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC47::NONE:               return "NONE";
        case PciSubDevice104CAC47::SUBDEVICE_10280139: return "SUBDEVICE_10280139";
        case PciSubDevice104CAC47::SUBDEVICE_1028013F: return "SUBDEVICE_1028013F";
        case PciSubDevice104CAC47::SUBDEVICE_1028014E: return "SUBDEVICE_1028014E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC47 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC47 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC47::SUBDEVICE_10280139: return "Latitude D400";
        case PciSubDevice104CAC47::SUBDEVICE_1028013F: return "Precision M60";
        case PciSubDevice104CAC47::SUBDEVICE_1028014E: return "Latitude D800";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC47_H
