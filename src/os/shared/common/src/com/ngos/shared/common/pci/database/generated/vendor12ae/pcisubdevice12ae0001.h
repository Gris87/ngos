// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCISUBDEVICE12AE0001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCISUBDEVICE12AE0001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12AE0001: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140104 = 0x10140104,
    SUBDEVICE_12AE0001 = 0x12AE0001
};



inline const char8* enumToString(PciSubDevice12AE0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12AE0001::NONE:               return "NONE";
        case PciSubDevice12AE0001::SUBDEVICE_10140104: return "SUBDEVICE_10140104";
        case PciSubDevice12AE0001::SUBDEVICE_12AE0001: return "SUBDEVICE_12AE0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12AE0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12AE0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12AE0001::SUBDEVICE_10140104: return "Gigabit Ethernet-SX PCI Adapter";
        case PciSubDevice12AE0001::SUBDEVICE_12AE0001: return "Gigabit Ethernet-SX (Universal)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12AE_PCISUBDEVICE12AE0001_H
