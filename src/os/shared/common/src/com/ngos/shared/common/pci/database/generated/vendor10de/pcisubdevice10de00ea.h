// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00EA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00EA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00EA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043819D = 0x1043819D,
    SUBDEVICE_105B0C43 = 0x105B0C43,
    SUBDEVICE_1462B010 = 0x1462B010,
    SUBDEVICE_147B1C0B = 0x147B1C0B
};



inline const char8* enumToString(PciSubDevice10DE00EA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00EA::NONE:               return "NONE";
        case PciSubDevice10DE00EA::SUBDEVICE_1043819D: return "SUBDEVICE_1043819D";
        case PciSubDevice10DE00EA::SUBDEVICE_105B0C43: return "SUBDEVICE_105B0C43";
        case PciSubDevice10DE00EA::SUBDEVICE_1462B010: return "SUBDEVICE_1462B010";
        case PciSubDevice10DE00EA::SUBDEVICE_147B1C0B: return "SUBDEVICE_147B1C0B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00EA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00EA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00EA::SUBDEVICE_1043819D: return "K8N-E";
        case PciSubDevice10DE00EA::SUBDEVICE_105B0C43: return "Winfast NF3250K8AA";
        case PciSubDevice10DE00EA::SUBDEVICE_1462B010: return "K8N Neo-FSR v2.0";
        case PciSubDevice10DE00EA::SUBDEVICE_147B1C0B: return "NF8 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00EA_H
