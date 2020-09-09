// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR194A_PCIDEVICE194A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR194A_PCIDEVICE194A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice194A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1111 = 0x1111,
    DEVICE_1112 = 0x1112,
    DEVICE_1113 = 0x1113,
    DEVICE_1114 = 0x1114,
    DEVICE_1115 = 0x1115,
    DEVICE_1200 = 0x1200,
    DEVICE_1201 = 0x1201,
    DEVICE_1202 = 0x1202,
    DEVICE_1203 = 0x1203
};



inline const char8* enumToString(PciDevice194A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice194A::NONE:        return "NONE";
        case PciDevice194A::DEVICE_1111: return "DEVICE_1111";
        case PciDevice194A::DEVICE_1112: return "DEVICE_1112";
        case PciDevice194A::DEVICE_1113: return "DEVICE_1113";
        case PciDevice194A::DEVICE_1114: return "DEVICE_1114";
        case PciDevice194A::DEVICE_1115: return "DEVICE_1115";
        case PciDevice194A::DEVICE_1200: return "DEVICE_1200";
        case PciDevice194A::DEVICE_1201: return "DEVICE_1201";
        case PciDevice194A::DEVICE_1202: return "DEVICE_1202";
        case PciDevice194A::DEVICE_1203: return "DEVICE_1203";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice194A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice194A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice194A::DEVICE_1111: return "FireSpy3850";
        case PciDevice194A::DEVICE_1112: return "FireSpy450b";
        case PciDevice194A::DEVICE_1113: return "FireSpy450bT";
        case PciDevice194A::DEVICE_1114: return "FireSpy850";
        case PciDevice194A::DEVICE_1115: return "FireSpy850bT";
        case PciDevice194A::DEVICE_1200: return "FireTrac 3460bT";
        case PciDevice194A::DEVICE_1201: return "FireTrac 3460bT (fallback firmware)";
        case PciDevice194A::DEVICE_1202: return "FireTrac 3460bT";
        case PciDevice194A::DEVICE_1203: return "FireTrac 3460bT (fallback firmware)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR194A_PCIDEVICE194A_H
