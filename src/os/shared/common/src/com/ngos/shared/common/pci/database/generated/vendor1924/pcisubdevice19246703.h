// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19246703_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19246703_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19246703: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B80102 = 0x10B80102,
    SUBDEVICE_10B80103 = 0x10B80103,
    SUBDEVICE_10B80201 = 0x10B80201,
    SUBDEVICE_19240101 = 0x19240101,
    SUBDEVICE_19240102 = 0x19240102,
    SUBDEVICE_19240103 = 0x19240103,
    SUBDEVICE_19240201 = 0x19240201,
    SUBDEVICE_19240301 = 0x19240301,
    SUBDEVICE_19240302 = 0x19240302,
    SUBDEVICE_19240303 = 0x19240303,
    SUBDEVICE_19240304 = 0x19240304,
    SUBDEVICE_19240500 = 0x19240500
};



inline const char8* enumToString(PciSubDevice19246703 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19246703::NONE:               return "NONE";
        case PciSubDevice19246703::SUBDEVICE_10B80102: return "SUBDEVICE_10B80102";
        case PciSubDevice19246703::SUBDEVICE_10B80103: return "SUBDEVICE_10B80103";
        case PciSubDevice19246703::SUBDEVICE_10B80201: return "SUBDEVICE_10B80201";
        case PciSubDevice19246703::SUBDEVICE_19240101: return "SUBDEVICE_19240101";
        case PciSubDevice19246703::SUBDEVICE_19240102: return "SUBDEVICE_19240102";
        case PciSubDevice19246703::SUBDEVICE_19240103: return "SUBDEVICE_19240103";
        case PciSubDevice19246703::SUBDEVICE_19240201: return "SUBDEVICE_19240201";
        case PciSubDevice19246703::SUBDEVICE_19240301: return "SUBDEVICE_19240301";
        case PciSubDevice19246703::SUBDEVICE_19240302: return "SUBDEVICE_19240302";
        case PciSubDevice19246703::SUBDEVICE_19240303: return "SUBDEVICE_19240303";
        case PciSubDevice19246703::SUBDEVICE_19240304: return "SUBDEVICE_19240304";
        case PciSubDevice19246703::SUBDEVICE_19240500: return "SUBDEVICE_19240500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19246703 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19246703 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19246703::SUBDEVICE_10B80102: return "SMC10GPCIe-10BT (A2) [TigerCard]";
        case PciSubDevice19246703::SUBDEVICE_10B80103: return "SMC10GPCIe-10BT (A3) [TigerCard]";
        case PciSubDevice19246703::SUBDEVICE_10B80201: return "SMC10GPCIe-XFP (A1) [TigerCard]";
        case PciSubDevice19246703::SUBDEVICE_19240101: return "SFE4001-A1";
        case PciSubDevice19246703::SUBDEVICE_19240102: return "SFE4001-A2";
        case PciSubDevice19246703::SUBDEVICE_19240103: return "SFE4001-A3";
        case PciSubDevice19246703::SUBDEVICE_19240201: return "SFE4002-A1";
        case PciSubDevice19246703::SUBDEVICE_19240301: return "SFE4003-A1";
        case PciSubDevice19246703::SUBDEVICE_19240302: return "SFE4003-A2";
        case PciSubDevice19246703::SUBDEVICE_19240303: return "SFE4003-A3";
        case PciSubDevice19246703::SUBDEVICE_19240304: return "SFE4003-A4";
        case PciSubDevice19246703::SUBDEVICE_19240500: return "SFE4005-A0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19246703_H
