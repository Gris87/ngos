// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086008B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865315 = 0x80865315,
    SUBDEVICE_80865317 = 0x80865317
};



inline const char8* enumToString(PciSubDevice8086008B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086008B::NONE:               return "NONE";
        case PciSubDevice8086008B::SUBDEVICE_80865315: return "SUBDEVICE_80865315";
        case PciSubDevice8086008B::SUBDEVICE_80865317: return "SUBDEVICE_80865317";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086008B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086008B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086008B::SUBDEVICE_80865315: return "Centrino Wireless-N 1030 BGN";
        case PciSubDevice8086008B::SUBDEVICE_80865317: return "Centrino Wireless-N 1030 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008B_H
