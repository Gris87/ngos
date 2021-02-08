// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086100E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140265 = 0x10140265,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_1014026A = 0x1014026A,
    SUBDEVICE_1028002E = 0x1028002E,
    SUBDEVICE_10280134 = 0x10280134,
    SUBDEVICE_10280151 = 0x10280151,
    SUBDEVICE_107B8920 = 0x107B8920,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_8086001E = 0x8086001E,
    SUBDEVICE_8086002E = 0x8086002E,
    SUBDEVICE_80861376 = 0x80861376,
    SUBDEVICE_80861476 = 0x80861476
};



inline const char8* enumToString(PciSubDevice8086100E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100E::NONE:               return "NONE";
        case PciSubDevice8086100E::SUBDEVICE_10140265: return "SUBDEVICE_10140265";
        case PciSubDevice8086100E::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice8086100E::SUBDEVICE_1014026A: return "SUBDEVICE_1014026A";
        case PciSubDevice8086100E::SUBDEVICE_1028002E: return "SUBDEVICE_1028002E";
        case PciSubDevice8086100E::SUBDEVICE_10280134: return "SUBDEVICE_10280134";
        case PciSubDevice8086100E::SUBDEVICE_10280151: return "SUBDEVICE_10280151";
        case PciSubDevice8086100E::SUBDEVICE_107B8920: return "SUBDEVICE_107B8920";
        case PciSubDevice8086100E::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice8086100E::SUBDEVICE_8086001E: return "SUBDEVICE_8086001E";
        case PciSubDevice8086100E::SUBDEVICE_8086002E: return "SUBDEVICE_8086002E";
        case PciSubDevice8086100E::SUBDEVICE_80861376: return "SUBDEVICE_80861376";
        case PciSubDevice8086100E::SUBDEVICE_80861476: return "SUBDEVICE_80861476";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086100E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086100E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100E::SUBDEVICE_10140265: return "PRO/1000 MT Network Connection";
        case PciSubDevice8086100E::SUBDEVICE_10140267: return "PRO/1000 MT Network Connection";
        case PciSubDevice8086100E::SUBDEVICE_1014026A: return "PRO/1000 MT Network Connection";
        case PciSubDevice8086100E::SUBDEVICE_1028002E: return "Optiplex GX260";
        case PciSubDevice8086100E::SUBDEVICE_10280134: return "PowerEdge 600SC";
        case PciSubDevice8086100E::SUBDEVICE_10280151: return "Optiplex GX270";
        case PciSubDevice8086100E::SUBDEVICE_107B8920: return "PRO/1000 MT Desktop Adapter";
        case PciSubDevice8086100E::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice8086100E::SUBDEVICE_8086001E: return "PRO/1000 MT Desktop Adapter";
        case PciSubDevice8086100E::SUBDEVICE_8086002E: return "PRO/1000 MT Desktop Adapter";
        case PciSubDevice8086100E::SUBDEVICE_80861376: return "PRO/1000 GT Desktop Adapter";
        case PciSubDevice8086100E::SUBDEVICE_80861476: return "PRO/1000 GT Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100E_H
