// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860158_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860158_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860158: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043844D = 0x1043844D,
    SUBDEVICE_80862010 = 0x80862010
};



inline const char8* enumToString(PciSubDevice80860158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860158::NONE:               return "NONE";
        case PciSubDevice80860158::SUBDEVICE_1043844D: return "SUBDEVICE_1043844D";
        case PciSubDevice80860158::SUBDEVICE_80862010: return "SUBDEVICE_80862010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860158 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860158::SUBDEVICE_1043844D: return "P8 series motherboard";
        case PciSubDevice80860158::SUBDEVICE_80862010: return "Server Board S1200BT Family";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860158_H
