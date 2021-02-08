// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024150_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024150_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024150: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020002 = 0x10020002,
    SUBDEVICE_10020003 = 0x10020003,
    SUBDEVICE_10024722 = 0x10024722,
    SUBDEVICE_14584024 = 0x14584024,
    SUBDEVICE_148C2064 = 0x148C2064,
    SUBDEVICE_148C2066 = 0x148C2066,
    SUBDEVICE_174B7C19 = 0x174B7C19,
    SUBDEVICE_174B7C29 = 0x174B7C29,
    SUBDEVICE_17EE2002 = 0x17EE2002,
    SUBDEVICE_18BC0101 = 0x18BC0101
};



inline const char8* enumToString(PciSubDevice10024150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024150::NONE:               return "NONE";
        case PciSubDevice10024150::SUBDEVICE_10020002: return "SUBDEVICE_10020002";
        case PciSubDevice10024150::SUBDEVICE_10020003: return "SUBDEVICE_10020003";
        case PciSubDevice10024150::SUBDEVICE_10024722: return "SUBDEVICE_10024722";
        case PciSubDevice10024150::SUBDEVICE_14584024: return "SUBDEVICE_14584024";
        case PciSubDevice10024150::SUBDEVICE_148C2064: return "SUBDEVICE_148C2064";
        case PciSubDevice10024150::SUBDEVICE_148C2066: return "SUBDEVICE_148C2066";
        case PciSubDevice10024150::SUBDEVICE_174B7C19: return "SUBDEVICE_174B7C19";
        case PciSubDevice10024150::SUBDEVICE_174B7C29: return "SUBDEVICE_174B7C29";
        case PciSubDevice10024150::SUBDEVICE_17EE2002: return "SUBDEVICE_17EE2002";
        case PciSubDevice10024150::SUBDEVICE_18BC0101: return "SUBDEVICE_18BC0101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024150::SUBDEVICE_10020002: return "R9600 Pro primary (Asus OEM for HP)";
        case PciSubDevice10024150::SUBDEVICE_10020003: return "R9600 Pro secondary (Asus OEM for HP)";
        case PciSubDevice10024150::SUBDEVICE_10024722: return "All-in-Wonder 2006 AGP Edition";
        case PciSubDevice10024150::SUBDEVICE_14584024: return "GV-R96128D";
        case PciSubDevice10024150::SUBDEVICE_148C2064: return "R96A-C3N";
        case PciSubDevice10024150::SUBDEVICE_148C2066: return "R96A-C3N";
        case PciSubDevice10024150::SUBDEVICE_174B7C19: return "Atlantis Radeon 9600 Pro";
        case PciSubDevice10024150::SUBDEVICE_174B7C29: return "GC-R9600PRO";
        case PciSubDevice10024150::SUBDEVICE_17EE2002: return "Radeon 9600 256Mb Primary";
        case PciSubDevice10024150::SUBDEVICE_18BC0101: return "GC-R9600PRO (Primary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024150_H
