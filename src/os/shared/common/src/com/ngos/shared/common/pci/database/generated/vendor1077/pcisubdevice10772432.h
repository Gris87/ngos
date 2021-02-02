// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772432_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772432_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772432: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C7040 = 0x103C7040,
    SUBDEVICE_10770137 = 0x10770137
};



inline const char8* enumToString(PciSubDevice10772432 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772432::NONE:               return "NONE";
        case PciSubDevice10772432::SUBDEVICE_103C7040: return "SUBDEVICE_103C7040";
        case PciSubDevice10772432::SUBDEVICE_10770137: return "SUBDEVICE_10770137";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772432 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772432 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772432::SUBDEVICE_103C7040: return "FC1142SR 4Gb 1-port PCIe Fibre Channel Host Bus Adapter [HPAE311A]";
        case PciSubDevice10772432::SUBDEVICE_10770137: return "QLE2460 4 GB PCI-X Host-Bus-Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772432_H
