// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8025_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8025_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8025: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043813C = 0x1043813C,
    SUBDEVICE_14438025 = 0x14438025,
    SUBDEVICE_14581000 = 0x14581000,
    SUBDEVICE_15468025 = 0x15468025,
    SUBDEVICE_17FC8025 = 0x17FC8025
};



inline const char8* enumToString(PciSubDevice104C8025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8025::NONE:               return "NONE";
        case PciSubDevice104C8025::SUBDEVICE_1043813C: return "SUBDEVICE_1043813C";
        case PciSubDevice104C8025::SUBDEVICE_14438025: return "SUBDEVICE_14438025";
        case PciSubDevice104C8025::SUBDEVICE_14581000: return "SUBDEVICE_14581000";
        case PciSubDevice104C8025::SUBDEVICE_15468025: return "SUBDEVICE_15468025";
        case PciSubDevice104C8025::SUBDEVICE_17FC8025: return "SUBDEVICE_17FC8025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8025::SUBDEVICE_1043813C: return "P5P series mainboard";
        case PciSubDevice104C8025::SUBDEVICE_14438025: return "FireBoard800";
        case PciSubDevice104C8025::SUBDEVICE_14581000: return "GA-K8N Ultra-9 Mainboard";
        case PciSubDevice104C8025::SUBDEVICE_15468025: return "FWB-PCI01";
        case PciSubDevice104C8025::SUBDEVICE_17FC8025: return "GIC3800";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8025_H
