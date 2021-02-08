// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063188_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063188_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063188: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380A3 = 0x104380A3,
    SUBDEVICE_147B1407 = 0x147B1407
};



inline const char8* enumToString(PciSubDevice11063188 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063188::NONE:               return "NONE";
        case PciSubDevice11063188::SUBDEVICE_104380A3: return "SUBDEVICE_104380A3";
        case PciSubDevice11063188::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063188 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063188 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063188::SUBDEVICE_104380A3: return "K8V Deluxe/K8V-X motherboard";
        case PciSubDevice11063188::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063188_H
