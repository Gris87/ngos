// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862415_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862415_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862415: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280095 = 0x10280095,
    SUBDEVICE_102800B4 = 0x102800B4,
    SUBDEVICE_110A0051 = 0x110A0051,
    SUBDEVICE_11D40040 = 0x11D40040,
    SUBDEVICE_11D40048 = 0x11D40048,
    SUBDEVICE_11D45340 = 0x11D45340,
    SUBDEVICE_17341025 = 0x17341025,
    SUBDEVICE_1AF41100 = 0x1AF41100
};



inline const char8* enumToString(PciSubDevice80862415 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862415::NONE:               return "NONE";
        case PciSubDevice80862415::SUBDEVICE_10280095: return "SUBDEVICE_10280095";
        case PciSubDevice80862415::SUBDEVICE_102800B4: return "SUBDEVICE_102800B4";
        case PciSubDevice80862415::SUBDEVICE_110A0051: return "SUBDEVICE_110A0051";
        case PciSubDevice80862415::SUBDEVICE_11D40040: return "SUBDEVICE_11D40040";
        case PciSubDevice80862415::SUBDEVICE_11D40048: return "SUBDEVICE_11D40048";
        case PciSubDevice80862415::SUBDEVICE_11D45340: return "SUBDEVICE_11D45340";
        case PciSubDevice80862415::SUBDEVICE_17341025: return "SUBDEVICE_17341025";
        case PciSubDevice80862415::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862415 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862415 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862415::SUBDEVICE_10280095: return "Precision Workstation 220 Integrated Digital Audio";
        case PciSubDevice80862415::SUBDEVICE_102800B4: return "OptiPlex GX110";
        case PciSubDevice80862415::SUBDEVICE_110A0051: return "Activy 2xx";
        case PciSubDevice80862415::SUBDEVICE_11D40040: return "SoundMAX Integrated Digital Audio";
        case PciSubDevice80862415::SUBDEVICE_11D40048: return "SoundMAX Integrated Digital Audio";
        case PciSubDevice80862415::SUBDEVICE_11D45340: return "SoundMAX Integrated Digital Audio";
        case PciSubDevice80862415::SUBDEVICE_17341025: return "Activy 3xx";
        case PciSubDevice80862415::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862415_H
