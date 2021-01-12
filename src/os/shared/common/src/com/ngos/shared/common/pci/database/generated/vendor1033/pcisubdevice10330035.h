// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330035_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330035_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10330035: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10330035 = 0x10330035,
    SUBDEVICE_103C1293 = 0x103C1293,
    SUBDEVICE_103C1294 = 0x103C1294,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11860035 = 0x11860035,
    SUBDEVICE_12EE7000 = 0x12EE7000,
    SUBDEVICE_14C20105 = 0x14C20105,
    SUBDEVICE_17990001 = 0x17990001,
    SUBDEVICE_1931000A = 0x1931000A,
    SUBDEVICE_1931000B = 0x1931000B,
    SUBDEVICE_807D0035 = 0x807D0035,
    SUBDEVICE_80864D44 = 0x80864D44
};



inline const char8* enumToString(PciSubDevice10330035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330035::NONE:               return "NONE";
        case PciSubDevice10330035::SUBDEVICE_10330035: return "SUBDEVICE_10330035";
        case PciSubDevice10330035::SUBDEVICE_103C1293: return "SUBDEVICE_103C1293";
        case PciSubDevice10330035::SUBDEVICE_103C1294: return "SUBDEVICE_103C1294";
        case PciSubDevice10330035::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice10330035::SUBDEVICE_11860035: return "SUBDEVICE_11860035";
        case PciSubDevice10330035::SUBDEVICE_12EE7000: return "SUBDEVICE_12EE7000";
        case PciSubDevice10330035::SUBDEVICE_14C20105: return "SUBDEVICE_14C20105";
        case PciSubDevice10330035::SUBDEVICE_17990001: return "SUBDEVICE_17990001";
        case PciSubDevice10330035::SUBDEVICE_1931000A: return "SUBDEVICE_1931000A";
        case PciSubDevice10330035::SUBDEVICE_1931000B: return "SUBDEVICE_1931000B";
        case PciSubDevice10330035::SUBDEVICE_807D0035: return "SUBDEVICE_807D0035";
        case PciSubDevice10330035::SUBDEVICE_80864D44: return "SUBDEVICE_80864D44";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10330035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10330035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330035::SUBDEVICE_10330035: return "USB Controller";
        case PciSubDevice10330035::SUBDEVICE_103C1293: return "USB add-in card";
        case PciSubDevice10330035::SUBDEVICE_103C1294: return "USB 2.0 add-in card";
        case PciSubDevice10330035::SUBDEVICE_11790001: return "USB";
        case PciSubDevice10330035::SUBDEVICE_11860035: return "DUB-C2 USB 2.0 2-port 32-bit cardbus controller";
        case PciSubDevice10330035::SUBDEVICE_12EE7000: return "Root Hub";
        case PciSubDevice10330035::SUBDEVICE_14C20105: return "PTI-205N USB 2.0 Host Controller";
        case PciSubDevice10330035::SUBDEVICE_17990001: return "Root Hub";
        case PciSubDevice10330035::SUBDEVICE_1931000A: return "GlobeTrotter Fusion Quad Lite (PPP data)";
        case PciSubDevice10330035::SUBDEVICE_1931000B: return "GlobeTrotter Fusion Quad Lite (GSM data)";
        case PciSubDevice10330035::SUBDEVICE_807D0035: return "PCI-USB2 (OHCI subsystem)";
        case PciSubDevice10330035::SUBDEVICE_80864D44: return "D850EMV2 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330035_H
