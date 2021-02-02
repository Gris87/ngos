// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E1E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E1E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861E1E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF16E9 = 0x10CF16E9,
    SUBDEVICE_18491E1E = 0x18491E1E
};



inline const char8* enumToString(PciSubDevice80861E1E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E1E::NONE:               return "NONE";
        case PciSubDevice80861E1E::SUBDEVICE_10CF16E9: return "SUBDEVICE_10CF16E9";
        case PciSubDevice80861E1E::SUBDEVICE_18491E1E: return "SUBDEVICE_18491E1E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861E1E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861E1E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E1E::SUBDEVICE_10CF16E9: return "LIFEBOOK E752";
        case PciSubDevice80861E1E::SUBDEVICE_18491E1E: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E1E_H
