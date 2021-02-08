// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAD8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAD8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002AAD8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_174BAAD8 = 0x174BAAD8
};



inline const char8* enumToString(PciSubDevice1002AAD8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AAD8::NONE:               return "NONE";
        case PciSubDevice1002AAD8::SUBDEVICE_174BAAD8: return "SUBDEVICE_174BAAD8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002AAD8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002AAD8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AAD8::SUBDEVICE_174BAAD8: return "Radeon R9 285/380 HDMI Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AAD8_H
