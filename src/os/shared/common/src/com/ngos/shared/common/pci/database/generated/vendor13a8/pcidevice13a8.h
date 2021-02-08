// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A8_PCIDEVICE13A8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A8_PCIDEVICE13A8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13A8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0152 = 0x0152,
    DEVICE_0154 = 0x0154,
    DEVICE_0158 = 0x0158,
    DEVICE_0252 = 0x0252,
    DEVICE_0254 = 0x0254,
    DEVICE_0258 = 0x0258,
    DEVICE_0352 = 0x0352
};



inline const char8* enumToString(PciDevice13A8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13A8::NONE:        return "NONE";
        case PciDevice13A8::DEVICE_0152: return "DEVICE_0152";
        case PciDevice13A8::DEVICE_0154: return "DEVICE_0154";
        case PciDevice13A8::DEVICE_0158: return "DEVICE_0158";
        case PciDevice13A8::DEVICE_0252: return "DEVICE_0252";
        case PciDevice13A8::DEVICE_0254: return "DEVICE_0254";
        case PciDevice13A8::DEVICE_0258: return "DEVICE_0258";
        case PciDevice13A8::DEVICE_0352: return "DEVICE_0352";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13A8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13A8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13A8::DEVICE_0152: return "XR17C/D152 Dual PCI UART";
        case PciDevice13A8::DEVICE_0154: return "XR17C154 Quad UART";
        case PciDevice13A8::DEVICE_0158: return "XR17C158 Octal UART";
        case PciDevice13A8::DEVICE_0252: return "XR17V252 Dual UART PCI controller";
        case PciDevice13A8::DEVICE_0254: return "XR17V254 Quad UART PCI controller";
        case PciDevice13A8::DEVICE_0258: return "XR17V258 Octal UART PCI controller";
        case PciDevice13A8::DEVICE_0352: return "XR17V3521 Dual PCIe UART";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A8_PCIDEVICE13A8_H
