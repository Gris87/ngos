// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DEA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DEA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0DEA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA365A = 0x17AA365A,
    SUBDEVICE_17AA365B = 0x17AA365B,
    SUBDEVICE_17AA365E = 0x17AA365E,
    SUBDEVICE_17AA3660 = 0x17AA3660,
    SUBDEVICE_17AA366C = 0x17AA366C
};



inline const char8* enumToString(PciSubDevice10DE0DEA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0DEA::NONE:               return "NONE";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365A: return "SUBDEVICE_17AA365A";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365B: return "SUBDEVICE_17AA365B";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365E: return "SUBDEVICE_17AA365E";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA3660: return "SUBDEVICE_17AA3660";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA366C: return "SUBDEVICE_17AA366C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0DEA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0DEA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365A: return "GeForce 615";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365B: return "GeForce 615";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA365E: return "GeForce 615";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA3660: return "GeForce 615";
        case PciSubDevice10DE0DEA::SUBDEVICE_17AA366C: return "GeForce 615";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0DEA_H
