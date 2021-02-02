// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00DF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00DF: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380A7 = 0x104380A7,
    SUBDEVICE_105B0C43 = 0x105B0C43,
    SUBDEVICE_147B1C0B = 0x147B1C0B
};



inline const char8* enumToString(PciSubDevice10DE00DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00DF::NONE:               return "NONE";
        case PciSubDevice10DE00DF::SUBDEVICE_104380A7: return "SUBDEVICE_104380A7";
        case PciSubDevice10DE00DF::SUBDEVICE_105B0C43: return "SUBDEVICE_105B0C43";
        case PciSubDevice10DE00DF::SUBDEVICE_147B1C0B: return "SUBDEVICE_147B1C0B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00DF::SUBDEVICE_104380A7: return "K8N-E";
        case PciSubDevice10DE00DF::SUBDEVICE_105B0C43: return "Winfast NF3250K8AA";
        case PciSubDevice10DE00DF::SUBDEVICE_147B1C0B: return "NF8 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00DF_H
