// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC94020: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_180C2040 = 0x180C2040
};



inline const char8* enumToString(PciSubDevice1FC94020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94020::NONE:               return "NONE";
        case PciSubDevice1FC94020::SUBDEVICE_180C2040: return "SUBDEVICE_180C2040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC94020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC94020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94020::SUBDEVICE_180C2040: return "Mustang-200 10GbE Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94020_H
