// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9712_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9712_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice177D9712: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_177D0003 = 0x177D0003,
    SUBDEVICE_177D0004 = 0x177D0004,
    SUBDEVICE_177D0005 = 0x177D0005,
    SUBDEVICE_177D0006 = 0x177D0006,
    SUBDEVICE_177D0007 = 0x177D0007
};



inline const char8* enumToString(PciSubDevice177D9712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177D9712::NONE:               return "NONE";
        case PciSubDevice177D9712::SUBDEVICE_177D0003: return "SUBDEVICE_177D0003";
        case PciSubDevice177D9712::SUBDEVICE_177D0004: return "SUBDEVICE_177D0004";
        case PciSubDevice177D9712::SUBDEVICE_177D0005: return "SUBDEVICE_177D0005";
        case PciSubDevice177D9712::SUBDEVICE_177D0006: return "SUBDEVICE_177D0006";
        case PciSubDevice177D9712::SUBDEVICE_177D0007: return "SUBDEVICE_177D0007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice177D9712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice177D9712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177D9712::SUBDEVICE_177D0003: return "CN2350 [LiquidIO II] 2-port 10GbE SRIOV Virtual Function";
        case PciSubDevice177D9712::SUBDEVICE_177D0004: return "CN2350 [LiquidIO II] 2-port 10GbE SRIOV Virtual Function";
        case PciSubDevice177D9712::SUBDEVICE_177D0005: return "CN2360 [LiquidIO II] 2-port 10GbE SRIOV Virtual Function";
        case PciSubDevice177D9712::SUBDEVICE_177D0006: return "CN2360 [LiquidIO II] 2-port 25GbE SRIOV Virtual Function";
        case PciSubDevice177D9712::SUBDEVICE_177D0007: return "CN2350 [LiquidIO II] 2-port 25GbE SRIOV Virtual Function";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9712_H
