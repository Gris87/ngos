// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086101E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086101E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086101E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140549 = 0x10140549,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_8086101E = 0x8086101E
};



inline const char8* enumToString(PciSubDevice8086101E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086101E::NONE:               return "NONE";
        case PciSubDevice8086101E::SUBDEVICE_10140549: return "SUBDEVICE_10140549";
        case PciSubDevice8086101E::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice8086101E::SUBDEVICE_8086101E: return "SUBDEVICE_8086101E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086101E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086101E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086101E::SUBDEVICE_10140549: return "Thinkpad";
        case PciSubDevice8086101E::SUBDEVICE_11790001: return "PRO/1000 MT Mobile Connection";
        case PciSubDevice8086101E::SUBDEVICE_8086101E: return "PRO/1000 MT Mobile Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086101E_H
