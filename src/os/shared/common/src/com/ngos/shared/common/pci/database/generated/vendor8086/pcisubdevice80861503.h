// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861503_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861503_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861503: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043849C = 0x1043849C,
    SUBDEVICE_10CF161C = 0x10CF161C,
    SUBDEVICE_8086200D = 0x8086200D
};



inline const char8* enumToString(PciSubDevice80861503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861503::NONE:               return "NONE";
        case PciSubDevice80861503::SUBDEVICE_1043849C: return "SUBDEVICE_1043849C";
        case PciSubDevice80861503::SUBDEVICE_10CF161C: return "SUBDEVICE_10CF161C";
        case PciSubDevice80861503::SUBDEVICE_8086200D: return "SUBDEVICE_8086200D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861503::SUBDEVICE_1043849C: return "P8P67 Deluxe Motherboard";
        case PciSubDevice80861503::SUBDEVICE_10CF161C: return "LIFEBOOK E752";
        case PciSubDevice80861503::SUBDEVICE_8086200D: return "DH61CR motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861503_H
