// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8120_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8120_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice123F8120: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE01E1 = 0x10DE01E1,
    SUBDEVICE_10DE01E2 = 0x10DE01E2,
    SUBDEVICE_10DE01E3 = 0x10DE01E3,
    SUBDEVICE_10DE0248 = 0x10DE0248,
    SUBDEVICE_10DE0249 = 0x10DE0249,
    SUBDEVICE_11BD0006 = 0x11BD0006,
    SUBDEVICE_11BD000A = 0x11BD000A,
    SUBDEVICE_11BD000F = 0x11BD000F,
    SUBDEVICE_18090016 = 0x18090016
};



inline const char8* enumToString(PciSubDevice123F8120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice123F8120::NONE:               return "NONE";
        case PciSubDevice123F8120::SUBDEVICE_10DE01E1: return "SUBDEVICE_10DE01E1";
        case PciSubDevice123F8120::SUBDEVICE_10DE01E2: return "SUBDEVICE_10DE01E2";
        case PciSubDevice123F8120::SUBDEVICE_10DE01E3: return "SUBDEVICE_10DE01E3";
        case PciSubDevice123F8120::SUBDEVICE_10DE0248: return "SUBDEVICE_10DE0248";
        case PciSubDevice123F8120::SUBDEVICE_10DE0249: return "SUBDEVICE_10DE0249";
        case PciSubDevice123F8120::SUBDEVICE_11BD0006: return "SUBDEVICE_11BD0006";
        case PciSubDevice123F8120::SUBDEVICE_11BD000A: return "SUBDEVICE_11BD000A";
        case PciSubDevice123F8120::SUBDEVICE_11BD000F: return "SUBDEVICE_11BD000F";
        case PciSubDevice123F8120::SUBDEVICE_18090016: return "SUBDEVICE_18090016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice123F8120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice123F8120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice123F8120::SUBDEVICE_10DE01E1: return "NVTV PAL";
        case PciSubDevice123F8120::SUBDEVICE_10DE01E2: return "NVTV NTSC";
        case PciSubDevice123F8120::SUBDEVICE_10DE01E3: return "NVTV PAL";
        case PciSubDevice123F8120::SUBDEVICE_10DE0248: return "NVTV NTSC";
        case PciSubDevice123F8120::SUBDEVICE_10DE0249: return "NVTV PAL";
        case PciSubDevice123F8120::SUBDEVICE_11BD0006: return "DV500 E4";
        case PciSubDevice123F8120::SUBDEVICE_11BD000A: return "DV500 E4";
        case PciSubDevice123F8120::SUBDEVICE_11BD000F: return "DV500 E4";
        case PciSubDevice123F8120::SUBDEVICE_18090016: return "Emuzed MAUI-III PCI PVR FM TV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123F_PCISUBDEVICE123F8120_H
