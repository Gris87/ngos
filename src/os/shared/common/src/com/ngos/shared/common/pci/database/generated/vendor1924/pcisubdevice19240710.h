// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240710_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240710_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240710: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B80103 = 0x10B80103,
    SUBDEVICE_10B80201 = 0x10B80201,
    SUBDEVICE_19240102 = 0x19240102,
    SUBDEVICE_19240103 = 0x19240103,
    SUBDEVICE_19240201 = 0x19240201,
    SUBDEVICE_19240302 = 0x19240302,
    SUBDEVICE_19240303 = 0x19240303,
    SUBDEVICE_19240304 = 0x19240304,
    SUBDEVICE_19240500 = 0x19240500,
    SUBDEVICE_19245102 = 0x19245102,
    SUBDEVICE_19245103 = 0x19245103,
    SUBDEVICE_19245104 = 0x19245104,
    SUBDEVICE_19245105 = 0x19245105,
    SUBDEVICE_19245201 = 0x19245201,
    SUBDEVICE_19245202 = 0x19245202
};



inline const char8* enumToString(PciSubDevice19240710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240710::NONE:               return "NONE";
        case PciSubDevice19240710::SUBDEVICE_10B80103: return "SUBDEVICE_10B80103";
        case PciSubDevice19240710::SUBDEVICE_10B80201: return "SUBDEVICE_10B80201";
        case PciSubDevice19240710::SUBDEVICE_19240102: return "SUBDEVICE_19240102";
        case PciSubDevice19240710::SUBDEVICE_19240103: return "SUBDEVICE_19240103";
        case PciSubDevice19240710::SUBDEVICE_19240201: return "SUBDEVICE_19240201";
        case PciSubDevice19240710::SUBDEVICE_19240302: return "SUBDEVICE_19240302";
        case PciSubDevice19240710::SUBDEVICE_19240303: return "SUBDEVICE_19240303";
        case PciSubDevice19240710::SUBDEVICE_19240304: return "SUBDEVICE_19240304";
        case PciSubDevice19240710::SUBDEVICE_19240500: return "SUBDEVICE_19240500";
        case PciSubDevice19240710::SUBDEVICE_19245102: return "SUBDEVICE_19245102";
        case PciSubDevice19240710::SUBDEVICE_19245103: return "SUBDEVICE_19245103";
        case PciSubDevice19240710::SUBDEVICE_19245104: return "SUBDEVICE_19245104";
        case PciSubDevice19240710::SUBDEVICE_19245105: return "SUBDEVICE_19245105";
        case PciSubDevice19240710::SUBDEVICE_19245201: return "SUBDEVICE_19245201";
        case PciSubDevice19240710::SUBDEVICE_19245202: return "SUBDEVICE_19245202";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240710::SUBDEVICE_10B80103: return "SMC10GPCIe-10BT (A3) [TigerCard]";
        case PciSubDevice19240710::SUBDEVICE_10B80201: return "SMC10GPCIe-XFP (A1) [TigerCard]";
        case PciSubDevice19240710::SUBDEVICE_19240102: return "SFE4001-A2";
        case PciSubDevice19240710::SUBDEVICE_19240103: return "SFE4001-A3";
        case PciSubDevice19240710::SUBDEVICE_19240201: return "SFE4002-A1";
        case PciSubDevice19240710::SUBDEVICE_19240302: return "SFE4003-A2";
        case PciSubDevice19240710::SUBDEVICE_19240303: return "SFE4003-A3";
        case PciSubDevice19240710::SUBDEVICE_19240304: return "SFE4003-A4";
        case PciSubDevice19240710::SUBDEVICE_19240500: return "SFE4005-A0";
        case PciSubDevice19240710::SUBDEVICE_19245102: return "SFN4111T-A2";
        case PciSubDevice19240710::SUBDEVICE_19245103: return "SFN4111T-R3";
        case PciSubDevice19240710::SUBDEVICE_19245104: return "SFN4111T-R4";
        case PciSubDevice19240710::SUBDEVICE_19245105: return "SFN4111T-R5";
        case PciSubDevice19240710::SUBDEVICE_19245201: return "SFN4112F-R1";
        case PciSubDevice19240710::SUBDEVICE_19245202: return "SFN4112F-R2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240710_H
