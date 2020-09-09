// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E02_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E02_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861E02: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104384CA = 0x104384CA,
    SUBDEVICE_18491E02 = 0x18491E02
};



inline const char8* enumToString(PciSubDevice80861E02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E02::NONE:               return "NONE";
        case PciSubDevice80861E02::SUBDEVICE_104384CA: return "SUBDEVICE_104384CA";
        case PciSubDevice80861E02::SUBDEVICE_18491E02: return "SUBDEVICE_18491E02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861E02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861E02 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861E02::SUBDEVICE_104384CA: return "P8 series motherboard";
        case PciSubDevice80861E02::SUBDEVICE_18491E02: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861E02_H
