// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11030004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11030004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11030004: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11030001 = 0x11030001,
    SUBDEVICE_11030004 = 0x11030004,
    SUBDEVICE_11030005 = 0x11030005,
    SUBDEVICE_11030006 = 0x11030006
};



inline const char8* enumToString(PciSubDevice11030004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11030004::NONE:               return "NONE";
        case PciSubDevice11030004::SUBDEVICE_11030001: return "SUBDEVICE_11030001";
        case PciSubDevice11030004::SUBDEVICE_11030004: return "SUBDEVICE_11030004";
        case PciSubDevice11030004::SUBDEVICE_11030005: return "SUBDEVICE_11030005";
        case PciSubDevice11030004::SUBDEVICE_11030006: return "SUBDEVICE_11030006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11030004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11030004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11030004::SUBDEVICE_11030001: return "HPT370A";
        case PciSubDevice11030004::SUBDEVICE_11030004: return "HPT366 UDMA66 (r1) / HPT368 UDMA66 (r2) / HPT370 UDMA100 (r3) / HPT370 UDMA100 RAID (r4)";
        case PciSubDevice11030004::SUBDEVICE_11030005: return "HPT370 UDMA100";
        case PciSubDevice11030004::SUBDEVICE_11030006: return "HPT302/302N";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCISUBDEVICE11030004_H
