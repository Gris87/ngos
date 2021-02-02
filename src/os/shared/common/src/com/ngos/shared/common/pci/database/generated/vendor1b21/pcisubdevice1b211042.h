// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B211042: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431059 = 0x10431059,
    SUBDEVICE_10438488 = 0x10438488,
    SUBDEVICE_18491042 = 0x18491042
};



inline const char8* enumToString(PciSubDevice1B211042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B211042::NONE:               return "NONE";
        case PciSubDevice1B211042::SUBDEVICE_10431059: return "SUBDEVICE_10431059";
        case PciSubDevice1B211042::SUBDEVICE_10438488: return "SUBDEVICE_10438488";
        case PciSubDevice1B211042::SUBDEVICE_18491042: return "SUBDEVICE_18491042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B211042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B211042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B211042::SUBDEVICE_10431059: return "K53SM motherboard";
        case PciSubDevice1B211042::SUBDEVICE_10438488: return "P8B WS Motherboard";
        case PciSubDevice1B211042::SUBDEVICE_18491042: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCISUBDEVICE1B211042_H
