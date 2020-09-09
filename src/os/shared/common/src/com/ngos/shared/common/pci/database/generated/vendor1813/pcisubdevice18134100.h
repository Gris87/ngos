// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCISUBDEVICE18134100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCISUBDEVICE18134100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18134100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16BE0002 = 0x16BE0002
};



inline const char8* enumToString(PciSubDevice18134100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18134100::NONE:               return "NONE";
        case PciSubDevice18134100::SUBDEVICE_16BE0002: return "SUBDEVICE_16BE0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18134100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18134100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18134100::SUBDEVICE_16BE0002: return "V9x HAM 1394";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCISUBDEVICE18134100_H
