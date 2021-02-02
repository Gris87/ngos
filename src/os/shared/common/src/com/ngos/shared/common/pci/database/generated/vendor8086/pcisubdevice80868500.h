// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868500_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868500_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80868500: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19930DED = 0x19930DED,
    SUBDEVICE_19930DEE = 0x19930DEE,
    SUBDEVICE_19930DEF = 0x19930DEF
};



inline const char8* enumToString(PciSubDevice80868500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868500::NONE:               return "NONE";
        case PciSubDevice80868500::SUBDEVICE_19930DED: return "SUBDEVICE_19930DED";
        case PciSubDevice80868500::SUBDEVICE_19930DEE: return "SUBDEVICE_19930DEE";
        case PciSubDevice80868500::SUBDEVICE_19930DEF: return "SUBDEVICE_19930DEF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80868500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80868500 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868500::SUBDEVICE_19930DED: return "mGuard-PCI AV#2";
        case PciSubDevice80868500::SUBDEVICE_19930DEE: return "mGuard-PCI AV#1";
        case PciSubDevice80868500::SUBDEVICE_19930DEF: return "mGuard-PCI AV#0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868500_H
