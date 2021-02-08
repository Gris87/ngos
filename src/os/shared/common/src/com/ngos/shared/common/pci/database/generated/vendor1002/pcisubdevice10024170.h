// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024170_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024170_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024170: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020003 = 0x10020003,
    SUBDEVICE_10024723 = 0x10024723,
    SUBDEVICE_14584025 = 0x14584025,
    SUBDEVICE_148C2067 = 0x148C2067,
    SUBDEVICE_174B7C28 = 0x174B7C28,
    SUBDEVICE_17EE2003 = 0x17EE2003,
    SUBDEVICE_18BC0100 = 0x18BC0100
};



inline const char8* enumToString(PciSubDevice10024170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024170::NONE:               return "NONE";
        case PciSubDevice10024170::SUBDEVICE_10020003: return "SUBDEVICE_10020003";
        case PciSubDevice10024170::SUBDEVICE_10024723: return "SUBDEVICE_10024723";
        case PciSubDevice10024170::SUBDEVICE_14584025: return "SUBDEVICE_14584025";
        case PciSubDevice10024170::SUBDEVICE_148C2067: return "SUBDEVICE_148C2067";
        case PciSubDevice10024170::SUBDEVICE_174B7C28: return "SUBDEVICE_174B7C28";
        case PciSubDevice10024170::SUBDEVICE_17EE2003: return "SUBDEVICE_17EE2003";
        case PciSubDevice10024170::SUBDEVICE_18BC0100: return "SUBDEVICE_18BC0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024170 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024170::SUBDEVICE_10020003: return "R9600 Pro secondary (Asus OEM for HP)";
        case PciSubDevice10024170::SUBDEVICE_10024723: return "All-in-Wonder 2006 AGP Edition (Secondary)";
        case PciSubDevice10024170::SUBDEVICE_14584025: return "GV-R96128D (Secondary)";
        case PciSubDevice10024170::SUBDEVICE_148C2067: return "R96A-C3N (Secondary)";
        case PciSubDevice10024170::SUBDEVICE_174B7C28: return "GC-R9600PRO (Secondary)";
        case PciSubDevice10024170::SUBDEVICE_17EE2003: return "Radeon 9600 256Mb (Secondary)";
        case PciSubDevice10024170::SUBDEVICE_18BC0100: return "GC-R9600PRO (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024170_H
