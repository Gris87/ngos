// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11AE10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11AE10_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0E11AE10: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E114030 = 0x0E114030,
    SUBDEVICE_0E114031 = 0x0E114031,
    SUBDEVICE_0E114032 = 0x0E114032,
    SUBDEVICE_0E114033 = 0x0E114033,
    SUBDEVICE_0E114034 = 0x0E114034
};



inline const char8* enumToString(PciSubDevice0E11AE10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11AE10::NONE:               return "NONE";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114030: return "SUBDEVICE_0E114030";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114031: return "SUBDEVICE_0E114031";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114032: return "SUBDEVICE_0E114032";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114033: return "SUBDEVICE_0E114033";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114034: return "SUBDEVICE_0E114034";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0E11AE10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0E11AE10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11AE10::SUBDEVICE_0E114030: return "Smart-2/P Array Controller";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114031: return "Smart-2SL Array Controller";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114032: return "Smart Array 3200 Controller";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114033: return "Smart Array 3100ES Controller";
        case PciSubDevice0E11AE10::SUBDEVICE_0E114034: return "Smart Array 221 Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11AE10_H
