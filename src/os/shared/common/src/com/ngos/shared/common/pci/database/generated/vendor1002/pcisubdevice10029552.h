// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029552_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029552_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029552: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281103 = 0x10281103,
    SUBDEVICE_145821AC = 0x145821AC,
    SUBDEVICE_145821ED = 0x145821ED,
    SUBDEVICE_148C3000 = 0x148C3000,
    SUBDEVICE_174B3000 = 0x174B3000
};



inline const char8* enumToString(PciSubDevice10029552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029552::NONE:               return "NONE";
        case PciSubDevice10029552::SUBDEVICE_10281103: return "SUBDEVICE_10281103";
        case PciSubDevice10029552::SUBDEVICE_145821AC: return "SUBDEVICE_145821AC";
        case PciSubDevice10029552::SUBDEVICE_145821ED: return "SUBDEVICE_145821ED";
        case PciSubDevice10029552::SUBDEVICE_148C3000: return "SUBDEVICE_148C3000";
        case PciSubDevice10029552::SUBDEVICE_174B3000: return "SUBDEVICE_174B3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029552 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029552::SUBDEVICE_10281103: return "M92 [Mobility Radeon HD 4330]";
        case PciSubDevice10029552::SUBDEVICE_145821AC: return "Radeon HD 4350";
        case PciSubDevice10029552::SUBDEVICE_145821ED: return "Radeon HD 4550";
        case PciSubDevice10029552::SUBDEVICE_148C3000: return "Radeon HD 4350 Go! Green 512MB GDDR3";
        case PciSubDevice10029552::SUBDEVICE_174B3000: return "Radeon HD 4350/4550 HyperMemory DDR2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029552_H
