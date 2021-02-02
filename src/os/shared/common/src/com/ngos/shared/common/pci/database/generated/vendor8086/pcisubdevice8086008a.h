// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086008A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865305 = 0x80865305,
    SUBDEVICE_80865307 = 0x80865307,
    SUBDEVICE_80865325 = 0x80865325,
    SUBDEVICE_80865327 = 0x80865327
};



inline const char8* enumToString(PciSubDevice8086008A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086008A::NONE:               return "NONE";
        case PciSubDevice8086008A::SUBDEVICE_80865305: return "SUBDEVICE_80865305";
        case PciSubDevice8086008A::SUBDEVICE_80865307: return "SUBDEVICE_80865307";
        case PciSubDevice8086008A::SUBDEVICE_80865325: return "SUBDEVICE_80865325";
        case PciSubDevice8086008A::SUBDEVICE_80865327: return "SUBDEVICE_80865327";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086008A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086008A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086008A::SUBDEVICE_80865305: return "Centrino Wireless-N 1030 BGN";
        case PciSubDevice8086008A::SUBDEVICE_80865307: return "Centrino Wireless-N 1030 BG";
        case PciSubDevice8086008A::SUBDEVICE_80865325: return "Centrino Wireless-N 1030 BGN";
        case PciSubDevice8086008A::SUBDEVICE_80865327: return "Centrino Wireless-N 1030 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086008A_H
