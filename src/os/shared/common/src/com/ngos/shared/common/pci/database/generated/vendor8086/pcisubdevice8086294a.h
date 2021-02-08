// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086294A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086294A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086294A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_10438277 = 0x10438277,
    SUBDEVICE_14627345 = 0x14627345
};



inline const char8* enumToString(PciSubDevice8086294A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086294A::NONE:               return "NONE";
        case PciSubDevice8086294A::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice8086294A::SUBDEVICE_10438277: return "SUBDEVICE_10438277";
        case PciSubDevice8086294A::SUBDEVICE_14627345: return "SUBDEVICE_14627345";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086294A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086294A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086294A::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice8086294A::SUBDEVICE_10438277: return "P5K PRO Motherboard: 82801IR [ICH9R]";
        case PciSubDevice8086294A::SUBDEVICE_14627345: return "MS-7345 Motherboard: Intel 82801I/IR [ICH9/ICH9R]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086294A_H
